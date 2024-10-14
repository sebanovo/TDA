//---------------------------------------------------------------------------

#ifndef MatrizDispersaSMDobleH
#define MatrizDispersaSMDobleH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UCSMemoria/CSMemoria.h"

namespace UMatrizDispersaSMDoble
{
    const int TamanoCelda = 100;
    using namespace std;

    const string _col = "->col";
    const string _dato = "->dato";
    const string _sigC = "->sigC";
    const string _col_dato_sigC = "col,dato,sigC";

    const string _fil = "->fil";
    const string _antF = "->antF";
    const string _sigF = "->sigF";
    const string _ptrCol = "->ptrCol";
    const string _fil_antF_sigF_ptrCol = "fil,antF,sigF,ptrCol";

    class MatrizDispersaSMDoble
    {
      private:
        UCSMemoria::CSMemoria* mem;
        int PtrFil, repe, df, dc, nt;

        int buscarC(int f, int c);
        int buscarF(int f);
        int posicionIns(int f);
        void insertar(int f, int c, int elemento);
        void suprimir(int dirFil, int dirCol);
        void suprimir(int dir);
        bool hay(int elemento);
      public:
        MatrizDispersaSMDoble();
        MatrizDispersaSMDoble(UCSMemoria::CSMemoria* m);
        void dimensionar(int f, int c);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        string mostrar();

        // graficar
        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
            int posX, int posY, String cad);
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);
    };

    int suma(MatrizDispersaSMDoble* m);
    void transpuesta(MatrizDispersaSMDoble* m, MatrizDispersaSMDoble* m1);
    bool es_simetrica(MatrizDispersaSMDoble* m);
} // namespace UMatrizDispersaSMDoble
#endif

