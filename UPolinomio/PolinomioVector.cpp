//---------------------------------------------------------------------------

#pragma hdrstop

#include <vector>
#include "PolinomioVector.h"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioVector
{
    using std::to_string;
    PolinomioVector::PolinomioVector()
    {
        nt = 0;
        vc = new int[MAX];
        ve = new int[MAX];
    }

    // verifica si no hay terminos
    bool PolinomioVector::es_cero()
    {
        return nt == 0;
    }

    // obtiene el grado del polinomio
    int PolinomioVector::grado()
    {
        // if (nt <= 0)
        //     throw new Exception("No existen terminos");
        int max = ve[1];
        for (int i = 1; i <= nt; i++) {
            if (ve[i] > max)
                max = ve[i];
        }
        return max;
    }

    // devuelve el coeficiente asociado a ese exponente
    int PolinomioVector::coeficiente(int exp)
    {
        for (int i = 1; i <= nt; i++) {
            if (ve[i] == exp)
                return vc[i];
        }
        return 0;
    }

    void PolinomioVector::sumar(PolinomioVector* p1, PolinomioVector* p2)
    {
        for (int i = 1; i <= p1->numero_terminos(); i++) {
            int exp = p1->exponente(i);
            int coef = p1->coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2->numero_terminos(); i++) {
            int exp = p2->exponente(i);
            int coef = p2->coeficiente(exp);
            poner_termino(coef, exp);
        }
    }

    void PolinomioVector::restar(PolinomioVector* p1, PolinomioVector* p2)
    {
        for (int i = 1; i <= p1->numero_terminos(); i++) {
            int exp = p1->exponente(i);
            int coef = p1->coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2->numero_terminos(); i++) {
            int exp = p2->exponente(i);
            int coef = p2->coeficiente(exp) * -1;
            poner_termino(coef, exp);
        }
    }

    void PolinomioVector::multiplicar(PolinomioVector* p1, PolinomioVector* p2)
    {
        // P1 * P2 = (2x + 1) * (3x + 3)
        // 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
        // 6x^2 + 9x + 3
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

    // retorna la direccion del exponente
    int PolinomioVector::buscar_exponente(int exp)
    {
        for (int i = 1; i <= nt; i++) {
            if (ve[i] == exp)
                return i;
        }
        return -1;
    }

    // pone un termino al polinomio
    void PolinomioVector::poner_termino(int coef, int exp)
    {
        int dir_exp = buscar_exponente(exp);
        if (dir_exp == -1) {
            if (coef != 0) {
                vc[nt + 1] = coef;
                ve[nt + 1] = exp;
                nt++;
            }
        } else {
            vc[dir_exp] = coef + vc[dir_exp];
            if (vc[dir_exp] == 0) {
                for (int i = dir_exp; i < nt; i++) {
                    vc[i] = vc[i + 1];
                    ve[i] = ve[i + 1];
                }
                nt--;
            }
        }
    }

    // devuelve el número de terminos
    int PolinomioVector::numero_terminos()
    {
        return nt;
    }

    // devuelvo el exponente asociado al nro de termino
    int PolinomioVector::exponente(int nroTer)
    {
        // if (nroTer < 0 || nroTer > MAX)
        //     new Exception("Fuera de los límites");
        return ve[nroTer];
    }

    // cambia el coeficiente del termino
    void PolinomioVector::asignar_coeficiente(int coef, int exp)
    {
        int dir = buscar_exponente(exp);
        if (dir != -1) {
            vc[dir] = coef;
            if (vc[dir] == 0) {
                for (int i = dir; i < numero_terminos(); i++) {
                    vc[i] = vc[i + 1];
                    ve[i] = ve[i + 1];
                }
            }
        } else {
            throw new Exception("No existe ese exponente");
        }
    }

    // muestra el polinomio
    string PolinomioVector::mostrar()
    {
        string s = "";
        for (int i = 1; i <= nt; i++) {
            s += vc[i] >= 0 && s != "" ? "+" : "";
            s += to_string(vc[i]) + "x^" + to_string(ve[i]) + "  ";
        }
        return s;
    }

    PolinomioVector::~PolinomioVector()
    {
        delete[] vc;
        delete[] ve;
    }

    double PolinomioVector::evaluar(double x)
    {
        double resultado = 0.0;

        for (int i = 1; i <= numero_terminos(); i++) {
            int exp = exponente(i);
            int coef = coeficiente(exp);

            resultado += coef * pow(x, exp);
        }
        return resultado;
    }

    void PolinomioVector::derivada(PolinomioVector* p, PolinomioVector* p1)
    {
        for (int i = 1; i <= p->numero_terminos(); i++) {
            int exp = p->exponente(i);
            int coef = p->coeficiente(exp);
            p1->poner_termino(coef * exp, exp - 1);
        }
    }

    std::string PolinomioVector::mostrar_integral(PolinomioVector* p)
    {
        std::string s = "";
        for (int i = 1; i <= p->numero_terminos(); i++) {
            int exp = p->exponente(i);
            int co = p->coeficiente(exp);

            s += "(" + std::to_string(co) + "x^" + std::to_string(exp + 1) +
                 ")/" + std::to_string(exp + 1) + " + ";
            if (i == p->numero_terminos())
                s += "C";
        }
        return s;
    }

    void PolinomioVector::dibujar_polinomio(TForm* Form, int posX, int posY)
    {
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

    void PolinomioVector::graficar(
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

    void PolinomioVector::graficar_image(TImage* Image, double a, double b)
    {
        TCanvas* Canvas = Image->Canvas;
        Canvas->FillRect(Canvas->ClipRect);

        int ancho = Image->Width;
        int alto = Image->Height;
        //        int factorEscala = 50;
        int factorEscala = 30;
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
        //        double a = -ancho / (2.0 * factorEscala);
        //        double b = a * -1;

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

    void PolinomioVector::graficar_integral(TImage* Image, double a, double b)
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

    void PolinomioVector::graficar_interseccion(TImage* Image,
        PolinomioVector* p1, PolinomioVector* p2, double a, double b)
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

        // dibujar la funcion 1
        bool esContinua = false;
        double limite = alto;

        Canvas->Pen->Color = clBlue;
        Canvas->Pen->Width = 3;
        Canvas->MoveTo(centroX, centroY);

        for (double x = a; x <= b; x += 0.01) {
            int graficoX = centroX + (int)(x * factorEscala);
            double yValor = p1->evaluar(x);
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

        // dibujar la funcion 2
        esContinua = false;

        Canvas->Pen->Color = clRed;
        Canvas->Pen->Width = 3;
        Canvas->MoveTo(centroX, centroY);

        for (double x = a; x <= b; x += 0.01) {
            int graficoX = centroX + (int)(x * factorEscala);
            double yValor = p2->evaluar(x);
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

        // dibujar intersecciones
        // IMPORTANTE SOLO GRAFICA CUANDO LOS PUNTOS SON ENTEROS (X,Y) = (int, int)
        int radio = 5;
        Canvas->Brush->Color = clBlack;
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = factorEscala / 25;
        for (double x = a; x <= b; x += 1) {
            int p1X = centroX + (int)(x * factorEscala);
            int p1Y = centroY - (int)(p1->evaluar(x) * factorEscala);

            int p2X = centroX + (int)(x * factorEscala);
            int p2Y = centroY - (int)(p2->evaluar(x) * factorEscala);

            if (p1X == p2X && p1Y == p2Y) {
                Canvas->Ellipse(
                    p1X - radio, p1Y - radio, p1X + radio, p2Y + radio);
            }
        }

        // dibujar el marco
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = borderWidth;
        Canvas->Brush->Style = bsClear;
        Canvas->Rectangle(0, 0, ancho, alto);
        Canvas->Brush->Style = bsSolid;
    }

    std::string PolinomioVector::intersectar(
        PolinomioVector* p1, PolinomioVector* p2, int a, int b)
    {
        struct Puntos
        {
            int x;
            int y;
        };

        std::vector<Puntos> puntos;

        for (int x = a; x <= b; x++) {
            int p1Y = (int)p1->evaluar(x);
            int p2Y = (int)p2->evaluar(x);

            if (p1Y == p2Y) {
                puntos.push_back({ x : x, y : p1Y });
            }
        }

        if (puntos.empty()) {
            return "No intersectan en ningún punto";
        }
        std::string s = "SOLO PUNTOS ENTEROS Pi = (int, int)\n";
        for (int i = 0; i < puntos.size(); i++) {
            s += "P" + std::to_string(i + 1) + "=" + "(" +
                 std::to_string(puntos[i].x) + "," +
                 std::to_string(puntos[i].y) + ")" + '\n';
        }
        return s;
    }
} // namespace UPolinomioVector

