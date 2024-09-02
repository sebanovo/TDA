#include <vcl.h>

#pragma hdrstop
#include "main.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}

void __fastcall TForm1::FormCreate(TObject* Sender)
{
    Image1->Stretch = true;
    Image1->Picture->LoadFromFile(
        "C:\\Users\\HP\\Documents\\Embarcadero\\Studio\\Projects\\Canvas\\public\\img\\tensor.png");
}

void __fastcall TForm1::FormPaint(TObject* Sender)
{
    // Establecer el color de la pluma y el grosor
    Canvas->Pen->Color = clRed;
    Canvas->Pen->Width = 2;

    // Establecer el color del pincel (relleno)
    Canvas->Brush->Color = clYellow;

    // Dibujar un rectángulo
    Canvas->Rectangle(50, 50, 200, 150);

    // Dibujar una línea
    Canvas->MoveTo(50, 50);
    Canvas->LineTo(200, 150);

    // Dibujar un texto
    Canvas->Font->Size = 16;
    Canvas->Font->Color = clBlue;
    Canvas->TextOut(60, 160, "Hola, Canvas!");
}

