//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaPuntero.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaPuntero
{
    PilaPuntero::PilaPuntero()
    {
        tope = nullptr;
    }

    bool PilaPuntero::vacia()
    {
        return tope == nullptr;
    }

    void PilaPuntero::meter(int e)
    {
        Nodo* x = new Nodo;
        if (x == nullptr)
            throw new Exception("No hay espacio en la memoria");
        x->elemento = e;
        x->sig = tope;
        tope = x;
    }

    void PilaPuntero::sacar(int* e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        // if (e == nullptr) throw std::invalid_argument("Puntero nulo pasado a sacar");
        *e = tope->elemento;
        Nodo* aux = tope;
        tope = tope->sig;
        delete aux;
    }

    int PilaPuntero::cima()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cima");
        return tope->elemento;
    }

    std::string PilaPuntero::mostrar()
    {
        std::string s = "";
        PilaPuntero* aux = new PilaPuntero;
        while (!vacia()) {
            int e;
            sacar(&e);
            s += "| " + std::to_string(e) + " |\n";
            aux->meter(e);
        }
        while (!aux->vacia()) {
            int e;
            aux->sacar(&e);
            meter(e);
        }
        return s;
    }

    PilaPuntero::~PilaPuntero()
    {
        delete tope;
    }
} // namespace UPilaPuntero
