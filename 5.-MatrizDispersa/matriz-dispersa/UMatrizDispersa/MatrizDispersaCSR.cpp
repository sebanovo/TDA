//---------------------------------------------------------------------------

#pragma hdrstop
#include <sstream>
#include "MatrizDispersaCSR.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UMatrizDispersaCSR
{
    MatrizDispersaCSR::MatrizDispersaCSR()
    {
        df = dc = nt = repe = 0;
        vf = new int[MAX];
        vc = new int[MAX];
        vd = new int[MAX];

        // incializar en 0 solamente sirve en el c++ no nativo
        for (int i = 1; i < MAX; i++) {
            vf[i] = 0;
            vc[i] = 0;
            vd[i] = 0;
        }

        for (int i = 1; i <= df + 1; i++) {
            vf[i] = 1;
        }
    }

    // dimensionar la fila y la columna
    void MatrizDispersaCSR::dimensionar(int f, int c)
    {
        df = f;
        dc = c;

        for (int i = 1; i <= df + 1; i++) {
            vf[i] = 1;
        }
    }

    // verifica que exista el elemento
    int MatrizDispersaCSR::buscar_posicion_vd(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");

        int lug_antes = 0;
        for (int i = 1; i <= f - 1; i++) {
            lug_antes += (vf[i + 1] - vf[i]);
        }

        int max_elem = vf[f + 1] - vf[f];

        for (int i = 1; i <= max_elem; i++) {
            if (vc[lug_antes + i] == c)
                return lug_antes + i;
        }
        return 0;
    }

    // busca la posicion de vd donde insertar
    int MatrizDispersaCSR::donde_insertar(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int lugar_antes = 0;
        for (int i = 1; i <= f - 1; i++) {
            lugar_antes += vf[i + 1] - vf[i];
        }

        int nuevo_lugar = lugar_antes;
        int lugar = lugar_antes;

        for (int i = 1; i <= vf[f + 1] - vf[f]; i++) {
            lugar = lugar_antes + i;
            if (c > vc[lugar])
                nuevo_lugar = lugar;
        }
        return nuevo_lugar + 1;
    }

    // pone o remplaza un elemento en la matriz (fila, columna, elemento)
    void MatrizDispersaCSR::poner(int f, int c, int elemento)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");

        int lugar = buscar_posicion_vd(f, c);
        if (lugar > 0) {
            vd[lugar] = elemento;
            if (vd[lugar] == repe) {
                for (int i = lugar; i < nt; i++) {
                    vd[i] = vd[i + 1];
                    vc[i] = vc[i + 1];
                }
                for (int i = f; i <= df + 1; i++) {
                    vf[i]--;
                }
                nt--;
            }
        } else {
            if (elemento != repe) {
                int pos = donde_insertar(f, c);
                for (int i = nt; i >= pos; i--) {
                    vd[i] = vd[i - 1];
                    vc[i] = vc[i - 1];
                }
                vd[pos] = elemento;
                vc[pos] = c;
                nt++;
                for (int i = f + 1; i <= df + 1; i++)
                    vf[i]++;
            }
        }
    }

    // devuelve el elemento (fila, columna)
    int MatrizDispersaCSR::elemento(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw new Exception("Indices fuera de rango!!");
        int lugar = buscar_posicion_vd(f, c);
        return lugar < 1 ? repe : vd[lugar];
    }

    int MatrizDispersaCSR::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaCSR::dimension_columna()
    {
        return dc;
    }

    // verifica si hay el elemento especificado en la matriz
    bool MatrizDispersaCSR::hay(int elemento)
    {
        for (int i = 1; i <= nt; i++)
            if (vd[i] == elemento)
                return true;
        return false;
    }

    // define y redefine la matriz con un nuevo valor repetido
    void MatrizDispersaCSR::definir_valor_repetido(int elemento)
    {
        if (nt == 0 || !hay(elemento)) {
            repe = elemento;
        } else {
            for (int i = 1; i <= df; i++) {
                for (int j = 1; j <= dc; j++) {
                    int el = this->elemento(i, j);
                    if (el == elemento) {
                        int lugar = buscar_posicion_vd(i, j);
                        for (int k = lugar; k < nt; k++) {
                            vd[k] = vd[k + 1];
                            vc[k] = vc[k + 1];
                        }
                        for (int k = i; k <= df + 1; k++)
                            vf[k]--;
                        nt--;
                    } else if (el == repe) {
                        int pos = donde_insertar(i, j);
                        for (int k = nt; k > pos; k--) {
                            vd[k] = vd[k - 1];
                            vc[k] = vc[k - 1];
                        }
                        vd[pos] = elemento;
                        vc[pos] = j;
                        nt++;
                        for (int k = i; k <= df + 1; k++)
                            vf[k]++;
                    }
                }
            }
            repe = elemento;
        }
    }

    std::string MatrizDispersaCSR::mostrar()
    {
        std::string s = "";
        for (int f = 1; f <= df; f++) {
            for (int c = 1; c <= dc; c++) {
                s += std::to_string(elemento(f, c)) + "\t";
            }
            s += "\r\n";
        }

        std::stringstream info;
        info << "\n-----------------------------------\n";
        info << "nt = " << std::to_string(nt) << "\n";
        info << "df = " << std::to_string(df) << "\n";
        info << "dc = " << std::to_string(dc) << "\n";
        info << "repe = " << std::to_string(repe) << "\n";

        int n = df * dc;
        std::string r;
        r += "vd: ";
        for (int i = 1; i <= n; i++) {
            r += std::to_string(vd[i]);
            r += i < n ? "," : "";
        }
        r += "\nvc: ";
        for (int i = 1; i <= n; i++) {
            r += std::to_string(vc[i]);
            r += i < n ? "," : "";
        }
        r += "\nvf: ";
        for (int i = 1; i <= df + 1; i++) {
            r += std::to_string(vf[i]);
            r += i < n ? "," : "";
        }
        info << r;
        return s + info.str();
    }

    MatrizDispersaCSR::~MatrizDispersaCSR()
    {
        delete[] vf, vc, vd;
    }
    void MatrizDispersaCSR::dibujar_celda(TForm* Form, TColor brushColor,
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

    void MatrizDispersaCSR::graficar_matriz_dispersa(
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

    int suma(MatrizDispersaCSR* m)
    {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++) {
            for (int c = 1; c <= m->dimension_columna(); c++) {
                int el = m->elemento(f, c);
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }

    void transpuesta(MatrizDispersaCSR* m, MatrizDispersaCSR* m1)
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

    bool es_simetrica(MatrizDispersaCSR* m)
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
} // namespace UMatrizDispersaCSR

