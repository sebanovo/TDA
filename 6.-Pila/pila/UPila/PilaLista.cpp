
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

    void PilaLista::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = ls->recupera(ls->primero());
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
        PilaLista aux;
        while (!vacia()) {
            int e;
            sacar(e);
            s += "| " + std::to_string(e) + " |\n";
            aux.meter(e);
        }
        while (!aux.vacia()) {
            int e;
            aux.sacar(e);
            meter(e);
        }
        return s;
    }

    PilaLista::~PilaLista()
    {
        // delete ls, mem;
        delete ls;
    }

    void dibujar_celda(TForm* Form, TColor brushColor,
        bool withBorder, int posX, int posY, String cad)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Font->Size = 20;
        Canvas->Font->Name = "Microsoft YaHei UI";

        int TamanoCeldaX = TamanoCelda;
        int TamanoCeldaY = TamanoCelda;
        TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);

        int anchoTexto = Canvas->TextWidth(cad);
        int posXCentro = posX + (TamanoCeldaX - anchoTexto) / 2;
        int posYCentro = posY + (TamanoCeldaY - Canvas->TextHeight(cad)) / 2;

        Canvas->Brush->Color = brushColor;
        Canvas->Pen->Color = withBorder ? clBlack : brushColor;
        Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Pen->Color = clBlack;
        Canvas->TextOutW(posXCentro, posYCentro, cad);
    }

    void PilaLista::graficar_pila(TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        std::string s = "";
        PilaLista aux;
        while (!vacia()) {
            int e;
            sacar(e);
            dibujar_celda(Form, clBtnFace, true, posX, posY, String(e));
            posY += TamanoCelda;
            aux.meter(e);
        }
        while (!aux.vacia()) {
            int e;
            aux.sacar(e);
            meter(e);
        }
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->TextOutW(posX, posY, "Cima " + String(cima()));
    }
} // namespace UPilaLista

