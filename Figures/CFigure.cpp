#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	FigGfxInfo.isFilled=true;
	ID = 1;
}

CFigure::CFigure()
{
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

 void  CFigure::ChngDrawClr(color Dclr) 
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


//FOR SAVE 
string CFigure::getstringFclr(color clr)
{
	if (clr == BLUE)
		return "BLUE";
	if (clr == BLACK)
		return "BLACK";
	if (clr == YELLOW)
		return "YELLOW";
	if (clr == GREEN)
		return "GREEN";
	if (clr == RED)
		return "RED";
	if (clr == ORANGE)
	    return "ORANGE";
}
color CFigure::getcolorFstr(string clr)
{
	if (clr == "BLUE")
		return BLUE;
	if (clr == "BLACK")
		return BLACK;
	if (clr == "YELLOW")
		return YELLOW;
	if (clr == "GREEN")
		return GREEN;
	if (clr == "RED")
		return RED;
	if (clr == "ORANGE")
		return ORANGE;


}
// DO THE OPPOSITE FOR LOADING


