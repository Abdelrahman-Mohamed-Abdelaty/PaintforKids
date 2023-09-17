#include"AddSqrAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>
#include"MMsystem.h"
AddSqrAction::AddSqrAction(ApplicationManager * pApp):Action(pApp)
{}

void AddSqrAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	/// calling the function in the application manager to check if the user wants to allow the voice

	if (pManager->isVoiceOn())
		PlaySound(TEXT("square.wav"), NULL, SND_SYNC);
	pOut->PrintMessage("New Square: Click at Center of the square");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute(bool readparameters)
{
	//This action needs to read some parameters first
	if (readparameters)
	{
		ReadActionParameters();
		S = new CSquare(P1, SqrGfxInfo);
		AddtoUndo();
	}
	
	//Create a rectangle with the parameters read from the user
	delete S;
	S = new CSquare(P1, SqrGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
	
	
}
void AddSqrAction::undo()
{
	pManager->RemoveUndone(S);
}
void AddSqrAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}