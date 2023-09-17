#include"AddHexaAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>
#include"MMsystem.h"
AddHexaAction::AddHexaAction(ApplicationManager * pApp):Action(pApp)
{}

void AddHexaAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	/// calling the function in the application manager to check if the user wants to allow the voice

	if (pManager->isVoiceOn())
		PlaySound(TEXT("hexagonvoice.wav"), NULL, SND_SYNC);
	pOut->PrintMessage("New Hexagon: Click at Center of the hexagon");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute(bool readparameters) 
{
	//This action needs to read some parameters first
	if (readparameters)
	{
		ReadActionParameters();
		H = new CHexa(P1, HexaGfxInfo);
		AddtoUndo();
	}
	
	//Create a rectangle with the parameters read from the user
	delete H;
	H = new CHexa(P1, HexaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(H);
	
}
void AddHexaAction::undo()
{
	pManager->RemoveUndone(H);
}
void AddHexaAction::AddtoUndo()
{
	pManager->AddUndoAction(this);
}