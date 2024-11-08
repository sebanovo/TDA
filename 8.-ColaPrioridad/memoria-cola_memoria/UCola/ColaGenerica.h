//---------------------------------------------------------------------------

#ifndef ColaGenericaH
#define ColaGenericaH
//---------------------------------------------------------------------------
#include <string>

namespace UColaGenerica
{
    template<typename T>
    class ColaGenerica
    {
      private:
        const int MAX = 1000;
        T* v;
        int ini, fin;
      public:
        ColaGenerica();
        bool vacia();
        void poner(T e);
        void sacar(T &e);
        T primero();
        std::string mostrar();
        ~ColaGenerica();

        // metodos para la dicola
        T ultimo();
        void poner_frente(T e);
        void sacar_final(T &e);

        // ejercicio
        template<typename U>
        static void concatenar(
            ColaGenerica<U>* c1, ColaGenerica<U>* c2, ColaGenerica<U>* c3);

        void graficar_cola(TForm* Form, int posX, int posY);
    };

}; // namespace UColaGenerica

#endif

