#include "RedoAction.h"
#include "..\ApplicationManager.h"
RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{
}
void RedoAction::Execute(bool readparameters)
{
	pManager->redoCurrent();
}
void RedoAction::ReadActionParameters()
{

}