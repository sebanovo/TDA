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

    void PilaSM::dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
        int posX, int posY, String cad)
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
    void PilaSM::graficar_pila(TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        //        Form->Canvas->Pen->Color = clBlack;
        int x = tope;
        while (x != NULO) {
            dibujar_celda(Form, clBtnFace, true, posX, posY,
                String(mem->obtener_dato(x, _elemento)));
            posY += TamanoCelda;
            x = mem->obtener_dato(x, _sig);
        }

        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->TextOutW(posX, posY, "Cima " + String(cima()));
    }
} // namespace UPilaSM

