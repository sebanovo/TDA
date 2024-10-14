//---------------------------------------------------------------------------

#ifndef MatrizDispersaPunteroDobleH
#define MatrizDispersaPunteroDobleH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaPunteroDoble
{
    const int TamanoCelda = 100;
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

        // graficar
        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
            int posX, int posY, String cad);
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);
    };

    int suma(MatrizDispersaPunteroDoble* m);
    void transpuesta(
        MatrizDispersaPunteroDoble* m, MatrizDispersaPunteroDoble* m1);
    bool es_simetrica(MatrizDispersaPunteroDoble* m);
} // namespace UMatrizDispersaPunteroDoble

#endif

