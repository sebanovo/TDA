//---------------------------------------------------------------------------

#ifndef PilaCadenaH
#define PilaCadenaH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaCadena
{
    class PilaCadena
    {
      private:
        std::string datos;
      public:
        PilaCadena();
        bool vacia();
        void meter(int e);
        void sacar(int* e);
        int cima();
        std::string mostrar();
        ~PilaCadena() = default;
    };
}; // namespace UPilaCadena

#endif

