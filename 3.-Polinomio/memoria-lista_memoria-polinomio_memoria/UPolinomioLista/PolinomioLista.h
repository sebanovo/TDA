//---------------------------------------------------------------------------

#ifndef UPolinomioListaH
#define UPolinomioListaH
//---------------------------------------------------------------------------
#include <UListaSM/UListaSM.h>
#include <UListaVector/UListaVector.h>

#include <iostream>
#include <string>

// ESTE POLINOMIO FUNCIONA USANDO UNA LISTASM O UN LISTA VECTOR

namespace UPolinomioLista
{
    class PolinomioLista
    {
      private:
        UCSMemoria::CSMemoria* mem;
        // UListaSM::ListaSM* ls;
        UListaVector::ListaVector* ls;

        int buscar_exponente(int exp);
        int buscar_termino_n(int n);
      public:
        PolinomioLista();
        PolinomioLista(UCSMemoria::CSMemoria* m);
        bool es_cero();
        int grado();
        void poner_en_cero();
        int coeficiente(int exp);
        void asignar_coeficiente(int coef, int exp);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTerm);
        void sumar(PolinomioLista* p1, PolinomioLista* p2);
        void restar(PolinomioLista* p1, PolinomioLista* p2);
        void multiplicar(PolinomioLista* P1, PolinomioLista* P2);
        double evaluar(double x);
        std::string mostrar();
        ~PolinomioLista();
        void dibujar_polinomio(TForm* Form, int posX, int posY);

        void graficar(TForm* Form, int posX, int posY, int ancho, int alto);
        void graficar_image(TImage* Image);

        void graficarIntegral(TImage* Image, double a, double b);
    };

    void derivada(PolinomioLista* p, PolinomioLista* p1);
    std::string mostrar_integral(PolinomioLista p);
} // namespace UPolinomioLista
#endif

