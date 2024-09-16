//---------------------------------------------------------------------------

#ifndef UPolinomioVectorH
#define UPolinomioVectorH
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
        void dibujar_polinomio(TForm* Form, int posX, int posY);
        void graficar(TForm* Form, int posX, int posY, int ancho, int alto);
        void graficar_image(TImage* Image);

        void graficarIntegral(TImage* Image, double a, double b);
    };
    void derivada(PolinomioVector* p, PolinomioVector* p1);
    string mostrar_integral(PolinomioVector* p);
} // namespace UPolinomioVector

#endif

