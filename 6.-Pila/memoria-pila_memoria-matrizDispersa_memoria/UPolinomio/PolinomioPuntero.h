//---------------------------------------------------------------------------

#ifndef PolinomioPunteroH
#define PolinomioPunteroH
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
        void sumar(PolinomioPuntero* p1, PolinomioPuntero* p2);
        void restar(PolinomioPuntero* p1, PolinomioPuntero* p2);
        void multiplicar(PolinomioPuntero* p1, PolinomioPuntero* p2);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        double evaluar(double x);
        string mostrar();
        ~PolinomioPuntero();

        // graficar
        void graficar(TForm* Form, int posX, int posY, int ancho, int alto);
        void dibujar_polinomio(TForm* Form, int posX, int posY);
        void graficar_image(TImage* Image, double a, double b);
        void graficar_integral(TImage* Image, double a, double b);

        // ejercicios
        static void derivada(PolinomioPuntero* p, PolinomioPuntero* p1);
        static std::string mostrar_integral(PolinomioPuntero* p);

        static std::string intersectar(
            PolinomioPuntero* p1, PolinomioPuntero* p2, int a, int b);
        static void graficar_interseccion(TImage* Image, PolinomioPuntero* p1,
            PolinomioPuntero* p2, double a, double b);
    };

} // namespace UPolinomioPuntero
#endif

