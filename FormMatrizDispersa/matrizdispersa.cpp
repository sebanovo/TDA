//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "matrizdispersa.h"
#include "ULista/ListaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9* Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button1Click(TObject* Sender)
{
    Matriz = new UMatrizDispersaVector::MatrizDispersaVector;
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button2Click(TObject* Sender)
{
    Matriz->dimensionar(Edit1->Text.ToInt(), Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button3Click(TObject* Sender)
{
    Matriz->definir_valor_repetido(Edit3->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button4Click(TObject* Sender)
{
    Matriz->poner(
        Edit4->Text.ToInt(), Edit5->Text.ToInt(), Edit6->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button5Click(TObject* Sender)
{
    int posX = 600;
    int posY = 100;
    Matriz->graficar_matriz_dispersa(Form9, posX, posY);
}
//---------------------------------------------------------------------------

