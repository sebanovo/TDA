//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include <cmath>
#include <vector>
#include "ConjuntoVector.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoVector
{
    ConjuntoVector::ConjuntoVector()
    {
        v = new bool[MAX];
        cant = 0;
        for (int i = 1; i <= MAX; i++) {
            v[i] = 0;
        }
    }

    // cantidad de elementos del conjunto
    int ConjuntoVector::cardinal()
    {
        return cant;
    }

    // esta vacio?
    bool ConjuntoVector::vacio()
    {
        return cant == 0;
    }

    // busca el lugar que ocupa el elemento E en el conjunto
    // en este caso el indice coincide con el elemento
    int ConjuntoVector::ordinal(int e)
    {
        int resp = 0;
        for (int i = 1; i <= MAX; i++) {
            if (v[i] != 0) {
                resp++;
                if (e == i)
                    return resp;
            }
        }
        return resp;
    }

    // inserta elementos en el conjunto
    void ConjuntoVector::inserta(int e)
    {
        if (!pertenece(e)) {
            v[e] = 1;
            cant++;
        }
    }

    // elimna un elemento del conjunto
    void ConjuntoVector::suprime(int e)
    {
        if (pertenece(e)) {
            v[e] = 0;
            cant--;
        }
    }

    bool ConjuntoVector::pertenece(int e)
    {
        return v[e] == 1;
    }

    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoVector::muestrea()
    {
        int resp = 0;
        int elemento = 0;
        int lug = rand() % cardinal() + 1; // >= 1 && <= cant
        for (int i = 1; i <= MAX; i++) {
            if (v[i] == 1) {
                resp++;
                if (resp == lug)
                    return i;
            }
        }
        return elemento;
    }

    ConjuntoVector::~ConjuntoVector()
    {
        delete[] v;
    }

    std::string ConjuntoVector::mostrar()
    {
        std::string s = "{";
        for (int i = 1, j = 0; i <= MAX; i++) {
            if (v[i]) {
                j++;
                s += std::to_string(i);
                s += j < cardinal() ? "," : "";
            }
        }
        return s + "}";
    }

    void ConjuntoVector::dibujar_conjunto(TForm* Form, int posX, int posY)
    {
        TCanvas* Canvas = Form->Canvas;
        // limpiar el lienzo
        int anchoTexto = Canvas->TextWidth(mostrar().c_str());
        int altoTexto = Canvas->TextHeight(mostrar().c_str());
        TRect rect(posX, posY, posX + anchoTexto, posY + altoTexto);
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(rect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }

    struct Posicion
    {
        int x;
        int y;
        int width;
        int height;
    };

    bool seSolapan(const Posicion a, const Posicion b)
    {
        return !(a.x + a.width < b.x || a.x > b.x + b.width ||
                 a.y + a.height < b.y || a.y > b.y + b.height);
    }

    void ConjuntoVector::graficar_conjunto(
        TForm* Form, int centroX, int centroY, int radio, std::string nombre)
    {
        TCanvas* Canvas = Form->Canvas;

        // limpiar el circulo
        Canvas->Brush->Color = Form->Color;
        TRect rect(
            centroX - radio, centroY - radio, centroX + radio, centroY + radio);
        Canvas->FillRect(rect);

        // dibujar circulo
        Canvas->Pen->Width = 10;
        Canvas->Pen->Color = clBlack;
        Canvas->Brush->Color = clBtnFace;
        Canvas->Ellipse(
            centroX - radio, centroY - radio, centroX + radio, centroY + radio);

        // dibujar el nombre
        Canvas->Font->Color = clScrollBar;
        Canvas->Font->Size = radio / 6;
        Canvas->Brush->Style = bsClear;
        Canvas->TextOutW(centroX - radio, centroY - radio, nombre.c_str());
        Canvas->Font->Color = clBlack;
        Canvas->Brush->Style = bsSolid;

        // dibujar elementos
        Canvas->Font->Size = radio / 10;
        Canvas->Font->Name = "Microsoft YaHei UI";
        Canvas->Font->Style = TFontStyles() << fsBold;
        Canvas->Brush->Style = bsClear;

        std::vector<Posicion> posiciones;

        for (int i = 1; i <= MAX; i++) {
            if (pertenece(i)) {
                String dato = String(i);

                int datoW = Canvas->TextWidth(dato);
                int datoH = Canvas->TextHeight(dato);

                double angulo;
                double distancia;
                int x, y;
                Posicion nuevaPosicion;

                // Repetir hasta encontrar una posición sin solapamiento
                bool posicionValida;
                do {
                    angulo = rand() * 2 * M_PI / RAND_MAX;
                    distancia = rand() % (radio - std::max(datoW, datoH) / 2);

                    x = centroX + distancia * cos(angulo);
                    y = centroY + distancia * sin(angulo);

                    nuevaPosicion = { x - datoW / 2, y - datoH / 2, datoW,
                        datoH };

                    // verificar solapamiento
                    posicionValida = true;
                    for (const auto posicion : posiciones) {
                        if (seSolapan(posicion, nuevaPosicion)) {
                            posicionValida = false;
                            break;
                        }
                    }

                } while (!posicionValida ||
                         (x - datoW / 2 < centroX - radio ||
                             x + datoW / 2 > centroX + radio) ||
                         (y - datoH / 2 < centroY - radio ||
                             y + datoH / 2 > centroY + radio));

                Canvas->TextOutW(nuevaPosicion.x, nuevaPosicion.y, dato);
                posiciones.push_back(nuevaPosicion);
            }
        }

        Canvas->Brush->Style = bsSolid;
        Canvas->Font->Style = TFontStyles();
    }

    void _union(ConjuntoVector* a, ConjuntoVector* b, ConjuntoVector* c)
    {
        ConjuntoVector* aux = new ConjuntoVector;
        while (!a->vacio()) {
            int m = a->muestrea();
            a->suprime(m);
            aux->inserta(m);
            c->inserta(m);
        }
        // while (!aux->vacio()) {
        //     int m = aux->muestrea();
        //     aux->suprime(m);
        //     a->inserta(m);
        // }
        while (!b->vacio()) {
            int m = b->muestrea();
            b->suprime(m);
            aux->inserta(m);
            if (!c->pertenece(m))
                c->inserta(m);
        }
        // while (!aux->vacio()) {
        //     int m = aux->muestrea();
        //     aux->suprime(m);
        //     b->inserta(m);
        // }

        delete aux;
    };

    void _interseccion(ConjuntoVector* a, ConjuntoVector* b, ConjuntoVector* c)
    {
        auto* aux = new ConjuntoVector;
        while (!a->vacio()) {
            int m = a->muestrea();
            if (a->pertenece(m) && b->pertenece(m)) {
                c->inserta(m);
            }
            a->suprime(m);
            aux->inserta(m);
        }

        while (!aux->vacio()) {
            int m = aux->muestrea();
            aux->suprime(m);
            a->inserta(m);
        }

        delete aux;
    }

    bool _equivalentes(ConjuntoVector* a, ConjuntoVector* b)
    {
        return a->cardinal() == b->cardinal();
    }

} // namespace UConjuntoVector

