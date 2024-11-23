//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaVector.h"
#include <math.h>
#include <stdexcept>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaVector
{
    PilaVector ::PilaVector()
    {
        tope = 0;
        elementos = new int[MAX];
    }

    bool PilaVector ::vacia()
    {
        return tope == 0;
    }

    void PilaVector ::meter(int e)
    {
        if (tope >= MAX)
            return;
        tope++;
        elementos[tope] = e;
    }

    void PilaVector ::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = elementos[tope];
        tope--;
    }

    int PilaVector ::cima()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cima");
        return elementos[tope];
    }

    std::string PilaVector ::mostrar()
    {
        std::string s = "";
        PilaVector aux;
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

    PilaVector ::~PilaVector()
    {
        delete[] elementos;
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

    void PilaVector::graficar_pila(TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        std::string s = "";
        PilaVector aux;
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
} // namespace UPilaVector

