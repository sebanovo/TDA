
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioSM.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioSM
{
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

    int PolinomioSM::buscar_exponente(int exp)
    {
        int dir = PtrPoli;
        int x;

        if (dir != NULO) {
            int dirEx = NULO;
            while ((dir != NULO) && (dirEx == NULO)) {
                if (mem->obtener_dato(dir, "->exp") == exp)
                    dirEx = dir;
                dir = mem->obtener_dato(dir, "->sig");
            }
            return dirEx;
        } else
            return NULO;
    }

    int PolinomioSM::buscar_termino_n(int n)
    {
        int Dir = PtrPoli;
        if (Dir != NULO) {
            int dirTer = NULO;
            int Nt = 0;
            while ((Dir != NULO) && (dirTer == NULO)) {
                Nt = Nt + 1;
                if (Nt == n) {
                    dirTer = Dir;
                }
                Dir = mem->obtener_dato(Dir, "->sig");
            }
            return dirTer;

        } else
            return NULO;
    }

    bool PolinomioSM::es_cero() {}
    int PolinomioSM::grado() {}
    int PolinomioSM::coeficiente(int exp)
    {
        int dir = buscar_exponente(exp);
        return dir == NULO ? mem->obtener_dato(dir, "->coef")
                           : throw new Exception("No existe este exponente");
    }
    void PolinomioSM::sumar(PolinomioSM p1, PolinomioSM p2) {}
    void PolinomioSM::restar(PolinomioSM p1, PolinomioSM p2) {}
    void PolinomioSM::multiplicar(PolinomioSM p1, PolinomioSM p3) {}
    void PolinomioSM::poner_termino(int coef, int exp)
    {
        int existe = buscar_exponente(exp);
        if (existe == NULO) { //
            int aux = mem->new_espacio("coef,exp,sig");
            if (aux != NULO) {
                mem->poner_dato(aux, "->coef", coef);
                mem->poner_dato(aux, "->exp", exp);
                mem->poner_dato(aux, "->sig", PtrPoli);
                PtrPoli = aux;

                nt = nt + 1;
            } else {
                throw new Exception("Error de espacio de memoria");
            }
        } else {
            int NuevoCoef = mem->obtener_dato(existe, "->coef") + coef;
            mem->poner_dato(existe, "->coef", NuevoCoef);
        }
    }
    int PolinomioSM::numero_terminos()
    {
        return nt;
    }
    int PolinomioSM::exponente(int nroTer)
    {
        int dir = buscar_termino_n(nroTer);
        return dir == NULO ? mem->obtener_dato(dir, "->exp")
                           : throw new Exception("No existe este exponente");
    }
    void PolinomioSM::asignar_coeficiente(int coef, int exp) {}
    string PolinomioSM::mostrar() {}
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
} // namespace UPolinomioSM

