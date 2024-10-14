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
void _fastcall TForm1::Button3Click(TObject* Sender)
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

void __fastcall TForm1::Button10Click(TObject* Sender)
{
    pol1 = new UPolinomioSM::PolinomioSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject* Sender)
{
    int coef = Edit10->Text.ToInt();
    int exp = Edit11->Text.ToInt();

    pol1->poner_termino(coef, exp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject* Sender)
{
    int posX = 300;
    int posY = 900;
    double a = Edit8->Text.ToDouble();
    double b = Edit9->Text.ToDouble();

    Canvas->FillRect(Canvas->ClipRect);

    UPolinomioSM::graficar_interseccion(Image1, pol1, pol2, a, b);
    pol1->dibujar_polinomio(Form1, 700, 800);
    pol2->dibujar_polinomio(Form1, 700, 900);
    // polinomioLista->graficar(Form1, 600, 10, 700, 700);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject* Sender)
{
    int a = Edit8->Text.ToInt();
    int b = Edit9->Text.ToInt();
    std::string re = UPolinomioSM::intersectar(pol1, pol2, a, b);
    ShowMessage(re.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    pol2 = new UPolinomioSM::PolinomioSM(M);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject* Sender)
{
    int coef = Edit12->Text.ToInt();
    int exp = Edit13->Text.ToInt();

    pol2->poner_termino(coef, exp);
}
//---------------------------------------------------------------------------
