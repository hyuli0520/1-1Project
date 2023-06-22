#include "main.h"

#define kbUP 72
#define kbDOWN 80
#define kbLEFT 75
#define kbRIGHT 77

int AttackAtoB(int iAtkA, int iDefB, int iHpB, int iCurY);
int RPGRandom(int iPercent);

void gotoXY(int x, int y);
void ClearMenu();
void ClearMainScreen();
void ClearTextBox();
void DrawScreenLine();
void DrawMap();
void ClearMap();
int GetEventForMap(int iCurrentX, int iCurrentY);