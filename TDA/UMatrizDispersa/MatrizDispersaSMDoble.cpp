// ---------------------------------------------------------------------------

#pragma hdrstop

#include <sstream>
#include "MatrizDispersaSMDoble.h"
// ---------------------------------------------------------------------------

#pragma package(smart_init)

namespace UMatrizDispersaSMDoble
{
    using UCSMemoria::NULO;
    MatrizDispersaSMDoble::MatrizDispersaSMDoble()
    {
        mem = new UCSMemoria::CSMemoria;
        PtrFil = NULO;
        df = dc = repe = nt = 0;
    }

    MatrizDispersaSMDoble::MatrizDispersaSMDoble(UCSMemoria::CSMemoria* m)
    {
        mem = m;
        PtrFil = NULO;
        df = dc = nt = repe = 0;
    }

    void MatrizDispersaSMDoble::dimensionar(int f, int c)
    {
        df = f;
        dc = c;
    }

    int MatrizDispersaSMDoble::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaSMDoble::dimension_columna()
    {
        return dc;
    }

    int MatrizDispersaSMDoble::buscarC(int f, int c)
    {
        int auxF = PtrFil;
        while(auxF != NULO)
        {
            if(mem->obtener_dato(auxF, _fil) == f)
            {
                int auxC = mem->obtener_dato(auxF, _PtrCol);
                while(auxC != NULO)
                {
                    if(mem->obtener_dato(auxC, _col) == c)
                        return auxC;
                    auxC = mem->obtener_dato(auxC, _sigC);
                }
                return NULO;
            }
            auxF = mem->obtener_dato(auxF, _sigF);
        }
        return NULO;
    }

    int MatrizDispersaSMDoble::buscarF(int f)
    {
        int auxF = PtrFil;
        while(auxF != NULO)
        {
            if(mem->obtener_dato(auxF, _fil) == f)
                return auxF;
            auxF = mem->obtener_dato(auxF, _sigF);
        }
        return NULO;
    }

    int MatrizDispersaSMDoble::posicionIns(int f)
    {
        int auxF = PtrFil;
        while(auxF != NULO)
        {
            if(f < mem->obtener_dato(auxF, _fil))
                return auxF;
            auxF = mem->obtener_dato(auxF, _sigF);
        }
        return NULO;
    }

    void MatrizDispersaSMDoble::suprimir(int dirFil, int dirCol)
    {
        if(dirCol == mem->obtener_dato(dirFil, _PtrCol))
        {
            mem->poner_dato(
            dirFil, _PtrCol, mem->obtener_dato(mem->obtener_dato(dirFil, _PtrCol), _sigC));
        }
        else
        {
            // El anterior
            int x = mem->obtener_dato(dirFil, _PtrCol);
            int ant = NULO;
            while(x != NULO)
            {
                if(x == dirCol)
                    break;
                ant = x;
                x = mem->obtener_dato(x, _sigC);
            }
            mem->poner_dato(ant, _sigC, mem->obtener_dato(dirCol, _sigC));
        }
        mem->delete_espacio(dirCol);
        nt--;
        if(mem->obtener_dato(dirFil, _PtrCol) == NULO)
        {
            suprimir(dirFil);
        }
    }

    void MatrizDispersaSMDoble::suprimir(int dir)
    {
        if(dir == PtrFil)
        {
            PtrFil = mem->obtener_dato(PtrFil, _sigF);
        }
        else
        {
            int ant = mem->obtener_dato(dir, _antF);
            int sig = mem->obtener_dato(dir, _sigF);
            mem->poner_dato(ant, _sigF, sig);
            if(sig != NULO)
            {
                mem->poner_dato(sig, _antF, ant);
            }
        }
        mem->delete_espacio(dir);
    }

