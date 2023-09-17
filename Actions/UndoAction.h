#pragma once
#include "Action.h"
class UndoAction :
	public Action
{

public:
	UndoAction(ApplicationManager* pApp);
	virtual void Execute(bool readparameters);
	virtual void ReadActionParameters();
};

