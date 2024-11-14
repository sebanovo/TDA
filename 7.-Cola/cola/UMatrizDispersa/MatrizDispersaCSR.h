//---------------------------------------------------------------------------

#ifndef MatrizDispersaCSRH
#define MatrizDispersaCSRH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaCSR
{
    const int TamanoCelda = 50;
    class MatrizDispersaCSR
    {
        private:
        const int MAX = 1000;
        int *vf, *vc, *vd; // filas, columnas, datos
        int df, dc, nt, repe;
        int existe_elemento(int f, int c);
        int donde_insertar(int f, int c);
        bool hay(int elemento);

        public:
        MatrizDispersaCSR();
        void dimensionar(int df, int dc);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        std::string mostrar();
        ~MatrizDispersaCSR();

        // graficar
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);

        // ejercicios
        static int suma(MatrizDispersaCSR* m);
        static void transpuesta(MatrizDispersaCSR* m, MatrizDispersaCSR* m1);
        static bool es_simetrica(MatrizDispersaCSR* m);
    };

    void resolverSudoku(MatrizDispersaCSR* m);
    bool esSudoku(MatrizDispersaCSR* m);
} // namespace UMatrizDispersaCSR

#endif