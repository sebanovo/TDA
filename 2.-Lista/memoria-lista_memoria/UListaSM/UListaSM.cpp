//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaSM.h"

#include <iostream>
#include <string>

#include "UCSMemoria/UCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UListaSM {
    using std::runtime_error;
    using std::string;
    using std::to_string;
    using UCSMemoria::NULO;

    ListaSM::ListaSM(UCSMemoria::CSMemoria* m) {
        longitud = 0;
        PtrElementos = NULO;
        mem = m;
    }

    // retorna la dirección de memoria final
    int ListaSM::fin() {
        if (vacia())
            throw std::runtime_error("Lista vacia");
        int x = PtrElementos;
        int PtrFin;
        while (x != NULO) {
            PtrFin = x;
            x = mem->obtener_dato(x, sig);
        }
        return PtrFin;
    }

    // retorna la dirección de memoria de la cabeza de la lista
    int ListaSM::primero() {
        if (vacia())
            throw std::runtime_error("La lista esta vacía");
        return PtrElementos;
    }

    // retorna la dirección de memoria siguiente a este
    int ListaSM::siguiente(int dir) {
        if (vacia())
            throw std::runtime_error("La lista esta vacia");
        else if (!es_direccion_valida(dir))
            throw std::runtime_error("Esta dirección no es valida");
        else if (dir == fin())
            throw std::runtime_error(
                "No hay siguiente luego de esta dirección");
        return mem->obtener_dato(dir, sig);
    }

    // retorna la dirección de memoria anterior a esta
    int ListaSM::anterior(int dir) {
        if (vacia())
            throw std::runtime_error("La lista esta vacía");
        if (!es_direccion_valida(dir))
            throw std::runtime_error("No existe esta dirección en la Lista");
        if (dir == primero())
            throw std::runtime_error(
                "No existe la dirección anterior a esta\n");

        int x = PtrElementos;
        int ant = NULO;
        while (x != NULO) {
            if (x == dir)
                return ant;
            ant = x;
            x = mem->obtener_dato(x, sig);
        }
        return NULO;
    }

    // esta vacía?
    bool ListaSM::vacia() {
        return longitud == 0 || PtrElementos == NULO;
    }

    // recupera el elemento de la dirección de memoria
    int ListaSM::recupera(int dir) {
        if (vacia())
            throw std::runtime_error("La lista esta vacía\n");
        if (!es_direccion_valida(dir))
            throw std::runtime_error("No existe esta dirección en la Lista");
        return mem->obtener_dato(dir, elemento);
    }

    // retorna la longitud
    int ListaSM::_longitud() {
        return longitud;
    }

    // insertar un elemento en una dirección de memoria
    void ListaSM::inserta(int dir, int element) {
        int x = mem->new_espacio(elemento_sig);
        mem->poner_dato(x, elemento, element);
        mem->poner_dato(x, sig, NULO);

        if (x == NULO)
            throw std::runtime_error("No hay espacio en la memoria");
        if (vacia())
            PtrElementos = x;
        else if (!es_direccion_valida(dir))
            std::runtime_error("La dirección no es valida");
        else if (dir == primero()) {  // caso especial
            mem->poner_dato(x, sig, PtrElementos);
            PtrElementos = x;
        } else {
            int ant = anterior(dir);
            mem->poner_dato(x, sig, mem->obtener_dato(ant, sig));
            mem->poner_dato(ant, sig, x);
        }
        longitud++;
    }

    // insertar un elemento al principio de la lista
    void ListaSM::inserta_primero(int element) {
        int x = mem->new_espacio(elemento_sig);
        mem->poner_dato(x, elemento, element);
        mem->poner_dato(x, sig, PtrElementos);
        PtrElementos = x;
        longitud++;
    }

    // inserta un elemento al final de la lista
    void ListaSM::inserta_ultimo(int element) {
        int x = mem->new_espacio(elemento_sig);
        mem->poner_dato(x, elemento, element);
        mem->poner_dato(x, sig, NULO);
        if (x == NULO)
            throw std::runtime_error("No hay espacio en la memoria");
        if (vacia()) {
            PtrElementos = x;
            longitud++;
            return;
        }

        mem->poner_dato(fin(), sig, x);
        longitud++;
    }

    // elimina un elemento de la lista
    void ListaSM::suprime(int dir) {
        if (vacia())
            throw std::runtime_error("La lista esta vacía");
        if (!es_direccion_valida(dir))
            throw std::runtime_error("La dirección no es valida");
        if (PtrElementos == dir) {
            int temp = PtrElementos;
            PtrElementos = mem->obtener_dato(PtrElementos, sig);
            mem->delete_espacio(temp);
            return;
        } else {
            int ant = anterior(dir);
            mem->poner_dato(ant, sig, mem->obtener_dato(dir, sig));
            mem->delete_espacio(dir);
        }
        longitud--;
    }

    // modifica el elemento de una direccion de la lista
    void ListaSM::modifica(int dir, int element) {
        if (vacia())
            throw std::runtime_error("La lista esta vacía");
        if (!es_direccion_valida(dir))
            throw std::runtime_error("La dirección no es valida");
        mem->poner_dato(dir, elemento, element);
    }

    // muestra la lista
    string ListaSM::mostrar() {
        // mem->mostrar();
        string s = "[";
        int x = PtrElementos;
        while (x != NULO) {
            int el = mem->obtener_dato(x, elemento);
            s += to_string(el);
            x = mem->obtener_dato(x, sig);
            if (x != NULO)
                s += ",";
        }
        return s + "]";
    }

    ListaSM::~ListaSM() {
        delete mem;
    }

    // retorna la direccion de memoria de la primera ocurrencia del elemento
    int ListaSM::localiza(int element) {
        int x = PtrElementos;
        while (x != NULO) {
            if (mem->obtener_dato(x, elemento) == element)
                return x;
            x = mem->obtener_dato(x, sig);
        }
        return NULO;
    }

    // elimina todas las ocurrencias del elemento
    void ListaSM::elimina_dato(int element) {
        int x = PtrElementos;
        while (x != NULO) {
            if (mem->obtener_dato(x, elemento) == element) {
                int elim = x;
                x = mem->obtener_dato(x, sig);
                suprime(elim);
            } else {
                x = mem->obtener_dato(x, sig);
            }
        }
    }

    // elimina todos los nodos y elementos de la lista
    void ListaSM::anula() {
        while (!vacia())
            suprime(primero());
    }

    // verifica que la dirección exista
    bool ListaSM::es_direccion_valida(int dir) {
        int x = PtrElementos;
        while (x != NULO) {
            if (x == dir)
                return true;
            x = mem->obtener_dato(x, sig);
        }
        return false;
    }

    void ListaSM::dibujar_lista(TForm* Form, int posX, int posY) {
        TCanvas* Canvas = Form->Canvas;
        // limpiar el lienzo
        int anchoTexto = Canvas->TextWidth(mostrar().c_str());
        int altoTexto = Canvas->TextHeight(mostrar().c_str());
        TRect rect(posX, posY, posX + anchoTexto, posY + altoTexto);
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(rect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }

    // ejercicio
    void ListaSM::bubble_sort() {
        int x = PtrElementos;
        int y;
        while (x != NULO) {
            y = mem->obtener_dato(x, sig);
            while (y != NULO) {
                if (mem->obtener_dato(x, elemento) >
                    mem->obtener_dato(y, elemento)) {
                    int temp = mem->obtener_dato(x, elemento);
                    mem->poner_dato(
                        x, elemento, mem->obtener_dato(y, elemento));
                    mem->poner_dato(y, elemento, temp);
                }
                y = mem->obtener_dato(y, sig);
            }
            x = mem->obtener_dato(x, sig);
        }
    }
}  // namespace UListaSM

