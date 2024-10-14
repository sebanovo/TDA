//---------------------------------------------------------------------------

#pragma hdrstop
#include <sstream>
#include "MatrizDispersaVector.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UMatrizDispersaVector
{
    MatrizDispersaVector::MatrizDispersaVector()
    {
        df = dc = nt = repe = 0;
        vf = new int[MAX];
        vc = new int[MAX];
        vd = new int[MAX];

        for (int i = 1; i < MAX; i++) {
            vf[i] = repe;
            vc[i] = 0;
            vd[i] = 0;
        }
    }

    // dimensionar la fila y la columna
    void MatrizDispersaVector::dimensionar(int f, int c)
    {
        if (f * c > MAX)
            throw std::runtime_error("Memoria insuficiente");
        df = f;
        dc = c;
    }

    // busca la posicion de la fila y la columna
    int MatrizDispersaVector::buscar_posicion_vd(int f, int c)
    {
        for (int i = 1; i <= nt; i++) {
            if (vf[i] == f && vc[i] == c)
                return i;
        }
        return 0;
    }

    // pone o remplaza un elemento en la matriz (fila, columna, elemento)
    void MatrizDispersaVector::poner(int f, int c, int elemento)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw std::runtime_error("Indices fuera de rango!!");

        int lugar = buscar_posicion_vd(f, c);
        if (lugar > 0) {
            vd[lugar] = elemento;
            if (vd[lugar] == repe) {
                for (int i = lugar; i < nt; i++) {
                    vf[i] = vf[i + 1];
                    vc[i] = vc[i + 1];
                    vd[i] = vd[i + 1];
                }
                nt--;
            }
        } else if (lugar == 0 && nt < df * dc) {
            if (elemento != repe) {
                nt++;
                vf[nt] = f;
                vc[nt] = c;
                vd[nt] = elemento;
            }
        } else {
            throw std::runtime_error("No hay espacio");
        }
    }

    // devuelve el elemento (fila, columna)
    int MatrizDispersaVector::elemento(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw std::runtime_error("Indices fuera de rango!!");
        int lugar = buscar_posicion_vd(f, c);
        return lugar < 1 ? repe : vd[lugar];
    }

    int MatrizDispersaVector::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaVector::dimension_columna()
    {
        return dc;
    }

    // verifica si hay el elemento especificado en la matriz
    bool MatrizDispersaVector::hay(int elemento)
    {
        for (int i = 1; i <= nt; i++)
            if (vd[i] == elemento)
                return true;
        return false;
    }

    // define y redefine la matriz con un nuevo valor repetido
    void MatrizDispersaVector::definir_valor_repetido(int elemento)
    {
        if (nt == 0 || !hay(elemento))
            return (void)(repe = elemento);
        for (int i = 1; i <= df; i++) {
            for (int j = 1; j <= dc; j++) {
                int el = this->elemento(i, j);

                if (el == elemento) {
                    int lugar = buscar_posicion_vd(i, j);
                    for (int k = lugar; k <= nt; k++) {
                        vf[k] = vf[k + 1];
                        vc[k] = vc[k + 1];
                        vd[k] = vd[k + 1];
                    }
                    nt--;
                } else if (el == repe) {
                    nt++;
                    vd[nt] = repe; // aquí mirar si es repe o elemento
                    vf[nt] = i;
                    vc[nt] = j;
                }
            }
        }
        repe = elemento;
    }

    std::string MatrizDispersaVector::mostrar()
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
        for (int i = 1; i <= n; i++) {
            r += std::to_string(vf[i]);
            r += i < n ? "," : "";
        }
        info << r;
        return s + info.str();
    }

    MatrizDispersaVector::~MatrizDispersaVector()
    {
        delete[] vf, vc, vd;
    }

    int suma(MatrizDispersaVector* m)
    {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++) {
            for (int c = 1; c <= m->dimension_columna(); c++) {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }

    void transpuesta(MatrizDispersaVector* m, MatrizDispersaVector* m1)
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

    bool es_simetrica(MatrizDispersaVector* m)
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
} // namespace UMatrizDispersaVector

