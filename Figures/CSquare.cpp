#include "CSquare.h"
#include<fstream>

CSquare::CSquare(Point P1,  GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p=P1;
}

CSquare::CSquare()
{
}
	

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(p, FigGfxInfo, Selected);
}

bool CSquare::IsShape(int x, int y) const
{
	Point P1, P2;
	P1.x = p.x - 100;
	P1.y = p.y - 100;
	P2.x = p.x + 100;
	P2.y = p.y + 100;
	if (P2.x >= x && P1.x <= x && P1.y <= y && P2.y >= y)
		return true;
	else return false;
}

void CSquare::Save(ofstream& foutfile)
{
	foutfile << "SQUAR" << '\t' << ID << '\t' << p.x << '\t' << p.y << '\t' ;
	foutfile << getstringFclr(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		foutfile << getstringFclr(FigGfxInfo.FillClr) << endl;
	else
		foutfile << "NO_FILL" << endl;
}

void CSquare::Load(ifstream& Infile)
{
	string z1, z2;
	Infile >> ID >> p.x >> p.y >> z1 >> z2;
	FigGfxInfo.DrawClr = getcolorFstr(z1);
	if (z2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolorFstr(z2);
	}
	Selected = false;

}

void CSquare::PrintInfo(Output* pOut)
{
	string s = to_string(ID);
	string p1 = "(" + to_string(p.x) + "," + to_string(p.y) + ")";

	pOut->PrintMessage("ID:" + s + "the width=height=100 and the drawing point is"+p1);
	
}

void CSquare::Move(Point po)
{
	p.x = po.x;
	p.y = po.y;

}
Point CSquare::GetCenter()
{
	return p;
}