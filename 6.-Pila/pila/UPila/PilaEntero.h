//---------------------------------------------------------------------------

#ifndef PilaEnteroH
#define PilaEnteroH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaEntero
{
    class PilaEntero
    {
      private:
        int datos;
      public:
        PilaEntero();
        bool vacia();
        void meter(int e);
        void sacar(int* e);
        int cima();
        std::string mostrar();
        ~PilaEntero() = default;
    };
}; // namespace UPilaEntero
#endif
