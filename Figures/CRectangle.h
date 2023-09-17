#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	double width;
	double height;
public:

	CRectangle();
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	//two added functions 
	virtual	bool IsShape(int x, int y) const;
	virtual void Save(ofstream& foutfile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void Move(Point p);
	Point GetCenter();

};
     
#endif