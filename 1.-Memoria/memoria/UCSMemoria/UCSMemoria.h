//---------------------------------------------------------------------------

#ifndef UMemoriaH
#define UMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include <tchar.h>
#include <iomanip>
#include <Graphics.hpp>

using namespace std;

//const int TamanoCelda = 20; // 20
const int TamanoCeldaX = 75; // 40
const int TamanoCeldaY = 40; // 30

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
    const int MAX = 12;
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
    bool hay_un_id_repetido(string cadena);
    string eliminar_flecha(string cadena);

    // metodos de dibujado
    void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
        int posX, int posY, String cad);
  public:
    void dibujar_memoria(TForm* Form, int posX, int posY, int a, int b);

    // ejercicio
    void sumar(int dir, string campo);
};
#endif

