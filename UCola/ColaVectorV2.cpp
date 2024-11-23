//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVectorV2.h"
#include <math.h>
#include <stdexcept>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaVectorV2
{
    ColaVectorV2::ColaVectorV2()
    {
        fin = 0;
        ini = 1;
        v = new int[MAX];
    }

    bool ColaVectorV2 ::vacia()
    {
        return ini > fin;
    }

    void ColaVectorV2::poner(int e)
    {
        if (fin >= MAX)
            throw new Exception("No hay espacio en la cola");
        v[++fin] = e;
    }

    void ColaVectorV2 ::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = v[ini];
        for (int i = ini; i < fin; i++)
            v[i] = v[i + 1];
        fin--;
    }

    int ColaVectorV2 ::primero()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return v[ini];
    }

    std::string ColaVectorV2::mostrar()
    {
        std::string s = "<<";
        ColaVectorV2 aux;
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

    ColaVectorV2 ::~ColaVectorV2()
    {
        delete[] v;
    }

    int ColaVectorV2::ultimo()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return v[fin];
    }

    void ColaVectorV2::poner_frente(int e)
    {
        if (fin >= MAX)
            throw new Exception("No hay espacio en la cola");
        fin++;
        for (int i = fin; i > ini; i--) {
            v[i] = v[i - 1];
        }
        v[ini] = e;
    }

    void ColaVectorV2::sacar_final(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = v[fin];
        fin--;
    }

    void ColaVectorV2::concatenar(
        ColaVectorV2* c1, ColaVectorV2* c2, ColaVectorV2* c3)
    {
        ColaVectorV2 aux;
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

    void ColaVectorV2::graficar_cola(TForm* Form, int posX, int posY)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(Canvas->ClipRect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }
} // namespace UColaVectorV2

