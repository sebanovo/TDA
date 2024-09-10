
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

    double PolinomioPuntero::evaluar(double x)
    {
        double resultado = 0.0;

        for (int i = 1; i <= numero_terminos(); i++) {
            int exp = exponente(i);
            int coef = coeficiente(exp);

            resultado += coef * pow(x, exp);
        }
        return resultado;
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

    void PolinomioPuntero::dibujar_polinomio(TForm* Form, int posX, int posY)
    {
        // ls->dibujar_lista(Form, posX, posY);

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

    void PolinomioPuntero::graficar(
        TForm* Form, int posX, int posY, int ancho, int alto)
    {
        TCanvas* Canvas = Form->Canvas;
        TRect rect(posX, posY, posX + ancho, posY + alto);
        Canvas->FillRect(rect);
        HDC hdc = Canvas->Handle;
        int savedDC = SaveDC(hdc);
        IntersectClipRect(hdc, posX, posY, posX + ancho, posY + alto);

        int factorEscala = 50;
        int borderWidth = 8;

        // pintar el fondo
        Canvas->Brush->Color = clBtnFace;
        Canvas->Pen->Style = psClear;
        Canvas->Rectangle(posX, posY, posX + ancho, posY + alto);
        Canvas->Pen->Style = psSolid;

        Canvas->Pen->Color = clBlack;
        Canvas->Brush->Color = clBtnFace;
        Canvas->Pen->Width = 8;

        // dibujar los ejes
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = 2;
        Canvas->MoveTo(posX + ancho / 2, posY);
        Canvas->LineTo(posX + ancho / 2, posY + alto);
        Canvas->MoveTo(posX, posY + alto / 2);
        Canvas->LineTo(posX + ancho, posY + alto / 2);
        int centroX = posX + ancho / 2;
        int centroY = posY + alto / 2;

        // dibujar las | del eje X
        for (int i = centroX; i < posX + ancho; i += factorEscala) {
            if (i > centroX && i < posX + ancho) {
                Canvas->Pen->Width = 3;
                Canvas->Pen->Color = clScrollBar;

                // verticales +
                Canvas->MoveTo(i, posY);
                Canvas->LineTo(i, posY + alto);

                // verticales -
                Canvas->MoveTo(2 * centroX - i, posY);
                Canvas->LineTo(2 * centroX - i, posY + alto);

                Canvas->Pen->Width = 2;
                Canvas->Pen->Color = clBlack;
            }
            // +x
            Canvas->MoveTo(i, centroY - 5);
            Canvas->LineTo(i, centroY + 5);

            // -x
            Canvas->MoveTo(2 * centroX - i, centroY - 5);
            Canvas->LineTo(2 * centroX - i, centroY + 5);
        }

        // dibujar las | del eje Y
        for (int j = centroY; j < posY + alto; j += factorEscala) {
            if (j > centroY && j < posY + alto) {
                Canvas->Pen->Width = 3;
                Canvas->Pen->Color = clScrollBar;

                // horizontales +
                Canvas->MoveTo(posX, j);
                Canvas->LineTo(posX + ancho, j);

                // horizontales -
                Canvas->MoveTo(posX, 2 * centroY - j);
                Canvas->LineTo(posX + ancho, 2 * centroY - j);

                Canvas->Pen->Width = 2;
                Canvas->Pen->Color = clBlack;
            }
            // +y
            Canvas->MoveTo(centroX - 5, j);
            Canvas->LineTo(centroX + 5, j);

            // -y
            Canvas->MoveTo(centroX - 5, 2 * centroY - j);
            Canvas->LineTo(centroX + 5, 2 * centroY - j);
        }

        // dibujar la funcion
        bool esContinua = false;
        double limite = alto;
        Canvas->Pen->Color = clBlue;
        Canvas->Pen->Width = 3;
        double a = -ancho / (2.0 * factorEscala);
        double b = a * -1;

        Canvas->MoveTo(centroX, centroY);

        for (double x = a; x <= b; x += 0.01) {
            int graficoX = centroX + (int)(x * factorEscala);
            double yValor = evaluar(x);
            int graficoY = centroY - (int)(yValor * factorEscala);

            // Limitar los valores extremos
            if (std::abs(yValor) > limite) {
                esContinua = false;
            } else {
                if (esContinua) {
                    Canvas->LineTo(graficoX, graficoY);
                } else {
                    Canvas->MoveTo(graficoX, graficoY);
                    esContinua = true;
                }
            }
        }

        // dibujar el marco
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = borderWidth;
        Canvas->Brush->Style = bsClear;
        Canvas->Rectangle(rect);
        Canvas->Brush->Style = bsSolid;
        RestoreDC(hdc, savedDC);
    }

    void PolinomioPuntero::graficar_image(TImage* Image)
    {
        TCanvas* Canvas = Image->Canvas;
        Canvas->FillRect(Canvas->ClipRect);

        int ancho = Image->Width;
        int alto = Image->Height;
        int factorEscala = 50;
        int borderWidth = 8;

        // pintar el fondo
        Canvas->Brush->Color = clBtnFace;
        Canvas->Pen->Style = psClear;
        Canvas->Rectangle(0, 0, ancho, alto);
        Canvas->Pen->Style = psSolid;

        // dibujar los ejes
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = 2;
        Canvas->MoveTo(ancho / 2, 0);
        Canvas->LineTo(ancho / 2, alto);
        Canvas->MoveTo(0, alto / 2);
        Canvas->LineTo(ancho, alto / 2);

        // dibujar las | del eje X
        int centroX = ancho / 2;
        int centroY = alto / 2;
        for (int i = centroX; i < ancho; i += factorEscala) {
            if (i > centroX && i < ancho) {
                Canvas->Pen->Width = 1;
                Canvas->Pen->Color = clScrollBar;

                // verticales +
                Canvas->MoveTo(i, 0);
                Canvas->LineTo(i, alto);

                // verticales -
                Canvas->MoveTo(ancho - i, 0);
                Canvas->LineTo(ancho - i, alto);

                Canvas->Pen->Width = 2;
                Canvas->Pen->Color = clBlack;
            }

            // +x
            Canvas->MoveTo(i, centroY - 5);
            Canvas->LineTo(i, centroY + 5);

            // -x
            Canvas->MoveTo(ancho - i, centroY - 5);
            Canvas->LineTo(ancho - i, centroY + 5);
        }

        // dibujar las | del eje Y
        for (int i = centroY; i < alto; i += factorEscala) {
            if (i > centroY && i < alto) {
                Canvas->Pen->Width = 1;
                Canvas->Pen->Color = clScrollBar;

                // horizantales +
                Canvas->MoveTo(0, alto - i);
                Canvas->LineTo(ancho, alto - i);

                // horizantes -
                Canvas->MoveTo(0, i);
                Canvas->LineTo(ancho, i);

                Canvas->Pen->Width = 2;
                Canvas->Pen->Color = clBlack;
            }

            // +y
            Canvas->MoveTo(centroX - 5, i);
            Canvas->LineTo(centroX + 5, i);

            // -y
            Canvas->MoveTo(centroX - 5, alto - i);
            Canvas->LineTo(centroX + 5, alto - i);
        }

        // dibujar la funcion
        bool esContinua = false;
        double limite = alto;
        double a = -ancho / (2.0 * factorEscala);
        double b = a * -1;

        Canvas->Pen->Color = clBlue;
        Canvas->Pen->Width = 3;
        Canvas->MoveTo(centroX, centroY);

        for (double x = a; x <= b; x += 0.01) {
            int graficoX = centroX + (int)(x * factorEscala);
            double yValor = evaluar(x);
            int graficoY = centroY - (int)(yValor * factorEscala);

            // Limitar los valores extremos
            if (std::abs(yValor) > limite) {
                esContinua = false;
            } else {
                if (esContinua) {
                    Canvas->LineTo(graficoX, graficoY);
                } else {
                    Canvas->MoveTo(graficoX, graficoY);
                    esContinua = true;
                }
            }
        }

        // dibujar el marco
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = borderWidth;
        Canvas->Brush->Style = bsClear;
        Canvas->Rectangle(0, 0, ancho, alto);
        Canvas->Brush->Style = bsSolid;
    }

    void PolinomioPuntero::graficarIntegral(TImage* Image, double a, double b)
    {
        TCanvas* Canvas = Image->Canvas;
        int alto = Image->Height;
        int ancho = Image->Width;
        int factorEscala = 50;
        int borderWidth = 8;
        int centroX = Image->Width / 2;
        int centroY = Image->Height / 2;
        int limite = alto;

        double dx = 0.001;

        Canvas->Pen->Width = 1;
        Canvas->Pen->Color = clBackground;
        Canvas->Brush->Style = bsSolid;
        Canvas->MoveTo(centroX, centroY);

        // Parte derecha (x >= 0)
        for (double x = 0; x <= b; x += dx) {
            int graficoX1 = centroX + (int)(x * factorEscala);
            int graficoX2 = centroX + (int)((x + dx) * factorEscala);
            double yValor = evaluar(x);
            int graficoY = centroY - (int)(yValor * factorEscala);

            if (std::abs(yValor) <= limite) {
                TRect rect(graficoX1, centroY, graficoX2, graficoY);
                Canvas->Rectangle(rect);
            }
        }

        // Parte izquierda (x <= 0)
        for (double x = 0; x >= a; x -= dx) {
            int graficoX1 = centroX + (int)(x * factorEscala);
            int graficoX2 = centroX + (int)((x - dx) * factorEscala);
            double yValor = evaluar(x);
            int graficoY = centroY - (int)(yValor * factorEscala);

            if (std::abs(yValor) <= limite) {
                TRect rect(graficoX2, centroY, graficoX1, graficoY);
                Canvas->Rectangle(rect);
            }
        }

        // dibujar el marco
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = borderWidth;
        Canvas->Brush->Style = bsClear;
        Canvas->Rectangle(0, 0, ancho, alto);
        Canvas->Brush->Style = bsSolid;
    }
} // namespace UPolinomioPuntero

