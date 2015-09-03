//---------------------------------------------------------------------------
#ifndef GridLayoutH
#define GridLayoutH

#include <vector>
#include <exception>
#include "ALayout.h"

// Forward declaration
class TLayoutCell;

class LayoutException : std::exception
{
public:
    LayoutException(const char* msg) : std::exception() {}
};

class TGridLayout : public ALayout
{
public:
    class TRowDef
    {
        friend TGridLayout;
    public:
        TRowDef() : fixedHeight(DEFAULT_SIZE), height(DEFAULT_SIZE), top(DEFAULT_SIZE), minHeight(DEFAULT_SIZE), maxHeight(DEFAULT_SIZE), computedHeightPercent(0) {}
        void SetMinHeight(int pixels) {
            minHeight = pixels;
        }
        void SetMaxHeight(int pixels) {
            maxHeight = pixels;
        }
        void SetFixedHeight(int pixels) {
            fixedHeight = pixels;
        }
    private:
        double computedHeightPercent; // pourcentage
        int top; // pixels
        int height; // pixels
        int minHeight; // pixels
        int maxHeight; // pixels
        int fixedHeight; // pixels

        int Bottom() const {
            return top + height;
        }
    };

    class TColDef
    {
        friend TGridLayout;
    public:
        TColDef() : left(DEFAULT_SIZE), width(DEFAULT_SIZE), minWidth(DEFAULT_SIZE), maxWidth(DEFAULT_SIZE), fixedWidth(DEFAULT_SIZE) {}
        void SetMinWidth(int pixels) {
            minWidth = pixels;
        }
        void SetMaxWidth(int pixels) {
            maxWidth = pixels;
        }
        void SetFixedWidth(int pixels) {
            fixedWidth = pixels;
        }

    private:
        int left; // pixels
        int width; // pixels
        int minWidth; // pixels
        int maxWidth;
        int fixedWidth; // pixels

        int Right() const {
            return left + width;
        }
    };

    TGridLayout(TWinControl* parent, size_t colCount, size_t rowCount);
    ~TGridLayout();

    TControl* GetControl(size_t col, size_t row);
    bool IsVisible(size_t col, size_t row) const;
    void SetControl(size_t col, size_t row, TControl* aControl);
    size_t GetCellMargin() const { return cellMargin;}
    void SetCellMargin(size_t aMargin) { cellMargin = aMargin;}
    void MergeCells(size_t fromCol, size_t fromRow, size_t toCol, size_t toRow);
    TColDef* ColDef(size_t col);
    TRowDef* RowDef(size_t row);

    static void FillParentHeight(TControl* topControl, TControl* bottomControl, int maxHeight = DEFAULT_SIZE);
    static void FillParentWidth(TControl* leftControl, TControl* rightControl, int maxWidth = DEFAULT_SIZE);

protected:
    virtual void DoAlign();

private:
    TGridLayout(const TGridLayout&);
    operator=(const TGridLayout&);

    TLayoutCell** cells;
    TRowDef* rowDefs;
    TColDef* colDefs;
    size_t colCount;
    size_t rowCount;
    size_t cellMargin;

    void AllocateMembers();
    void FreeMembers();
    void ComputeColsWidth();
    void ComputeRowsHeight();
    TRect GetControlRect(size_t col, size_t row) const;
};

//---------------------------------------------------------------------------
#endif // GridLayoutH
