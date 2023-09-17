#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)(0)
	MODE_PLAY	//Playing mode(1)
	//vlues to be taken by this data type ca
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,//Recangle item in menu(0)
	ITM_SQURE,
	ITM_TRIANGLE,
	ITM_CIRCLE,
	ITM_HEXA,
	SELECT_ONE,
	CHAN_FILLCOLOR,
	CHAN_DRAWCOLOR,
	BLACK_,
	RED_,
	YELLOW_,
	GREEN_,
	BLUE_,
	ORANGE_,
	DELTE,
	MOVE_FIGURE,
	UNDO,
	REDO,
	CLRER_ALL,
	START_RECORD,
	STOP_RECORD,
	PLAY_RECORD,
	SAVE_GRAPH ,
	LOAD_GRAPH,
	Read_Shapes,
	SWITCHT0_PLAYMODE,

	//TODO: Add more items names here
	//////////////////=============
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	FIGURE_TYPE,
	FIGURE_FILLCOLOR,
	FIGURE_TYPE_FILL,
	SWITCHT0_DRAWMODE,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif