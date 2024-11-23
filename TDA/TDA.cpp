// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
// ---------------------------------------------------------------------------
USEFORM("polinomio.cpp", Form5);
USEFORM("memoria.cpp", Form1);
USEFORM("lista.cpp", Form2);
USEFORM("memoria-conjunto_memoria.cpp", Form6);
USEFORM("memoria-lista_memoria.cpp", Form3);
USEFORM("memoria-polinomio_memoria.cpp", Form4);
USEFORM("conjunto.cpp", Form7);
USEFORM("memoria-matrizdispersa_memoria.cpp", Form8);
USEFORM("matrizdispersa.cpp", Form9);
USEFORM("memoria-pila_memorie.cpp", Form10);
USEFORM("memoria-pila_memoria-matrizdispersa_memoria.cpp", Form11);
USEFORM("pila.cpp", Form12);
USEFORM("memoria-cola_memoria.cpp", Form13);
USEFORM("cola.cpp", Form14);
USEFORM("cola_prioridad.cpp", Form15);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try {
        Application->Initialize();
        //        Application->MainFormOnTaskBar = true;
        //        Application->CreateForm(__classid(TForm1), &Form1);
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
        Application->CreateForm(__classid(TForm15), &Form15);
        Application->Run();
    } catch (Exception &exception) {
        Application->ShowException(&exception);
    }
    return 0;
}
// ---------------------------------------------------------------------------

