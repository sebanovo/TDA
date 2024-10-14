//---------------------------------------------------------------------------

#ifndef MatrizDispersaPunteroH
#define MatrizDispersaPunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaPuntero
{
    const int TamanoCelda = 100;
    struct Nodo
    {
        int fil;
        int col;
        int dato;
        Nodo* sig;
    };

    class MatrizDispersaPuntero
    {
      private:
        Nodo* PtrMatD;
        int repe, df, dc, nt;
        Nodo* buscar(int f, int c);
        bool hay(int elemento);
      public:
        MatrizDispersaPuntero();
        void dimensionar(int f, int c);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        std::string mostrar();
        ~MatrizDispersaPuntero();

        // graficar
        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
            int posX, int posY, String cad);
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);
    };

    int suma(MatrizDispersaPuntero* m);
    void transpuesta(MatrizDispersaPuntero* m, MatrizDispersaPuntero* m1);
    bool es_simetrica(MatrizDispersaPuntero* m);
} // namespace UMatrizDispersaPuntero
#endif

