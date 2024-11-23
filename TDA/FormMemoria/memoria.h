//---------------------------------------------------------------------------

#ifndef MEMORIAH
#define MEMORIAH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "UCSMemoria/CSMemoria.h"
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
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
  private:
    UCSMemoria::CSMemoria* M; // User declarations
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

