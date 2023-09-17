#pragma once
#include "Action.h"
#include"../Figures/CFigure.h"
#include"../ApplicationManager.h"
class MoveAction :
    public Action
{
private:
	Point Pold;
	Point Pnew;
	CFigure* shape;
public:
	MoveAction(ApplicationManager* App);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters);
	virtual void AddtoUndo();
	void undo();
};

