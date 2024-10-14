// ---------------------------------------------------------------------------

#pragma hdrstop

#include <sstream>
#include "MatrizDispersaSMDoble.h"
// ---------------------------------------------------------------------------

#pragma package(smart_init)

namespace UMatrizDispersaSMDoble
{
    using UCSMemoria::NULO;
    MatrizDispersaSMDoble::MatrizDispersaSMDoble()
    {
        mem = new UCSMemoria::CSMemoria;
        PtrFil = NULO;
        df = dc = repe = nt = 0;
    }

    MatrizDispersaSMDoble::MatrizDispersaSMDoble(UCSMemoria::CSMemoria* m)
    {
        mem = m;
        PtrFil = NULO;
        df = dc = nt = repe = 0;
    }

    void MatrizDispersaSMDoble::dimensionar(int f, int c)
    {
        df = f;
        dc = c;
    }

    int MatrizDispersaSMDoble::dimension_fila()
    {
        return df;
    }

    int MatrizDispersaSMDoble::dimension_columna()
    {
        return dc;
    }

    int MatrizDispersaSMDoble::buscarC(int f, int c)
    {
        int auxf = PtrFil;
        while (auxf != NULO) {
            if (mem->obtener_dato(auxf, _fil) == f) {
                int auxc = mem->obtener_dato(auxf, _ptrCol);
                while (auxc != NULO) {
                    if (mem->obtener_dato(auxc, _col) == c)
                        return auxc;
                    auxc = mem->obtener_dato(auxc, _sigC);
                }
                return NULO;
            }
            auxf = mem->obtener_dato(auxf, _sigF);
        }
        return NULO;
    }

    int MatrizDispersaSMDoble::buscarF(int f)
    {
        int auxf = PtrFil;
        while (auxf != NULO) {
            if (mem->obtener_dato(auxf, _fil) == f)
                return auxf;
            auxf = mem->obtener_dato(auxf, _sigF);
        }
        return NULO;
    }

    int MatrizDispersaSMDoble::posicionIns(int f)
    {
        int aux = PtrFil;
        while (aux != NULO) {
            if (f < mem->obtener_dato(aux, _fil))
                return aux;
            aux = mem->obtener_dato(aux, _sigF);
        }
        return NULO;
    }

    void MatrizDispersaSMDoble::suprimir(int dirFil, int dirCol)
    {
        if (dirCol == mem->obtener_dato(dirFil, _ptrCol)) {
            mem->poner_dato(dirFil, _ptrCol,
                mem->obtener_dato(mem->obtener_dato(dirFil, _ptrCol), _sigC));
        } else {
            // El anterior
            int x = mem->obtener_dato(dirFil, _ptrCol);
            int ant = NULO;
            while (x != NULO) {
                if (x == dirCol)
                    break;
                ant = x;
                x = mem->obtener_dato(x, _sigC);
            }
            mem->poner_dato(ant, _sigC, mem->obtener_dato(dirCol, _sigC));
        }
        mem->delete_espacio(dirCol);
        nt--;
        if (mem->obtener_dato(dirFil, _ptrCol) == NULO) {
            suprimir(dirFil);
        }
    }

    void MatrizDispersaSMDoble::suprimir(int dir)
    {
        if (dir == PtrFil) {
            PtrFil = mem->obtener_dato(PtrFil, _sigF);
        } else {
            int ant = mem->obtener_dato(dir, _antF);
            int sig = mem->obtener_dato(dir, _sigF);
            mem->poner_dato(ant, _sigF, sig);
            if (sig != NULO) {
                mem->poner_dato(sig, _antF, ant);
            }
        }
        mem->delete_espacio(dir);
    }

