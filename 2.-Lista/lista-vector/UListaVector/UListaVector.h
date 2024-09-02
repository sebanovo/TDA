//---------------------------------------------------------------------------

#ifndef UListavectorH
#define UListavectorH
//---------------------------------------------------------------------------
#include <string>

namespace UListaVector
{
    using std::string;
    typedef int direccion;
    class ListaVector
    {
      private:
        static constexpr int MAX = 100;
        int elementos[MAX];
        int longitud;
      public:
        ListaVector();
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

        // extra
        direccion localiza(int element);
        void elimina_dato(int element);
        void anula();

        // dibujar
        void dibujar_lista(TForm* Form, int posX, int posY);
    };
} // namespace UListaVector
#endif

