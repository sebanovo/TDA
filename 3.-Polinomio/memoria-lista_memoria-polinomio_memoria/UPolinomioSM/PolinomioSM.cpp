
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioSM.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioSM
{
    using std::runtime_error;
    using std::string;
    using std::to_string;
    using UCSMemoria::NULO;

    PolinomioSM::PolinomioSM()
    {
        nt = 0;
        PtrPoli = NULO;
        mem = new UCSMemoria::CSMemoria();
    }

    PolinomioSM::PolinomioSM(UCSMemoria::CSMemoria* m)
    {
        nt = 0;
        PtrPoli = UCSMemoria::NULO;
        mem = m;
    }

    // devuelve la direccion del termino del exponente (osea un nodo)
    int PolinomioSM::buscar_exponente(int exp)
    {
        int dir = PtrPoli;
        int dirEx = NULO;

        if (dir == NULO)
            return NULO; // exception

        while (dir != NULO) {
            if (mem->obtener_dato(dir, _exp) == exp)
                return dir;
            dir = mem->obtener_dato(dir, _sig);
        }
        return dirEx;
    }

    // devuelve la direccion donde esta el termino n (osea el nodo)
    int PolinomioSM::buscar_termino_n(int n)
    {
        int dir = PtrPoli;
        int dirTer = NULO;

        if (dir == NULO)
            return NULO; // exception

        int Nt = 0;
        while (dir != NULO) {
            Nt = Nt + 1;
            if (Nt == n)
                return dir;

            dir = mem->obtener_dato(dir, _sig);
        }
        return dirTer;
    }

    bool PolinomioSM::es_cero()
    {
        return nt == 0;
    }

    // devuelve el grado del polinomio
    int PolinomioSM::grado()
    {
        int dir = PtrPoli;
        if (dir == NULO)
            return -1; // exception

        int gradoMax = mem->obtener_dato(dir, _sig);
        while (dir != NULO) {
            if (mem->obtener_dato(dir, _exp) > gradoMax)
                gradoMax = mem->obtener_dato(dir, _exp);
            dir = mem->obtener_dato(dir, _sig);
        }
        return gradoMax;
    }

    // devuelve el coeficiente del exponente del termino
    int PolinomioSM::coeficiente(int exp)
    {
        int dir = buscar_exponente(exp);
        if (dir == NULO)
            return -1; // exception
        return mem->obtener_dato(dir, _coef);
    }

    // P1 + P2
    void PolinomioSM::sumar(PolinomioSM p1, PolinomioSM p2)
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

    // P1 - P2
    void PolinomioSM::restar(PolinomioSM p1, PolinomioSM p2)
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

    // P2 * P2
    void PolinomioSM::multiplicar(PolinomioSM p1, PolinomioSM p2)
    {
        // = (2x + 1) * (3x + 3)
        // = 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
        // = 6x^2 + 9x + 3
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

    // pone un termino con su coeficiente y su exponente
    void PolinomioSM::poner_termino(int coef, int exp)
    {
        int existe = buscar_exponente(exp);
        if (existe == NULO) { //
            int aux = mem->new_espacio(_coef_exp_sig);
            if (aux != NULO) {
                mem->poner_dato(aux, _coef, coef);
                mem->poner_dato(aux, _exp, exp);
                mem->poner_dato(aux, _sig, PtrPoli);
                PtrPoli = aux;
                nt++;
            } else {
                throw std::runtime_error("Error de espacio de memoria");
            }
        } else {
            mem->poner_dato(
                existe, _coef, mem->obtener_dato(existe, _coef) + coef);
        }
    }

    int PolinomioSM::numero_terminos()
    {
        return nt;
    }

    // devuelve el exponente
    int PolinomioSM::exponente(int nroTer)
    {
        int dir = buscar_termino_n(nroTer);
        return dir == NULO
                   ? mem->obtener_dato(dir, _exp)
                   : throw std::runtime_error("No existe este exponente");
    }

    // cambia el coeficiente indicando el termino con el exponente asociado
    void PolinomioSM::asignar_coeficiente(int coef, int exp)
    {
        int dir = buscar_exponente(exp);
        if (dir != NULO) {
            mem->poner_dato(dir, _coef, coef);
            if (coef == 0) {
                int aux = dir;
                dir = mem->obtener_dato(dir, _sig);
                mem->delete_espacio(aux);
            }
        } else {
            throw std::runtime_error("No existe ese término");
        }
    }

    string PolinomioSM::mostrar()
    {
        int x = PtrPoli;
        string s = "";

        while (x != NULO) {
            s += mem->obtener_dato(x, _coef) >= 0 && s != "" ? "+" : "";
            s += std::to_string(mem->obtener_dato(x, _coef)) + "x^" +
                 std::to_string(mem->obtener_dato(x, _exp)) + "  ";
            x = mem->obtener_dato(x, _sig);
        }
        return s;
    }

    PolinomioSM::~PolinomioSM()
    {
        delete mem;
    }

    void derivada(PolinomioSM p, PolinomioSM p1)
    {
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int coef = p.coeficiente(exp);
            p1.poner_termino(coef * exp, exp - 1);
        }
    }

    std::string mostrar_integral(PolinomioSM p)
    {
        std::string s = "";
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int co = p.coeficiente(exp);

            s += "(" + std::to_string(co) + "x^" + std::to_string(exp + 1) +
                 ")/" + std::to_string(exp + 1) + " + ";
            if (i == p.numero_terminos())
                s += "C";
        }
        return s;
    }
} // namespace UPolinomioSM

