//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConjuntoPuntero.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoPuntero
{
    ConjuntoPuntero::ConjuntoPuntero()
    {
        PtrConj = nullptr;
        cant = 0;
    }

    // cantidad de elementos del conjunto
    int ConjuntoPuntero::cardinal()
    {
        return cant;
    }

    // esta vacio?
    bool ConjuntoPuntero::vacio()
    {
        return cant == 0; //|| PtrConj == nullptr;
    }

    // busca el lugar que ocupa el elemento E en el conjunto
    int ConjuntoPuntero::ordinal(int e)
    {
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
    void ConjuntoPuntero::inserta(int e)
    {
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
    void ConjuntoPuntero::suprime(int e)
    {
        if (!pertenece(e))
            return;

        Nodo* dir;
        if (PtrConj->dato == e) { // caso si esta en la cabeza
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

    bool ConjuntoPuntero::pertenece(int e)
    {
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
    int ConjuntoPuntero::muestrea()
    {
        if (vacio())
            return -1;
        int i = 0;
        int lugar = rand() % cardinal() + 1; // >= 1 && <= cant
        Nodo* pc = PtrConj;
        while (pc != nullptr) {
            i++;
            if (i == lugar) {
                return pc->dato;
            }
            pc = pc->sig;
        }
    }

    ConjuntoPuntero::~ConjuntoPuntero()
    {
        Nodo* dir = PtrConj;
        Nodo* ant;
        while (dir != nullptr) {
            ant = dir;
            dir = dir->sig;
            delete ant;
        }
    }

    std::string ConjuntoPuntero::mostrar()
    {
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

    void _union(ConjuntoPuntero* a, ConjuntoPuntero* b, ConjuntoPuntero* c)
    {
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

    void _union()
    {
        ConjuntoPuntero* a = new ConjuntoPuntero();
        ConjuntoPuntero* b = new ConjuntoPuntero();
        ConjuntoPuntero* c = new ConjuntoPuntero();
        a->inserta(1);
        a->inserta(2);
        a->inserta(3);
        a->inserta(5);
        b->inserta(1);
        b->inserta(2);
        b->inserta(3);
        b->inserta(4);
        _union(a, b, c);
        std::cout << a->mostrar() << std::endl;
        std::cout << b->mostrar() << std::endl;
        std::cout << c->mostrar() << std::endl;

        delete a, b, c;
    }

    void _interseccion(
        ConjuntoPuntero* a, ConjuntoPuntero* b, ConjuntoPuntero* c)
    {
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

    void _interseccion()
    {
        ConjuntoPuntero* a = new ConjuntoPuntero();
        ConjuntoPuntero* b = new ConjuntoPuntero();
        ConjuntoPuntero* c = new ConjuntoPuntero();
        a->inserta(1);
        a->inserta(2);
        a->inserta(3);
        a->inserta(5);
        b->inserta(1);
        b->inserta(2);
        b->inserta(3);
        b->inserta(4);
        _interseccion(a, b, c);
        std::cout << a->mostrar() << std::endl;
        std::cout << b->mostrar() << std::endl;
        std::cout << c->mostrar() << std::endl;

        delete a, b, c;
    }

    bool _equivalentes(ConjuntoPuntero* a, ConjuntoPuntero* b)
    {
        return a->cardinal() == b->cardinal();
    }

    void _equivalentes()
    {
        ConjuntoPuntero* a = new ConjuntoPuntero();
        ConjuntoPuntero* b = new ConjuntoPuntero();
        a->inserta(1);
        a->inserta(2);
        a->inserta(3);
        a->inserta(5);
        b->inserta(1);
        b->inserta(2);
        b->inserta(3);
        b->inserta(4);
        std::cout << (_equivalentes(a, b) ? "si" : "no") << " equivalentes"
                  << std::endl;

        delete a, b;
    }
} // namespace UConjuntoPuntero
