#include "MoveAction.h"
MoveAction::MoveAction(ApplicationManager* App) :Action(App)
{
	shape = pManager->GetSelectedFig();
	if(shape!=NULL)
	Pold = shape->GetCenter();
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please click A point to move the shape to ");
	pIn->GetPointClicked(Pnew.x, Pnew.y);
	pOut->ClearStatusBar();
}

void MoveAction::Execute(bool readparameters)
{
	if (shape)
	{
		if (readparameters)
		{
			ReadActionParameters();
			AddtoUndo();
		}
		shape = pManager->GetSelectedFig();
		shape->Move(Pnew);
	}
}
void MoveAction::undo()
{
	shape->Move(Pold);
}
void MoveAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}