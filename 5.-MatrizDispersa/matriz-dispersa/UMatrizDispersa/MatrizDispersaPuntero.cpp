//---------------------------------------------------------------------------

#pragma hdrstop
#include <sstream>
#include "MatrizDispersaPuntero.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UMatrizDispersaPuntero
{
    MatrizDispersaPuntero::MatrizDispersaPuntero()
    {
        PtrMatD = nullptr;
        df = dc = repe = nt = 0;
    }

    void MatrizDispersaPuntero::dimensionar(int f, int c)
    {
        df = f;
        dc = c;
    }

    int MatrizDispersaPuntero::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaPuntero::dimension_columna()
    {
        return dc;
    }

    Nodo* MatrizDispersaPuntero::buscar(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        Nodo* x = PtrMatD;
        while (x != nullptr) {
            if (x->fil == f && x->col == c)
                return x;
            x = x->sig;
        }
        return nullptr;
    }

    void MatrizDispersaPuntero::poner(int f, int c, int elemento)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        Nodo* dir = buscar(f, c);
        if (dir == nullptr && elemento != repe) {
            Nodo* x = new Nodo;
            if (x == nullptr)
                throw new Exception("No ha espacios en la memoria");
            x->fil = f;
            x->col = c;
            x->dato = elemento;
            x->sig = PtrMatD;
            PtrMatD = x;
            nt++;

        } else {
            dir->dato = elemento;
            if (elemento == repe) {
                if (dir == PtrMatD)
                    PtrMatD = PtrMatD->sig;
                else {
                    Nodo* x = PtrMatD;
                    Nodo* ant = nullptr;
                    while (x != nullptr) {
                        if (x == dir)
                            break;
                        ant = x;
                        x = x->sig;
                    }
                    ant->sig = dir->sig;
                }
                delete dir;
                nt--;
            }
        }
    }

    int MatrizDispersaPuntero::elemento(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        Nodo* dir = buscar(f, c);
        return dir == nullptr ? repe : dir->dato;
    }

    bool MatrizDispersaPuntero::hay(int elemento)
    {
        Nodo* x = PtrMatD;
        while (x != nullptr) {
            if (x->dato == elemento)
                return true;
            x = x->sig;
        }
        return false;
    }

    void MatrizDispersaPuntero::definir_valor_repetido(int elemento)
    {
        if (PtrMatD == nullptr || !hay(elemento)) {
            repe = elemento;
        } else {
            for (int i = 1; i <= df; i++) {
                for (int j = 1; j <= dc; j++) {
                    int el = this->elemento(i, j);
                    if (el == elemento) {
                        Nodo* dir = buscar(i, j);
                        if (dir == PtrMatD)
                            PtrMatD = PtrMatD->sig;
                        else {
                            // El anterior
                            Nodo* x = PtrMatD;
                            Nodo* ant = nullptr;
                            while (x != nullptr) {
                                if (x == dir)
                                    break;
                                ant = x;
                                x = x->sig;
                            }
                            ant->sig = dir->sig;
                        }
                        delete (dir);
                        nt--;
                    } else if (el == repe) {
                        Nodo* x = new Nodo;
                        if (x == nullptr)
                            throw new Exception("No hay espacio en la memoria");
                        x->fil = i;
                        x->col = j;
                        x->dato = repe;
                        x->sig = PtrMatD;
                        PtrMatD = x;
                        nt++;
                    }
                }
            }
            repe = elemento;
        }
    }

    MatrizDispersaPuntero::~MatrizDispersaPuntero()
    {
        Nodo* x = PtrMatD;
        while (x != nullptr) {
            Nodo* temp = x;
            x = x->sig;
            delete temp;
        }
        PtrMatD = nullptr;
        x = nullptr;
    }

    std::string MatrizDispersaPuntero::mostrar()
    {
        std::string s = "";
        for (int i = 1; i <= df; i++) {
            for (int j = 1; j <= dc; j++) {
                s += std::to_string(elemento(i, j)) + "\t";
            }
            s += "\r\n";
        }

        std::stringstream info;
        info << "\n-----------------------------------\n";
        info << "nt = " << std::to_string(nt) << "\n";
        info << "df = " << std::to_string(df) << "\n";
        info << "dc = " << std::to_string(dc) << "\n";
        info << "repe = " << std::to_string(repe) << "\n";
        return s + info.str();
    }

    void MatrizDispersaPuntero::dibujar_celda(TForm* Form, TColor brushColor,
        bool withBorder, int posX, int posY, String cad)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Font->Size = 20;
        Canvas->Font->Name = "Microsoft YaHei UI";

        int TamanoCeldaX = TamanoCelda;
        int TamanoCeldaY = TamanoCelda;
        TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);

        int anchoTexto = Canvas->TextWidth(cad);
        int posXCentro = posX + (TamanoCeldaX - anchoTexto) / 2;
        int posYCentro = posY + (TamanoCeldaY - Canvas->TextHeight(cad)) / 2;

        Canvas->Brush->Color = brushColor;
        Canvas->Pen->Color = withBorder ? clBlack : brushColor;
        Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Pen->Color = clBlack;
        Canvas->TextOutW(posXCentro, posYCentro, cad);
    }

    void MatrizDispersaPuntero::graficar_matriz_dispersa(
        TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        int auxX = posX;
        int auxY = posY;
        for (int f = 1; f <= df; f++) {
            for (int c = 1; c <= dc; c++) {
                dibujar_celda(
                    Form, clBtnFace, true, posX, posY, String(elemento(f, c)));
                posX += TamanoCelda;
            }
            posX = auxX;
            posY += TamanoCelda;
        }

        int offSetY = 40;
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->TextOutW(posX, posY, "nt = " + String(nt));
        posY += offSetY;
        Form->Canvas->TextOutW(posX, posY, "df = " + String(df));
        posY += offSetY;
        Form->Canvas->TextOutW(posX, posY, "dc = " + String(dc));
        posY += offSetY;
        Form->Canvas->TextOutW(posX, posY, "repe = " + String(repe));
    }

    int suma(MatrizDispersaPuntero* m)
    {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++) {
            for (int c = 1; c <= m->dimension_columna(); c++) {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }

    void transpuesta(MatrizDispersaPuntero* m, MatrizDispersaPuntero* m1)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        m1->dimensionar(c, f);
        for (int i = 1; i <= f; i++) {
            for (int j = 1; j <= c; j++) {
                m1->poner(j, i, m->elemento(i, j));
            }
        }
        return;
    }

    bool es_simetrica(MatrizDispersaPuntero* m)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        if (f != c)
            return false;
        for (int i = 1; i <= f; i++) {
            for (int j = 1; j <= c; j++) {
                if (m->elemento(i, j) != m->elemento(j, i))
                    return false;
            }
        }
        return true;
    }
} // namespace UMatrizDispersaPuntero

