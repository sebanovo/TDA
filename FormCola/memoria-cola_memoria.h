//---------------------------------------------------------------------------

#ifndef MEMORIA_COLAH
#define MEMORIA_COLAH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>

#include "UCSMemoria/CSMemoria.h"
#include "ULista/ListaPuntero.h"
#include "ULista/ListaSM.h"
#include "ULista/ListaVector.h"
#include "UPolinomio/PolinomioLista.h"
#include "UPolinomio/PolinomioSM.h"
#include "UPolinomio/PolinomioVector.h"
#include "UPolinomio/PolinomioPuntero.h"
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
#include "UPila/PilaVector.h"
#include "UPila/PilaLista.h"
#include "UPila/PilaPuntero.h"
#include "UPila/PilaSM.h"
#include "UPila/PilaEntero.h"
#include "UPila/PilaCadena.h"
#include "UPila/PilaGenerica.h"
#include "UCola/ColaVectorV1.h"
#include "UCola/ColaVectorV2.h"
#include "UCola/ColaVectorV3.h"
#include "UCola/ColaPuntero.h"
#include "UCola/ColaSM.h"
#include "UCola/ColaGenerica.h"
//---------------------------------------------------------------------------
class TForm13 : public TForm
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
    TButton* Button6;
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Button2Click(TObject* Sender);
    void __fastcall Button3Click(TObject* Sender);
    void __fastcall Button4Click(TObject* Sender);
    void __fastcall Button6Click(TObject* Sender);
    void __fastcall Button5Click(TObject* Sender);
  private:
    UCSMemoria::CSMemoria* M; // User declaration
    UColaSM::ColaSM* cola;
  public: // User declarations
    __fastcall TForm13(TComponent* Owner);
    __fastcall ~TForm13();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13* Form13;
//---------------------------------------------------------------------------
#endif

