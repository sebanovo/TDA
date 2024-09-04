
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioPuntero.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioPuntero
{
    PolinomioPuntero::PolinomioPuntero()
    {
        nt = 0;
        PtrPoli = nullptr;
    }

    // devuelve la direccion del termino del exponente (osea un nodo)
    direccion PolinomioPuntero::buscar_exponente(int exp)
    {
        Nodo* dir = PtrPoli;
        Nodo* dirEx = nullptr;
        if (dir == nullptr)
            return nullptr; // exception

        while (dir != nullptr) {
            if (dir->exp == exp)
                return dir;
            dir = dir->sig;
        }
        return dirEx;
    }

    // devuelve la direccion donde esta el termino n (osea el nodo)
    direccion PolinomioPuntero::buscar_termino_n(int n)
    {
        Nodo* dir = PtrPoli;
        Nodo* dirTer = nullptr;

        if (dir == nullptr)
            return nullptr; // exception

        int Nt = 0;
        while (dir != nullptr) {
            Nt = Nt + 1;
            if (Nt == n)
                return dir;

            dir = dir->sig;
        }
        return dirTer;
    }

    bool PolinomioPuntero::es_cero()
    {
        return nt == 0;
    }

    // devuelve el grado del polinomio
    int PolinomioPuntero::grado()
    {
        Nodo* dir = PtrPoli;
        if (dir == nullptr)
            return -1; // exception

        int gradoMax = dir->exp;
        while (dir != nullptr) {
            if (dir->exp > gradoMax)
                gradoMax = dir->exp;
            dir = dir->sig;
        }
        return gradoMax;
    }

    // devuelve el coeficiente del exponente del termino
    int PolinomioPuntero::coeficiente(int exp)
    {
        Nodo* dir = buscar_exponente(exp);
        if (dir == nullptr)
            return -1; // exception
        return dir->coef;
    }

    // P1 + P2
    void PolinomioPuntero::sumar(PolinomioPuntero p1, PolinomioPuntero p2)
    {
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            int exp = p1.exponente(i);
            int coef = p1.coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2.numero_terminos(); i++) {
            int exp = p2.exponente(i);
            int coef = p2.coeficiente(exp);
            poner_termino(coef, exp);
        }
    }

    // P1 - P2
    void PolinomioPuntero::restar(PolinomioPuntero p1, PolinomioPuntero p2)
    {
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            int exp = p1.exponente(i);
            int coef = p1.coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2.numero_terminos(); i++) {
            int exp = p2.exponente(i);
            int coef = p2.coeficiente(exp) * -1;
            poner_termino(coef, exp);
        }
    }

    // P1 * P2
    void PolinomioPuntero::multiplicar(PolinomioPuntero p1, PolinomioPuntero p2)
    {
        // = (2x + 1) * (3x + 3)
        // = 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
        // = 6x^2 + 9x + 3
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            for (int j = 1; j <= p2.numero_terminos(); j++) {
                int exp1 = p1.exponente(i);
                int coef1 = p1.coeficiente(exp1);

                int exp2 = p2.exponente(j);
                int coef2 = p2.coeficiente(exp2);

                poner_termino(coef1 * coef2, exp1 + exp2);
            }
        }
    }

    // pone un termino con su coeficiente y su exponente
    void PolinomioPuntero::poner_termino(int coef, int exp)
    {
        Nodo* dir = buscar_exponente(exp);
        if (dir == nullptr) {
            Nodo* aux = new Nodo;
            aux->sig = nullptr;
            if (aux != nullptr) {
                aux->coef = coef;
                aux->exp = exp;
                aux->sig = PtrPoli;
                PtrPoli = aux;
                nt++;
            } else {
                throw new Exception("Error de espacio de memoria");
            }
        } else {
            dir->coef = dir->coef + coef;
        }
    }

    int PolinomioPuntero::numero_terminos()
    {
        return nt;
    }

    // devuelve el exponente
    int PolinomioPuntero::exponente(int nroTer)
    {
        Nodo* dir = buscar_termino_n(nroTer);
        if (dir == nullptr)
            return -1; // exception
        return dir->exp;
    }

    // cambia el coeficiente indicando el termino con el exponente asociado
    void PolinomioPuntero::asignar_coeficiente(int coef, int exp)
    {
        Nodo* dir = buscar_exponente(exp);
        if (dir != nullptr) {
            dir->coef = coef;
            if (coef == 0) {
                Nodo* aux = dir;
                dir = dir->sig;
                delete aux;
                aux = nullptr;
                dir = nullptr;
            }
        } else {
            throw new Exception("No existe ese término");
        }
    }

    string PolinomioPuntero::mostrar()
    {
        Nodo* x = PtrPoli;
        string s = "";

        while (x != nullptr) {
            s += x->coef >= 0 && s != "" ? "+" : "";
            s += std::to_string(x->coef) + "x^" + std::to_string(x->exp) + "  ";
            x = x->sig;
        }
        return s;
    }

    PolinomioPuntero::~PolinomioPuntero()
    {
        Nodo* current = PtrPoli;
        while (current != nullptr) {
            Nodo* next = current->sig;
            delete current;
            current = next;
        }
        current = nullptr;
        PtrPoli = nullptr;
    }

    void derivada(PolinomioPuntero p, PolinomioPuntero p1)
    {
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int coef = p.coeficiente(exp);
            p1.poner_termino(coef * exp, exp - 1);
        }
    }

    std::string mostrar_integral(PolinomioPuntero p)
    {
        std::string s = "";
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int co = p.coeficiente(exp);

            s += "(" + std::to_string(co) + "x^" + std::to_string(exp + 1) +
                 ")/" + std::to_string(exp + 1) + " + ";
            if (i == p.numero_terminos())
                s += "C";
        }
        return s;
    }
} // namespace UPolinomioPuntero

