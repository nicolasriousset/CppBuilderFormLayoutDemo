//---------------------------------------------------------------------------
#ifndef ALayoutH
#define ALayoutH

class ALayout
{
public:
    static const double DEFAULT_SIZE;

    ALayout(TWinControl* aParent);
    virtual ~ALayout();

    void Align(const TRect& layoutRect);
    void Align(int left, int top = DEFAULT_SIZE, int right = DEFAULT_SIZE, int bottom = DEFAULT_SIZE);
    void Align();

protected:
    const TRect& GetRect() const {return rect;};
    TWinControl* GetParent() const {return parent;};
    virtual void DoAlign() = 0;

private:
    TRect rect;
    TWinControl* parent;

    bool ValidateRect();
};

//---------------------------------------------------------------------------
#endif
