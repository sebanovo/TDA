//---------------------------------------------------------------------------

#ifndef ColaVectorV2H
#define ColaVectorV2H
//---------------------------------------------------------------------------
#include <string>

namespace UColaVectorV2
{
    class ColaVectorV2
    {
      private:
        const int MAX = 1000;
        int* v;
        int ini, fin;
      public:
        ColaVectorV2();
        bool vacia();
        void poner(int e);
        void sacar(int &e);
        int primero();
        std::string mostrar();
        ~ColaVectorV2();

        // metodos para la dicola
        int ultimo();
        void poner_frente(int e);
        void sacar_final(int &e);

        // ejercicio
        static void concatenar(
            ColaVectorV2* c1, ColaVectorV2* c2, ColaVectorV2* c3);

        void graficar_cola(TForm* Form, int posX, int posY);
    };
}; // namespace UColaVectorV2
#endif

