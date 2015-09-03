//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ALayout.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

const double ALayout::DEFAULT_SIZE = -1;

ALayout::ALayout(TWinControl* aParent)
    :   parent(aParent),
        rect(DEFAULT_SIZE, DEFAULT_SIZE, DEFAULT_SIZE, DEFAULT_SIZE)
{
}

ALayout::~ALayout()
{
}

bool ALayout::ValidateRect()
{
    if (parent == NULL)
        return false;
    
    TRect parentRect = parent->ClientRect;
    if (rect.Left == DEFAULT_SIZE)
        rect.Left = parentRect.Left;

    if (rect.Top == DEFAULT_SIZE)
        rect.Top = parentRect.Top;

    if (rect.Right == DEFAULT_SIZE)
        rect.Right = parentRect.Right;

    if (rect.Bottom == DEFAULT_SIZE)
        rect.Bottom = parentRect.Bottom;

    return true;
}


void ALayout::Align(int left, int top, int right, int bottom)
{
    Align(TRect(left, top, right, bottom)); 
}

void ALayout::Align()
{
    Align(DEFAULT_SIZE, DEFAULT_SIZE, DEFAULT_SIZE, DEFAULT_SIZE);
}

void ALayout::Align(const TRect& layoutRect)
{
    rect = layoutRect;
    if (!ValidateRect())
        return;

    DoAlign();
}
