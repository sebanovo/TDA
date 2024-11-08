//---------------------------------------------------------------------------

#ifndef ColaVectorV3H
#define ColaVectorV3H
//---------------------------------------------------------------------------
#include <string>

namespace UColaVectorV3
{
    class ColaVectorV3
    {
      private:
        const int MAX = 1000;
        int* v;
        int ini, fin;
        int siguiente(int dir);
        int anterior(int dir);
      public:
        ColaVectorV3();
        bool vacia();
        void poner(int e);
        void sacar(int &e);
        int primero();
        std::string mostrar();
        ~ColaVectorV3();

        // metodos para la dicola
        int ultimo();
        void poner_frente(int e);
        void sacar_final(int &e);

        // ejercicio
        static void concatenar(
            ColaVectorV3* c1, ColaVectorV3* c2, ColaVectorV3* c3);

        void graficar_cola(TForm* Form, int posX, int posY);
    };
}; // namespace UColaVectorV3
#endif

