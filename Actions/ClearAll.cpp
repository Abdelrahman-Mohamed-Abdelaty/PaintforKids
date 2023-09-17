#include"ClearAll.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ClearAll::ClearAll(ApplicationManager *pApp):Action(pApp)
{
	m=pApp;
}
void ClearAll:: ReadActionParameters()
{
}
void ClearAll::Execute(bool readparameters)
{
		m->DeletingAllfigs();
		UI.DrawColor=BLUE;
	    UI.FillColor=GREEN;
}
bool ClearAll::Record()
{
	return false;
}
