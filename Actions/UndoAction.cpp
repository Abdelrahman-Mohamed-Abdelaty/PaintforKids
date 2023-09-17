#include "UndoAction.h"
#include "..\ApplicationManager.h"
UndoAction::UndoAction(ApplicationManager* pApp):Action(pApp)
{

}
void UndoAction::Execute(bool readparameters)
{
	pManager->undoCurrent();
}
void UndoAction::ReadActionParameters()
{

}