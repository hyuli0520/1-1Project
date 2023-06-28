#include "main.h"

#define kbUP 72
#define kbDOWN 80
#define kbLEFT 75
#define kbRIGHT 77

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum
{
	black,
	blue, 
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

int AttackAtoB(int iAtkA, int iDefB, int iHpB, int iCurY);
int RPGRandom(int iPercent);

void gotoXY(int x, int y);
void setColor(int forground, int background);
void ClearMenu();
void ClearMainScreen();
void ClearTextBox();
void DrawScreenLine();
void DrawMap();
void ClearMap();
int GetEventForMap(int iCurrentX, int iCurrentY);