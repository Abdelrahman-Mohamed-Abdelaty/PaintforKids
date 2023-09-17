#pragma once
#include"Actions/action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include "Figures/CFigure.h"
class VoiceAcion : public Action
{
private:
    bool VoiceOn;
public:
	VoiceAcion(ApplicationManager* app);
	virtual void ReadActionParameters() ;
	virtual void Execute(bool readparameters) ;
};

