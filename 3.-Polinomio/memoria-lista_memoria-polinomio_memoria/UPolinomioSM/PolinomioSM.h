//---------------------------------------------------------------------------

#ifndef PolinomioSMH
#define PolinomioSMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "UCSMemoria/UCSMemoria.h"

namespace UPolinomioSM
{
    using std::string;

    const string _coef_exp_sig = "coef,exp,sig";
    const string _coef = "->coef";
    const string _exp = "->exp";
    const string _sig = "->sig";

    class PolinomioSM
    {
      private:
        int PtrPoli;
        UCSMemoria::CSMemoria* mem;
        int nt;
        int buscar_exponente(int exp);
        int buscar_termino_n(int n);
      public:
        PolinomioSM();
        PolinomioSM(UCSMemoria::CSMemoria* m);
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioSM p1, PolinomioSM p2);
        void restar(PolinomioSM p1, PolinomioSM p2);
        void multiplicar(PolinomioSM p1, PolinomioSM p3);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioSM();
    };
    void derivada(PolinomioSM p, PolinomioSM p1);
} // namespace UPolinomioSM
#endif

