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

    void PilaCadena::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        int pos = datos.find_first_of(",");
        std::string sub = datos.substr(0, pos);
        e = atoi(sub.c_str());
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
        PilaCadena aux;
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

    void PilaCadena::graficar_pila(TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        std::string s = "";
        PilaCadena aux;
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

} // namespace UPilaCadena

