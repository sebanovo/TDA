//---------------------------------------------------------------------------

#ifndef MatrizDispersaVectorH
#define MatrizDispersaVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaVector
{
    class MatrizDispersaVector
    {
      private:
        const int MAX = 1000;
        int *vf, *vc, *vd; // filas, columnas, datos
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
    };

    int suma(MatrizDispersaVector* m);
    void transpuesta(MatrizDispersaVector* m, MatrizDispersaVector* m1);
    bool es_simetrica(MatrizDispersaVector* m);
} // namespace UMatrizDispersaVector
#endif
