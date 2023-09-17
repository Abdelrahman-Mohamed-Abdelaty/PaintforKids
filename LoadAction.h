#pragma once
#include<fstream>
#include"Actions/action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include "Figures/CFigure.h"
#include<string>
class LoadAction:public Action
{
private:
	string filename;
	string crntdrawclr;
	string crntfillclr;
public:
	LoadAction(ApplicationManager* AppM);
	color getcolorFstr(string clr);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters);
	virtual bool Record();
};

