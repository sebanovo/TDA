// ---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <stdexcept>
#include "ColaPuntero.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaPuntero
{
    ColaPuntero::ColaPuntero()
    {
        ini = fin = nullptr;
    }

    bool ColaPuntero::vacia()
    {
        return ini == nullptr;
    }

    void ColaPuntero::poner(int e)
    {
        Nodo* aux = new Nodo;
        if (aux == nullptr)
            throw new Exception("No hay espacio en la memoria");
        aux->elemento = e;
        aux->sig = nullptr;
        if (vacia()) {
            ini = fin = aux;
        } else {
            fin->sig = aux;
            fin = aux;
        }
    }

    void ColaPuntero::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = ini->elemento;
        Nodo* x = ini;
        if (ini == fin)
            ini = fin = nullptr;
        else
            ini = ini->sig;
        delete x;
    }

    int ColaPuntero::primero()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return ini->elemento;
    }

    std::string ColaPuntero::mostrar()
    {
        std::string s = "<<";
        ColaPuntero aux;
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

    ColaPuntero::~ColaPuntero()
    {
        Nodo* x = ini;
        while (x != nullptr) {
            Nodo* aux = x;
            x = x->sig;
            delete aux;
        }
    }

    int ColaPuntero::ultimo()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return fin->elemento;
    }

    void ColaPuntero::poner_frente(int e)
    {
        Nodo* aux = new Nodo;
        if (aux == nullptr)
            throw new Exception("No hay espacio en la memoria");
        aux->elemento = e;
        aux->sig = nullptr;
        if (vacia()) {
            ini = fin = aux;
        } else {
            aux->sig = ini;
            ini = aux;
        }
    }

    void ColaPuntero::sacar_final(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        Nodo* x = ini;
        Nodo* ant = x;
        while (x != fin) {
            ant = x;
            x = x->sig;
        }
        if (x == ini) {
            delete fin;
            ini = fin = nullptr;
            return;
        }
        e = fin->elemento;
        delete fin;
        fin = ant;
    }

    void ColaPuntero::concatenar(
        ColaPuntero* c1, ColaPuntero* c2, ColaPuntero* c3)
    {
        ColaPuntero aux;
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

    void ColaPuntero::graficar_cola(TForm* Form, int posX, int posY)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(Canvas->ClipRect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }
} // namespace UColaPuntero

