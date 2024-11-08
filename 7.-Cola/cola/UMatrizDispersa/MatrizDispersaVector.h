//---------------------------------------------------------------------------

#ifndef MatrizDispersaVectorH
#define MatrizDispersaVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaVector {
    const int TamanoCelda = 100;
    class MatrizDispersaVector {
       private:
        const int MAX = 1000;
        int *vf, *vc, *vd;  // filas, columnas, datos
        int df, dc, nt, repe;
        int buscar_posicion_vd(int f, int c);
        bool hay(int elemento);

       public:
        MatrizDispersaVector();
        void dimensionar(int df, int dc);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        std::string mostrar();
        ~MatrizDispersaVector();

        // graficar
        void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
                           int posX, int posY, String cad);
        void graficar_matriz_dispersa(TForm* Form, int posX, int posY);

        // ejercicios
        static int suma(MatrizDispersaVector* m);
        static void transpuesta(MatrizDispersaVector* m, MatrizDispersaVector* m1);
        static bool es_simetrica(MatrizDispersaVector* m);
    };
}  // namespace UMatrizDispersaVector
#endif
