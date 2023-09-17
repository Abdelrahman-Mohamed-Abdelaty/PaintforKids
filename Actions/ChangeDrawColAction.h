#include "Action.h"
#include"..\Figures\CFigure.h"
class ChangeDrawColAction :public Action
{
private:
	Point p;
	ActionType Act;
	color New;
	color Old;
	CFigure* shape;
public:
	ChangeDrawColAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters);
	virtual void AddtoUndo();
	void undo();
};