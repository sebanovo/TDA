//---------------------------------------------------------------------------

#ifndef PilaVectorH
#define PilaVectorH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaVector
{
    const int TamanoCelda = 50;
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
        void sacar(int* e);
        int cima();
        std::string mostrar();
        ~PilaVector();

        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
            int posX, int posY, String cad);
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaVector

#endif

