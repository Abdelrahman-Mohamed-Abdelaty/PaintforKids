#pragma once
#include "Action.h"

class StartRecordingAction :
    public Action
{
public:
    StartRecordingAction(ApplicationManager*pApp);
    virtual void ReadActionParameters();
    virtual void Execute(bool readparameters);
    virtual bool Record();
};

