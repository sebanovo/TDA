

//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioLista.h"
#include "windows.h"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioLista
{
    using UCSMemoria::NULO;

    PolinomioLista::PolinomioLista()
    {
        // mem = new UCSMemoria::CSMemoria;
        // ls = new UListaSM::ListaSM(mem);
        ls = new UListaVector::ListaVector;
    }

    PolinomioLista::PolinomioLista(UCSMemoria::CSMemoria* m)
    {
        // ls = new UListaSM::ListaSM(m);
        ls = new UListaVector::ListaVector;
    }

    // Retorna el exponente del término
    int PolinomioLista::exponente(int nroTer)
    {
        int dir = buscar_termino_n(nroTer);

        if (dir != -1) {
            return ls->recupera(ls->siguiente(dir));
        }
    }

    // devuelve la direccion del termino del exponente (osea un nodo)
    int PolinomioLista::buscar_exponente(int exp)
    {
        int dir = ls->siguiente(ls->primero());

        int direxp = -1;
        if (dir != -1) {
            while (dir != -1 && direxp == -1 && dir <= ls->fin()) {
                if (dir <= ls->fin()) {
                    if (ls->recupera(dir) == exp) {
                        return direxp = dir;
                    }

                    dir = ls->siguiente(ls->siguiente(dir));
                }
            }
            return direxp;
        }
        return -1;
    }

    // devuelve la direccino del termino n
    int PolinomioLista::buscar_termino_n(int n)
    {
        int dir = ls->primero();
        int nt = 0;
        if (dir != -1) {
            int dirter = -1;
            while (dir != -1 && dirter == -1) {
                nt++;
                if (nt == n) {
                    dirter = dir;
                }
                dir = ls->siguiente(ls->siguiente(dir));
            }
            return dirter;
        } else
            return -1;
    }

    bool PolinomioLista::es_cero()
    {
        return ls->_longitud() == 0;
    }

    int PolinomioLista::grado()
    {
        int dir = ls->siguiente(ls->primero());
        if (dir != -1) {
            int MaxG = ls->recupera(dir);
            while (dir != -1 && dir <= ls->fin()) {
                if (ls->recupera(dir) > MaxG) {
                    MaxG = ls->recupera(dir);
                }
                dir = ls->siguiente(ls->siguiente(dir));
            }
            return MaxG;
        } else
            return -1;
    }

    // devuelve el coeficiente del exponente del termino
    int PolinomioLista::coeficiente(int exp)
    {
        int dir = buscar_exponente(exp);
        if (dir != -1) {
            return ls->recupera(ls->anterior(dir));
        } else
            return -1;
    }

    void PolinomioLista::asignar_coeficiente(int coef, int exp)
    {
        int dir = buscar_exponente(exp);
        if (dir != -1) {
            int dirCoef = ls->anterior(dir);
            ls->modifica(dirCoef, coef);
            if (coef == 0) {
                ls->suprime(dir);
                ls->suprime(dirCoef);
            }
        }
    }

    void PolinomioLista::poner_termino(int coef, int exp)
    {
        int direxp = buscar_exponente(exp);
        if (direxp != -1) {
            int dirCoef = ls->anterior(direxp);
            ls->modifica(dirCoef, ls->recupera((dirCoef)) + coef);
            if (ls->recupera(dirCoef) == 0) {
                ls->suprime(direxp);
                ls->suprime(dirCoef);
            }
        } else {
            if (coef != 0) {
                ls->inserta_ultimo(exp);
                ls->inserta(ls->fin(), coef);
            }
        }
    }

    int PolinomioLista::numero_terminos()
    {
        return ls->_longitud() / 2;
    }

    void PolinomioLista::poner_en_cero()
    {
        int p = ls->primero();
        while (ls->_longitud() != 0) {
            ls->suprime(p);
            p = ls->siguiente(p);
        }
    }

    // P1 + P2
    void PolinomioLista::sumar(PolinomioLista* p1, PolinomioLista* p2)
    {
        // poner_en_cero();
        for (int i = 1; i <= p1->numero_terminos(); i++) {
            int ex = p1->exponente(i);
            int co = p1->coeficiente(ex);
            poner_termino(co, ex);
        }
        for (int i = 1; i <= p2->numero_terminos(); i++) {
            int ex = p2->exponente(i);
            int co = p2->coeficiente(ex);
            poner_termino(co, ex);
        }
    }

    // P1 - P2
    void PolinomioLista::restar(PolinomioLista* p1, PolinomioLista* p2)
    {
        // poner_en_cero();
        for (int i = 1; i <= p1->numero_terminos(); i++) {
            int ex = p1->exponente(i);
            int co = p1->coeficiente(ex);
            poner_termino(co, ex);
        }
        for (int i = 1; i <= p2->numero_terminos(); i++) {
            int ex = p2->exponente(i);
            int co = p2->coeficiente(ex) * -1;
            poner_termino(co, ex);
        }
    }

    // P1 * P2
    void PolinomioLista::multiplicar(PolinomioLista* p1, PolinomioLista* p2)
    {
        // = (2x + 1) * (3x + 3)
        // = 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
        // = 6x^2 + 9x + 3
        for (int i = 1; i <= p1->numero_terminos(); i++) {
            for (int j = 1; j <= p2->numero_terminos(); j++) {
                int exp1 = p1->exponente(i);
                int coef1 = p1->coeficiente(exp1);

                int exp2 = p2->exponente(j);
                int coef2 = p2->coeficiente(exp2);

                poner_termino(coef1 * coef2, exp1 + exp2);
            }
        }
    }

    double PolinomioLista::evaluar(double x)
    {
        double resultado = 0.0;

        for (int i = 1; i <= numero_terminos(); i++) {
            int exp = exponente(i);
            int coef = coeficiente(exp);

            resultado += coef * pow(x, exp);
        }
        return resultado;
    }

    std::string PolinomioLista::mostrar()
    {
        std::string s = "";
        for (int i = 1; i <= numero_terminos(); i++) {
            int exp = exponente(i);
            int coef = coeficiente(exp);

            s += coef >= 0 && s != "" ? "+" : "";
            s += std::to_string(coef) + "x^" + std::to_string(exp) + "  ";
        }
        return s;
    }

    PolinomioLista::~PolinomioLista()
    {
        delete ls;
        delete mem;
    }

    void derivada(PolinomioLista* p, PolinomioLista* p1)
    {
        for (int i = 1; i <= p->numero_terminos(); i++) {
            int exp = p->exponente(i);
            int co = p->coeficiente(exp);
            p->poner_termino(co * exp, exp - 1);
        }
    };

    std::string mostrar_integral(PolinomioLista p)
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

    void PolinomioLista::dibujar_polinomio(TForm* Form, int posX, int posY)
    {
        ls->dibujar_lista(Form, posX, posY);
    }

    void PolinomioLista::graficar(
        TForm* Form, int posX, int posY, double ancho, double alto)
    {
        TCanvas* Canvas = Form->Canvas;
        Canvas->FillRect(Canvas->ClipRect);
        HDC hdc = Canvas->Handle;
        int savedDC = SaveDC(hdc);
        IntersectClipRect(hdc, posX, posY, posX + ancho, posY + alto);

        int factorEscala = 50;

        Canvas->Pen->Color = clBlack;
        Canvas->Brush->Color = clBtnFace;
        Canvas->Pen->Width = 8;

        // dibujar el marco
        Canvas->Rectangle(posX, posY, posX + ancho, posY + alto);

        // dibujar los ejes
        Canvas->Pen->Width = 1;
        Canvas->MoveTo(posX + ancho / 2, posY);
        Canvas->LineTo(posX + ancho / 2, posY + alto);
        Canvas->MoveTo(posX, posY + alto / 2);
        Canvas->LineTo(posX + ancho, posY + alto / 2);

        for (int i = posX; i < posX + ancho; i = i + 50) {
            Canvas->MoveTo(i, posY + alto / 2 - 5);
            Canvas->LineTo(i, posY + alto / 2 + 5);
        }

        for (int i = posY; i < posY + alto; i = i + 50) {
            Canvas->MoveTo(posX + ancho / 2 - 5, i);
            Canvas->LineTo(posX + ancho / 2 + 5, i);
        }

        // Dibujar la función
        Canvas->Pen->Color = clBlue;
        Canvas->Pen->Width = 3;
        int centroX = posX + ancho / 2;
        int centroY = posY + alto / 2;

        bool dentroDelMarco = false;

        for (double x = -ancho / (2.0 * factorEscala);
             x <= ancho / (2.0 * factorEscala); x += 0.01)
        {
            int graficoX = centroX + static_cast<int>(x * factorEscala);
            int graficoY =
                centroY - static_cast<int>(evaluar(x) * factorEscala);

            if (x == -ancho / (2.0 * factorEscala)) {
                Canvas->MoveTo(graficoX, graficoY);
            } else {
                Canvas->LineTo(graficoX, graficoY);
            }
        }

        RestoreDC(hdc, savedDC);
        Canvas->Pen->Width = 1;
    }

    void PolinomioLista::graficar_image(TImage* Image)
    {
        TCanvas* Canvas = Image->Canvas;

        int factorEscala = 50;
        int ancho = Image->Width;
        int alto = Image->Height;
        int borderWidth = 8;

        // pintar el fondo
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = borderWidth;
        Canvas->Pen->Style = psClear;
        Canvas->Brush->Color = clBtnFace;
        Canvas->Rectangle(0, 0, ancho, alto);
        Canvas->Pen->Style = psSolid;

        // dibujar los ejes
        Canvas->Pen->Width = 2;
        Canvas->MoveTo(ancho / 2, 0);
        Canvas->LineTo(ancho / 2, alto);
        Canvas->MoveTo(0, alto / 2);
        Canvas->LineTo(ancho, alto / 2);
        int centroX = ancho / 2;
        int centroY = alto / 2;

        // dibujar los | de los ejes
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

                // horizantales +
                Canvas->MoveTo(0, alto - i);
                Canvas->LineTo(ancho, alto - i);

                // horizantes -
                Canvas->MoveTo(0, i);
                Canvas->LineTo(ancho, i);

                Canvas->Pen->Width = 2;
                Canvas->Pen->Color = clBlack;
            }

            // +x
            Canvas->MoveTo(i, centroY - 5);
            Canvas->LineTo(i, centroY + 5);

            // -x
            Canvas->MoveTo(ancho - i, centroY - 5);
            Canvas->LineTo(ancho - i, centroY + 5);

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
        Canvas->Pen->Color = clBlue;
        Canvas->Pen->Width = 3;

        Canvas->MoveTo(centroX, centroY);

        for (double x = -ancho / (2.0 * factorEscala);
             x <= ancho / (2.0 * factorEscala); x += 0.01)
        {
            int graficoX = centroX + (int)(x * factorEscala);
            double yValor = evaluar(x);
            int graficoY = centroY - (int)(yValor * factorEscala);

            // Limitar los valores extremos
            if (abs(yValor) > limite) {
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

} // namespace UPolinomioLista

