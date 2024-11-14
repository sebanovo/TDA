//---------------------------------------------------------------------------

#ifndef CSMemoriaH
#define CSMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include <tchar.h>
#include <iomanip>
#include <Graphics.hpp>

namespace UCSMemoria
{
    using std::string;
    //const int TamanoCelda = 20; // 20
    const int TamanoCeldaX = 80; // 100
    const int TamanoCeldaY = 30; // 40

    const int NULO = -1;

    struct Nodo
    {
        int dato = 0;
        string id;
        int link;
    };

    class CSMemoria
    {
      private:
        const int MAX = 1000;
        int libre;
        Nodo* mem;
      public:
        CSMemoria();
        // importantes
        int new_espacio(string cadena);
        void delete_espacio(int dir);
        void poner_dato(int dir, string id, int valor);
        int obtener_dato(int dir, string lugar);

        // relleno
        int espacio_disponible();
        int espacio_ocupado();
        bool dir_libre(int dir);
        void mostrar();
        ~CSMemoria();
      private:
        // metodos auxiliares
        int numero_ids(string id);
        string obtener_id(string cadena, int n);
        bool hay_al_menos_un_id(string cadena);
        string eliminar_flecha(string cadena);

        // metodos de dibujado
      public:
        void dibujar_memoria(TForm* Form, int posX, int posY, int a, int b);
    };
} // namespace UCSMemoria
#endif

