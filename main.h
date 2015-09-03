//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "GridLayout.h"
#include "StackLayout.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
    TPanel *MainPanel;
    TPanel *StatusPanel;
    TPanel *Panel7;
    TPanel *Panel8;
    TPanel *Panel9;
    TPanel *Panel6;
    TPanel *Panel5;
    TPanel *Panel4;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TButton *ButtonC;
    TButton *ButtonB;
    TButton *ButtonA;
    void __fastcall FormResize(TObject *Sender);
    void __fastcall ButtonCClick(TObject *Sender);
private:	// Déclarations de l'utilisateur
    TGridLayout mainLayout;
    TStackLayout statusLayout;
public:		// Déclarations de l'utilisateur
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
