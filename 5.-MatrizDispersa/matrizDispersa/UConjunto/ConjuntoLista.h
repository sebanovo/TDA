//---------------------------------------------------------------------------

#ifndef ConjuntoListaH
#define ConjuntoListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "ULista/ListaSM.h"
#include "ULista/ListaVector.h"

// Conjunto LISTA
// SOLO FUNCIONA PARA UNA (LISTA SM) Y (LISTA VECTOR)

namespace UConjuntoLista
{
    class ConjuntoLista
    {
      private:
        // UListaVector::ListaVector* elem;
        UListaSM::ListaSM* elem;
        UCSMemoria::CSMemoria* mem;
      public:
        ConjuntoLista();
        ConjuntoLista(UCSMemoria::CSMemoria* m);
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoLista();
        std::string mostrar();

        void dibujar_conjunto(TForm* Form, int posX, int posY);
        void graficar_conjunto(TForm* Form, int centroX, int centroY, int radio,
            std::string nombre);

        // ejercicios
        static void _union(
            ConjuntoLista* a, ConjuntoLista* b, ConjuntoLista* c);
        static void _interseccion(
            ConjuntoLista* a, ConjuntoLista* b, ConjuntoLista* c);
        static bool _equivalentes(ConjuntoLista* a, ConjuntoLista* b);
    };
} // namespace UConjuntoLista
#endif

