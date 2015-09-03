//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StackLayout.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

#define _countof(x) (sizeof(x) / sizeof(x[0]))

TStackLayout::TStackLayout(TWinControl* aParent)
    :   ALayout(aParent),
        orientation(HORIZONTAL),
        alignment(RIGHT),
        margin(4)
{
}

bool TStackLayout::mustDisplayControl(TControl* control) const
{
    return control != NULL && control->Visible;
}

void TStackLayout::DoHAlignLeft()
{
    int left = GetRect().left + margin;

    for (CONTROL_LIST::iterator it = controls.begin(); it != controls.end(); it++)
    {
        TControl* control = *it;
        if (mustDisplayControl(control))
        {
            control->SetBounds( left, GetRect().Bottom - control->Height - margin, control->Width, control->Height);
            control->Anchors = TAnchors() << akLeft << akTop;
            left += control->Width + margin;
        }
    }
}

void TStackLayout::DoHAlignRight()
{
    int left = GetRect().right - margin;

    for (CONTROL_LIST::reverse_iterator it = controls.rbegin(); it != controls.rend(); it++)
    {
        TControl* control = *it;
        if (mustDisplayControl(control))
        {
            left -= control->Width - margin;
            control->SetBounds( left, GetRect().Bottom - control->Height - margin, control->Width, control->Height);
            control->Anchors = TAnchors() << akRight << akTop;
        }
    }
}

void TStackLayout::DoVAlignTop()
{
    int top = GetRect().top + margin;

    for (CONTROL_LIST::iterator it = controls.begin(); it != controls.end(); it++)
    {
        TControl* control = *it;
        if (mustDisplayControl(control))
        {
            control->SetBounds( GetRect().left, top, control->Width, control->Height);
            control->Anchors = TAnchors() << akLeft << akTop;
            top += control->Height + margin;
        }
    }
}

void TStackLayout::DoVAlignBottom()
{
    int top = GetRect().bottom - margin;

    for (CONTROL_LIST::reverse_iterator it = controls.rbegin(); it != controls.rend(); it++)
    {
        TControl* control = *it;
        if (mustDisplayControl(control))
        {
            top -= control->Height - margin;
            control->SetBounds( GetRect().Left, top, control->Width, control->Height);
            control->Anchors = TAnchors() << akLeft << akBottom;
        }
    }
}

void TStackLayout::DoAlign()
{
    if (orientation == HORIZONTAL)
    {
        if (alignment == RIGHT)
        {
            DoHAlignRight();
        }
        else
        {
            DoHAlignLeft();
        }
    }
    else
    {
        if (alignment == TOP)
        {
            DoVAlignTop();
        }
        else
        {
            DoVAlignBottom();
        }
    }
}

void TStackLayout::AlignRight(TControl* left, TControl* right )
{
    TControl* controls[] = {left, right};
    AlignRight(controls, _countof(controls));
}

void TStackLayout::AlignRight(TControl* left, TControl* middle, TControl* right)
{
    TControl* controls[] = {left, middle, right};
    AlignRight(controls, _countof(controls));
}

void TStackLayout::AlignRight(TControl* left, TControl* middle1, TControl* middle2, TControl* right)
{
    TControl* controls[] = {left, middle1, middle2, right};
    AlignRight(controls, _countof(controls));
}

void TStackLayout::AlignRight(TControl** controls, size_t count)
{
    if (count == 0)
        return;

    TStackLayout layout(controls[0]->Parent);
    
    for (size_t i = 0; i < count; ++i)
        layout.Controls().push_back(controls[i]);

    layout.Align();
}

