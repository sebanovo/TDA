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
bool esSudoku(UMatrizDispersaSM::MatrizDispersaSM* m)
{
    int df = m->dimension_fila();
    int dc = m->dimension_columna();
    const int n = 9;
    if (df != 9 || dc != 9)
        throw new Exception("No es Sudoku");

    // Verificar filas y columnas
    for (int i = 1; i < n; ++i) {
        bool fila[n + 1] = { false }; // índice 1 a 9
        bool columna[n + 1] = { false }; // índice 1 a 9

        for (int j = 1; j < n; ++j) {
            // Verificar filas
            int valorFila = m->elemento(i, j);
            if (valorFila < 1 || valorFila > 9 || fila[valorFila]) {
                return false;
            }
            fila[valorFila] = true;

            // Verificar columnas
            int valorColumna = m->elemento(j, i);
            if (valorColumna < 1 || valorColumna > 9 || columna[valorColumna]) {
                return false;
            }
            columna[valorColumna] = true;
        }
    }

    // Verificar cada subcuadrícula 3x3
    for (int startRow = 1; startRow < n; startRow += 3) {
        for (int startCol = 1; startCol < n; startCol += 3) {
            bool subCuadricula[n + 1] = { false }; // índice 1 a 9

            for (int i = 1; i < 3; ++i) {
                for (int j = 1; j < 3; ++j) {
                    int valor = m->elemento(startRow + i, startCol + j);
                    if (valor < 1 || valor > 9 || subCuadricula[valor]) {
                        return false;
                    }
                    subCuadricula[valor] = true;
                }
            }
        }
    }

    // Si se cumplieron todas las condiciones, es un Sudoku válido
    return true;
}

void ponerSudoku(
    UMatrizDispersaSM::MatrizDispersaSM* matriz, UPilaSM::PilaSM* pila)
{
    // sudoku valido ganador
    std::vector<std::vector<int> > v = {
        { 7, 4, 3, 9, 5, 2, 8, 6, 1 }, //
        { 1, 8, 2, 4, 3, 6, 7, 5, 9 }, //
        { 9, 6, 5, 1, 8, 7, 4, 2, 3 }, //
        { 4, 3, 1, 5, 7, 9, 6, 8, 2 }, //
        { 8, 2, 7, 6, 1, 3, 5, 9, 4 }, //
        { 6, 5, 9, 8, 2, 4, 1, 3, 7 }, //
        { 3, 7, 8, 2, 6, 1, 9, 4, 5 }, //
        { 5, 1, 4, 3, 9, 8, 2, 7, 6 }, //
        { 2, 9, 6, 7, 4, 5, 3, 1, 8 }, //
    };

    for (int f = 0; f < v.size(); f++) {
        for (int c = 0; c < v[0].size(); c++) {
            int anterior = matriz->elemento(f + 1, c + 1);
            pila->meter(f + 1);
            pila->meter(c + 1);
            pila->meter(anterior);
            matriz->poner(f + 1, c + 1, v[f][c]);
        }
    }
}
void __fastcall TForm1::Button10Click(TObject* Sender)
{
    ShowMessage(esSudoku(matriz) ? "ES SUDOKU" : "NO ES SUDOKU");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject* Sender)
{
    int f, c, elemento;
    if (pila->vacia())
        return;
    pila->sacar(&elemento);
    if (pila->vacia())
        return;
    pila->sacar(&c);
    if (pila->vacia())
        return;
    pila->sacar(&f);

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
    pila2->sacar(&elemento);
    if (pila2->vacia())
        return;
    pila2->sacar(&c);
    if (pila2->vacia())
        return;
    pila2->sacar(&f);

    int anterior = matriz->elemento(f, c);
    matriz->poner(f, c, elemento);

    pila->meter(f);
    pila->meter(c);
    pila->meter(anterior);
    Button8Click(Sender);
}

