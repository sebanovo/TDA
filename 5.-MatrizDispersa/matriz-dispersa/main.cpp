//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "ULista/ListaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject* Sender)
{
    lista = new UListaPuntero::ListaPuntero;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject* Sender)
{
    lista->inserta_primero(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------
void _fastcall TForm1::Button3Click(TObject* Sender)
{
    lista->inserta_ultimo(Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject* Sender)
{
    int posX = 300;
    int posY = 300;
    lista->dibujar_lista(Form1, posX, posY);
}
//---------------------------------------------------------------------------

