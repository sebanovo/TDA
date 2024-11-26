//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "memoria-conjunto_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6* Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm6::~TForm6()
{
    delete M, A, B, C;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject* Sender)
{
    M = new UCSMemoria::CSMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject* Sender)
{
    AnsiString ids = Edit1->Text;
    M->new_espacio(ids.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button3Click(TObject* Sender)
{
    A = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button4Click(TObject* Sender)
{
    B = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button5Click(TObject* Sender)
{
    C = new UConjuntoSM::ConjuntoSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button6Click(TObject* Sender)
{
    String elemento, Conjunto;
    Conjunto = ComboBox1->Text;

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

void __fastcall TForm6::Button7Click(TObject* Sender)
{
    String conjunto = ComboBox1->Text;
    int radio = 200;
    Canvas->Pen->Color = Form6->Color;
    Canvas->Brush->Color = Form6->Color;
    Canvas->Rectangle(0, 0, Form6->Width, Form6->Height);

    switch (conjunto[1]) {
        case 'A':
            A->dibujar_conjunto(Form6, 400, 200);
            A->graficar_conjunto(Form6, 500, 600, radio, "A");
            break;
        case 'B':
            B->dibujar_conjunto(Form6, 400, 300);
            B->graficar_conjunto(Form6, 1000, 600, radio, "B");
            break;
        case 'C':
            C->dibujar_conjunto(Form6, 400, 400);
            C->graficar_conjunto(Form6, 1500, 600, radio, "C");
            break;
        default:
            ShowMessage("Conjunto No Valido");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button8Click(TObject* Sender)
{
    UConjuntoSM::ConjuntoSM::_union(A, B, C);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button9Click(TObject* Sender)
{
    UConjuntoSM::ConjuntoSM::_interseccion(A, B, C);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button10Click(TObject* Sender)
{
    M->dibujar_memoria(Form6, 1300, 20, 0, 20);
}
//---------------------------------------------------------------------------

