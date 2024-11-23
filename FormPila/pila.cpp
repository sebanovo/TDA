//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12* Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm12::~TForm12()
{
    delete pila;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button1Click(TObject* Sender)
{
    pila = new UPilaVector::PilaVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button2Click(TObject* Sender)
{
    pila->meter(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button3Click(TObject* Sender)
{
    int x;
    pila->sacar(x);
    ShowMessage("Sacado " + String(x));
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button4Click(TObject* Sender)
{
    int posX = 300;
    int posY = 300;
    pila->graficar_pila(Form12, posX, posY);
}
//---------------------------------------------------------------------------

