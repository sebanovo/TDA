//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "memoria-cola_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13* Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm13::~TForm13()
{
    delete M, cola;
}
//---------------------------------------------------------------------------
void __fastcall TForm13::Button1Click(TObject* Sender)
{
    M = new UCSMemoria::CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm13::Button2Click(TObject* Sender)
{
    AnsiString ids = Edit1->Text;
    M->new_espacio(ids.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button3Click(TObject* Sender)
{
    cola = new UColaSM::ColaSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button4Click(TObject* Sender)
{
    cola->poner(Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button5Click(TObject* Sender)
{
    M->dibujar_memoria(
        Form13, 1000, 10, Edit3->Text.ToInt(), Edit4->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm13::Button6Click(TObject* Sender)
{
    int posX = 400;
    int posY = 300;
    cola->graficar_cola(Form13, posX, posY);
}

//---------------------------------------------------------------------------
