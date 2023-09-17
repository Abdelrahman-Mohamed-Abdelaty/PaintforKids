#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point s1;	
	Point s2;
	Point s3;

public:
	CTriangle(Point,Point,Point ,GfxInfo FigureGfxInfo );
	CTriangle();
	Point GetCenter();
	virtual void Draw(Output* pOut) const;
	virtual	bool IsShape(int x, int y) const;
	virtual void Save(ofstream& foutfile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void Move(Point p);

};