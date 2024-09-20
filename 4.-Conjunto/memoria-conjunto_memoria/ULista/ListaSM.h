//---------------------------------------------------------------------------

#ifndef ListaSMH
#define ListaSMH
//---------------------------------------------------------------------------
#include <string>

#include "UCSMemoria/CSMemoria.h"

namespace UListaSM
{
    using std::string;
    const string elemento_sig = "elemento,sig";
    const string elemento = "->elemento";
    const string sig = "->sig";

    class ListaSM
    {
      private:
        int PtrElementos;
        int longitud;
        UCSMemoria::CSMemoria* mem;
      public:
        ListaSM();
        ListaSM(UCSMemoria::CSMemoria* m);
        int fin();
        int primero();
        int siguiente(int dir);
        int anterior(int dir);
        bool vacia();
        int recupera(int dir);
        int _longitud();
        void inserta(int dir, int element);
        void inserta_primero(int element);
        void inserta_ultimo(int element);
        void suprime(int dir);
        void modifica(int dir, int element);
        string mostrar();
        ~ListaSM();

        // extra
        int localiza(int element);
        void elimina_dato(int element);
        void anula();

        bool es_direccion_valida(int dir);

        // dibujar
        void dibujar_lista(TForm* Form, int posX, int posY);

        // ejercicio
        void bubble_sort();
    };

} // namespace UListaSM

#endif

