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
    delete A, B, C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject* Sender)
{
    A = new UConjuntoVector::ConjuntoVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject* Sender)
{
    B = new UConjuntoVector::ConjuntoVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject* Sender)
{
    C = new UConjuntoVector::ConjuntoVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
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

void __fastcall TForm1::Button5Click(TObject* Sender)
{
    String conjunto = InputBox("Mostrar Conjunto", "Conjunto", "");
    int radio = 200;

    Canvas->Pen->Color = Form1->Color;
    Canvas->Brush->Color = Form1->Color;
    Canvas->Rectangle(0, 0, Form1->Width, Form1->Height);

    switch (conjunto[1]) {
        case 'A':
            A->dibujar_conjunto(Form1, 400, 200);
            //            A->graficar_conjunto(Form1, 500, 600, radio, "A");
            break;
        case 'B':
            B->dibujar_conjunto(Form1, 400, 300);
            //            B->graficar_conjunto(Form1, 1000, 600, radio, "B");
            break;
        case 'C':
            C->dibujar_conjunto(Form1, 400, 400);
            //            C->graficar_conjunto(Form1, 1500, 600, radio, "C");
            break;
        default:
            ShowMessage("Conjunto No Valido");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    UConjuntoVector::_union(A, B, C);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject* Sender)
{
    UConjuntoVector::_interseccion(A, B, C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject* Sender)
{
    Close();
}
//---------------------------------------------------------------------------