// void Lista::imprimir(TColor FormColor, TCanvas* Canvas)
//{
//     int posX = 210;
//     int posY = 600;
//     int auxX = posX;
//     int auxY = posY;
//     Canvas->Font->Size = 10;
//     if (vacia() == false) {
//         //DIBUJAMOS CABECERA
//         Pintado(posX, posY - 10, "Lista", FormColor, Canvas);
//         posX = auxX;
//         posY += TamanoCeldaY;
//
//         direccion x = PtrElementos;
//         Pintado(posX, posY, "< ", FormColor, Canvas);
//         posX += 40;
//         while (x != NULO) {
//             Pintado(posX, posY, IntToStr(Cmemoria->obtenerDato(x, elementNL)),
//                 FormColor, Canvas);
//             posX += 80;
//             if (x != NULO) {
//                 Pintado(posX, posY, ", ", FormColor, Canvas);
//                 posX += 40;
//             }
//             x = Cmemoria->obtenerDato(x, sigNL);
//         }
//         Pintado(posX, posY, ">", FormColor, Canvas);
//         posX += 40;
//     } else {
//         Pintado(posX, posY, "Lista Vacia", FormColor, Canvas);
//         posX = auxX;
//         posY += TamanoCeldaY;
//     }
// }
//
// int Lista::getPtr()
//{
//     return PtrElementos;
// }
