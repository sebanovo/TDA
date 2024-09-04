//---------------------------------------------------------------------------

#ifndef UPolinomioPunteroH
#define UPolinomioPunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UPolinomioPuntero
{
    using std::string;
    struct Nodo;
    typedef Nodo* direccion;
    struct Nodo
    {
        int coef;
        int exp;
        Nodo* sig;
    };

    class PolinomioPuntero
    {
      private:
        direccion PtrPoli;
        int nt;
        direccion buscar_exponente(int exp);
        direccion buscar_termino_n(int n);
      public:
        PolinomioPuntero();
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioPuntero p1, PolinomioPuntero p2);
        void restar(PolinomioPuntero p1, PolinomioPuntero p2);
        void multiplicar(PolinomioPuntero p1, PolinomioPuntero p2);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioPuntero();
    };
    void derivada(PolinomioPuntero p, PolinomioPuntero p1);
} // namespace UPolinomioPuntero
#endif

