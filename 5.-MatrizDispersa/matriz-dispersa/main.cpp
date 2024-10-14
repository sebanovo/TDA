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
    Matriz = new UMatrizDispersaVector::MatrizDispersaVector;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject* Sender)
{
    Matriz->dimensionar(Edit1->Text.ToInt(), Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject* Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
{
    //
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject* Sender)
{
    //
}
//---------------------------------------------------------------------------

