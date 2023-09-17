#include"ChangeFillColAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillColAction::ChangeFillColAction(ApplicationManager* pApp) :Action(pApp)
{
	Old = UI.FillColor;
}
void ChangeFillColAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please select a shape");
	pIn->GetPointClicked(p.x, p.y);
	shape = pManager->GetFigure(p.x, p.y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Choose the new draw color ");
	Act = pIn->GetUserAction();
	pOut->ClearStatusBar();
	switch (Act)
	{
	case COLBLACK:
		C1 = BLACK;
		break;
	case COLRED:
		C1 = RED;
		break;
	case COLYELLOW:
		C1 = YELLOW;
		break;
	case COLORANGE:
		C1 = ORANGE;
		break;
	case COLBLUE:
		C1 = BLUE;
		break;
	case COLGREEN:
		C1 = GREEN;
		break;
	default:
		C1 = RED;
	}
}
void ChangeFillColAction::Execute(bool readparameters)
{
	if (readparameters)
	{
		ReadActionParameters();
		AddtoUndo();
	}
	UI.FillColor = C1;
	shape->ChngFillClr(C1);

}
void ChangeFillColAction::undo()
{
	shape->ChngFillClr(Old);
	UI.FillColor = Old;
}
void ChangeFillColAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}