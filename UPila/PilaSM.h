//---------------------------------------------------------------------------

#ifndef PilaSMH
#define PilaSMH
//---------------------------------------------------------------------------
#include <string>
#include "UCSMemoria/CSMemoria.h"

namespace UPilaSM
{
    const int TamanoCelda = 100;

    const std::string _elemento_sig = "elemento,sig";
    const std::string _elemento = "->elemento";
    const std::string _sig = "->sig";

    class PilaSM
    {
      private:
        int tope;
        UCSMemoria::CSMemoria* mem;
      public:
        PilaSM();
        PilaSM(UCSMemoria::CSMemoria* m);
        bool vacia();
        void meter(int e);
        void sacar(int &e);
        int cima();
        std::string mostrar();
        ~PilaSM();

        // graficar
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaSM
#endif

