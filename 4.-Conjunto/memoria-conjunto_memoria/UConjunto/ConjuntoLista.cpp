//---------------------------------------------------------------------------

#pragma hdrstop

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
    void _union(ConjuntoLista* a, ConjuntoLista* b, ConjuntoLista* c)
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

    void _union()
    {
        ConjuntoLista* a = new ConjuntoLista();
        ConjuntoLista* b = new ConjuntoLista();
        ConjuntoLista* c = new ConjuntoLista();
        a->inserta(1);
        a->inserta(2);
        a->inserta(3);
        a->inserta(5);
        b->inserta(1);
        b->inserta(2);
        b->inserta(3);
        b->inserta(4);
        UConjuntoLista::_union(a, b, c);
        std::cout << a->mostrar() << std::endl;
        std::cout << b->mostrar() << std::endl;
        std::cout << c->mostrar() << std::endl;

        delete a, b, c;
    }

    void _interseccion(ConjuntoLista* a, ConjuntoLista* b, ConjuntoLista* c)
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

    void _interseccion()
    {
        ConjuntoLista* a = new ConjuntoLista();
        ConjuntoLista* b = new ConjuntoLista();
        ConjuntoLista* c = new ConjuntoLista();
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

    bool _equivalentes(ConjuntoLista* a, ConjuntoLista* b)
    {
        return a->cardinal() == b->cardinal();
    }

    void _equivalentes()
    {
        ConjuntoLista* a = new ConjuntoLista();
        ConjuntoLista* b = new ConjuntoLista();
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
} // namespace UConjuntoLista

