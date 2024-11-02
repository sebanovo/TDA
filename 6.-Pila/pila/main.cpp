//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm1::~TForm1()
{
    delete pila;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject* Sender)
{
    pila = new UPilaVector::PilaVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject* Sender)
{
    pila->meter(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject* Sender)
{
    int x;
    pila->sacar(x);
    ShowMessage("Sacado " + String(x));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
{
    int posX = 300;
    int posY = 300;
    pila->graficar_pila(Form1, posX, posY);
}
//---------------------------------------------------------------------------

