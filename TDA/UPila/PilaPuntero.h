//---------------------------------------------------------------------------

#ifndef PilaPunteroH
#define PilaPunteroH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaPuntero
{
    const int TamanoCelda = 100;
    struct Nodo
    {
        int elemento;
        Nodo* sig;
    };

    class PilaPuntero
    {
      private:
        Nodo* tope;
      public:
        PilaPuntero();
        bool vacia();
        void meter(int e);
        void sacar(int &e);
        int cima();
        std::string mostrar();
        ~PilaPuntero();

        // graficar
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaPuntero
#endif