    void MatrizDispersaSMDoble::insertar(int f, int c, int elemento)
    {
        int x = mem->new_espacio(_col_dato_sigC);
        if (x == NULO)
            throw std::runtime_error("No hay espacio en la memoria");
        mem->poner_dato(x, _col, c);
        mem->poner_dato(x, _dato, elemento);
        mem->poner_dato(x, _sigC, NULO);
        int dirFila = buscarF(f);
        if (dirFila != NULO) {
            mem->poner_dato(x, _sigC, mem->obtener_dato(dirFila, _ptrCol));
            mem->poner_dato(dirFila, _ptrCol, x);
        } else {
            int xf = mem->new_espacio(_fil_antF_sigF_ptrCol);
            if (xf != NULO) {
                mem->poner_dato(xf, _fil, f);
                mem->poner_dato(xf, _antF, NULO);
                mem->poner_dato(xf, _sigF, NULO);
                mem->poner_dato(xf, _ptrCol, NULO);
                int posF = posicionIns(f);
                if (posF == NULO) {
                    if (PtrFil == NULO)
                        PtrFil = xf;
                    else {
                        int fin = PtrFil;
                        while (mem->obtener_dato(fin, _sigF) != NULO)
                            fin = mem->obtener_dato(fin, _sigF);
                        mem->poner_dato(xf, _antF, fin);
                        mem->poner_dato(fin, _sigF, xf);
                    }
                } else if (posF == PtrFil) {
                    mem->poner_dato(xf, _sigF, PtrFil);
                    mem->poner_dato(PtrFil, _antF, xf);
                    PtrFil = xf;
                } else {
                    int ant = mem->obtener_dato(posF, _antF);
                    int sig = posF;
                    mem->poner_dato(xf, _sigF, sig);
                    mem->poner_dato(xf, _antF, ant);
                    mem->poner_dato(ant, _sigF, xf);
                    mem->poner_dato(sig, _antF, xf);
                }

                mem->poner_dato(x, _sigC, mem->obtener_dato(xf, _ptrCol));
                mem->poner_dato(xf, _ptrCol, x);
            }
        }
        nt++;
    }

    void MatrizDispersaSMDoble::poner(int f, int c, int elemento)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw std::runtime_error("Indices fuera de rango!!");
        int dir = buscarC(f, c);
        if (dir != NULO) {
            mem->poner_dato(dir, _dato, elemento);
            if (elemento == repe) {
                int dirFila = buscarF(f);
                suprimir(dirFila, dir);
            }
        } else if (elemento != repe)
            insertar(f, c, elemento);
    }

    int MatrizDispersaSMDoble::elemento(int f, int c)
    {
        if ((f < 1 || f > df) || (c < 1 || c > dc))
            throw std::runtime_error("Indices fuera de rango!!");
        int dir = buscarC(f, c);
        return dir == NULO ? repe : mem->obtener_dato(dir, _dato);
    }

    bool MatrizDispersaSMDoble::hay(int elemento)
    {
        int auxF = PtrFil;
        while (auxF != NULO) {
            int auxC = mem->obtener_dato(auxF, _ptrCol);
            while (auxC != NULO) {
                if (mem->obtener_dato(auxC, _dato) == elemento)
                    return true;
                auxC = mem->obtener_dato(auxC, _sigC);
            }
            auxF = mem->obtener_dato(auxF, _sigF);
        }
        return false;
    }

    void MatrizDispersaSMDoble::definir_valor_repetido(int elemento)
    {
        if (PtrFil == NULO || !hay(elemento)) {
            repe = elemento;
        } else {
            for (int i = 1; i <= df; i++) {
                for (int j = 1; j <= dc; j++) {
                    int el = this->elemento(i, j);
                    if (el == elemento) {
                        int dirF = buscarF(i);
                        int dirC = buscarC(i, j);
                        suprimir(dirF, dirC);
                    } else if (el == repe)
                        insertar(i, j, repe);
                }
            }
            repe = elemento;
        }
    }

    string MatrizDispersaSMDoble::mostrar()
    {
        std::string s = "";
        for (int i = 1; i <= df; i++) {
            for (int j = 1; j <= dc; j++) {
                s += std::to_string(elemento(i, j)) + "\t";
            }
            s += "\r\n";
        }

        std::stringstream info;
        info << "\n-----------------------------------\n";
        info << "nt = " << std::to_string(nt) << "\n";
        info << "df = " << std::to_string(df) << "\n";
        info << "dc = " << std::to_string(dc) << "\n";
        info << "repe = " << std::to_string(repe) << "\n";

        return s + info.str();
    }

    int suma(MatrizDispersaSMDoble* m)
    {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++) {
            for (int c = 1; c <= m->dimension_columna(); c++) {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }

    void transpuesta(MatrizDispersaSMDoble* m, MatrizDispersaSMDoble* m1)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        m1->dimensionar(c, f);
        for (int i = 1; i <= f; i++) {
            for (int j = 1; j <= c; j++) {
                m1->poner(j, i, m->elemento(i, j));
            }
        }
        return;
    }

    bool es_simetrica(MatrizDispersaSMDoble* m)
    {
        int f = m->dimension_fila();
        int c = m->dimension_columna();
        if (f != c)
            return false;
        for (int i = 1; i <= f; i++) {
            for (int j = 1; j <= c; j++) {
                if (m->elemento(i, j) != m->elemento(j, i))
                    return false;
            }
        }
        return true;
    }
} // namespace UMatrizDispersaSMDoble

