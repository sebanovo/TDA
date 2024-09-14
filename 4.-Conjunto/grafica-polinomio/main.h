//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "UCSMemoria/UCSMemoria.h"
#include "ULista/UListaPuntero.h"
#include "ULista/UListaSM.h"
#include "ULista/UListaVector.h"
#include "UPolinomio/PolinomioLista.h"
#include "UPolinomio/PolinomioSM.h"
#include "UPolinomio/PolinomioVector.h"
#include "UPolinomio/PolinomioPuntero.h"
#include "UConjunto/ConjuntoLista.h"
#include "UConjunto/ConjuntoPuntero.h"
#include "UConjunto/ConjuntoSM.h"
#include "UConjunto/ConjuntoVector.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TButton* Button1;
    TButton* Button2;
    TEdit* Edit1;
    TImage* Image1;
    TButton* Button3;
    TButton* Button4;
    TButton* Button5;
    TButton* Button6;
    TButton* Button7;
    TButton* Button8;
    TButton* Button9;
    TButton* Button10;
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
  private:
    UCSMemoria::CSMemoria* M; // User declarations
    UConjuntoSM::ConjuntoSM* A;
    UConjuntoSM::ConjuntoSM* B;
    UConjuntoSM::ConjuntoSM* C;
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

