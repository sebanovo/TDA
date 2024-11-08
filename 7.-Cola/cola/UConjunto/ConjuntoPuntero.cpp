//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include <cmath>
#include <vector>
#include "ConjuntoPuntero.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoPuntero {
    ConjuntoPuntero::ConjuntoPuntero() {
        PtrConj = nullptr;
        cant = 0;
    }

    // cantidad de elementos del conjunto
    int ConjuntoPuntero::cardinal() {
        return cant;
    }

    // esta vacio?
    bool ConjuntoPuntero::vacio() {
        return cant == 0;  //|| PtrConj == nullptr;
    }

    // busca el lugar que ocupa el elemento E en el conjunto
    int ConjuntoPuntero::ordinal(int e) {
        int resp = 0;
        Nodo* pc = PtrConj;
        while (pc != nullptr) {
            resp++;
            if (pc->dato == e) {
                return resp;
            }
            pc = pc->sig;
        }
        return -1;
    }

    // inserta elementos en el conjunto
    void ConjuntoPuntero::inserta(int e) {
        if (!pertenece(e)) {
            Nodo* dir = new Nodo();
            dir->dato = e;
            dir->sig = PtrConj;
            PtrConj = dir;
            cant++;
        } else {
            // error pertenece
        }
    }

    // elimna un elemento del conjunto
    void ConjuntoPuntero::suprime(int e) {
        if (!pertenece(e))
            return;

        Nodo* dir;
        if (PtrConj->dato == e) {  // caso si esta en la cabeza
            dir = PtrConj;
            PtrConj = PtrConj->sig;
        } else {
            Nodo* pc = PtrConj;
            Nodo* ant;
            while (pc != nullptr) {
                if (pc->dato == e) {
                    dir = pc;
                    break;
                }
                ant = pc;
                pc = pc->sig;
            }
            ant->sig = pc->sig;
            pc->sig = nullptr;
        }
        cant--;
        delete dir;
    }

    bool ConjuntoPuntero::pertenece(int e) {
        Nodo* pc = PtrConj;
        while (pc != nullptr) {
            if (pc->dato == e) {
                return true;
            }
            pc = pc->sig;
        }
        return false;
    }

    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoPuntero::muestrea() {
        if (vacio())
            return -1;
        int i = 0;
        int lugar = rand() % cardinal() + 1;  // >= 1 && <= cant
        Nodo* pc = PtrConj;
        while (pc != nullptr) {
            i++;
            if (i == lugar) {
                return pc->dato;
            }
            pc = pc->sig;
        }
    }

    ConjuntoPuntero::~ConjuntoPuntero() {
        Nodo* dir = PtrConj;
        Nodo* ant;
        while (dir != nullptr) {
            ant = dir;
            dir = dir->sig;
            delete ant;
        }
    }

    std::string ConjuntoPuntero::mostrar() {
        std::string s = "{";
        Nodo* x = PtrConj;
        int i = 0;
        while (x != nullptr) {
            i++;
            s += std::to_string(x->dato);
            s += i < cardinal() ? "," : "";
            x = x->sig;
        }
        return s + "}";
    }

    void ConjuntoPuntero::dibujar_conjunto(TForm* Form, int posX, int posY) {
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

    struct Posicion {
        int x;
        int y;
        int width;
        int height;
    };

    bool seSolapan(const Posicion a, const Posicion b) {
        return !(a.x + a.width < b.x || a.x > b.x + b.width ||
                 a.y + a.height < b.y || a.y > b.y + b.height);
    }

    void ConjuntoPuntero::graficar_conjunto(
        TForm* Form, int centroX, int centroY, int radio, std::string nombre) {
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

        Nodo* pc = PtrConj;
        std::vector<Posicion> posiciones;
        while (pc != nullptr) {
            String dato = String(pc->dato);

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

                nuevaPosicion = {x - datoW / 2, y - datoH / 2, datoW, datoH};

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
            pc = pc->sig;
        }

        Canvas->Brush->Style = bsSolid;
        Canvas->Font->Style = TFontStyles();
    }

    void ConjuntoPuntero::_union(ConjuntoPuntero* a, ConjuntoPuntero* b, ConjuntoPuntero* c) {
        ConjuntoPuntero* aux = new ConjuntoPuntero;
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

    void ConjuntoPuntero::_interseccion(ConjuntoPuntero* a, ConjuntoPuntero* b, ConjuntoPuntero* c) {
        auto* aux = new ConjuntoPuntero;
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

    bool ConjuntoPuntero::_equivalentes(ConjuntoPuntero* a, ConjuntoPuntero* b) {
        return a->cardinal() == b->cardinal();
    }
}  // namespace UConjuntoPuntero
