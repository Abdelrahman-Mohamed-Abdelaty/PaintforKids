#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include"Actions\AddTriAction.h"
#include"Actions\AddCirAction.h"
#include"Actions\AddHexaAction.h"
#include"Actions\ChangeDrawColAction.h"
#include"Actions\ChangeFillColAction.h"
#include"Actions\ClearAll.h"
#include"SelectionAction.h"
#include "DeleteAction.h"
#include"SaveAction.h"
#include"LoadAction.h"
#include"Actions/MoveAction.h"
#include"VoiceAcion.h"
#include"Actions/UndoAction.h"
#include"Actions/RedoAction.h"
#include"Actions/StartRecordingAction.h"
#include"Actions/StopRecordingAction.h"
#include"Actions/PlayRecordingAction.h"
#include<Windows.h>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	Record = false;
	FigCount = 0;
	recordedactions = 0;
	voice_on = false;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case SELECTONE:
			pAct = new SelectionAction(this);
			break;
		//case EXIT:
            delete pIn;
	        delete pOut;		
			break;
		case DRAW_SQURE:
			pAct=new AddSqrAction(this);
			break;
		case ReadShapes:
			pAct = new VoiceAcion(this);
			break;
		case MOVE_FIG:
			pAct = new MoveAction(this);
			break;
		case LOADGRAPH:
			pAct = new LoadAction(this);
			break;
		case DELETE_FIG:
			pAct = new DeleteAction(this);
			break;
		case DRAW_TRI:
			pAct=new AddTriAction(this);
				break;
		case DRAW_CIRC:
			pAct=new AddCirAction(this);
			break;
		case DRAW_HEXA:
			pAct=new AddHexaAction(this);
			break;
		case SAVEGRAPH:
			pAct = new SaveAction(this);
			break;
		case CHAN_DRAWCOL :
			pAct=new ChangeDrawColAction(this);
			break;
		case CHAN_FILLCOl:
			pAct=new ChangeFillColAction(this);
			break;
		case CLEARALL:
			pAct=new ClearAll(this);
			break;
		case UNDO_:
			pAct = new UndoAction(this);
			break;
		case REDO_:
			pAct = new RedoAction(this);
			break;
		case STARTREC:
			pAct = new StartRecordingAction(this);
			break;
		case STOPREC:
			pAct = new StopRecordingAction(this);
			break;
		case PLAYREC:
			pAct = new PlayRecordingAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		

	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		if((Record)&&(pAct->Record()))
		{
			addRecordedAction(pAct);
		}
		
		
		//delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
	
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
void ApplicationManager::SetSelectedFig(CFigure* selectp)
{
	SelectedFig = selectp;
}
CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}
void ApplicationManager::DeleteSelected()
{
	
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i] == SelectedFig)
			{
				//delete FigList[i];
				FigList[i] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
				FigCount--;
				SetSelectedFig(NULL);
			}

		}
	
}
void ApplicationManager::Save_All(ofstream& foutfile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(foutfile);
	}
}
int ApplicationManager::getActualNumFigure()
{
	return FigCount;
}



bool ApplicationManager::isVoiceOn()
{
	return voice_on;
}

void ApplicationManager::setVoiceOn(bool v)
{
	voice_on = v;
}

	


////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsShape(x, y))
		{
			return FigList[i];

		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if(FigList[i]!=NULL)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
void ApplicationManager::DeletingAllfigs()
{
	for(int i=0;i<FigCount;i++)
	{
		FigList[i]=NULL;
	}
	FigCount = 0;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::Clearall()
{
	pOut->ClearDrawArea();
	DeletingAllfigs();
	UA.RemoveAll();

}
void ApplicationManager::AddUndoAction(Action* x)
{
	UA.pushAction(x);
}
void ApplicationManager::undoCurrent()
{
	UA.undo();
}
void ApplicationManager::redoCurrent()
{
	UA.redo();
}
void ApplicationManager::RemoveUndone(CFigure*u)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == u)
		{
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
	}
}
void ApplicationManager::SetRecord(bool r)
{
	Record = r;
}
void ApplicationManager::addRecordedAction(Action*a)
{
	if (recordedactions < 20)
	{
			RecordedActions[recordedactions++] = a;
	}
}
void ApplicationManager::PlayRecorded()
{
	Clearall();
	Sleep(1000);
	for (int i = 0; i < recordedactions; i++)
	{
		RecordedActions[i]->Execute(false);
		RecordedActions[i]->AddtoUndo();
		UpdateInterface();
		Sleep(1000);
	}
}