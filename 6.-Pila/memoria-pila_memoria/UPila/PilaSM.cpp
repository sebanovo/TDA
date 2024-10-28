//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaSM.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaSM
{
    using UCSMemoria::NULO;

    PilaSM::PilaSM()
    {
        tope = NULO;
        mem = new UCSMemoria::CSMemoria;
    }

    PilaSM::PilaSM(UCSMemoria::CSMemoria* m)
    {
        mem = m;
        tope = NULO;
    }

    bool PilaSM::vacia()
    {
        return tope == NULO;
    }

    void PilaSM::meter(int e)
    {
        int x = mem->new_espacio(_elemento_sig);
        if (x == NULO)
            throw new Exception("No hay espacio en la memoria");
        mem->poner_dato(x, _elemento, e);
        mem->poner_dato(x, _sig, tope);
        tope = x;
    }

    void PilaSM::sacar(int* e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        // if (e == NULO) throw std::invalid_argument("Puntero nulo pasado a sacar");
        *e = mem->obtener_dato(tope, _elemento);
        int aux = tope;
        tope = mem->obtener_dato(tope, _sig);
        mem->delete_espacio(aux);
    }

    int PilaSM::cima()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cima");
        return mem->obtener_dato(tope, _elemento);
    }

    std::string PilaSM::mostrar()
    {
        std::string s = "";
        PilaSM* aux = new PilaSM;
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

    PilaSM::~PilaSM()
    {
        delete mem;
    }
} // namespace UPilaSM
