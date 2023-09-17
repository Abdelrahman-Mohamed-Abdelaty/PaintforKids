#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//to do:creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//to do: creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const;
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawSquare(Point P, GfxInfo SquareGfxInfo, bool selected) const;
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TRIGfxInfo, bool selected) const;
	void Drawcircle(Point P1,Point P2, GfxInfo CircGfxInfo, bool selected) const;
	void DrawHexagon(Point P, GfxInfo HexGfxInfo, bool selected) const;

	///TO DOO:  Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	void setCrntDrawColor(color D);
	void setCrntFillColor(color F);

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif