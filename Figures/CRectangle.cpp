#include "CRectangle.h"
#include<string>
#include<fstream>
CRectangle::CRectangle()
{
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsShape(int x, int y) const
{
	double larg_x, small_x, larg_y, small_y;
	if (Corner1.x > Corner2.x)
	{
		larg_x = Corner1.x;
		small_x = Corner2.x;
	}
	else
	{
		larg_x = Corner2.x;
		small_x = Corner1.x;
	}
	if (Corner1.y > Corner2.y)
	{
		larg_y = Corner1.y;
		small_y = Corner2.y;
	}
	else
	{
		larg_y = Corner2.y;
		small_y = Corner1.y;
	}
	if (larg_x >= x && small_x <= x && small_y <= y && larg_y >= y)
		return true;
	else return false;
}

void CRectangle::Save(ofstream& foutfile){
	foutfile << "RECT" << '\t' << ID <<  '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t';
	foutfile << getstringFclr(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		foutfile << getstringFclr(FigGfxInfo.FillClr) << endl;
	else
		foutfile << "NO_FILL"<< endl;
}

void CRectangle::Load(ifstream& Infile)
{
	string s1,s2;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> s1>>s2;
	FigGfxInfo.DrawClr = getcolorFstr(s1);
	if (s2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else 
	{ 
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolorFstr(s2);
	}
	Selected = false;


}

void CRectangle::PrintInfo(Output* pOut)
{
	string s = to_string(ID);
	string p1 ="("+to_string(Corner1.x) + "," + to_string(Corner1.y)+")";
	string p2 = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	width = abs(Corner1.x - Corner2.x);
	height = abs(Corner2.y - Corner1.y);
	string Width = to_string(width);
	string Height = to_string(height);
	pOut->PrintMessage("ID:" + s + "the top left corner is (X,Y)="+ p1+"the top right corner is(X, Y) = "+p2+"the width ="+Width +"the heigth is"+Height);
	
}

void CRectangle::Move(Point p)
{
	Corner1.x = p.x - .5 * width;
	Corner1.y = p.y - .5 * height;
	Corner2.x = p.x + .5 * width;
	Corner2.y = p.y + .5 * height;

}
Point CRectangle::GetCenter()
{
	Point C;
	C.x = (Corner1.x + Corner2.x) / 2;
	C.y= (Corner1.y + Corner2.y)/ 2;
	return C;
}
