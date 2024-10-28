//---------------------------------------------------------------------------

#ifndef PolinomioVectorH
#define PolinomioVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UPolinomioVector
{
    using std::string;
    class PolinomioVector
    {
      private:
        const int MAX = 100;
        int* vc;
        int* ve;
        int nt;
      public:
        PolinomioVector();
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioVector* p1, PolinomioVector* p2);
        void restar(PolinomioVector* p1, PolinomioVector* p2);
        void multiplicar(PolinomioVector* p1, PolinomioVector* p3);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioVector();
        double evaluar(double x);

        // extra
        int buscar_exponente(int exp);

        // graficar
        void graficar(TForm* Form, int posX, int posY, int ancho, int alto);
        void dibujar_polinomio(TForm* Form, int posX, int posY);
        void graficar_image(TImage* Image, double a, double b);
        void graficar_integral(TImage* Image, double a, double b);

        // ejercicios
        static void derivada(PolinomioVector* p, PolinomioVector* p1);
        static string mostrar_integral(PolinomioVector* p);

        static std::string intersectar(
            PolinomioVector* p1, PolinomioVector* p2, int a, int b);
        static void graficar_interseccion(TImage* Image, PolinomioVector* p1,
            PolinomioVector* p2, double a, double b);
    };
} // namespace UPolinomioVector

#endif

