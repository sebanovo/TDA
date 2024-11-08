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
    delete M, cola;
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
    cola = new UColaPrioridad::ColaPrioridad(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
{
    cola->poner(Edit2->Text.ToInt(), Edit3->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject* Sender)
{
    cola->asignar_frecuencia_prioridad(
        Edit4->Text.ToInt(), Edit5->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    M->dibujar_memoria(
        Form1, 1000, 10, Edit6->Text.ToInt(), Edit7->Text.ToInt());
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject* Sender)
{
    int e;
    cola->sacar(e);
    ShowMessage(IntToStr(e));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject* Sender)
{
    int posX = 400;
    int posY = 300;
    cola->graficar_cola_prioridad(Form1, posX, posY);
}
//---------------------------------------------------------------------------

