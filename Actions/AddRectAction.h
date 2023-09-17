#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H
#include "..\Figures\CRectangle.h"
#include "Action.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CRectangle* R;
public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readparameters) ;
	virtual void AddtoUndo();
	void undo();
};

#endif