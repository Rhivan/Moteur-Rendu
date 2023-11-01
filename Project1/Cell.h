class Cell 
{
public:
    Cell();

    void setValue(int val);
    void setEmpty();
    void setMergedCell();
    void resetMerged();
    int getValue();
    bool isEmptyCell();
    bool isMergedCell();

private:
    int value;
    bool isMerged;
};