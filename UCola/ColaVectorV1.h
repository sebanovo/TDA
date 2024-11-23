//---------------------------------------------------------------------------

#ifndef ColaVectorV1H
#define ColaVectorV1H
//---------------------------------------------------------------------------
#include <string>

namespace UColaVectorV1
{
    class ColaVectorV1
    {
      private:
        const int MAX = 1000;
        int* v;
        int ini, fin;
      public:
        ColaVectorV1();
        bool vacia();
        void poner(int e);
        void sacar(int &e);
        int primero();
        std::string mostrar();
        ~ColaVectorV1();

        // metodos para la dicola
        int ultimo();
        void poner_frente(int e);
        void sacar_final(int &e);

        // ejercicio
        static void concatenar(
            ColaVectorV1* c1, ColaVectorV1* c2, ColaVectorV1* c3);

        void graficar_cola(TForm* Form, int posX, int posY);
    };
}; // namespace UColaVectorV1
#endif

