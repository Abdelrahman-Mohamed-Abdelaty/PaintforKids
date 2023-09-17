#pragma once
#include "Action.h"
class PlayRecordingAction :
    public Action
{
public:
    PlayRecordingAction(ApplicationManager* pApp);
    virtual void Execute(bool readactionparameters);
    virtual void ReadActionParameters();
};

