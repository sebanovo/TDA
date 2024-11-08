//---------------------------------------------------------------------------

#ifndef PilaCadenaH
#define PilaCadenaH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaCadena
{
    const int TamanoCelda = 100;
    class PilaCadena
    {
      private:
        std::string datos;
      public:
        PilaCadena();
        bool vacia();
        void meter(int e);
        void sacar(int &e);
        int cima();
        std::string mostrar();
        ~PilaCadena() = default;

        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
            int posX, int posY, String cad);
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaCadena

#endif

