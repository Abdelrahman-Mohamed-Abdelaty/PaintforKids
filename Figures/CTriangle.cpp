#include "CTriangle.h"
#include<fstream>
CTriangle::CTriangle(Point p1,Point p2,Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	s1=p1;
	s2=p2;
	s3=p3;
}

CTriangle::CTriangle()
{
}
	

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(s1,s2,s3,FigGfxInfo,Selected);
}

bool CTriangle::IsShape(int x, int y) const
{
	//the following formla is a mathematical formula
	//it depends on if we have Three points of triangle then any point in it can be written as compination of
	//two of them
	//assume point p ,and the agdes points of the triangle are A,B,C
	//p=A+w1(B-A)+w2(C-A) so if w1 and w2 both are less than one then P is inside the triangle
	//I has the three points and the P so I will get w1 and w2 and check if they are less than one 
	double w1, w2;
	w1 = (s1.x * (s3.y - s1.y) + (y - s1.y) * (s3.x - s1.x) - x * (s3.y - s1.y)) / ((s2.y - s1.y) *(s3.x - s1.x) * 1.0 - (s2.x - s1.x) * (s3.y - s1.y));
	w2 = (y - s1.y - w1 * (s2.y - s1.y)) / (s3.y - s1.y);
	if (w1 >= 0 && w2 >= 0&&((w1+w2)<=1))
		return true;
	return false;
}

void CTriangle::Save(ofstream& foutfile)
{
	foutfile << "TRIAN" << '\t' << ID << '\t' << s1.x << '\t' << s1.y << '\t' << s2.x << '\t' << s2.y << '\t' << s3.x << '\t' << s3.y << '\t';
	foutfile << getstringFclr(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		foutfile << getstringFclr(FigGfxInfo.FillClr) << endl;
	else
		foutfile << "NO_FILL" << endl;
}

void CTriangle::Load(ifstream& Infile)
{
	string z1, z2;
	Infile >> ID >> s1.x >> s1.y >>s2.x>>s2.y>> s3.x>>s3.y>>z1 >> z2;
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

void CTriangle::PrintInfo(Output* pOut)
{
	string s = to_string(ID);
	string p1 = "(" + to_string(s1.x) + "," + to_string(s1.y) + ")";
	string p2 = "(" + to_string(s2.x) + "," + to_string(s2.y) + ")";
	string p3 = "(" + to_string(s3.x) + "," + to_string(s3.y) + ")";
	string side1 = to_string(pow((pow((s1.x - s2.x), 2) + pow((s1.y - s2.y), 2)), 0.5));
	string side2 = to_string(pow((pow((s1.x - s3.x), 2) + pow((s1.y - s3.y), 2)), 0.5));
	string side3 = to_string(pow((pow((s3.x - s2.x), 2) + pow((s3.y - s2.y), 2)), 0.5));
	pOut->PrintMessage("ID:" + s + "the Points of the triangle is"+p1+", " + p2 + ", " + p3 + ", " + "the lenth of each side of triangle = " + side1 + ", " + side2+", " + side3);


}

void CTriangle::Move(Point p)
{
	double xc = (s1.x + s2.x + s3.x) / 3.0;
	double yc = (s1.y + s2.y + s3.y) / 3.0;
	s1.x += p.x - xc;
	s2.x += p.x - xc;
	s3.x += p.x - xc;
	s1.y += p.y - yc;
	s2.y += p.y - yc;
	s3.y += p.y - yc;

}
Point CTriangle::GetCenter()
{
	Point C;
	C.x = (s1.x + s2.x + s3.x) / 3;
	C.y = (s1.y + s2.y + s3.y) / 3;
	return C;
}