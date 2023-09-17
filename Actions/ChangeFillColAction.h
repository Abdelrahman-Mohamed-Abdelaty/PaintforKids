#include "Action.h"
#include"..\Figures\CFigure.h"
class ChangeFillColAction :public Action
{
private:
	Point p;
	ActionType Act;
	color C1;
	color Old;
	CFigure* shape;
public:
	ChangeFillColAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters);
	virtual void AddtoUndo();
	void undo();
};