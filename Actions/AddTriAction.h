#include "Action.h"
#include "..\Figures\CTriangle.h"
//Add Rectangle Action class
class AddTriAction: public Action
{
private:
	Point P1, P2,P3; 
	GfxInfo TriGfxInfo;
	CTriangle* T;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readparameters) ;
	virtual void AddtoUndo();
	void undo();
};