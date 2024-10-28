
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaLista.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaLista
{
    PilaLista::PilaLista()
    {
        // mem = new UCSMemoria::CSMemoria;
        // ls = new UListaSM::ListaSM(mem);
        ls = new UListaVector::ListaVector;
    }

    PilaLista::PilaLista(UCSMemoria::CSMemoria* m)
    {
        // mem = m;
        // ls = new UListaSM::ListaSM(mem);
        ls = new UListaVector::ListaVector;
    }

    bool PilaLista::vacia()
    {
        return ls->_longitud() == 0;
    }

    void PilaLista::meter(int e)
    {
        ls->inserta(ls->primero(), e);
    }

    void PilaLista::sacar(int* e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        *e = ls->recupera(ls->primero());
        ls->suprime(ls->primero());
    }

    int PilaLista::cima()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cima");
        return ls->recupera(ls->primero());
    }

    std::string PilaLista::mostrar()
    {
        std::string s = "";
        PilaLista* aux = new PilaLista();
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

    PilaLista::~PilaLista()
    {
        // delete ls, mem;
        delete ls;
    }
} // namespace UPilaLista
