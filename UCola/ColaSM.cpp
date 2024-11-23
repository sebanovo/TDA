// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaSM.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaSM
{
    using UCSMemoria::NULO;
    ColaSM::ColaSM()
    {
        mem = new UCSMemoria::CSMemoria;
        ini = fin = NULO;
    }

    ColaSM::ColaSM(UCSMemoria::CSMemoria* m)
    {
        mem = m;
        ini = fin = NULO;
    }

    bool ColaSM::vacia()
    {
        return ini == NULO;
    }

    void ColaSM::poner(int e)
    {
        int aux = mem->new_espacio(_elemento_sig);
        if (aux == NULO)
            throw new Exception("No hay espacio en la memoria");
        mem->poner_dato(aux, _elemento, e);
        mem->poner_dato(aux, _sig, NULO);
        if (vacia()) {
            ini = fin = aux;
        } else {
            mem->poner_dato(fin, _sig, aux);
            fin = aux;
        }
    }

    void ColaSM::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = mem->obtener_dato(ini, _elemento);
        int x = ini;
        if (ini == fin)
            ini = fin = NULO;
        else
            ini = mem->obtener_dato(ini, _sig);
        mem->delete_espacio(x);
    }

    int ColaSM::primero()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return mem->obtener_dato(ini, _elemento);
    }

    std::string ColaSM::mostrar()
    {
        std::string s = "<<";
        ColaSM aux;
        while (!vacia()) {
            int e;
            sacar(e);
            aux.poner(e);
            s += std::to_string(e);
            if (!vacia())
                s += ",";
        }
        while (!aux.vacia()) {
            int e;
            aux.sacar(e);
            poner(e);
        }
        return s + "<<";
    }

    ColaSM::~ColaSM()
    {
        delete mem;
    }

    int ColaSM::ultimo()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return mem->obtener_dato(fin, _elemento);
    }

    void ColaSM::poner_frente(int e)
    {
        int aux = mem->new_espacio(_elemento_sig);
        if (aux == NULO)
            throw new Exception("No hay espacio en la memoria");
        mem->poner_dato(aux, _elemento, e);
        mem->poner_dato(aux, _sig, NULO);
        if (vacia()) {
            ini = fin = aux;
        } else {
            mem->poner_dato(aux, _sig, ini);
            ini = aux;
        }
    }

    void ColaSM::sacar_final(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        int x = ini;
        int ant = x;
        while (x != fin) {
            ant = x;
            x = mem->obtener_dato(x, _sig);
        }
        if (x == ini) {
            mem->delete_espacio(fin);
            ini = fin = NULO;
            return;
        }
        e = mem->obtener_dato(fin, _elemento);
        mem->delete_espacio(fin);
        fin = ant;
    }

    void ColaSM::concatenar(ColaSM* c1, ColaSM* c2, ColaSM* c3)
    {
        ColaSM aux;
        while (!c1->vacia()) {
            int e;
            c1->sacar(e);
            aux.poner(e);
        }
        while (!aux.vacia()) {
            int e;
            aux.sacar(e);
            c3->poner(e);
            c1->poner(e);
        }
        while (!c2->vacia()) {
            int e;
            c2->sacar(e);
            aux.poner(e);
        }
        while (!aux.vacia()) {
            int e;
            aux.sacar(e);
            c3->poner(e);
            c2->poner(e);
        }
    }

    void ColaSM::graficar_cola(TForm* Form, int posX, int posY)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(Canvas->ClipRect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }
} // namespace UColaSM

