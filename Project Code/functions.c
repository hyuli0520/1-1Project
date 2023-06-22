#include "functions.h"

/////////////////////////////////////////////////////////////
// A가 B를 공격하는 함수
/////////////////////////////////////////////////////////////
int AttackAtoB(int iAtkA, int iDefB, int iHpB)
{
	int iDamage = 0;
	// 데미지 계산
	iDamage = iDefB - iAtkA;
	if (iDamage < 0)
	{
		iHpB += iDamage;

		printf("피해를 %d 입혔습니다.\n", iDamage);
		printf("남은 체력 : %d\n", iHpB);
		printf("\n");
	}
	else
	{
		printf("공격에 실패 하셨습니다.\n");
		printf("\n");
	}
	return iHpB;
}

/////////////////////////////////////////////////////////////
// Random 함수(확률 값을 반환하는 함수)
/////////////////////////////////////////////////////////////
int RPGRandom(int iPercent)
{
	int iRand = 0;
	srand(time(NULL));
	iRand = rand() % iPercent;

	return iRand;
}

/////////////////////////////////////////////////////////////
// X, Y로 이동하는 함수
/////////////////////////////////////////////////////////////
void gotoXY(int x, int y)
{
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

void ClearMenu()
{
	// 메뉴 지우기
	gotoXY(50, 31);
	printf("                      ");
	gotoXY(50, 32);
	printf("                      ");
	gotoXY(50, 33);
	printf("                      ");
	gotoXY(50, 34);
	printf("                      ");
}
void ClearMainScreen()
{
	gotoXY(30, 15);
	printf("                      ");
}