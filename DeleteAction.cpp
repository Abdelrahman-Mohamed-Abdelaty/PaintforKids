#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* App) :Action(App)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute(bool readparameters)
{
	if (readparameters)
	{
		Output* pOut = pManager->GetOutput();
		Selectedfig = pManager->GetSelectedFig();
		if (Selectedfig)
		{
			pOut->ClearStatusBar();
			pManager->DeleteSelected();

		}
		AddtoUndo();
	}
	else
	{
		pManager->RemoveUndone(Selectedfig);
	}

}
void DeleteAction::undo()
{
	Selectedfig->SetSelected(false);
	pManager->AddFigure(Selectedfig);
}
void DeleteAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}