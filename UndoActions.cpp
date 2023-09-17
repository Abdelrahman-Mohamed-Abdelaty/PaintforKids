#include "UndoActions.h"
UndoActions::UndoActions()
{
	actualcount = 0;
	undocount = 0;
	for (int i = 0; i < 5; i++)
	{
		A[i] = NULL;
		undone[i] = NULL;
	}
	current = NULL;
	currentindex = -1;
}
void UndoActions::pushAction(Action* a)
{
	for (int i = 0; i < 5; i++)
	{
		for(int j=0;j<5;j++)
		{
			if (A[i] == undone[j])
				A[i] = NULL;
		}
	}
	actualcount = 0;
	undocount = 0;
	for (int i = 0; i < 5; i++)
	{
		if (A[i] != NULL)
			actualcount++;
	}
	if (actualcount < 5)
	{
		currentindex++;
		A[actualcount] = a;
		current = A[currentindex];
		actualcount++;
	}
	else
	{
		A[0] = NULL;
		for (int i = 0; i < 4; i++)
		{
			A[i] = A[i + 1];
		}
		A[4] = a;
		currentindex = 4;
		current = A[currentindex];
	}
}
void UndoActions::undo()
{
	if ((actualcount>1)&&(undocount<5)&& (currentindex >= 0))
	{
		current->undo();
		undone[undocount++] = current;
		current = A[--currentindex];
	}
	else if(actualcount==1)
	{
		current->undo();
		undocount++;
	}
}
void UndoActions::redo()
{
	if ((actualcount>1)&&(undocount>0)&&(currentindex<4))
	{
		
		current = A[++currentindex];
		current->Execute(false);
		undone[--undocount] = NULL;
	}
	else if ((actualcount == 1) && (undocount > 0))
	{
		current->Execute(false);
		undocount--;
	}
}
void UndoActions::RemoveAll()
{
	actualcount = 0;
	undocount = 0;
	for (int i = 0; i < 5; i++)
	{
		A[i] = NULL;
		undone[i] = NULL;
	}
	current = NULL;
	currentindex = -1;
}