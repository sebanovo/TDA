//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "polinomio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5* Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject* Sender)
{
    pol1 = new UPolinomioPuntero::PolinomioPuntero;
}

//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject* Sender)
{
    pol2 = new UPolinomioPuntero::PolinomioPuntero;
}

//---------------------------------------------------------------------------
void _fastcall TForm5::Button3Click(TObject* Sender)
{
    int coef = Edit1->Text.ToInt();
    int exp = Edit2->Text.ToInt();

    pol1->poner_termino(coef, exp);
}

//---------------------------------------------------------------------------
void __fastcall TForm5::Button4Click(TObject* Sender)
{
    int coef = Edit3->Text.ToInt();
    int exp = Edit4->Text.ToInt();

    pol2->poner_termino(coef, exp);
}

//---------------------------------------------------------------------------
void __fastcall TForm5::Button5Click(TObject* Sender)
{
    int posX = 300;
    int posY = 900;
    double a = Edit5->Text.ToDouble();
    double b = Edit6->Text.ToDouble();

    Canvas->FillRect(Canvas->ClipRect);

    UPolinomioPuntero::PolinomioPuntero::graficar_interseccion(
        Image1, pol1, pol2, a, b);
    pol1->dibujar_polinomio(Form5, 700, 800);
    pol2->dibujar_polinomio(Form5, 700, 900);
    // polinomioLista->graficar(Form5, 600, 10, 700, 700);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button6Click(TObject* Sender)
{
    int a = Edit5->Text.ToInt();
    int b = Edit6->Text.ToInt();
    std::string re =
        UPolinomioPuntero::PolinomioPuntero::intersectar(pol1, pol2, a, b);
    ShowMessage(re.c_str());
}

//---------------------------------------------------------------------------

