#include "CHexa.h"
#include<fstream>

CHexa::CHexa(Point p1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	s1=p1;
	
}

CHexa::CHexa()
{
}
	

void CHexa::Draw(Output* pOut) const
{
	pOut->DrawHexagon(s1,FigGfxInfo,Selected);
}

bool CHexa::IsShape(int x, int y) const
{
	//here i am going to consider the hexagon as two triangles and a rectangle
	
	//double dist=pow((pow((s1.x - x), 2) + pow((s1.y - y), 2)), 0.5);
	int* px = new int[6];
	px[0] = s1.x - 50;
	px[1] = s1.x + 50;
	px[2] = s1.x + 100;
	px[3] = s1.x + 50;
	px[4] = s1.x - 50;
	px[5] = s1.x - 100;
	int* py = new int[6];
	py[0] = s1.y - 86;
	py[1] = s1.y - 86;
	py[2] = s1.y;
	py[3] = s1.y + 86;
	py[4] = s1.y + 86;
	py[5] = s1.y;
	//p[1]-> means px[1],py[1]
	//first triangle p[1],p[2],p[3]
	

	double w1, w2;
	w1 = (px[1] * (py[3] - py[1]) + (y - py[1]) * (px[3] - px[1]) - x * (py[3] - py[1])) / ((py[2] - py[1]) * (px[3] - px[1]) * 1.0 - (px[2] - px[1]) * (py[3] - py[1]));
	w2 = (y - py[1] - w1 * (py[2] - py[1])) / (py[3] - py[1]);
	if (w1 >= 0 && w2 >= 0 && ((w1 + w2) <= 1))
		return true;
	//second triangle
	double w3, w4;
	w3 = (px[0] * (py[4] - py[0]) + (y - py[0]) * (px[4] - px[0]) - x * (py[4] - py[0])) / ((py[5] - py[0]) * (px[4] - px[0]) * 1.0 - (px[5] - px[0]) * (py[4] - py[0]));
	w4 = (y - py[0] - w3 * (py[5] - py[0])) / (py[4] - py[0]);
	if (w3 >= 0 && w4 >= 0 && ((w3 + w4) <= 1))
		return true;
	// the rectangle between the two triangles
	// the two points of the triagle p[0],p[3]

	if (px[3] >= x && px[0] <= x && py[0] <= y && py[3] >= y)
		return true;

	return false;
	
}

void CHexa::Save(ofstream& foutfile)
{
	foutfile << "HEXA" << '\t' << ID << '\t' << s1.x << '\t' << s1.y << '\t';
	foutfile << getstringFclr(FigGfxInfo.DrawClr) << '\t';
	if (FigGfxInfo.isFilled)
		foutfile << getstringFclr(FigGfxInfo.FillClr) << endl;
	else
		foutfile << "NO_FILL" << endl;

}

void CHexa::Load(ifstream& Infile)
{
	string z1, z2;
	Infile >> ID >> s1.x >> s1.y >> z1 >> z2;
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

void CHexa::PrintInfo(Output* pOut)
{
	string s = to_string(ID);
	string p1 = "(" + to_string(s1.x) + "," + to_string(s1.y) + ")";

	pOut->PrintMessage("ID:" + s + "the drawing point :"+p1+ "the length equal 100");
}

void CHexa::Move(Point p)
{
	s1.x = p.x;
	s1.y = p.y;
}
Point CHexa::GetCenter()
{
	return s1;
}