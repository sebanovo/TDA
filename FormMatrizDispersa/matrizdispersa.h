//---------------------------------------------------------------------------

#ifndef MATRIZ_DISPERSAH
#define MATRIZ_DISPERSAH
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
#include "UPolinomio/PolinomioPuntero.h"
#include "UPolinomio/PolinomioSM.h"
#include "UPolinomio/PolinomioVector.h"
#include "UConjunto/ConjuntoLista.h"
#include "UConjunto/ConjuntoPuntero.h"
#include "UConjunto/ConjuntoSM.h"
#include "UConjunto/ConjuntoVector.h"
#include "UMatrizDispersa/MatrizDispersaVector.h"
#include "UMatrizDispersa/MatrizDispersaCSR.h"
#include "UMatrizDispersa/MatrizDispersaPuntero.h"
#include "UMatrizDispersa/MatrizDispersaSM.h"
#include "UMatrizDispersa/MatrizDispersaPunteroDoble.h"
#include "UMatrizDispersa/MatrizDispersaSMDoble.h"
//---------------------------------------------------------------------------
class TForm9 : public TForm
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
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
  private:
    UMatrizDispersaVector::MatrizDispersaVector* Matriz; // User declarations
  public: // User declarations
    __fastcall TForm9(TComponent* Owner);
    __fastcall ~TForm9()
    {
        delete Matriz;
    };
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9* Form9;
//---------------------------------------------------------------------------
#endif

