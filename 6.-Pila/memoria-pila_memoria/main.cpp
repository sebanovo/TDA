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
    delete M, conjuntoA, pila;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject* Sender)
{
    M = new UCSMemoria::CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject* Sender)
{
    AnsiString ids = Edit1->Text;
    M->new_espacio(ids.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject* Sender)
{
    pila = new UPilaSM::PilaSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
{
    pila->meter(Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    conjuntoA = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject* Sender)
{
    conjuntoA->inserta(Edit5->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject* Sender)
{
    int radio = 200;
    Canvas->Pen->Color = Form1->Color;
    Canvas->Brush->Color = Form1->Color;
    Canvas->Rectangle(0, 0, Form1->Width, Form1->Height);
    conjuntoA->dibujar_conjunto(Form1, 400, 200);
    conjuntoA->graficar_conjunto(Form1, 500, 500, radio, "A");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject* Sender)
{
    M->dibujar_memoria(
        Form1, 1000, 10, Edit3->Text.ToInt(), Edit4->Text.ToInt());
}
//---------------------------------------------------------------------------

