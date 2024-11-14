//---------------------------------------------------------------------------

#ifndef MatrizDispersaSMDobleH
#define MatrizDispersaSMDobleH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UCSMemoria/CSMemoria.h"

namespace UMatrizDispersaSMDoble
{
    const int TamanoCelda = 50;
    const std::string _col = "->col";
    const std::string _dato = "->dato";
    const std::string _sigC = "->sigC";
    const std::string _col_dato_sigC = "col,dato,sigC";

    const std::string _fil = "->fil";
    const std::string _antF = "->antF";
    const std::string _sigF = "->sigF";
    const std::string _PtrCol = "->ptrCol";
    const std::string _fil_antF_sigF_ptrCol = "fil,antF,sigF,ptrCol";

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
        std::string mostrar();
        ~MatrizDispersaSMDoble();

        // graficar
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);

        // ejercicios
        static int suma(MatrizDispersaSMDoble* m);
        static void transpuesta(MatrizDispersaSMDoble* m, MatrizDispersaSMDoble* m1);
        static bool es_simetrica(MatrizDispersaSMDoble* m);
    };

    void resolverSudoku(MatrizDispersaSMDoble* m);
    bool esSudoku(MatrizDispersaSMDoble* m);
} // namespace UMatrizDispersaSMDoble
#endif
