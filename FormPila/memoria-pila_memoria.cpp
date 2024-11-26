//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "memoria-pila_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10* Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm10::~TForm10()
{
    delete M, conjuntoA, pila;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button1Click(TObject* Sender)
{
    M = new UCSMemoria::CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button2Click(TObject* Sender)
{
    AnsiString ids = Edit1->Text;
    M->new_espacio(ids.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button3Click(TObject* Sender)
{
    pila = new UPilaSM::PilaSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button4Click(TObject* Sender)
{
    pila->meter(Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button6Click(TObject* Sender)
{
    conjuntoA = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button7Click(TObject* Sender)
{
    conjuntoA->inserta(Edit5->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button8Click(TObject* Sender)
{
    int radio = 200;
    Canvas->Pen->Color = Form10->Color;
    Canvas->Brush->Color = Form10->Color;
    Canvas->Rectangle(0, 0, Form10->Width, Form10->Height);
    conjuntoA->dibujar_conjunto(Form10, 400, 200);
    conjuntoA->graficar_conjunto(Form10, 500, 500, radio, "A");
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button5Click(TObject* Sender)
{
    M->dibujar_memoria(
        Form10, 1000, 10, Edit3->Text.ToInt(), Edit4->Text.ToInt());
}
//---------------------------------------------------------------------------
