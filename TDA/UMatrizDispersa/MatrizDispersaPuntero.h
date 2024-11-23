//---------------------------------------------------------------------------

#ifndef MatrizDispersaPunteroH
#define MatrizDispersaPunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaPuntero
{
    const int TamanoCelda = 50;
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
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);

        // ejercicios
        static int suma(MatrizDispersaPuntero* m);
        static void transpuesta(MatrizDispersaPuntero* m, MatrizDispersaPuntero* m1);
        static bool es_simetrica(MatrizDispersaPuntero* m);
    };

    void resolverSudoku(MatrizDispersaPuntero* m);
    bool esSudoku(MatrizDispersaPuntero* m);
} // namespace UMatrizDispersaPuntero
#endif