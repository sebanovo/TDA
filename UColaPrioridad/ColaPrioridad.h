// ---------------------------------------------------------------------------

#ifndef ColaPrioridadH
#define ColaPrioridadH
// ---------------------------------------------------------------------------
#include <string>
#include "UCola/ColaSM.h"
#include "UCSMemoria/CSMemoria.h"

namespace UColaPrioridad
{
    class ColaPrioridad
    {
      private:
        const int MAX = 3;
        UColaSM::ColaSM*(*vc);
        int* vf;
        int colaAct;
        int cant;
      public:
        ColaPrioridad();
        ColaPrioridad(UCSMemoria::CSMemoria* m);
        bool vacia();
        int primero();
        void poner(int e, int prioridad);
        void asignar_frecuencia_prioridad(int frec, int prioridad);
        void sacar(int &e);
        std::string mostrar();

        ~ColaPrioridad();

        void graficar_cola_prioridad(TForm* Form, int posX, int posY);
    };
} // namespace UColaPrioridad
#endif

