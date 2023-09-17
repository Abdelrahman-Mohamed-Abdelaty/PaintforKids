#include "PlayRecordingAction.h"
#include"..\ApplicationManager.h"
PlayRecordingAction::PlayRecordingAction(ApplicationManager*pApp):Action(pApp)
{}
void PlayRecordingAction::Execute(bool readactionparameters)
{
	pManager->PlayRecorded();
}
void PlayRecordingAction ::ReadActionParameters()
{}