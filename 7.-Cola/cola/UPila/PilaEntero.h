//---------------------------------------------------------------------------

#ifndef PilaEnteroH
#define PilaEnteroH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaEntero
{
    const int TamanoCelda = 100;
    class PilaEntero
    {
      private:
        int datos;
      public:
        PilaEntero();
        bool vacia();
        void meter(int e);
        void sacar(int &e);
        int cima();
        std::string mostrar();
        ~PilaEntero() = default;

        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
            int posX, int posY, String cad);
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaEntero
#endif

