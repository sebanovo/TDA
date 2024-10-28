//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaCadena.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaCadena
{
    PilaCadena::PilaCadena()
    {
        datos = "";
    }

    bool PilaCadena::vacia()
    {
        return datos == "";
    }

    void PilaCadena::meter(int e)
    {
        datos = std::to_string(e) + "," + datos;
    }

    void PilaCadena::sacar(int* e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        int pos = datos.find_first_of(",");
        std::string sub = datos.substr(0, pos);
        *e = atoi(sub.c_str());
        datos.erase(0, pos + 1);
    }

    int PilaCadena::cima()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cima");
        int pos = datos.find_first_of(",");
        std::string sub = datos.substr(0, pos);
        return atoi(sub.c_str());
    }

    std::string PilaCadena::mostrar()
    {
        std::string s = "";
        PilaCadena* aux = new PilaCadena;
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

} // namespace UPilaCadena

