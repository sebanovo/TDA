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
    delete M, A, B, C;
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
    A = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
{
    B = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject* Sender)
{
    C = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    String elemento, Conjunto;
    Conjunto = InputBox("Seleccionar Conjunto", "Conjunto", "");

    switch (Conjunto[1]) {
        case 'A':

            elemento = InputBox("Insertar Elemento en A", "Elemento:", "");
            A->inserta(elemento.ToInt());
            break;
        case 'B':

            elemento = InputBox("Insertar Elemento en B", "Elemento:", "");
            B->inserta(elemento.ToInt());
            break;
        case 'C':

            elemento = InputBox("Insertar Elemento en C", "Elemento:", "");
            C->inserta(elemento.ToInt());
            break;
        default:
            ShowMessage("Conjunto No Valido");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject* Sender)
{
    String Conjunto;
    Conjunto = InputBox("Mostrar Conjunto", "Conjunto", "");

    switch (Conjunto[1]) {
        case 'A':
            A->dibujar_conjunto(Form1, 800, 200);
            break;
        case 'B':
            B->dibujar_conjunto(Form1, 800, 300);
            break;
        case 'C':
            C->dibujar_conjunto(Form1, 800, 400);
            break;
        default:
            ShowMessage("Conjunto No Valido");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject* Sender)
{
    UConjuntoSM::_union(A, B, C);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject* Sender)
{
    UConjuntoSM::_interseccion(A, B, C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject* Sender)
{
    Close();
}
//---------------------------------------------------------------------------

