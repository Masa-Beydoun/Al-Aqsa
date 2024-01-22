#pragma once
class IslamicMusuem
{
public:
	IslamicMusuem(void);
	~IslamicMusuem(void);
	void drawBase(int stoneWall);
	void drawDome(int domeTexture);
	void drawDecorations(int door, int windows, int label);
	void drawManara(int stoneWall, int window, int door, int stairsTex, int handrailTex);
};

