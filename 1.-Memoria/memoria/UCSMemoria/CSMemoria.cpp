//---------------------------------------------------------------------------

#pragma hdrstop

#include <algorithm>
#include <set>
#include <sstream>

#include "CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UCSMemoria
{
    using std::cout;
    using std::set;
    using std::stringstream;
    using std::to_string;

    // inicializa el constructor
    CSMemoria::CSMemoria()
    {
        mem = new Nodo[MAX];
        for (int i = 0; i < MAX - 1; i++)
            mem[i].link = i + 1;

        mem[MAX - 1].link = NULO;
        libre = 0;
    }

    // retorna el inicio de la dirección donde se colocaron los ids
    int CSMemoria::new_espacio(string cadena)
    {
        //        if (numero_ids(cadena) > espacio_disponible())
        //            throw new Exception("Exediste el limite del espacio disponible");
        //        if (cadena.empty())
        //            throw new Exception("La cadena esta vacía");
        //        if (!hay_al_menos_un_id(cadena))
        //            throw new Exception("Tiene que haber almenos un id");

        int cant = numero_ids(cadena);
        int dir = libre;
        int d = libre;
        for (int i = 1; i < cant; i++) {
            mem[d].id = obtener_id(cadena, i);
            d = mem[d].link;
        }
        libre = mem[d].link;
        mem[d].link = NULO;
        mem[d].id = obtener_id(cadena, cant);
        return dir;
    }

    // libera un espacio de la memoria
    void CSMemoria::delete_espacio(int dir)
    {
        if (dir < 0 || dir > MAX - 1)
            throw new Exception("Esta dirección no existe");

        int x = dir;
        while (mem[x].link != NULO)
            x = mem[x].link;
        mem[x].link = libre;
        libre = dir;
    }

    // pone un dato desde la dirección de memoria que quieras
    void CSMemoria::poner_dato(int dir, string cadena_id, int valor)
    {
        cadena_id = eliminar_flecha(cadena_id);
        //        if (dir < 0 || dir > MAX - 1)
        //            throw new Exception("Esta dirección no es valida");
        //        if (cadena_id.empty())
        //            throw new Exception("La cadena ID esta vacía");
        //        if (!hay_al_menos_un_id(cadena_id))
        //            throw new Exception("Tiene que haber almenos un id");

        int z = dir;
        while (z != NULO) {
            if (mem[z].id == cadena_id) {
                mem[z].dato = valor;
                break;
            }
            z = mem[z].link;
        }
    }

    // obtiene un dato desde la dirección de memoria
    int CSMemoria::obtener_dato(int dir, string cadena_id)
    {
        cadena_id = eliminar_flecha(cadena_id);
        //        if (dir < 0 || dir > MAX - 1)
        //            throw new Exception("Esta dirección no es valida");
        //        if (cadena_id.empty())
        //            throw new Exception("La cadena ID esta vacía");
        //        if (!hay_al_menos_un_id(cadena_id))
        //            throw new Exception("Tiene que haber almenos un id");

        int z = dir;
        while (z != NULO) {
            if (mem[z].id == cadena_id)
                return mem[z].dato;
            z = mem[z].link;
        }
        return NULO;
    }

    // calcula el espacio disponible
    int CSMemoria::espacio_disponible()
    {
        int x = libre;
        int c = 0;
        while (x != NULO) {
            c++;
            x = mem[x].link;
        }
        return c;
    }

    // calcula el espacio ocupado
    int CSMemoria::espacio_ocupado()
    {
        int c = MAX - espacio_disponible();
        return c;
    }

    // verifica si la dirección esta libre
    bool CSMemoria::dir_libre(int dir)
    {
        int x = libre;
        bool c = false;
        while (x != NULO && !c) {
            if (x == dir)
                c = true;
            x = mem[x].link;
        }
        return c;
    }

    // muestra en la consola la dirección de memoria
    void CSMemoria::mostrar()
    {
        string cab = "       | DIR |  DATO  |    ID    | LINK |\n";
        string lin = "       +" + string(cab.length() - 10, '-') + "+\n";
        string out = lin + cab + lin;
        int edir = 3, edat = 8, eid = 10; // eid variable
        for (int i = 0; i < MAX; i++) {
            string ocup = !dir_libre(i) ? "ocupado" : "       ";
            int rel = edir - to_string(i).length();
            string dir = " " + string(rel, '0') + to_string(i) + " ";
            rel = edat - to_string(mem[i].dato).length();
            string dat = string(rel, ' ') + to_string(mem[i].dato);
            rel = eid - mem[i].id.length();
            string id = string(rel, ' ') + mem[i].id;
            rel = edir - to_string(mem[i].link).length();
            string lnk = "  " + string(rel, ' ') + to_string(mem[i].link) + " ";
            out += ocup + "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
        }
        out += lin;
        out += "Libre = " + to_string(libre) + "\n";
        out += "Espacios libres = " + to_string(espacio_disponible()) + "\n";
        out += "Espacios ocupados = " + to_string(espacio_ocupado()) + "\n";
        cout << out;
    }

    CSMemoria::~CSMemoria()
    {
        delete[] mem;
    }

    // -----------------------------------------------------------------------------

    // devuelve el número de ids
    int CSMemoria::numero_ids(string ids)
    {
        // a,b,c,d
        // ,,,a,b,c,d,,,
        // a,,,b,,,c,,,d
        bool b = false;
        int c = 0;
        for (int i = 0; i < ids.length(); i++) {
            if (ids[i] != ',') {
                if (!b)
                    c++;
                b = true;
            } else
                b = false;
        }
        return c;
    }

    // Obtiene el id indicando el número del id que es
    string CSMemoria::obtener_id(string cadena, int n)
    {
        // a,b,c,d
        // ,,,a,b,c,d,,,
        // a,,,b,,,c,,,d
        string id = "";
        bool b = false;
        int c = 0;
        for (int i = 0; i < cadena.length(); i++) {
            if (cadena[i] != ',') {
                if (!b)
                    c++;

                if (c == n)
                    id += cadena[i];
                b = true;

            } else {
                if (b && c == n) {
                    return id;
                }
                b = false;
            }
        }
        return id;
    }

    // verifica si hay almenos un id
    bool CSMemoria::hay_al_menos_un_id(string cadena)
    {
        for (int i = 0; i < cadena.length(); i++) {
            if (cadena[i] != ',')
                return true;
        }
        return false;
    }

    // elimina la flecha
    string CSMemoria::eliminar_flecha(string cadena)
    {
        if (cadena.length() < 3)
            throw new Exception(
                "La cadena tiene que tener minimo 3 caracteres");
        if (cadena.substr(0, 2) != "->")
            throw new Exception("La cadena necesita una flecha (->)");
        return cadena.substr(2, cadena.length());
    }

    void dibujar_celda(TForm* Form, TColor brushColor, bool withBorder,
        int posX, int posY, String cad)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->Font->Size = 12;
        Canvas->Font->Name = "Microsoft YaHei UI";

        TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);

        int anchoTexto = Canvas->TextWidth(cad);
        int posXCentro = posX + (TamanoCeldaX - anchoTexto) / 2;
        int posYCentro = posY + (TamanoCeldaY - Canvas->TextHeight(cad)) / 2;

        Canvas->Brush->Color = brushColor;
        Canvas->Pen->Color = withBorder ? clBlack : brushColor;
        Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Pen->Color = clBlack;
        Canvas->TextOutW(posXCentro, posYCentro, cad);
    }

    void CSMemoria::dibujar_memoria(
        TForm* Form, int posX, int posY, int a, int b)
    {
        // pending
        if (a > b) {
            throw new Exception("a tiene que ser menor que b");
        }

        Form->Canvas->Brush->Color = Form->Color;
        Form->Canvas->FillRect(Form->Canvas->ClipRect);

        int auxX = posX;
        int auxY = posY;

        //DIBUJAMOS CABECERA
        dibujar_celda(Form, Form->Color, false, posX, posY, "dir");
        posX += TamanoCeldaX;
        dibujar_celda(Form, Form->Color, false, posX, posY, "dato");
        posX += TamanoCeldaX;
        dibujar_celda(Form, Form->Color, false, posX, posY, "id");
        posX += TamanoCeldaX;
        dibujar_celda(Form, Form->Color, false, posX, posY, "link");
        posX = auxX;
        posY += TamanoCeldaY;

        //CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
        for (int i = a; i <= b; i++) {
            if (mem[i].link != libre) {
                // Direccion columna
                dibujar_celda(Form, clBtnFace, false, posX, posY, IntToStr(i));
                posX += TamanoCeldaX;

                // Dato columna
                dibujar_celda(
                    Form, clGreen, true, posX, posY, IntToStr(mem[i].dato));
                posX += TamanoCeldaX;

                // Id columna
                dibujar_celda(
                    Form, clYellow, true, posX, posY, mem[i].id.c_str());
                posX += TamanoCeldaX;

                // Link columna
                dibujar_celda(
                    Form, clYellow, true, posX, posY, IntToStr(mem[i].link));
                posX = auxX;
                posY += TamanoCeldaY;
            }
        }

        String textLibre = "LIBRE: " + String(libre);
        dibujar_celda(Form, Form->Color, false, posX + 20, posY, textLibre);
    }
} // namespace UCSMemoria

