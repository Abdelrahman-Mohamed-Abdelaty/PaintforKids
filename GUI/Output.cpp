#include "Output.h"
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 40;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";//bath
	MenuItemImages[ITM_SQURE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\hexagon.jpg";
	MenuItemImages[SELECT_ONE] = "images\\MenuItems\\select.jpg";
	MenuItemImages[CHAN_FILLCOLOR] = "images\\MenuItems\\fillcolor.jpg";
	MenuItemImages[CHAN_DRAWCOLOR] = "images\\MenuItems\\drawcolor.jpg";
	MenuItemImages[BLACK_] = "images\\MenuItems\\black.jpg";
	MenuItemImages[RED_] = "images\\MenuItems\\red.jpg";
	MenuItemImages[YELLOW_] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[GREEN_] = "images\\MenuItems\\green.jpg";
	MenuItemImages[BLUE_] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ORANGE_] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[DELTE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[MOVE_FIGURE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[CLRER_ALL] = "images\\MenuItems\\clearall.jpg";
	MenuItemImages[START_RECORD] = "images\\MenuItems\\startrecord.jpg";
	MenuItemImages[STOP_RECORD] = "images\\MenuItems\\stoprecord.jpg";
	MenuItemImages[PLAY_RECORD] = "images\\MenuItems\\playrecord.jpg";
	MenuItemImages[SAVE_GRAPH] = "images\\MenuItems\\savegraph.jpg";
	MenuItemImages[LOAD_GRAPH] = "images\\MenuItems\\loadgraph.jpg";
	MenuItemImages[SWITCHT0_PLAYMODE] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[Read_Shapes] = "images\\MenuItems\\voice.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list
	//rectangle with just a click to draw square then call draw rectangle  
	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[FIGURE_TYPE]="images\\MenuItems\\figuretype.jpg";
	MenuItemImages[FIGURE_FILLCOLOR] = "images\\MenuItems\\figurefill.jpg";
	MenuItemImages[FIGURE_TYPE_FILL] = "images\\MenuItems\\figure_type_fill.jpg";
	MenuItemImages[SWITCHT0_DRAWMODE] = "images\\MenuItems\\drawmode.jpg";



	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	///TODO: write code to create Play mode menu
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
void Output::setCrntDrawColor(color D)
{
	UI.DrawColor = D;

}
void Output::setCrntFillColor(color F)
{
	UI.FillColor = F;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawSquare(Point P, GfxInfo SquareGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P1, P2;
	P1.x = P.x - 100;
	P1.y = P.y - 100;
	P2.x = P.x + 100;
	P2.y = P.y + 100;
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::Drawcircle(Point P1,Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int Radius = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	pWind->DrawCircle(P1.x, P1.y, Radius, style);
}
void Output::DrawHexagon(Point P, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int* px = new int[6];
	px[0] = P.x - 50;
	px[1] = P.x + 50;
	px[2] = P.x + 100;
	px[3] = P.x + 50;
	px[4] = P.x - 50;
	px[5] = P.x - 100;
	int* py = new int[6];
	py[0] = P.y - 86;
	py[1] = P.y - 86;
	py[2] = P.y;
	py[3] = P.y + 86;
	py[4] = P.y + 86;
	py[5] = P.y;
	pWind->DrawPolygon(px, py, 6, style);
	delete[]px;
	delete[]py;
}
void Output::ClearToolBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

