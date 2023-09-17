#include "SaveAction.h"
#include<fstream>
//fuction to convet color to string 

SaveAction::SaveAction(ApplicationManager* AppM):Action(AppM)
{
}

string SaveAction::getstringFclr(color clr)
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


void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	color clr1 = pOut->getCrntDrawColor();
	color clr2 = pOut->getCrntFillColor();
	crntdrawclr=getstringFclr(clr1);
	crntfillclr = getstringFclr(clr2);
	pOut->PrintMessage("please enter file name");
	Fname=pIn->GetSrting(pOut)+".txt";
	
	pOut->ClearStatusBar();
}

void SaveAction::Execute(bool readparameters)
{

	ReadActionParameters();
	ofstream foutfile(Fname, ios::out);
	foutfile << crntdrawclr << "\t" << crntfillclr << endl;
	foutfile << pManager->getActualNumFigure() << endl;
	pManager->Save_All(foutfile);
	foutfile.close();


}
bool  SaveAction::Record()
{
	return false;
}