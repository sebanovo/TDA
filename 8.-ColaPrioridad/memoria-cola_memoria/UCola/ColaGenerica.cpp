//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaGenerica.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaGenerica
{
    template<typename T>
    ColaGenerica<T>::ColaGenerica()
    {
        fin = 0;
        ini = 1;
        v = new T[MAX];
    }

    template<typename T>
    bool ColaGenerica<T>::vacia()
    {
        return ini > fin;
    }

    template<typename T>
    void ColaGenerica<T>::poner(T e)
    {
        if (fin >= MAX)
            throw new Exception("No hay espacio en la cola");
        v[++fin] = e;
    }

    template<typename T>
    void ColaGenerica<T>::sacar(T &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = v[ini];
        for (int i = ini; i < fin; i++)
            v[i] = v[i + 1];
        fin--;
    }

    template<typename T>
    T ColaGenerica<T>::primero()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return v[ini];
    }

    template<typename T>
    std::string ColaGenerica<T>::mostrar()
    {
        std::string s = "<<";
        ColaGenerica aux;
        while (!vacia()) {
            T e;
            sacar(e);
            aux.poner(e);
            // Usamos `if constexpr` para verificar el tipo en tiempo de compilación
            if constexpr (std::is_same<T, int>::value) {
                s += std::to_string(e);
            } else if constexpr (std::is_same<T, char>::value) {
                s += e;
            } else if constexpr (std::is_same<T, std::string>::value) {
                s += e;
            } else if constexpr (std::is_same<T, bool>::value) {
                s += e ? "true" : "false";
            } else {
                // tipo no especificado
                s += "| Tipo no soportado |\n";
            }
            if (!vacia())
                s += ",";
        }
        while (!aux.vacia()) {
            T e;
            aux.sacar(e);
            poner(e);
        }
        return s + "<<";
    }

    template<typename T>
    ColaGenerica<T>::~ColaGenerica()
    {
        delete[] v;
    }

    template<typename T>
    T ColaGenerica<T>::ultimo()
    {
        if (vacia())
            throw new Exception("No hay elementos en la cola");
        return v[fin];
    }

    template<typename T>
    void ColaGenerica<T>::poner_frente(T e)
    {
        if (fin >= MAX)
            throw new Exception("No hay espacio en la cola");
        fin++;
        for (int i = fin; i > ini; i--) {
            v[i] = v[i - 1];
        }
        v[ini] = e;
    }

    template<typename T>
    void ColaGenerica<T>::sacar_final(T &e)
    {
        if (vacia())
            throw new Exception("No hay elementos que sacar");
        e = v[fin];
        fin--;
    }

    template<typename T>
    template<typename U>
    void ColaGenerica<T>::concatenar(
        ColaGenerica<U>* c1, ColaGenerica<U>* c2, ColaGenerica<U>* c3)
    {
        ColaGenerica<U> aux;
        while (!c1->vacia()) {
            U e;
            c1->sacar(e);
            aux.poner(e);
        }
        while (!aux.vacia()) {
            U e;
            aux.sacar(e);
            c3->poner(e);
            c1->poner(e);
        }
        while (!c2->vacia()) {
            U e;
            c2->sacar(e);
            aux.poner(e);
        }
        while (!aux.vacia()) {
            U e;
            aux.sacar(e);
            c3->poner(e);
            c2->poner(e);
        }
    }

    template<typename T>
    void ColaGenerica<T>::graficar_cola(TForm* Form, int posX, int posY)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Brush->Color = Form->Color;
        Canvas->FillRect(Canvas->ClipRect);

        Form->Canvas->Font->Size = 30;
        Form->Canvas->Font->Name = "Microsoft YaHei UI";
        Form->Canvas->TextOutW(posX, posY, mostrar().c_str());
    }

} // namespace UColaGenerica
// Añadir mas instancias si se lo desea
template class UColaGenerica::ColaGenerica<int>;
template class UColaGenerica::ColaGenerica<char>;
template class UColaGenerica::ColaGenerica<std::string>;
template class UColaGenerica::ColaGenerica<bool>;

// instanciar el metodo estatico;
template void UColaGenerica::ColaGenerica<int>::concatenar<int>(
    ColaGenerica<int>*, ColaGenerica<int>*, ColaGenerica<int>*);
template void UColaGenerica::ColaGenerica<char>::concatenar<char>(
    ColaGenerica<char>*, ColaGenerica<char>*, ColaGenerica<char>*);
template void UColaGenerica::ColaGenerica<std::string>::concatenar<std::string>(
    ColaGenerica<std::string>*, ColaGenerica<std::string>*,
    ColaGenerica<std::string>*);
template void UColaGenerica::ColaGenerica<bool>::concatenar<bool>(
    ColaGenerica<bool>*, ColaGenerica<bool>*, ColaGenerica<bool>*);

