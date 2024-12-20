//---------------------------------------------------------------------------

#ifndef PilaVectorH
#define PilaVectorH
//---------------------------------------------------------------------------
#include <string>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <sstream>

namespace UPilaVector
{
    const int TamanoCelda = 100;
    class PilaVector
    {
      private:
        const int MAX = 1000;
        int* elementos;
        int tope;
      public:
        PilaVector();
        bool vacia();
        void meter(int e);
        void sacar(int &e);
        int cima();
        std::string mostrar();
        ~PilaVector();

        // graficar
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaVector
#endif

