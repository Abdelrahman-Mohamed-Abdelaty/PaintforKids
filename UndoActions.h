#pragma once
#include"Actions/Action.h"
class UndoActions
{
private:
	Action* A[5];
	Action* undone[5];
	int actualcount;
	int undocount;
	Action* current;
	int currentindex;
public:
	UndoActions();
	void pushAction(Action*);
	void undo();
	void redo();
	void RemoveAll();

};

