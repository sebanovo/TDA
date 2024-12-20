//---------------------------------------------------------------------------

#ifndef LISTAH
#define LISTAH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "ULista/ListaPuntero.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
  __published: // IDE-managed Components
    TButton* Button1;
    TButton* Button2;
    TButton* Button3;
    TButton* Button4;
    TEdit* Edit1;
    TEdit* Edit2;
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
  private:
    UListaPuntero::ListaPuntero* lista; // User declarations
  public: // User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2* Form2;
//---------------------------------------------------------------------------
#endif