    void MatrizDispersaSMDoble::insertar(int f, int c, int elemento)
    {
        int x = mem->new_espacio(_col_dato_sigC);
        if(x == NULO)
            throw new Exception("No hay espacio en la memoria");
        mem->poner_dato(x, _col, c);
        mem->poner_dato(x, _dato, elemento);
        mem->poner_dato(x, _sigC, NULO);
        int dirFila = buscarF(f);
        if(dirFila != NULO)
        {
            mem->poner_dato(x, _sigC, mem->obtener_dato(dirFila, _PtrCol));
            mem->poner_dato(dirFila, _PtrCol, x);
        }
        else
        {
            int xF = mem->new_espacio(_fil_antF_sigF_ptrCol);
            if(xF != NULO)
            {
                mem->poner_dato(xF, _fil, f);
                mem->poner_dato(xF, _antF, NULO);
                mem->poner_dato(xF, _sigF, NULO);
                mem->poner_dato(xF, _PtrCol, NULO);
                int posF = posicionIns(f);
                if(posF == NULO)
                {
                    if(PtrFil == NULO)
                        PtrFil = xF;
                    else
                    {
                        int fin = PtrFil;
                        while(mem->obtener_dato(fin, _sigF) != NULO)
                            fin = mem->obtener_dato(fin, _sigF);
                        mem->poner_dato(xF, _antF, fin);
                        mem->poner_dato(fin, _sigF, xF);
                    }
                }
                else if(posF == PtrFil)
                {
                    mem->poner_dato(xF, _sigF, PtrFil);
                    mem->poner_dato(PtrFil, _antF, xF);
                    PtrFil = xF;
                }
                else
                {
                    int ant = mem->obtener_dato(posF, _antF);
                    int sig = posF;
                    mem->poner_dato(xF, _sigF, sig);
                    mem->poner_dato(xF, _antF, ant);
                    mem->poner_dato(ant, _sigF, xF);
                    mem->poner_dato(sig, _antF, xF);
                }

                mem->poner_dato(x, _sigC, mem->obtener_dato(xF, _PtrCol));
                mem->poner_dato(xF, _PtrCol, x);
            }
        }
        nt++;
    }

