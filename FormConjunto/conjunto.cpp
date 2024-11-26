//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "conjunto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7* Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner) : TForm(Owner) {}
__fastcall TForm7::~TForm7()
{
    delete A, B, C;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button1Click(TObject* Sender)
{
    A = new UConjuntoVector::ConjuntoVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button2Click(TObject* Sender)
{
    B = new UConjuntoVector::ConjuntoVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button3Click(TObject* Sender)
{
    C = new UConjuntoVector::ConjuntoVector;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button4Click(TObject* Sender)
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

void __fastcall TForm7::Button5Click(TObject* Sender)
{
    String conjunto = ComboBox1->Text;
    int radio = 200;

    Canvas->Pen->Color = Form7->Color;
    Canvas->Brush->Color = Form7->Color;
    Canvas->Rectangle(0, 0, Form7->Width, Form7->Height);

    switch (conjunto[1]) {
        case 'A':
            A->dibujar_conjunto(Form7, 400, 200);
            //            A->graficar_conjunto(Form7, 500, 600, radio, "A");
            break;
        case 'B':
            B->dibujar_conjunto(Form7, 400, 300);
            //            B->graficar_conjunto(Form7, 1000, 600, radio, "B");
            break;
        case 'C':
            C->dibujar_conjunto(Form7, 400, 400);
            //            C->graficar_conjunto(Form7, 1500, 600, radio, "C");
            break;
        default:
            ShowMessage("Conjunto No Valido");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button6Click(TObject* Sender)
{
    UConjuntoVector::ConjuntoVector::_union(A, B, C);
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button7Click(TObject* Sender)
{
    UConjuntoVector::ConjuntoVector::_interseccion(A, B, C);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button8Click(TObject* Sender)
{
    Close();
}
//---------------------------------------------------------------------------

