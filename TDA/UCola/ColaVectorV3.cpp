//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVectorV3.h"
#include <math.h>
#include <stdexcept>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaVectorV3
{
    ColaVectorV3::ColaVectorV3()
    {
        fin = 0;
        ini = 1;
        v = new int[MAX];
    }

    bool ColaVectorV3 ::vacia()
    {
        return siguiente(fin) == ini;
    }

    void ColaVectorV3::poner(int e)
    {
        if (siguiente(siguiente(fin)) == ini)
            throw new Exception("No hay espacio en la cola");
        fin = siguiente(fin);
        v[fin - 1] = e;
    }

    void ColaVectorV3 ::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = v[ini - 1];
        ini = siguiente(ini);
    }

    int ColaVectorV3 ::primero()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return v[ini - 1];
    }

    std::string ColaVectorV3::mostrar()
    {
        std::string s = "<<";
        ColaVectorV3 aux;
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

    ColaVectorV3 ::~ColaVectorV3()
    {
        delete[] v;
    }

    int ColaVectorV3::siguiente(int dir)
    {
        return dir == MAX ? 1 : dir + 1;
    }

    int ColaVectorV3::anterior(int dir)
    {
        return dir == 1 ? MAX : dir - 1;
    }

    int ColaVectorV3::ultimo()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return v[fin - 1];
    }

    void ColaVectorV3::poner_frente(int e)
    {
        if (siguiente(siguiente(fin)) == ini)
            throw new Exception("No hay espacio en la cola");
        ini = anterior(ini);
        v[ini - 1] = e;
    }

    void ColaVectorV3::sacar_final(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = v[fin - 1];
        fin = anterior(fin);
    }

    void ColaVectorV3::concatenar(
        ColaVectorV3* c1, ColaVectorV3* c2, ColaVectorV3* c3)
    {
        ColaVectorV3 aux;
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

    void ColaVectorV3::graficar_cola(TForm* Form, int posX, int posY)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(Canvas->ClipRect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }
} // namespace UColaVectorV3

