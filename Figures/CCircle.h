#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point s1;	
	Point s2;
	
	double radious;
public:
	CCircle(Point,Point,GfxInfo FigureGfxInfo );
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual	bool IsShape(int x, int y) const;
	virtual void Save(ofstream& foutfile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void Move(Point p);
	Point GetCenter();
};