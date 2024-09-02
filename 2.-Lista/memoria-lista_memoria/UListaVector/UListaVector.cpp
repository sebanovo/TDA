//---------------------------------------------------------------------------
#pragma hdrstop
#include "UListavector.h"

#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UListaVector
{
    using std::cout;
    using std::endl;

    // constructor
    ListaVector::ListaVector()
    {
        longitud = 0;
    }

    // devuelve la direccion fin de la lista
    direccion ListaVector::fin()
    {
        if (vacia()) {
            throw std::runtime_error("La lista esta vacia\n");
        }
        return longitud;
        // if (!vacia()) {
        //     return longitud - 1;
        // }
        // else {
        //     cout << "Error: La lista esta vacia\n";
        // }
    }

    // devuelve la dirección del primer elemento de la lista
    direccion ListaVector::primero()
    {
        if (vacia()) {
            throw std::runtime_error("La lista esta vacia\n");
        }
        return 1;
        // if (!vacia()) {
        //     return 0;
        // }
        // else {
        //     cout << "Error: La lista esta vacia\n";
        // }
    }

    // retorna la dirección siguiente a esta
    direccion ListaVector::siguiente(direccion dir)
    {
        // if (vacia()) {
        //     cout << "Error: La lista esta vacia\n";
        // }
        // else {
        //     if (dir < longitud - 1) { //si esta en la ultima casilla
        //         return dir + 1;

        //     }
        //     else {
        //         cout << "Error de direccion sigiente " << dir
        //             << " no es parte del vector\n";
        //         return -1;
        //     }
        // }
        if (vacia())
            throw std::runtime_error("La lista esta vacia\n");
        if (dir == longitud)
            throw std::runtime_error(
                "No hay siguiente después de esta dirección (" +
                std::to_string(dir) + ")\n");
        if (dir < 1 || dir > longitud)
            throw std::runtime_error("La dirección (" + std::to_string(dir) +
                                     ") esta fuera de los limites\n");

        return dir + 1;
    }

    // retorna la dirección anterior a esta
    direccion ListaVector::anterior(direccion dir)
    {
        // if (vacia()) {
        //     cout << "Error: La lista esta vacia\n";
        // }
        // else {
        //     if (dir > 0 && dir <= longitud - 1) { //si esta en la ultima casilla
        //         return dir - 1;
        //     }
        //     else {
        //         cout << "Error de direccion anterior " << dir
        //             << " no es parte del vector";
        //         return -1;
        //     }
        // }

        if (vacia())
            throw std::runtime_error("La lista esta vacía\n");
        if (dir == 1)
            throw std::runtime_error(
                "No hay anterior antes de esta dirección (" +
                std::to_string(dir) + ")\n");
        if (dir < 1 || dir > longitud)
            throw std::runtime_error("La dirección (" + std::to_string(dir) +
                                     ") esta fuera de los limites\n");

        return dir - 1;
    }

    // esta vacia?
    bool ListaVector::vacia()
    {
        return longitud == 0;
    }

    // devuelve el valor del elemento
    int ListaVector::recupera(direccion dir)
    {
        // if (vacia()) {
        //     cout << "Error: La lista esta vacia\n";

        // }
        // else {
        //     if (dir >= 0 && dir <= longitud - 1) {
        //         return elementos[dir];
        //     }
        //     else {
        //         cout << "Error de direccion\n";
        //     }
        // }
        if (vacia())
            throw std::runtime_error("La lista esta vacía\n");
        if (dir < 1 || dir > longitud)
            throw std::runtime_error("La dirección (" + std::to_string(dir) +
                                     ") esta fuera de los limites\n");

        return elementos[dir];
    }

    // retorna la longitud de la lista
    int ListaVector::_longitud()
    {
        return longitud;
    }

    void ListaVector::inserta(direccion dir, int element)
    {
        // if (longitud == MAX) {
        //     cout << "Error: La lista esta llena\n";
        // }
        // if (vacia()) { //caso 0
        //     elementos[0] = element;
        //     longitud++;
        //     return; //added
        // }
        // if (dir >= 0 && dir <= longitud - 1) { //[55][1][2][3]
        //     for (int i = longitud; i > dir; i--) {
        //         elementos[i] = elementos[i - 1];
        //     }
        //     elementos[dir] = element;
        //     longitud++; //check! if it isn't at the beginning of all.
        // } //aumentar la cajita al vector para mover todo luego.
        // else
        // {
        //     cout << "Error de direccion\n";
        // }
        if (longitud == MAX) {
            std::runtime_error("La lista esta llena\n");
        }
        if (vacia()) {
            elementos[1] = element;
            longitud++;
            return;
        }
        if (dir < 1 || dir > longitud)
            throw std::runtime_error("La dirección (" + std::to_string(dir) +
                                     ") esta fuera de los limites\n");

        for (int i = longitud + 1; i > dir; i--) {
            elementos[i] = elementos[i - 1];
        }
        elementos[dir] = element;
        longitud++;
    }

    void ListaVector::inserta_primero(int element)
    {
        // if (longitud == MAX) {
        //     cout << "Error: La lista esta llena\n";
        //     return; //added
        // }
        // for (int i = longitud; i > 0; i--) {
        //     elementos[i] = elementos[i - 1];
        // }
        // elementos[0] = element;
        // longitud++; //check! if it isn't at the beginning.
        // //aumentar la cajita al vector para mover todo luego.
        if (longitud == MAX) {
            std::runtime_error("La lista esta llena\n");
        }

        for (int i = longitud + 1; i > 1; i--) {
            elementos[i] = elementos[i - 1];
        }

        elementos[1] = element;
        longitud++;
    }

    // inserta un elemento al final de la lista
    void ListaVector::inserta_ultimo(int element)
    {
        // if (longitud == MAX) {
        //     cout << "Error: La lista esta llena\n";
        //     return; //added
        // }
        // else {
        //     elementos[longitud] = element;
        //     longitud++; //at the beginning verificar si es 0 o 1???
        // }

        if (longitud == MAX) {
            std::runtime_error("La lista esta llena\n");
        }

        elementos[longitud + 1] = element;
        longitud++;
    }

    // elimina una dirección de la lista
    void ListaVector::suprime(direccion dir)
    {
        // if (longitud == 0) {
        //     cout << "Error: La lista esta vacia\n";
        //     return; //added
        // }
        // else {
        //     if (dir >= 0 && dir <= longitud - 1) {
        //         for (int i = dir; i < longitud - 1; i++) {
        //             elementos[i] = elementos[i + 1];
        //         }
        //         longitud--;
        //     }
        //     else {
        //         cout << "Error de direccion no se puede suprimir\n";
        //     }
        // }
        if (vacia())
            throw std::runtime_error("Lista vacia\n");
        if (dir < 1 || dir > longitud)
            throw std::runtime_error("La dirección (" + std::to_string(dir) +
                                     ") esta fuera de los limites\n");
        for (int i = dir; i < longitud; i++) {
            elementos[i] = elementos[i + 1];
        }
        longitud--;
    }

    // modifica el elemento de una dirección del vector
    void ListaVector::modifica(direccion dir, int element)
    {
        // if (longitud == 0) {
        //     cout << "Error: La lista esta vacia\n";
        //     return; //added
        // }
        // else {
        //     if (dir >= 0 && dir <= longitud - 1) {
        //         elementos[dir] = element;
        //     }
        //     else {
        //         cout << "Error de direccion no pertenece al vector\n";
        //     }
        // }
        if (vacia())
            throw std::runtime_error("Lista vacia\n");
        if (dir < 1 || dir > longitud)
            throw std::runtime_error("La dirección (" + std::to_string(dir) +
                                     ") esta fuera de los limites\n");
        elementos[dir] = element;
    }

    // muestra el vector
    void ListaVector::mostrar()
    {
        // string lista;
        // cout << '<';
        // for (int i = 0; i < longitud; i++) {
        //     int a = elementos[i];
        //     cout << a;
        //     if (i < longitud) {
        //         cout << ',';
        //     }
        // }
        // cout << '>' << endl;
        string lista;
        cout << '<';
        for (int i = 1; i <= longitud; i++) {
            int a = elementos[i];
            cout << a;
            if (i < longitud) {
                cout << ',';
            }
        }
        cout << '>' << endl;
    }

    // retorna la dirección de memoria del elemento
    direccion ListaVector::localiza(int element)
    {
        // for (int i = 0; i < longitud; i++)
        //     if (elementos[i] == element)
        //         return i;

        // return -1;

        for (int i = 1; i <= longitud; i++)
            if (elementos[i] == element)
                return i;

        return -1;
    }

    // elimina todas la ocurrencias de ese elemento
    void ListaVector::elimina_dato(int element)
    {
        // int i = 0;
        // while (i < longitud) {
        //     if (elementos[i] == element) {
        //         suprime(i);
        //     } else {
        //         i++;
        //     }
        // }
        int i = 1;
        while (i <= longitud) {
            if (elementos[i] == element) {
                suprime(i);
            } else {
                i++;
            }
        }
    }

    void ListaVector::anula()
    {
        longitud = 0;
    }

} // namespace UListaVector

