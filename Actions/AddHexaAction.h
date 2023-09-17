#include "Action.h"
#include "..\Figures\CHexa.h"
//Add Rectangle Action class
class AddHexaAction: public Action
{
private:
	Point P1;
	GfxInfo HexaGfxInfo;
	CHexa* H;
public:
	AddHexaAction(ApplicationManager *pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();
	
	//Add sqr to the ApplicationManager
	virtual void Execute(bool) ;
	virtual void AddtoUndo();
	void undo();
};