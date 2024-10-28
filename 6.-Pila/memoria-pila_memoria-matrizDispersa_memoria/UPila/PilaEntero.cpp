//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaEntero.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaEntero
{
    PilaEntero::PilaEntero()
    {
        datos = 0;
    }

    bool PilaEntero::vacia()
    {
        return datos == 0;
    }

    void PilaEntero::meter(int e)
    {
        if (e <= 0 || e >= 9)
            throw new Exception("datos fuera de rango");
        datos = datos * 10 + e;
    }

    void PilaEntero::sacar(int* e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        *e = datos % 10;
        datos = datos / 10;
    }

    int PilaEntero::cima()
    {
        return datos % 10;
    }

    std::string PilaEntero::mostrar()
    {
        std::string s = "";
        PilaEntero* aux = new PilaEntero;
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
} // namespace UPilaEntero
