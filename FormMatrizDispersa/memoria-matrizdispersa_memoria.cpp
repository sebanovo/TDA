
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "memoria-matrizdispersa_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8* Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject* Sender)
{
    M = new UCSMemoria::CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject* Sender)
{
    AnsiString ids = Edit1->Text;
    M->new_espacio(ids.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject* Sender)
{
    AnsiString dir = Edit2->Text;
    M->delete_espacio(dir.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button4Click(TObject* Sender)
{
    AnsiString a = Edit3->Text;
    AnsiString b = Edit4->Text;
    int posx = 1500, posy = 10;
    M->dibujar_memoria(Form8, posx, posy, a.ToInt(), b.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button5Click(TObject* Sender)
{
    AnsiString dir = Edit5->Text;
    AnsiString id = Edit6->Text;
    AnsiString valor = Edit7->Text;

    M->poner_dato(dir.ToInt(), id.c_str(), valor.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button6Click(TObject* Sender)
{
    Matriz = new UMatrizDispersaSM::MatrizDispersaSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button7Click(TObject* Sender)
{
    Matriz->dimensionar(Edit8->Text.ToInt(), Edit9->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button8Click(TObject* Sender)
{
    Matriz->definir_valor_repetido(Edit10->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button9Click(TObject* Sender)
{
    Matriz->poner(
        Edit11->Text.ToInt(), Edit12->Text.ToInt(), Edit13->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button10Click(TObject* Sender)
{
    int posX = 600;
    int posY = 100;
    Matriz->graficar_matriz_dispersa(Form8, posX, posY);
}
//---------------------------------------------------------------------------

