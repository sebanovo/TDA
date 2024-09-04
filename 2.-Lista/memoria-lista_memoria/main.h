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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TButton* Button1;
    TButton* Button2;
    TButton* Button3;
    TButton* Button4;
    TButton* Button5;
    TButton* Button6;
    TButton* Button7;
    TButton* Button8;
    TButton* Button9;
    TEdit* Edit1;
    TEdit* Edit2;
    TEdit* Edit3;
    TEdit* Edit4;
    TEdit* Edit5;
    TEdit* Edit6;
    TEdit* Edit7;
    TEdit* Edit8;
    TEdit* Edit9;
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
    void __fastcall Button6Click(TObject* Sender);
    void __fastcall Button7Click(TObject* Sender);
    void __fastcall Button8Click(TObject* Sender);
    void __fastcall Button9Click(TObject* Sender);
  private:
    UCSMemoria::CSMemoria* M; // User declarations
    UListaSM::ListaSM* listaSM;
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

