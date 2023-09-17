#include "Action.h"
#include "..\Figures\CCircle.h"
//Add Rectangle Action class
class AddCirAction: public Action
{
private:
	Point P1;
	Point P2;
	GfxInfo CirGfxInfo;
	CCircle* C;
public:
	AddCirAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readparameters) ;
	virtual void AddtoUndo();
	void undo();
};

