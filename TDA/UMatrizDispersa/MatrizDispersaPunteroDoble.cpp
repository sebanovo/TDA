// ---------------------------------------------------------------------------

#pragma hdrstop

#include <sstream>
#include "MatrizDispersaPunteroDoble.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UMatrizDispersaPunteroDoble
{

    MatrizDispersaPunteroDoble::MatrizDispersaPunteroDoble()
    {
        PtrFil = nullptr;
        df = dc = nt = repe = 0;
    }

    void MatrizDispersaPunteroDoble::dimensionar(int f, int c)
    {
        df = f;
        dc = c;
    }

    int MatrizDispersaPunteroDoble::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaPunteroDoble::dimension_columna()
    {
        return dc;
    }

    NodoColumna* MatrizDispersaPunteroDoble::buscar(int f, int c)
    {
        NodoFila* auxF = PtrFil;
        while(auxF != nullptr)
        {
            if(auxF->fil == f)
            {
                NodoColumna* auxC = auxF->PtrCol;
                while(auxC != nullptr)
                {
                    if(auxC->col == c)
                        return auxC;
                    auxC = auxC->sigC;
                }
                return nullptr;
            }
            auxF = auxF->sigF;
        }
        return nullptr;
    }

    NodoFila* MatrizDispersaPunteroDoble::buscar(int f)
    {
        NodoFila* auxF = PtrFil;
        while(auxF != nullptr)
        {
            if(auxF->fil == f)
                return auxF;
            auxF = auxF->sigF;
        }
        return nullptr;
    }

    NodoFila* MatrizDispersaPunteroDoble::posicionIns(int f)
    {
        NodoFila* auxF = PtrFil;
        while(auxF != nullptr)
        {
            if(f < auxF->fil)
                return auxF;
            auxF = auxF->sigF;
        }
        return nullptr;
    }

    void MatrizDispersaPunteroDoble::suprimir(NodoFila* dirFil, NodoColumna* dirCol)
    {
        if(dirCol == dirFil->PtrCol)
            dirFil->PtrCol = dirFil->PtrCol->sigC;
        else
        {
            // El anterior
            NodoColumna* x = dirFil->PtrCol;
            NodoColumna* ant = nullptr;
            while(x != nullptr)
            {
                if(x == dirCol)
                    break;
                ant = x;
                x = x->sigC;
            }

            ant->sigC = dirCol->sigC;
        }
        delete dirCol;
        nt--;
        if(dirFil->PtrCol == nullptr)
        {
            suprimir(dirFil);
        }
    }

    void MatrizDispersaPunteroDoble::suprimir(NodoFila* dir)
    {
        if(dir == PtrFil)
        {
            PtrFil = PtrFil->sigF;
        }
        else
        {
            NodoFila* ant = dir->antF;
            NodoFila* sig = dir->sigF;
            ant->sigF = sig;
            if(sig != nullptr)
                sig->antF = ant;
        }
        delete dir;
    }

    void MatrizDispersaPunteroDoble::insertar(int f, int c, int elemento)
    {
        NodoColumna* x = new NodoColumna;
        if(x == nullptr)
            throw new Exception("No hay espacio en la memoria");
        x->col = c;
        x->dato = elemento;
        x->sigC = nullptr;
        NodoFila* dirFila = buscar(f);
        if(dirFila != nullptr)
        {
            x->sigC = dirFila->PtrCol;
            dirFila->PtrCol = x;
        }
        else
        {
            NodoFila* xF = new NodoFila;
            if(xF != nullptr)
            {
                xF->fil = f;
                xF->antF = nullptr;
                xF->sigF = nullptr;
                xF->PtrCol = nullptr;
                NodoFila* posF = posicionIns(f);
                if(posF == nullptr)
                {
                    if(PtrFil == nullptr)
                        PtrFil = xF;
                    else
                    {
                        NodoFila* fin = PtrFil;
                        while(fin->sigF != nullptr)
                            fin = fin->sigF;
                        xF->antF = fin;
                        fin->sigF = xF;
                    }
                }
                else if(posF == PtrFil)
                {
                    xF->sigF = PtrFil;
                    PtrFil->antF = xF;
                    PtrFil = xF;
                }
                else
                {
                    NodoFila* ant = posF->antF;
                    NodoFila* sig = posF;
                    xF->sigF = sig;
                    xF->antF = ant;
                    ant->sigF = xF;
                    sig->antF = xF;
                }
                x->sigC = xF->PtrCol;
                xF->PtrCol = x;
            }
        }
        nt++;
    }

    void MatrizDispersaPunteroDoble::poner(int f, int c, int elemento)
    {
        if((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        NodoColumna* dir = buscar(f, c);
        if(dir != nullptr)
        {
            dir->dato = elemento;
            if(elemento == repe)
            {
                NodoFila* dirFila = buscar(f);
                suprimir(dirFila, dir);
            }
        }
        else if(elemento != repe)
            insertar(f, c, elemento);
    }

    int MatrizDispersaPunteroDoble::elemento(int f, int c)
    {
        if((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        NodoColumna* dir = buscar(f, c);
        return dir == nullptr ? repe : dir->dato;
    }

    bool MatrizDispersaPunteroDoble::hay(int elemento)
    {
        NodoFila* auxF = PtrFil;
        while(auxF != nullptr)
        {
            NodoColumna* auxC = auxF->PtrCol;
            while(auxC != nullptr)
            {
                if(auxC->dato == elemento)
                    return true;
                auxC = auxC->sigC;
            }
            auxF = auxF->sigF;
        }
        return false;
    }

    void MatrizDispersaPunteroDoble::definir_valor_repetido(int elemento)
    {
        if(PtrFil == nullptr || !hay(elemento))
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
                        NodoFila* dirF = buscar(i);
                        NodoColumna* dirC = buscar(i, j);
                        suprimir(dirF, dirC);
                    }
                    else if(el == repe)
                        insertar(i, j, repe);
                }
            }
            repe = elemento;
        }
    }

    std::string MatrizDispersaPunteroDoble::mostrar()
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

    MatrizDispersaPunteroDoble::~MatrizDispersaPunteroDoble()
    {
        NodoFila* auxF = PtrFil;

        while(auxF != nullptr)
        {
            NodoColumna* auxC = auxF->PtrCol;
            while(auxC != nullptr)
            {
                NodoColumna* temp = auxC;
                auxC = auxC->sigC;
                delete temp;
            }
            auxF->PtrCol = nullptr;
            NodoFila* tempRow = auxF;
            auxF = auxF->sigF;
            delete tempRow;
        }
        PtrFil = nullptr;
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

    void MatrizDispersaPunteroDoble::graficar_matriz_dispersa(
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

    int MatrizDispersaPunteroDoble::suma(MatrizDispersaPunteroDoble* m)
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

    void MatrizDispersaPunteroDoble::transpuesta(MatrizDispersaPunteroDoble* m,
    MatrizDispersaPunteroDoble* m1)
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

    bool MatrizDispersaPunteroDoble::es_simetrica(MatrizDispersaPunteroDoble* m)
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

    bool esValido(MatrizDispersaPunteroDoble* m, int f, int c, int k)
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
    bool backTracking(MatrizDispersaPunteroDoble* m, int f, int c)
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
    bool esSudoku(MatrizDispersaPunteroDoble* m)
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
    void resolverSudoku(MatrizDispersaPunteroDoble* m)
    {
        if(m->dimension_fila() != m->dimension_columna())
            throw new Exception("La matriz tiene que ser cuadrada");
        if(m->dimension_fila() != 9 || m->dimension_columna() != 9)
            throw new Exception("La matriz no es de 9x9");
        backTracking(m, 1, 1);
    }
} // namespace UMatrizDispersaPunteroDoble