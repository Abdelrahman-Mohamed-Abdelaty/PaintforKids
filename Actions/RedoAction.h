#pragma once
#include "Action.h"
class RedoAction :
    public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	virtual void Execute(bool readparameters);
	virtual void ReadActionParameters();
};

