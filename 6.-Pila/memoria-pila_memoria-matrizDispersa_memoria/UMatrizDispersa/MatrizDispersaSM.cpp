//---------------------------------------------------------------------------

#pragma hdrstop
#include <sstream>
#include <vector>
#include "MatrizDispersaSM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UMatrizDispersaSM
{
    using UCSMemoria::NULO;

    MatrizDispersaSM::MatrizDispersaSM()
    {
        PtrMatD = NULO;
        mem = new UCSMemoria::CSMemoria;
        df = dc = nt = repe = 0;
    }

    MatrizDispersaSM::MatrizDispersaSM(UCSMemoria::CSMemoria* m)
    {
        PtrMatD = NULO;
        mem = m;
        df = dc = nt = repe = 0;
    }

    void MatrizDispersaSM::dimensionar(int f, int c)
    {
        df = f;
        dc = c;
    }

    int MatrizDispersaSM::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaSM::dimension_columna()
    {
        return dc;
    }

    int MatrizDispersaSM::buscar(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int x = PtrMatD;
        while (x != NULO)
        {
            if (mem->obtener_dato(x, _fil) == f &&
                mem->obtener_dato(x, _col) == c)
                return x;
            x = mem->obtener_dato(x, _sig);
        }
        return NULO;
    }

    void MatrizDispersaSM::poner(int f, int c, int elemento)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int dir = buscar(f, c);
        if (dir == NULO && elemento != repe)
        {
            int x = mem->new_espacio(_fil_col_dato_sig);
            if (x == NULO)
                throw new Exception("No hay espacio en la memoria");
            mem->poner_dato(x, _fil, f);
            mem->poner_dato(x, _col, c);
            mem->poner_dato(x, _dato, elemento);
            mem->poner_dato(x, _sig, PtrMatD);
            PtrMatD = x;
            nt++;
        }
        else
        {
            mem->poner_dato(dir, _dato, elemento);
            if (elemento == repe)
            {
                if (dir == PtrMatD)
                    PtrMatD = mem->obtener_dato(PtrMatD, _sig);
                else
                {
                    int x = PtrMatD;
                    int ant = NULO;
                    while (x != NULO)
                    {
                        if (x == dir)
                            break;
                        ant = x;
                        x = mem->obtener_dato(x, _sig);
                    }
                    mem->poner_dato(ant, _sig, mem->obtener_dato(dir, _sig));
                }
                mem->delete_espacio(dir);
                nt--;
            }
        }
    }

    int MatrizDispersaSM::elemento(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int dir = buscar(f, c);
        return dir == NULO ? repe : mem->obtener_dato(dir, _dato);
    }

    bool MatrizDispersaSM::hay(int elemento)
    {
        int x = PtrMatD;
        while (x != NULO)
        {
            if (mem->obtener_dato(x, _dato) == elemento)
                return true;
            x = mem->obtener_dato(x, _sig);
        }
        return false;
    }

    void MatrizDispersaSM::definir_valor_repetido(int elemento)
    {
        if (PtrMatD == NULO || !hay(elemento))
            repe = elemento;
        else
        {
            for (int i = 1; i <= df; i++)
            {
                for (int j = 1; j <= dc; j++)
                {
                    int el = this->elemento(i, j);
                    if (el == elemento)
                    {  //
                        int dir = buscar(i, j);
                        if (dir == PtrMatD)
                            PtrMatD = mem->obtener_dato(PtrMatD, _sig);
                        else
                        {
                            int x = PtrMatD;
                            int ant = NULO;
                            while (x != NULO)
                            {
                                if (x == dir)
                                    break;
                                ant = x;
                                x = mem->obtener_dato(x, _sig);
                            }
                            mem->poner_dato(
                                ant, _sig, mem->obtener_dato(dir, _sig));
                        }
                        mem->delete_espacio(dir);
                        nt--;
                    }
                    else if (el == repe)
                    {
                        int x = mem->new_espacio(_fil_col_dato_sig);
                        if (x == NULO)
                            throw new Exception("No hay espacio en la memoria");
                        mem->poner_dato(x, _fil, i);
                        mem->poner_dato(x, _col, j);
                        mem->poner_dato(x, _dato, repe);
                        mem->poner_dato(x, _sig, PtrMatD);
                        PtrMatD = x;
                        nt++;
                    }
                }
            }
            repe = elemento;
        }
    }

    MatrizDispersaSM::~MatrizDispersaSM()
    {
        if (mem == nullptr)
            return;
        delete mem;
    }

    std::string MatrizDispersaSM::mostrar()
    {
        std::string s = "";
        for (int i = 1; i <= df; i++)
        {
            for (int j = 1; j <= dc; j++)
            {
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

    void MatrizDispersaSM::dibujar_celda(TForm* Form, TColor brushColor,
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

    void MatrizDispersaSM::graficar_matriz_dispersa(
        TForm* Form, int posX, int posY)
    {
        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);
        //        Form->Canvas->Pen->Color = clBlack;
        int auxX = posX;
        int auxY = posY;
        std::vector<std::vector<int> > v = {
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {1, 1, 1, 0, 0, 0, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0},
        };
        bool bFila = false;
        bool bColumna = false;
        int cFila = 0;
        int cColumna = 0;
        for (int f = 1; f <= df; f++)
        {
            for (int c = 1; c <= dc; c++)
            {
                if (df == 9 && dc == 9)
                {
                    if (v[f - 1][c - 1] == 0)
                    {
                        dibujar_celda(Form, clHighlight, true, posX, posY,
                                      String(elemento(f, c)));
                    }
                    else
                    {
                        dibujar_celda(Form, clYellow, true, posX, posY,
                                      String(elemento(f, c)));
                    }
                }
                else
                {
                    dibujar_celda(Form, clBtnFace, true, posX, posY,
                                  String(elemento(f, c)));
                }
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

    int MatrizDispersaSM::suma(MatrizDispersaSM* m)
    {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++)
        {
            for (int c = 1; c <= m->dimension_columna(); c++)
            {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }

    void MatrizDispersaSM::transpuesta(
        MatrizDispersaSM* m, MatrizDispersaSM* m1)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        m1->dimensionar(c, f);
        for (int i = 1; i <= f; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                m1->poner(j, i, m->elemento(i, j));
            }
        }
        return;
    }

    bool MatrizDispersaSM::es_simetrica(MatrizDispersaSM* m)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        if (f != c)
            return false;
        for (int i = 1; i <= f; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (m->elemento(i, j) != m->elemento(j, i))
                    return false;
            }
        }
        return true;
    }
}  // namespace UMatrizDispersaSM
