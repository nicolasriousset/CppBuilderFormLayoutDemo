//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), mainLayout(MainPanel, 3, 3), statusLayout(StatusPanel)
{
    // Configuring main layout
    mainLayout.ColDef(0)->SetMinWidth(200);
    mainLayout.ColDef(1)->SetFixedWidth(100);
    mainLayout.RowDef(0)->SetMinHeight(100);
    mainLayout.RowDef(1)->SetFixedHeight(50);
    mainLayout.SetControl(0, 0, Panel1);
    mainLayout.MergeCells(0, 0, 1, 0);
    mainLayout.SetControl(1, 0, Panel2);
    mainLayout.SetControl(2, 0, Panel3);
    mainLayout.SetControl(0, 1, Panel4);
    mainLayout.SetControl(1, 1, Panel5);
    mainLayout.SetControl(2, 1, Panel6);
    mainLayout.SetControl(0, 2, Panel7);
    mainLayout.SetControl(1, 2, Panel8);
    mainLayout.SetControl(2, 2, Panel9);

    // configuring status layout
    statusLayout.Controls().push_back(ButtonA);
    statusLayout.Controls().push_back(ButtonB);
    statusLayout.Controls().push_back(ButtonC);
    statusLayout.SetAlignment(TStackLayout::RIGHT);
    statusLayout.SetOrientation(TStackLayout::HORIZONTAL);

    mainLayout.Align();
    statusLayout.Align();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
    mainLayout.Align();
    statusLayout.Align();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonCClick(TObject *Sender)
{
    ButtonB->Visible = !ButtonB->Visible;
    ButtonC->Caption = ButtonB->Visible ? "Hide B" : "Show B";
    statusLayout.Align();
}
//---------------------------------------------------------------------------

