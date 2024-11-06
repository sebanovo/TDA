//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaPuntero.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaPuntero
{
    PilaPuntero::PilaPuntero()
    {
        tope = nullptr;
    }

    bool PilaPuntero::vacia()
    {
        return tope == nullptr;
    }

    void PilaPuntero::meter(int e)
    {
        Nodo* x = new Nodo;
        if (x == nullptr)
            throw new Exception("No hay espacio en la memoria");
        x->elemento = e;
        x->sig = tope;
        tope = x;
    }

    void PilaPuntero::sacar(int &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        // if (e == nullptr) throw std::invalid_argument("Puntero nulo pasado a sacar");
        e = tope->elemento;
        Nodo* aux = tope;
        tope = tope->sig;
        delete aux;
    }

    int PilaPuntero::cima()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cima");
        return tope->elemento;
    }

    std::string PilaPuntero::mostrar()
    {
        std::string s = "";
        PilaPuntero aux;
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

    PilaPuntero::~PilaPuntero()
    {
        Nodo* x = tope;
        while (x != nullptr)
        {
            Nodo* aux = tope;
            tope = tope->sig;
            delete aux;
        }
    }

    void PilaPuntero::dibujar_celda(TForm* Form, TColor brushColor,
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

    void PilaPuntero::graficar_pila(TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        std::string s = "";
        PilaPuntero aux;
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
} // namespace UPilaPuntero

