// ---------------------------------------------------------------------------

#ifndef ColaSMH
#define ColaSMH
// ---------------------------------------------------------------------------
#include <string>
#include "UCSMemoria/CSMemoria.h"

namespace UColaSM
{
    const std::string _elemento_sig = "elemento,sig";
    const std::string _elemento = "->elemento";
    const std::string _sig = "->sig";

    class ColaSM
    {
      private:
        UCSMemoria::CSMemoria* mem;
        int ini, fin;
      public:
        ColaSM();
        ColaSM(UCSMemoria::CSMemoria* m);
        bool vacia();
        void poner(int e);
        void sacar(int &e);
        int primero();
        std::string mostrar();
        ~ColaSM();

        // metodos para la dicola
        int ultimo();
        void poner_frente(int e);
        void sacar_final(int &e);

        // ejercicio
        static void concatenar(ColaSM* c1, ColaSM* c2, ColaSM* c3);

        void graficar_cola(TForm* Form, int posX, int posY);
    };
}; // namespace UColaSM
#endif

