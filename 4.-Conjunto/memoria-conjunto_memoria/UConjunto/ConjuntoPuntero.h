//---------------------------------------------------------------------------

#ifndef ConjuntoPunteroH
#define ConjuntoPunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UConjuntoPuntero
{
    struct Nodo
    {
        int dato;
        Nodo* sig;
    };

    class ConjuntoPuntero
    {
      private:
        Nodo* PtrConj;
        int cant;
      public:
        ConjuntoPuntero();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoPuntero();
        std::string mostrar();
    };

    void _union();
    void _interseccion();
    void _equivalentes();

    void _union(ConjuntoPuntero* a, ConjuntoPuntero* b, ConjuntoPuntero* c);
    void _interseccion(
        ConjuntoPuntero* a, ConjuntoPuntero* b, ConjuntoPuntero* c);
    bool _equivalentes(ConjuntoPuntero* a, ConjuntoPuntero* b);
} // namespace UConjuntoPuntero
#endif
