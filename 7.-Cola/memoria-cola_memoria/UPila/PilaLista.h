//---------------------------------------------------------------------------

#ifndef PilaListaH
#define PilaListaH
//---------------------------------------------------------------------------
#include <string>
#include "ULista/ListaVector.h"
#include "ULista/ListaSM.h"

// SOLO FUNCIONA CON SIMULADOR DE MEMORIA (SM) Y VECTOR

namespace UPilaLista
{
    const int TamanoCelda = 100;
    class PilaLista
    {
      private:
        // UListaSM::ListaSM* ls;
        // UCSMemoria::CSMemoria* mem;
        UListaVector::ListaVector* ls;
      public:
        PilaLista();
        PilaLista(UCSMemoria::CSMemoria* m);
        bool vacia();
        void meter(int e);
        void sacar(int &e);
        int cima();
        std::string mostrar();
        ~PilaLista();

        // graficar
        void graficar_pila(TForm* Form, int posX, int posY);
    };
}; // namespace UPilaLista
#endif

