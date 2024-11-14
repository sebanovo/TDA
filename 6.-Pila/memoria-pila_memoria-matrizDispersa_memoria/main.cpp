//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
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
    delete M, matriz, pila;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject* Sender)
{
    M = new UCSMemoria::CSMemoria;
    //    pila = new UPilaSM::PilaSM(M);
    pila = new UPilaVector::PilaVector;
    pila2 = new UPilaVector::PilaVector;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject* Sender)
{
    AnsiString ids = Edit1->Text;
    M->new_espacio(ids.c_str());
}
//-----------------z----------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject* Sender)
{
    M->delete_espacio(Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject* Sender)
{
    matriz = new UMatrizDispersaSM::MatrizDispersaSM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject* Sender)
{
    int defecto = Edit3->Text.ToInt();
    matriz->definir_valor_repetido(defecto);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject* Sender)
{
    int f = Edit4->Text.ToInt();
    int c = Edit5->Text.ToInt();
    matriz->dimensionar(f, c);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject* Sender)
{
    int f = Edit6->Text.ToInt();
    int c = Edit7->Text.ToInt();
    int elemento = Edit8->Text.ToInt();
    int anterior = matriz->elemento(f, c);
    matriz->poner(f, c, elemento);

    pila->meter(f);
    pila->meter(c);
    pila->meter(anterior);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject* Sender)
{
    int posX = 500;
    int posY = 10;
    matriz->graficar_matriz_dispersa(Form1, posX, posY);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject* Sender)
{
    M->dibujar_memoria(
        Form1, 1000, 10, Edit9->Text.ToInt(), Edit10->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject* Sender)
{
    ShowMessage(
        UMatrizDispersaSM::esSudoku(matriz) ? "ES SUDOKU" : "NO ES SUDOKU");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject* Sender)
{
    int f, c, elemento;
    if (pila->vacia())
        return;
    pila->sacar(elemento);
    if (pila->vacia())
        return;
    pila->sacar(c);
    if (pila->vacia())
        return;
    pila->sacar(f);

    int anterior = matriz->elemento(f, c);
    matriz->poner(f, c, elemento);
    pila2->meter(f);
    pila2->meter(c);
    pila2->meter(anterior);
    Button8Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject* Sender)
{
    // pending
    int f, c, elemento;
    if (pila2->vacia())
        return;
    pila2->sacar(elemento);
    if (pila2->vacia())
        return;
    pila2->sacar(c);
    if (pila2->vacia())
        return;
    pila2->sacar(f);

    int anterior = matriz->elemento(f, c);
    matriz->poner(f, c, elemento);

    pila->meter(f);
    pila->meter(c);
    pila->meter(anterior);
    Button8Click(Sender);
}

