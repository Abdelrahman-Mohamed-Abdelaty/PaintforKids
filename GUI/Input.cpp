#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_EXIT: return EXIT;		
			case ITM_SQURE :return DRAW_SQURE ;		
			case ITM_TRIANGLE:return DRAW_TRI;
			case ITM_CIRCLE:return DRAW_CIRC;
			case ITM_HEXA: return DRAW_HEXA;
			case SELECT_ONE:return SELECTONE;
			case CHAN_FILLCOLOR: return CHAN_FILLCOl;
			case CHAN_DRAWCOLOR:return CHAN_DRAWCOL;
			case BLACK_:return COLBLACK;
			case RED_:return COLRED;
			case YELLOW_:return COLYELLOW;
			case 	GREEN_:return COLGREEN;
			case BLUE_:return COLBLUE;
			case ORANGE_:return COLORANGE;
			case DELTE: return DELETE_FIG;
			case MOVE_FIGURE:return MOVE_FIG;
			case UNDO:return UNDO_;
			case REDO:return REDO_;
			case CLRER_ALL:return CLEARALL;
			case START_RECORD:return STARTREC;
			case STOP_RECORD:return STOPREC;
			case PLAY_RECORD:return PLAYREC;
			case SAVE_GRAPH :return SAVEGRAPH;
			case LOAD_GRAPH:return LOADGRAPH;
			case Read_Shapes:return ReadShapes;

			case SWITCHT0_PLAYMODE:return TO_PLAY;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case FIGURE_TYPE :return FIG_TYPE;
			case FIGURE_FILLCOLOR:return FIG_FILLCOLOR;
			case FIGURE_TYPE_FILL:return FIG_TYPE_FILL;
			case SWITCHT0_DRAWMODE:return TO_DRAW;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
		
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
