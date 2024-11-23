//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include <cmath>
#include <vector>
#include "ConjuntoLista.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoLista
{
    using UCSMemoria::NULO;
    ConjuntoLista::ConjuntoLista()
    {
        mem = new UCSMemoria::CSMemoria;
        elem = new UListaSM::ListaSM(mem);
        // elem = new UListaVector::ListaVector;
    }

    ConjuntoLista::ConjuntoLista(UCSMemoria::CSMemoria* m)
    {
        elem = new UListaSM::ListaSM(m);
        // elem = new UListaVector::ListaVector;
    }

    // cantidad de elementos del conjunto
    int ConjuntoLista::cardinal()
    {
        return elem->_longitud();
    }

    // esta vacio?
    bool ConjuntoLista::vacio()
    {
        return elem->_longitud() == 0;
    }

    // busca el lugar que ocupa el elemento E en el conjunto
    int ConjuntoLista::ordinal(int e)
    {
        int resp = 0;
        int pc = elem->primero();
        while (pc != NULO) {
            resp++;
            if (elem->recupera(pc) == e) {
                return resp;
            }
            pc = elem->siguiente(pc);
        }
        return -1;
    }

    // inserta elementos en el conjunto
    void ConjuntoLista::inserta(int e)
    {
        if (!pertenece(e)) {
            elem->inserta(elem->primero(), e);
        } else {
            // error pertenece
        }
    }

    // elimna un elemento del conjunto
    void ConjuntoLista::suprime(int e)
    {
        if (!pertenece(e))
            return;

        int aux = elem->primero();
        while (aux != -1) {
            if (elem->recupera(aux) == e) {
                elem->suprime(aux);
                return;
            }
            // if (elem->recupera(aux) == e && aux != -1) {
            //     elem->suprime(aux);
            //     return;
            // }
            aux = elem->siguiente(aux);
        }
    }

    bool ConjuntoLista::pertenece(int e)
    {
        int aux = elem->primero();
        while (aux != -1) {
            if (elem->recupera(aux) == e)
                return true;
            aux = elem->siguiente(aux);
        }
        return false;
    }

    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoLista::muestrea()
    {
        int i = 0;
        int lugar = rand() % cardinal() + 1; // >= 1 && <= cant
        int aux = elem->primero();
        while (aux != -1) {
            i++;
            if (i == lugar) {
                return elem->recupera(aux);
            }
            aux = elem->siguiente(aux);
        }
    }

    ConjuntoLista::~ConjuntoLista()
    {
        delete elem;
        // delete mem;
    }

    std::string ConjuntoLista::mostrar()
    {
        std::string s = "{";
        int aux = elem->_longitud() == 0 ? aux = -1 : elem->primero();
        int i = 0;
        while (aux != -1) {
            i++;
            s += std::to_string(elem->recupera(aux));
            s += i < cardinal() ? "," : "";
            aux = elem->siguiente(aux);
        }
        return s + "}";
    }

    void ConjuntoLista::dibujar_conjunto(TForm* Form, int posX, int posY)
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

    void ConjuntoLista::graficar_conjunto(
        TForm* Form, int centroX, int centroY, int radio, std::string nombre)
    {
        TCanvas* Canvas = Form->Canvas;

        // limpiar el circulo
        Canvas->Brush->Color = Form->Color;
        TRect rect(
            centroX - radio, centroY - radio, centroX + radio, centroY + radio);
        Canvas->FillRect(rect);

        // dibujar circulo
        int oldPenWidth = Canvas->Pen->Width;
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

        int pc = elem->primero();
        std::vector<Posicion> posiciones;

        while (pc != -1) {
            String dato = String(elem->recupera(pc));

            int datoW = Canvas->TextWidth(dato);
            int datoH = Canvas->TextHeight(dato);

            double angulo;
            double distancia;
            int x, y;
            Posicion nuevaPosicion;

            // Repetir hasta encontrar una posici�n sin solapamiento
            bool posicionValida;
            do {
                angulo = rand() * 2 * M_PI / RAND_MAX;
                distancia = rand() % (radio - std::max(datoW, datoH) / 2);

                x = centroX + distancia * cos(angulo);
                y = centroY + distancia * sin(angulo);

                nuevaPosicion = { x - datoW / 2, y - datoH / 2, datoW, datoH };

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
            pc = elem->siguiente(pc);
        }

        Canvas->Brush->Style = bsSolid;
        Canvas->Font->Style = TFontStyles();
        Canvas->Pen->Width = oldPenWidth;
    }

    void ConjuntoLista::_union(
        ConjuntoLista* a, ConjuntoLista* b, ConjuntoLista* c)
    {
        ConjuntoLista* aux = new ConjuntoLista;
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

    void ConjuntoLista::_interseccion(
        ConjuntoLista* a, ConjuntoLista* b, ConjuntoLista* c)
    {
        auto* aux = new ConjuntoLista;
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

    bool ConjuntoLista::_equivalentes(ConjuntoLista* a, ConjuntoLista* b)
    {
        return a->cardinal() == b->cardinal();
    }
} // namespace UConjuntoLista

