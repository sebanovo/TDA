//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lista.h"
#include "ULista/ListaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2* Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject* Sender)
{
    lista = new UListaPuntero::ListaPuntero;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject* Sender)
{
    lista->inserta_primero(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------
void _fastcall TForm2::Button3Click(TObject* Sender)
{
    lista->inserta_ultimo(Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject* Sender)
{
    int posX = 300;
    int posY = 300;
    lista->dibujar_lista(Form2, posX, posY);
}
//---------------------------------------------------------------------------

