//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("DemoLayout.res");
USEFORM("main.cpp", Form1);
USEUNIT("GridLayout.cpp");
USEUNIT("StackLayout.cpp");
USEUNIT("ALayout.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------



