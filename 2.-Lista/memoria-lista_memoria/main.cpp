
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
    int posx = 800, posy = 10;
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

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    listaSM = new UListaSM::ListaSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject* Sender)
{
    listaSM->inserta_primero(Edit8->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject* Sender)
{
    listaSM->inserta_ultimo(Edit9->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject* Sender)
{
    int posX = 100;
    int posY = 750;
    listaSM->dibujar_lista(Form1, posX, posY);
}
//---------------------------------------------------------------------------

