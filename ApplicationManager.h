#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include"UndoActions.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	UndoActions UA;
	Action* RecordedActions[20];
	int recordedactions;
	Action* LastAction;
	bool Record;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool voice_on;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SetRecord(bool);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure* selectp);
	CFigure* GetSelectedFig();
	void  DeleteSelected();
	void Save_All(ofstream& foutfile);
	int getActualNumFigure();
	bool isVoiceOn();
	void setVoiceOn(bool v);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void DeletingAllfigs();
	void RemoveUndone(CFigure*u);
	void AddUndoAction(Action*);
	void undoCurrent();
	void redoCurrent();
	void addRecordedAction(Action*);
	void PlayRecorded();
	void Clearall();
};

#endif