    void MatrizDispersaSMDoble::poner(int f, int c, int elemento)
    {
        if((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int dir = buscarC(f, c);
        if(dir != NULO)
        {
            mem->poner_dato(dir, _dato, elemento);
            if(elemento == repe)
            {
                int dirFila = buscarF(f);
                suprimir(dirFila, dir);
            }
        }
        else if(elemento != repe)
            insertar(f, c, elemento);
    }

    int MatrizDispersaSMDoble::elemento(int f, int c)
    {
        if((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int dir = buscarC(f, c);
        return dir == NULO ? repe : mem->obtener_dato(dir, _dato);
    }

    bool MatrizDispersaSMDoble::hay(int elemento)
    {
        int auxF = PtrFil;
        while(auxF != NULO)
        {
            int auxC = mem->obtener_dato(auxF, _PtrCol);
            while(auxC != NULO)
            {
                if(mem->obtener_dato(auxC, _dato) == elemento)
                    return true;
                auxC = mem->obtener_dato(auxC, _sigC);
            }
            auxF = mem->obtener_dato(auxF, _sigF);
        }
        return false;
    }

    void MatrizDispersaSMDoble::definir_valor_repetido(int elemento)
    {
        if(PtrFil == NULO || !hay(elemento))
        {
            repe = elemento;
        }
        else
        {
            for(int i = 1; i <= df; i++)
            {
                for(int j = 1; j <= dc; j++)
                {
                    int el = this->elemento(i, j);
                    if(el == elemento)
                    {
                        int dirF = buscarF(i);
                        int dirC = buscarC(i, j);
                        suprimir(dirF, dirC);
                    }
                    else if(el == repe)
                        insertar(i, j, repe);
                }
            }
            repe = elemento;
        }
    }

    std::string MatrizDispersaSMDoble::mostrar()
    {
        std::string s = "";
        for(int i = 1; i <= df; i++)
        {
            for(int j = 1; j <= dc; j++)
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

    MatrizDispersaSMDoble::~MatrizDispersaSMDoble()
    {
        delete mem;
    }

     void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
        int posX, int posY, String cad)
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

    void MatrizDispersaSMDoble::graficar_matriz_dispersa(
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

    int MatrizDispersaSMDoble::suma(MatrizDispersaSMDoble* m)
    {
        int suma = 0;
        for(int f = 1; f <= m->dimension_fila(); f++)
        {
            for(int c = 1; c <= m->dimension_columna(); c++)
            {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }

    void MatrizDispersaSMDoble::transpuesta(MatrizDispersaSMDoble* m, MatrizDispersaSMDoble* m1)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        m1->dimensionar(c, f);
        for(int i = 1; i <= f; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                m1->poner(j, i, m->elemento(i, j));
            }
        }
        return;
    }

    bool MatrizDispersaSMDoble::es_simetrica(MatrizDispersaSMDoble* m)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        if(f != c)
            return false;
        for(int i = 1; i <= f; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                if(m->elemento(i, j) != m->elemento(j, i))
                    return false;
            }
        }
        return true;
    }

    bool esValido(MatrizDispersaSMDoble* m, int f, int c, int k)
    {
        for(int j = 1; j <= m->dimension_columna(); ++j)
            if(m->elemento(f, j) == k)
                return false;

        for(int i = 1; i <= m->dimension_columna(); ++i)
            if(m->elemento(i, c) == k)
                return false;


        int box_row_start = ((f - 1) / 3) * 3 + 1;
        int box_col_start = ((c - 1) / 3) * 3 + 1;

        for(int i = box_row_start; i < box_row_start + 3; ++i)
            for(int j = box_col_start; j < box_col_start + 3; ++j)
                if(m->elemento(i, j) == k)
                    return false;

        return true;
    }

    // algoritmo para resolver el sudoku clasico de 9x9
    bool backTracking(MatrizDispersaSMDoble* m, int f, int c)
    {
        if(f > 9) //  caso base
            return true;
        else if(c > 9)
            return backTracking(m, f + 1, 1);
        else if(m->elemento(f, c) != 0)
            return backTracking(m, f, c + 1);
        else
        {
            for(int k = 1; k <= 9; k++)
            {
                if(esValido(m, f, c, k))
                {
                    m->poner(f, c, k);
                    if(backTracking(m, f, c + 1))
                        return true;
                    m->poner(f, c, 0);
                }
            }
            return false;
        }
    }

    // verifica únicamente el sudoku clasico de 9x9
    bool esSudoku(MatrizDispersaSMDoble* m)
    {
        const int n = 9;
        int df = m->dimension_fila();
        int dc = m->dimension_columna();

        if(df != n || dc != n)
            throw new Exception("No es Sudoku");

        // Verificar filas y columnas
        for(int f = 1; f <= n; f++)
        {
            bool fila[n + 1] = { false };
            bool columna[n + 1] = { false };

            for(int c = 1; c <= n; c++)
            {
                // Verificar filas
                int valorFila = m->elemento(f, c);
                if(valorFila < 1 || valorFila > 9 || fila[valorFila])
                    return false;
                fila[valorFila] = true;

                // Verificar columnas
                int valorColumna = m->elemento(f, c);
                if(valorColumna < 1 || valorColumna > 9 || columna[valorColumna])
                    return false;
                columna[valorColumna] = true;
            }
        }

        // Verificar cada subcuadricula 3x3
        for(int startRow = 1; startRow < n; startRow += 3)
        {
            for(int startCol = 1; startCol < n; startCol += 3)
            {
                bool subCuadricula[n + 1] = { false };
                for(int row = 0; row < 3; row++)
                {
                    for(int col = 0; col < 3; col++)
                    {
                        int valor = m->elemento(startRow + row, startCol + col);
                        if(valor < 1 || valor > 9 || subCuadricula[valor])
                        {
                            return false;
                        }
                        subCuadricula[valor] = true;
                    }
                }
            }
        }

        return true;
    }

    // resuelve únicamente sudokus de 9x9 (no resuelve las miles de variantes de este juego)
    void resolverSudoku(MatrizDispersaSMDoble* m)
    {
        if(m->dimension_fila() != m->dimension_columna())
            throw new Exception("La matriz tiene que ser cuadrada");
        if(m->dimension_fila() != 9 || m->dimension_columna() != 9)
            throw new Exception("La matriz no es de 9x9");
        backTracking(m, 1, 1);
    }
} // namespace UMatrizDispersaSMDoble