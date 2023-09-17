#include "CFigure.h"

class CHexa : public CFigure
{
private:
	Point s1;	

public:
	CHexa(Point,GfxInfo FigureGfxInfo );
	CHexa();
	virtual void Draw(Output* pOut) const;
	virtual	bool IsShape(int x, int y) const;
	virtual void Save(ofstream& foutfile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void Move(Point p);
	Point GetCenter();
};