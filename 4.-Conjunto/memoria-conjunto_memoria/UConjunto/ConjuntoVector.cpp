//---------------------------------------------------------------------------

#pragma hdrstop

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

    ConjuntoVector::~ConjuntoVector()
    {
        delete[] v;
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

    void _union()
    {
        ConjuntoVector* a = new ConjuntoVector();
        ConjuntoVector* b = new ConjuntoVector();
        ConjuntoVector* c = new ConjuntoVector();
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

    void _interseccion()
    {
        ConjuntoVector* a = new ConjuntoVector();
        ConjuntoVector* b = new ConjuntoVector();
        ConjuntoVector* c = new ConjuntoVector();
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

    bool _equivalentes(ConjuntoVector* a, ConjuntoVector* b)
    {
        return a->cardinal() == b->cardinal();
    }

    void _equivalentes()
    {
        ConjuntoVector* a = new ConjuntoVector();
        ConjuntoVector* b = new ConjuntoVector();
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

} // namespace UConjuntoVector
