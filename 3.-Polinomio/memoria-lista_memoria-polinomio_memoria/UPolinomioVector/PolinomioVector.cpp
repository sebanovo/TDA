//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioVector.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioVector
{
    using std::to_string;
    PolinomioVector::PolinomioVector()
    {
        nt = 0;
        vc = new int[MAX];
        ve = new int[MAX];
    }

    // verifica si no hay terminos
    bool PolinomioVector::es_cero()
    {
        return nt == 0;
    }

    // obtiene el grado del polinomio
    int PolinomioVector::grado()
    {
        // if (nt <= 0)
        //     throw new Exception("No existen terminos");
        int max = ve[1];
        for (int i = 1; i <= nt; i++) {
            if (ve[i] > max)
                max = ve[i];
        }
        return max;
    }

    // devuelve el coeficiente asociado a ese exponente
    int PolinomioVector::coeficiente(int exp)
    {
        for (int i = 1; i <= nt; i++) {
            if (ve[i] == exp)
                return vc[i];
        }
        return 0;
    }

    void PolinomioVector::sumar(PolinomioVector p1, PolinomioVector p2)
    {
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            int exp = p1.exponente(i);
            int coef = p1.coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2.numero_terminos(); i++) {
            int exp = p2.exponente(i);
            int coef = p2.coeficiente(exp);
            poner_termino(coef, exp);
        }
    }

    void PolinomioVector::restar(PolinomioVector p1, PolinomioVector p2)
    {
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            int exp = p1.exponente(i);
            int coef = p1.coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2.numero_terminos(); i++) {
            int exp = p2.exponente(i);
            int coef = p2.coeficiente(exp) * -1;
            poner_termino(coef, exp);
        }
    }

    void PolinomioVector::multiplicar(PolinomioVector p1, PolinomioVector p2)
    {
        // P1 * P2 = (2x + 1) * (3x + 3)
        // 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
        // 6x^2 + 9x + 3
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            for (int j = 1; j <= p2.numero_terminos(); j++) {
                int exp1 = p1.exponente(i);
                int coef1 = p1.coeficiente(exp1);

                int exp2 = p2.exponente(j);
                int coef2 = p2.coeficiente(exp2);

                poner_termino(coef1 * coef2, exp1 + exp2);
            }
        }
    }

    // retorna la direccion del exponenete
    int PolinomioVector::buscar_exponente(int exp)
    {
        for (int i = 1; i <= nt; i++) {
            if (ve[i] == exp)
                return i;
        }
        return -1;
    }

    // pone un termino al polinomio
    void PolinomioVector::poner_termino(int coef, int exp)
    {
        int dir_exp = buscar_exponente(exp);
        if (dir_exp == -1) {
            if (coef != 0) {
                vc[nt + 1] = coef;
                ve[nt + 1] = exp;
                nt++;
            }
        } else {
            vc[dir_exp] = coef + vc[dir_exp];
            if (vc[dir_exp] == 0) {
                for (int i = dir_exp; i < nt; i++) {
                    vc[i] = vc[i + 1];
                    ve[i] = ve[i + 1];
                }
                nt--;
            }
        }
    }

    // devuelve el número de terminos
    int PolinomioVector::numero_terminos()
    {
        return nt;
    }

    // devuelvo el exponente asociado al nro de termino
    int PolinomioVector::exponente(int nroTer)
    {
        // if (nroTer < 0 || nroTer > MAX)
        //     new Exception("Fuera de los límites");
        return ve[nroTer];
    }

    // cambia el coeficiente del termino
    void PolinomioVector::asignar_coeficiente(int coef, int exp)
    {
        int dir = buscar_exponente(exp);
        if (dir != -1) {
            vc[dir] = coef;
            if (vc[dir] == 0) {
                for (int i = dir; i < numero_terminos(); i++) {
                    vc[i] = vc[i + 1];
                    ve[i] = ve[i + 1];
                }
            }
        } else {
            throw new Exception("No existe ese exponente");
        }
    }

    // muestra el polinomio
    string PolinomioVector::mostrar()
    {
        string s = "";
        for (int i = 1; i <= nt; i++) {
            s += vc[i] >= 0 && s != "" ? "+" : "";
            s += to_string(vc[i]) + "x^" + to_string(ve[i]) + "  ";
        }
        return s;
    }

    PolinomioVector::~PolinomioVector()
    {
        delete[] vc;
        delete[] ve;
    }

    int PolinomioVector::evaluar(int x)
    {
        int resultado = 0;
        for (int i = 1; i <= numero_terminos(); i++) {
            int coe = vc[i];
            int exp = ve[i];
            resultado += coe * std::pow(x, exp);
        }
        return resultado;
    }

    void derivada(PolinomioVector p, PolinomioVector p1)
    {
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int co = p.coeficiente(exp);
            p1.poner_termino(co * exp, exp - 1);
        }
    }

    string mostrar_integral(PolinomioVector p)
    {
        string s = "";
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int co = p.coeficiente(exp);

            s += "(" + to_string(co) + "x^" + to_string(exp + 1) + ")/" +
                 to_string(exp + 1) + " + ";
            if (i == p.numero_terminos())
                s += "C";
        }
        return s;
    }

} // namespace UPolinomioVector

