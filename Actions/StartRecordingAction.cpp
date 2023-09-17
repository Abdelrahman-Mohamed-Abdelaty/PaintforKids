#include "StartRecordingAction.h"
#include"..\ApplicationManager.h"
StartRecordingAction::StartRecordingAction(ApplicationManager* pApp):Action(pApp)
{

}
void StartRecordingAction::Execute(bool readparameters)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getActualNumFigure() == 0)
	{
		pManager->SetRecord(true);
		pOut->PrintMessage("Recording Started");
	}
	else
		pOut->PrintMessage("Can't start recording please clear all first");
}
void  StartRecordingAction::ReadActionParameters()
{

}
bool  StartRecordingAction::Record()
{
	return false;
}