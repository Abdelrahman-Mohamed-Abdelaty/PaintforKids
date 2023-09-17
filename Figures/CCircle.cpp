#include "CCircle.h"
#include<fstream>
CCircle::CCircle(Point p1,Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	s1=p1;
	s2=p2;
	radious=pow((pow((s1.x - s2.x), 2) + pow((s1.y - s2.y), 2)), 0.5);
	
}

CCircle::CCircle()
{
}
	

void CCircle::Draw(Output* pOut) const
{
	pOut->Drawcircle(s1,s2,FigGfxInfo,Selected);
}

bool CCircle::IsShape(int x, int y) const
{
	double dist = pow((pow((s1.x - x), 2) + pow((s1.y - y), 2)), 0.5);
	
	if (dist <= radious)
		return true;
	return false;
}

void CCircle::Save(ofstream& foutfile)
{
	foutfile << "CIRCL" << '\t' << ID << '\t' << s1.x << '\t' << s1.y << '\t' << s2.x << '\t' << s2.y << '\t';
	foutfile << getstringFclr(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		foutfile << getstringFclr(FigGfxInfo.FillClr) << endl;
	else
		foutfile << "NO_FILL" << endl;
	
}

void CCircle::Load(ifstream& Infile)
{
	string z1, z2;
	Infile >> ID >> s1.x >> s1.y >> s2.x >> s2.y >> z1 >> z2;
	FigGfxInfo.DrawClr = getcolorFstr(z1);
	if (z2 == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolorFstr(z2);
	}
	Selected = false;
	radious = pow((pow((s1.x - s2.x), 2) + pow((s1.y - s2.y), 2)), 0.5);
}

void CCircle::PrintInfo(Output* pOut)
{
	string y = to_string(ID);
	string s = to_string(radious);
	string p1 = "(" + to_string(s1.x) + "," + to_string(s1.y) + ")";
	pOut->PrintMessage("ID:"+y+"the center is(x, y)"+p1+"the radious is"+s );


	
}

void CCircle::Move(Point p)
{
	s1.x = p.x;
	s1.y = p.y;
	s2.x = p.x;
	s2.y = p.y + radious;
}
Point CCircle:: GetCenter()
{
	return s1;
}