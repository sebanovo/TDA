//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14* Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm14::~TForm14()
{
    delete cola;
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button1Click(TObject* Sender)
{
    cola = new UColaVectorV3::ColaVectorV3;
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button2Click(TObject* Sender)
{
    cola->poner(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button3Click(TObject* Sender)
{
    int x;
    cola->sacar(x);
    ShowMessage("Sacado " + String(x));
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button4Click(TObject* Sender)
{
    int posX = 300;
    int posY = 300;
    cola->graficar_cola(Form14, posX, posY);
}
//---------------------------------------------------------------------------

