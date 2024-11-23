// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
// ---------------------------------------------------------------------------
USEFORM("FormMemoria\memoria.cpp", Form1);
USEFORM("FormLista\lista.cpp", Form2);
USEFORM("FormLista\memoria-lista_memoria.cpp", Form3);
USEFORM("FormPolinomio\memoria-polinomio_memoria.cpp", Form4);
USEFORM("FormPolinomio\polinomio.cpp", Form5);
USEFORM("FormConjunto\memoria-conjunto_memoria.cpp", Form6);
USEFORM("FormConjunto\conjunto.cpp", Form7);
USEFORM("FormMatrizDispersa\memoria-matrizdispersa_memoria.cpp", Form8);
USEFORM("FormMatrizDispersa\matrizdispersa.cpp", Form9);
USEFORM("FormPila\memoria-pila_memorie.cpp", Form10);
USEFORM("FormPila\memoria-pila_memoria-matrizdispersa_memoria.cpp", Form11);
USEFORM("FormPila\pila.cpp", Form12);
USEFORM("FormCola\memoria-cola_memoria.cpp", Form13);
USEFORM("FormCola\cola.cpp", Form14);
USEFORM("FormColaPrioridad\cola_prioridad.cpp", Form15);

//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try {
        Application->Initialize();
        Application->CreateForm(__classid(TForm1), &Form1);
        //        Application->CreateForm(__classid(TForm2), &Form2);
        //        Application->CreateForm(__classid(TForm3), &Form3);
        //        Application->CreateForm(__classid(TForm4), &Form4);
        //        Application->CreateForm(__classid(TForm5), &Form5);
        //        Application->CreateForm(__classid(TForm6), &Form6);
        //        Application->CreateForm(__classid(TForm7), &Form7);
        //        Application->CreateForm(__classid(TForm8), &Form8);
        //        Application->CreateForm(__classid(TForm9), &Form9);
        //        Application->CreateForm(__classid(TForm10), &Form10);
        //        Application->CreateForm(__classid(TForm11), &Form11);
        //        Application->CreateForm(__classid(TForm12), &Form12);
        //        Application->CreateForm(__classid(TForm13), &Form13);
        //        Application->CreateForm(__classid(TForm14), &Form14);
        //        Application->CreateForm(__classid(TForm15), &Form15);
        Application->Run();
    } catch (Exception &exception) {
        Application->ShowException(&exception);
    }
    return 0;
}
// ---------------------------------------------------------------------------

