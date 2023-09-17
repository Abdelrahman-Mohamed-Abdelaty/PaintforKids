
#pragma once
#include"Actions/action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include "Figures/CFigure.h"


class SelectionAction :public Action
{
private:
	Point p;
public:
	SelectionAction(ApplicationManager* AppM);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters);
	virtual bool Record();

};