//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "memoria.h"
#include "UCSMemoria/CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
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
    AnsiString dir = Edit2->Text;
    M->delete_espacio(dir.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject* Sender)
{
    AnsiString a = Edit3->Text;
    AnsiString b = Edit4->Text;
    int posx = 800, posy = 20;
    M->dibujar_memoria(Form1, posx, posy, a.ToInt(), b.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject* Sender)
{
    AnsiString dir = Edit5->Text;
    AnsiString id = Edit6->Text;
    AnsiString valor = Edit7->Text;

    M->poner_dato(dir.ToInt(), id.c_str(), valor.ToInt());
}
//---------------------------------------------------------------------------

