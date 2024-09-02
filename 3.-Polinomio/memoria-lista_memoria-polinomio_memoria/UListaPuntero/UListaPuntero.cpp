//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UListaPuntero
{
    // inicializa las variables
    using std::to_string;
    ListaPuntero::ListaPuntero()
    {
        longitud = 0;
        PtrElementos = nullptr;
    }

    // retorna la dirección de memoria final
    direccion ListaPuntero::fin()
    {
        Nodo* x = PtrElementos;
        Nodo* PtrFin;
        while (x != nullptr) {
            PtrFin = x;
            x = x->sig;
        }
        return PtrFin;
    }

    // retorna la dirección de memoria de la cabeza de la lista
    direccion ListaPuntero::primero()
    {
        return PtrElementos;
    }

    // retorna la dirección de memoria siguiente a este
    direccion ListaPuntero::siguiente(direccion dir)
    {
        if (vacia())
            throw new Exception("La lista esta vacía\n");
        if (!es_direccion_valida(dir))
            throw new Exception("No existe esta dirección en la Lista");
        if (dir == fin())
            throw new Exception("No existe la dirección siguiente a esta\n");

        return dir->sig;
    }

    // retorna la dirección de memoria anterior a esta
    direccion ListaPuntero::anterior(direccion dir)
    {
        if (vacia())
            throw new Exception("La lista esta vacía\n");
        if (!es_direccion_valida(dir))
            throw new Exception("No existe esta dirección en la Lista");
        if (dir == primero())
            throw new Exception("No existe la dirección anterior a esta\n");

        Nodo* x = PtrElementos;
        Nodo* ant;
        while (x != nullptr) {
            if (x == dir) {
                return ant;
            }
            ant = x;
            x = x->sig;
        }
        return nullptr;
    }

    // esta vacia?
    bool ListaPuntero::vacia()
    {
        return longitud == 0 || PtrElementos == nullptr;
    }

    // recupera el elemento de la dirección de la lista
    int ListaPuntero::recupera(direccion dir)
    {
        if (vacia())
            throw new Exception("La lista esta vacía\n");
        if (!es_direccion_valida(dir))
            throw new Exception("No existe esta dirección en la Lista");
        return dir->elemento;
    }

    // retorna la lontitud
    int ListaPuntero::_longitud()
    {
        return longitud;
    }

    // insertar un elemento en una dirección de memoria
    void ListaPuntero::inserta(direccion dir, int element)
    {
        Nodo* x = new Nodo;
        x->elemento = element;
        x->sig = nullptr;

        if (vacia()) {
            PtrElementos = x;
        } else if (!es_direccion_valida(dir))
            throw new Exception("La dirección no i valida");
        else if (dir == primero()) { // caso especial
            x->sig = PtrElementos;
            PtrElementos = x;
        } else {
            Nodo* ant = anterior(dir);
            x->sig = ant->sig;
            ant->sig = x;
        }
        longitud++;
    }

    // insertar un elemento al principio de la lista
    void ListaPuntero::inserta_primero(int element)
    {
        Nodo* x = new Nodo;
        x->elemento = element;
        x->sig = PtrElementos;
        PtrElementos = x;
        longitud++;
    }

    // insertar un elemento al final de la lista
    void ListaPuntero::inserta_ultimo(int element)
    {
        Nodo* x = new Nodo;
        x->elemento = element;
        x->sig = nullptr;

        if (vacia()) {
            PtrElementos = x;
            longitud++;
            return;
        }

        fin()->sig = x;
        longitud++;
    }

    // elimina un elemento
    void ListaPuntero::suprime(direccion dir)
    {
        if (vacia())
            throw new Exception("La lista esta vacía");
        if (!es_direccion_valida(dir))
            throw new Exception("La dirección no es valida");
        if (PtrElementos == dir) {
            Nodo* temp = PtrElementos;
            PtrElementos = PtrElementos->sig;
            delete temp;
            return;
        } else {
            Nodo* ant = anterior(dir);
            ant->sig = dir->sig;
            delete dir;
        }
        longitud--;
    }

    // modifica el elemento de una direccion de la lista
    void ListaPuntero::modifica(direccion dir, int element)
    {
        if (vacia())
            throw new Exception("La lista esta vacía");
        if (!es_direccion_valida(dir))
            throw new Exception("La dirección no es valida");
        dir->elemento = element;
    }

    // muestra la lista
    string ListaPuntero::mostrar()
    {
        string s = "[";
        direccion x = PtrElementos;
        while (x != nullptr) {
            int numero = x->elemento;
            s += to_string(numero);
            x = x->sig;
            if (x != nullptr)
                s += ",";
        }
        return s + "]";
    }

    ListaPuntero::~ListaPuntero()
    {
        while (!vacia())
            suprime(primero());
    }

    // retorna la direccion de memoria de la primera ocurrencia del elemento
    direccion ListaPuntero::localiza(int element)
    {
        Nodo* x = PtrElementos;
        while (x != nullptr) {
            if (x->elemento == element)
                return x;
            x = x->sig;
        }
        return nullptr;
    }

    // elimina todas las ocurrencias del elemento ocurrente
    void ListaPuntero::elimina_dato(int element)
    {
        Nodo* x = PtrElementos;
        while (x != nullptr) {
            if (x->elemento == element) {
                Nodo* elim = x;
                x = x->sig;
                suprime(elim);
            } else {
                x = x->sig;
            }
        }
    }

    // elimina todos los nodos y elementos de la lista
    void ListaPuntero::anula()
    {
        while (!vacia())
            suprime(primero());
    }

    // verifica que la dirección exista
    bool ListaPuntero::es_direccion_valida(direccion dir)
    {
        Nodo* x = PtrElementos;
        while (x != nullptr) {
            if (x == dir)
                return true;
            x = x->sig;
        }
        return false;
    }

    // ejercicios
    void ListaPuntero::bubble_sort()
    {
        Nodo* x = PtrElementos;
        Nodo* y;

        while (x != nullptr) {
            y = x->sig;
            while (y != nullptr) {
                if (x->elemento > y->elemento) {
                    int temp = x->elemento;
                    x->elemento = y->elemento;
                    y->elemento = temp;
                }
                y = y->sig;
            }
            x = x->sig;
        }
    }
} // namespace UListaPuntero

