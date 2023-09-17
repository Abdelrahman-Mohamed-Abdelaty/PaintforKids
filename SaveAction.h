#pragma once
#include"Actions/action.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include "Figures/CFigure.h"
#include<string>
class SaveAction:public Action
{
private:
    string Fname;
    string crntdrawclr;
    string crntfillclr;
public:
      SaveAction(ApplicationManager* AppM);
      string getstringFclr(color clr);
      virtual void ReadActionParameters();
      virtual void Execute(bool readparameters);
      virtual bool Record();
};

