//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "UCSMemoria/CSMemoria.h"
#include "ULista/ListaPuntero.h"
#include "ULista/ListaSM.h"
#include "ULista/ListaVector.h"
#include "UPolinomio/PolinomioLista.h"
#include "UPolinomio/PolinomioSM.h"
#include "UPolinomio/PolinomioPuntero.h"
#include "UPolinomio/PolinomioVector.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TEdit* Edit1;
    TEdit* Edit2;
    TEdit* Edit3;
    TEdit* Edit4;
    TEdit* Edit5;
    TEdit* Edit6;
    TButton* Button1;
    TButton* Button2;
    TButton* Button3;
    TButton* Button4;
    TButton* Button5;
    TButton* Button6;
    TImage* Image1;
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
    void __fastcall Button6Click(TObject* Sender);
  private:
    UPolinomioPuntero::PolinomioPuntero* pol1;
    UPolinomioPuntero::PolinomioPuntero* pol2;
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1()
    {
        delete pol1;
        delete pol2;
    }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

