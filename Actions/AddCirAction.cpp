#include "AddCirAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>
#include"MMsystem.h"

AddCirAction::AddCirAction(ApplicationManager * pApp):Action(pApp)
{
	C = NULL;
}

void AddCirAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	/// calling the function in the application manager to check if the user wants to allow the voice
	
	if (pManager->isVoiceOn())
		PlaySound(TEXT("circle.wav"), NULL, SND_SYNC);
	pOut->PrintMessage("New Circle: Click at the first corner of the circle");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at the second corner of the circle");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P2.x, P2.y);
	CirGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CirGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CirGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCirAction::Execute(bool readparameters) 
{
	//This action needs to read some parameters first
	if (readparameters)
	{
		ReadActionParameters();
		C = new CCircle(P1, P2, CirGfxInfo);
		AddtoUndo();
	}
	
	//Create a rectangle with the parameters read from the user
	delete C;
	C = new CCircle(P1, P2, CirGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(C);
	
}
void AddCirAction::undo()
{
	pManager->RemoveUndone(C);
}
void AddCirAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}