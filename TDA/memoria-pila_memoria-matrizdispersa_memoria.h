//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.StdCtrls.hpp>

#include "UCSMemoria/CSMemoria.h"
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
#include "ULista/ListaPuntero.h"
#include "UMatrizDispersa/MatrizDispersaCSR.h"
#include "UMatrizDispersa/MatrizDispersaPuntero.h"
#include "UMatrizDispersa/MatrizDispersaPunteroDoble.h"
#include "UMatrizDispersa/MatrizDispersaSM.h"
#include "UMatrizDispersa/MatrizDispersaSMDoble.h"
#include "UMatrizDispersa/MatrizDispersaVector.h"
#include "UPila/PilaCadena.h"
#include "UPila/PilaEntero.h"
#include "UPila/PilaLista.h"
#include "UPila/PilaPuntero.h"
#include "UPila/PilaSM.h"
#include "UPila/PilaVector.h"
#include "UPila/PilaGenerica.h"
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
  __published: // IDE-managed Components
    TButton* Button1;
    TButton* Button2;
    TButton* Button3;
    TButton* Button4;
    TButton* Button5;
    TButton* Button6;
    TButton* Button7;
    TButton* Button9;
    TButton* Button10;
    TButton* Button11;
    TButton* Button12;
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
  private:
    UCSMemoria::CSMemoria* M; // User declarations
    //    UPilaSM::PilaSM* pila;
    UPilaVector::PilaVector* pila;
    UPilaVector::PilaVector* pila2;
    UMatrizDispersaSM::MatrizDispersaSM* matriz;
  public: // User declarations
    __fastcall TForm11(TComponent* Owner);
    __fastcall ~TForm11();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11* Form11;
//---------------------------------------------------------------------------
#endif

