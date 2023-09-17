#include "LoadAction.h"
#include "Figures/CCircle.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTriangle.h"

LoadAction::LoadAction(ApplicationManager* AppM):Action(AppM)
{
}

color LoadAction::getcolorFstr(string clr)
{
	if (clr == "BLUE")
		return BLUE;
	if (clr =="BLACK")
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

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter a filename");
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void LoadAction::Execute(bool readparameters)
{
	int numofshapes;
	string figtype;
	ReadActionParameters();
	pManager->DeletingAllfigs();
	Output* pout = pManager->GetOutput();
	Input* pin = pManager->GetInput();
	ifstream finput(filename + ".txt",ios::in);
	finput >> crntdrawclr >> crntfillclr >> numofshapes;
	color crndraw = getcolorFstr(crntdrawclr);
	color crnfill = getcolorFstr(crntfillclr);
	pout->setCrntDrawColor(crndraw);
	pout->setCrntFillColor(crnfill);
	CFigure* figure;
	for (int i = 0; i < numofshapes; i++)
	{
		finput >> figtype;
		if (figtype == "RECT")
			figure = new CRectangle;
		else if (figtype == "CIRCL")
			figure = new CCircle;
		else if (figtype == "TRIAN")
			figure = new CTriangle;
		else if (figtype == "HEXA")
			figure = new CHexa;
		else if (figtype=="SQUAR")
			figure = new CSquare;
		figure->Load(finput);
		pManager->AddFigure(figure);
	}

	finput.close();

}
bool LoadAction::Record()
{
	return false;
}