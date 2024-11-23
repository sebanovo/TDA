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

    void PilaEntero::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = datos % 10;
        datos = datos / 10;
    }

    int PilaEntero::cima()
    {
        return datos % 10;
    }

    std::string PilaEntero::mostrar()
    {
        std::string s = "";
        PilaEntero aux;
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

    void PilaEntero::graficar_pila(TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        std::string s = "";
        PilaEntero aux;
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
} // namespace UPilaEntero

