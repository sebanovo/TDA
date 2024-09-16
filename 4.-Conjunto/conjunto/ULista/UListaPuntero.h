//---------------------------------------------------------------------------

#ifndef UListapunteroH
#define UListapunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UListaPuntero
{
    using std::runtime_error;
    using std::string;

    struct Nodo;
    typedef Nodo* direccion;
    struct Nodo
    {
      public:
        int elemento;
        Nodo* sig;
    };

    class ListaPuntero
    {
      private:
        direccion PtrElementos;
        int longitud;
      public:
        ListaPuntero();
        direccion fin();
        direccion primero();
        direccion siguiente(direccion dir);
        direccion anterior(direccion dir);
        bool vacia();
        int recupera(direccion dir);
        int _longitud();
        void inserta(direccion dir, int element);
        void inserta_primero(int element);
        void inserta_ultimo(int element);
        void suprime(direccion dir);
        void modifica(direccion dir, int element);
        string mostrar();
        ~ListaPuntero();

        // extra
        direccion localiza(int element);
        void elimina_dato(int element);
        void anula();

        bool es_direccion_valida(direccion dir);

        // ejercicios
        void bubble_sort();

        void dibujar_lista(TForm* Form, int posX, int posY);
    };

} // namespace UListaPuntero
#endif

