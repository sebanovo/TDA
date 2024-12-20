//---------------------------------------------------------------------------

#ifndef PolinomioSMH
#define PolinomioSMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "UCSMemoria/CSMemoria.h"

namespace UPolinomioSM {
    using std::string;

    const string _coef_exp_sig = "coef,exp,sig";
    const string _coef = "->coef";
    const string _exp = "->exp";
    const string _sig = "->sig";

    class PolinomioSM {
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
        void sumar(PolinomioSM* p1, PolinomioSM* p2);
        void restar(PolinomioSM* p1, PolinomioSM* p2);
        void multiplicar(PolinomioSM* p1, PolinomioSM* p3);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        double evaluar(double x);
        string mostrar();
        ~PolinomioSM();

        // graficar
        void graficar(TForm* Form, int posX, int posY, int ancho, int alto);
        void dibujar_polinomio(TForm* Form, int posX, int posY);
        void graficar_image(TImage* Image, double a, double b);
        void graficar_integral(TImage* Image, double a, double b);

        // ejercicios
        static void derivada(PolinomioSM* p, PolinomioSM* p1);
        static std::string mostrar_integral(PolinomioSM* p);

        static std::string intersectar(PolinomioSM* p1, PolinomioSM* p2, int a, int b);
        static void graficar_interseccion(
            TImage* Image, PolinomioSM* p1, PolinomioSM* p2, double a, double b);
    };
}  // namespace UPolinomioSM
#endif
