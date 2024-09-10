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
    //    polinomioLista = new UPolinomioLista::PolinomioLista(M);
    polinomioLista = new UPolinomioSM::PolinomioSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject* Sender)
{
    int coef = Edit10->Text.ToInt();
    int exp = Edit11->Text.ToInt();

    polinomioLista->poner_termino(coef, exp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject* Sender)
{
    int posX = 300;
    int posY = 900;
    double a = Edit8->Text.ToDouble();
    double b = Edit9->Text.ToDouble();

    Canvas->FillRect(Canvas->ClipRect);
    polinomioLista->dibujar_polinomio(Form1, 700, 800);
    polinomioLista->graficar_image(Image1, a, b);
    // polinomioLista->graficar(Form1, 600, 10, 700, 700);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject* Sender)
{
    //    UPolinomioLista::PolinomioLista* nuevoPolinomio =
    //        new UPolinomioLista::PolinomioLista(M);
    //    UPolinomioLista::derivada(polinomioLista, nuevoPolinomio);

    UPolinomioSM::PolinomioSM* nuevoPolinomio =
        new UPolinomioSM::PolinomioSM(M);
    UPolinomioSM::derivada(polinomioLista, nuevoPolinomio);
}
//---------------------------------------------------------------------------

