#include"ChangeDrawColAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"..\SelectionAction.h"
ChangeDrawColAction::ChangeDrawColAction(ApplicationManager* pApp) :Action(pApp)
{
	Old = UI.DrawColor;
}
void ChangeDrawColAction::ReadActionParameters()
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
		New = BLACK;
		break;
	case COLRED:
		New = RED;
		break;
	case COLYELLOW:
		New = YELLOW;
		break;
	case COLORANGE:
		New = ORANGE;
		break;
	case COLBLUE:
		New = BLUE;
		break;
	case COLGREEN:
		New = GREEN;
		break;
	default:
		New = RED;
	}
}
void ChangeDrawColAction::Execute(bool readparameters)
{
	if (readparameters)
	{
		ReadActionParameters();
		AddtoUndo();
	}
	UI.DrawColor = New;
	shape->ChngDrawClr(New);
}
void ChangeDrawColAction::undo()
{
	shape->ChngDrawClr(Old);
	UI.DrawColor = Old;
}
void ChangeDrawColAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}