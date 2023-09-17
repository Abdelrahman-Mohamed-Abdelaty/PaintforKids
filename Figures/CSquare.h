#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point p;	
public:
	CSquare(Point ,GfxInfo FigureGfxInfo );
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual	bool IsShape(int x, int y) const;
	virtual void Save(ofstream& foutfile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void Move(Point p);
	Point GetCenter();
};