//---------------------------------------------------------------------------

#ifndef MatrizDispersaPunteroDobleH
#define MatrizDispersaPunteroDobleH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaPunteroDoble
{
    const int TamanoCelda = 50;
    struct NodoColumna
    {
        int col;
        int dato;
        NodoColumna* sigC;
    };

    struct NodoFila
    {
        int fil;
        NodoFila* antF;
        NodoFila* sigF;
        NodoColumna* PtrCol;
    };

    class MatrizDispersaPunteroDoble
    {
        private:
        NodoFila* PtrFil;
        int repe, df, dc, nt;

        NodoColumna* buscar(int f, int c);
        NodoFila* buscar(int f);
        NodoFila* posicionIns(int f);
        void insertar(int f, int c, int elemento);
        void suprimir(NodoFila* dirFil, NodoColumna* dirCol);
        void suprimir(NodoFila* dir);
        bool hay(int elemento);

        public:
        MatrizDispersaPunteroDoble();
        void dimensionar(int f, int c);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        std::string mostrar();
        ~MatrizDispersaPunteroDoble();

        // graficar
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);

        // ejercicios
        static int suma(MatrizDispersaPunteroDoble* m);
        static void transpuesta(MatrizDispersaPunteroDoble* m,
        MatrizDispersaPunteroDoble* m1);
        static bool es_simetrica(MatrizDispersaPunteroDoble* m);
    };

    void resolverSudoku(MatrizDispersaPunteroDoble* m);
    bool esSudoku(MatrizDispersaPunteroDoble* m);
} // namespace UMatrizDispersaPunteroDoble

#endif
