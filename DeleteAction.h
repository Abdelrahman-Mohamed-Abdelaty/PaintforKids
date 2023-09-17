#pragma once
#include"Actions/action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include "Figures/CFigure.h"

class DeleteAction:public Action
{
private:
	Point p;
	CFigure* Selectedfig;
public:
	DeleteAction(ApplicationManager* App);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters);
	virtual void AddtoUndo();
	virtual void undo();

};

