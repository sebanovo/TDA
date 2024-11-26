// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
// ---------------------------------------------------------------------------
USEFORM("FormMatrizDispersa\memoria-matrizdispersa_memoria.cpp", Form8);
USEFORM("FormMatrizDispersa\matrizdispersa.cpp", Form9);
USEFORM("FormLista\memoria-lista_memoria.cpp", Form3);
USEFORM("FormPila\memoria-pila_memoria.cpp", Form10);
USEFORM("FormPila\memoria-pila_memoria_matrizdispersa_memoria.cpp", Form11);
USEFORM("FormMemoria\memoria.cpp", Form1);
USEFORM("FormLista\lista.cpp", Form2);
USEFORM("FormCola\cola.cpp", Form14);
USEFORM("FormColaPrioridad\cola_prioridad.cpp", Form15);
USEFORM("FormConjunto\memoria-conjunto_memoria.cpp", Form6);
USEFORM("FormConjunto\conjunto.cpp", Form7);
USEFORM("FormCola\memoria-cola_memoria.cpp", Form13);
USEFORM("FormPolinomio\polinomio.cpp", Form5);
USEFORM("FormPolinomio\memoria-polinomio_memoria.cpp", Form4);
USEFORM("FormPila\pila.cpp", Form12);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TForm10), &Form10);
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
// ---------------------------------------------------------------------------
