#include "StopRecordingAction.h"
#include"..\ApplicationManager.h"
StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) :Action(pApp)
{
}
void StopRecordingAction::Execute(bool readparameters)
{
	Output* pOut = pManager->GetOutput();
	pManager->SetRecord(false);
	pOut->PrintMessage("Recording Stopped");
}
void StopRecordingAction::ReadActionParameters()
{

}
bool StopRecordingAction::Record()
{
	return false;
}