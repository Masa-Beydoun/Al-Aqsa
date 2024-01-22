#pragma once
class QibliMosque
{
public:
	static int stoneWall, rug;
	void drawBase(int stoneWall, int rug, int qibliDome, int qibliWithWindow);
	void drawFrontSide(int stoneWall,int greenDoor);
	void drawRightSide(int greenDoor, int stoneWall, int qibliWithWindow);
	void drawLeftSide(int stoneWall, int qibliWithWindow);
	void drawLeftSidePillars(int stoneWall);
};


