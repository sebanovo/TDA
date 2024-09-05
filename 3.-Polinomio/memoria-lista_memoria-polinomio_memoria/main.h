//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "UCSMemoria/UCSMemoria.h"
#include "UListaPuntero/UListaPuntero.h"
#include "UListaSM/UListaSM.h"
#include "UListaVector/UListaVector.h"
#include "UPolinomioLista/PolinomioLista.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TButton* Button1;
    TButton* Button2;
    TButton* Button3;
    TButton* Button4;
    TButton* Button5;
    TEdit* Edit1;
    TEdit* Edit2;
    TEdit* Edit3;
    TEdit* Edit4;
    TEdit* Edit5;
    TEdit* Edit6;
    TEdit* Edit7;
    TEdit* Edit8;
    TEdit* Edit9;
    TEdit* Edit10;
    TEdit* Edit11;
    TButton* Button6;
    TButton* Button7;
    TButton* Button8;
    TButton* Button9;
    TButton* Button10;
    TButton* Button11;
    TButton* Button12;
    TButton* Button13;
    TImage* Image1;
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
    void __fastcall Button6Click(TObject* Sender);
    void __fastcall Button7Click(TObject* Sender);
    void __fastcall Button8Click(TObject* Sender);
    void __fastcall Button9Click(TObject* Sender);
    void __fastcall Button10Click(TObject* Sender);
    void __fastcall Button11Click(TObject* Sender);
    void __fastcall Button12Click(TObject* Sender);
    void __fastcall Button13Click(TObject* Sender);
  private:
    UCSMemoria::CSMemoria* M; // User declarations
    UListaSM::ListaSM* listaSM;
    UPolinomioLista::PolinomioLista* polinomioLista;
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1()
    {
        delete polinomioLista;
        delete listaSM;
        delete M;
    }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

