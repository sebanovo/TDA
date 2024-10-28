//---------------------------------------------------------------------------

#ifndef PilaPunteroH
#define PilaPunteroH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaPuntero
{
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
        void sacar(int* e);
        int cima();
        std::string mostrar();
        ~PilaPuntero();
    };
}; // namespace UPilaPuntero
#endif
