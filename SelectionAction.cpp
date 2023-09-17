#include "SelectionAction.h"



SelectionAction::SelectionAction(ApplicationManager* AppM):Action(AppM)
{
}

void SelectionAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please select a figure");
	pIn->GetPointClicked(p.x, p.y);


	pOut->ClearStatusBar();
}

void SelectionAction::Execute(bool readparameters)
{
	if(readparameters)
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	CFigure* wasSelected = pManager->GetSelectedFig();
	CFigure* tobeSelected = pManager->GetFigure(p.x, p.y);
	if (tobeSelected)
	{
		if (tobeSelected->IsSelected())
		{
			tobeSelected->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		}
		else
		{
			if (wasSelected)
				wasSelected->SetSelected(false);
			tobeSelected->SetSelected(true);
			pManager->SetSelectedFig(tobeSelected);
		}

	}
	if (pManager->GetSelectedFig())
		pManager->GetSelectedFig()->PrintInfo(pOut);
	
}
bool SelectionAction::Record()
{
	return true;
}