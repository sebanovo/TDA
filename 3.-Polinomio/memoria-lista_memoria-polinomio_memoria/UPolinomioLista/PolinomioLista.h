//---------------------------------------------------------------------------

#ifndef PolinomioListaH
#define PolinomioListaH
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
        UListaSM::ListaSM* ls;
        UCSMemoria::CSMemoria* mem;
        // UListaVector::ListaVector* ls;
      public:
        PolinomioLista();
        PolinomioLista(UCSMemoria::CSMemoria* m);
        int buscar_exponente(int exp);
        int buscar_termino_n(int n);
        void crear(UCSMemoria::CSMemoria* m);
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
        int evaluar(int x);
        ~PolinomioLista();

        void dibujar_polinomio(TForm* Form, int posX, int posY);

        void graficar(TForm* Form, int x0, int y0, int ancho, int alto);
    };

    void derivar(PolinomioLista* poli, PolinomioLista* poli1);
} // namespace UPolinomioLista
#endif

