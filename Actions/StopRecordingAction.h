#pragma once
#include "Action.h"
class StopRecordingAction :
    public Action
{
public:
    StopRecordingAction(ApplicationManager*pApp);
    virtual void Execute(bool readparameters);
    virtual void ReadActionParameters();
    virtual bool Record();
};

