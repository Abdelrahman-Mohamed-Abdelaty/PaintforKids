#include "Action.h"
#include "..\Figures\CSquare.h"
//Add Rectangle Action class
class AddSqrAction: public Action
{
private:
	Point P1;
	GfxInfo SqrGfxInfo;
	CSquare* S;
public:
	AddSqrAction(ApplicationManager *pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();
	
	//Add sqr to the ApplicationManager
	virtual void Execute(bool readparameters) ;
	virtual void AddtoUndo();
	void undo();
};