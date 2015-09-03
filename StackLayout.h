//---------------------------------------------------------------------------
#ifndef StackLayoutH
#define StackLayoutH

#include "ALayout.h"
#include <vector>

/** Affiche un série de contrôles horizontalement ou verticalement,
 *  en ignorant les contrôles invisibles. */
class TStackLayout : public ALayout
{
public:
    typedef std::vector<TControl*> CONTROL_LIST;
    typedef enum {HORIZONTAL, VERTICAL } ORIENTATION;
    typedef enum {TOP, BOTTOM, LEFT, RIGHT } ALIGNMENT;

    TStackLayout(TWinControl* aParent);

    CONTROL_LIST& Controls() {return controls; };
    void SetAlignment(ALIGNMENT anAlignment) { alignment = anAlignment;}
    ALIGNMENT GetAlignment() const { return alignment;}
    void SetOrientation(ORIENTATION anOrientation) { orientation = anOrientation;}
    ORIENTATION GetOrientation() const { return orientation;}
    void SetMargin(size_t aMargin) { margin = aMargin; }
    size_t GetMargin() const { return margin; }


    static void AlignRight(TControl* left, TControl* right);
    static void AlignRight(TControl* left, TControl* middle, TControl* right);
    static void AlignRight(TControl* left, TControl* middle1, TControl* middle2, TControl* right);
    static void AlignRight(TControl** controls, size_t count);

protected:
    virtual void DoAlign();
    CONTROL_LIST controls;

private:
    ALIGNMENT alignment;
    ORIENTATION orientation;
    size_t margin;

    void DoHAlignLeft();
    void DoHAlignRight();
    void DoVAlignTop();
    void DoVAlignBottom();
    bool mustDisplayControl(TControl* control) const;
};
//---------------------------------------------------------------------------
#endif
