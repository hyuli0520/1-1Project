#include "main.h"
#include "functions.h"

extern int money;

// 구조체
struct Mop
{
	double dHp;
	double dAtk;
	double dDef;
};

int rpg()
{

	// 캐릭터 이동


	int iHeroHp = 100, iHeroAtk = 10, iHeroDef = 5;
	int iMenu = -1;
	char cPosition;
	int iCenterX = 7, iCenterY = 7, iExit = 0, iEvent = -1;

	// 구조체
	struct Mop strMop1, strMop2, strMop3, strMopFight;
	// Mop1
	strMop1.dHp = 100;
	strMop1.dAtk = 8;
	strMop1.dDef = 3;
	// Mop2
	strMop2.dHp = 80;
	strMop2.dAtk = 8;
	strMop2.dDef = 3;
	// Mop3
	strMop3.dHp = 50;
	strMop3.dAtk = 8;
	strMop3.dDef = 3;

	// console 창 크기 변경
	system("mode con:cols=90 lines=50");

	printf("\t\t\t\t\t\t\tRPG");

	// 화면 구분해주는 함수
	DrawScreenLine();

	// 메인 화면
	gotoXY(30, 15);
	printf("RPG");

	while (1)
	{

		// 메뉴 화면
		gotoXY(50, 31);
		printf("## 메인 메뉴 ##");
		gotoXY(50, 32);
		printf("새 게임(0)");
		gotoXY(50, 33);
		printf("돌아가기(기타)");

		scanf_s("%d", &iMenu);

		if (iMenu == 0)		// 새 게임
		{
			// 메인 화면
			ClearMainScreen();
			gotoXY(30, 15);
			printf("새 게임");

			while (1)
			{
				// 게임 메뉴
				ClearMenu();
				gotoXY(50, 31);
				printf("## 게임 메뉴 ##");
				gotoXY(50, 32);
				printf("던전입장(0)");
				gotoXY(50, 33);
				printf("나가기(기타)");
				scanf_s("%d", &iMenu);

				if (iMenu == 0)		// 던전 입장
				{
					ClearMainScreen();
					//gotoXY(30, 15);
					//printf("던전 입장");
					DrawMap();

					while (1)
					{
						// 던전 메뉴 화면
						ClearMenu();
						gotoXY(50, 31);
						printf("던전 메뉴");
						gotoXY(50, 32);
						printf("이동(방향키 사용)");
						gotoXY(50, 33);
						printf("나가기(1)");

						// Center
						gotoXY(iCenterX, iCenterY);
						printf("*"); // Player

						while (1)
						{
							if (_kbhit())
							{
								gotoXY(iCenterX, iCenterY);
								printf(" ");

								// 캐릭터 이동
								cPosition = _getch();

								switch (cPosition)
								{
								case 'w': // Up
								case 'W':
								case kbUP:
									iCenterY--;
									break;
								case 's': // Down
								case 'S':
								case kbDOWN:
									iCenterY++;
									break;
								case 'a': // Left
								case 'A':
								case kbLEFT:
									iCenterX--;
									break;
								case 'd': // Right
								case 'D':
								case kbRIGHT:
									iCenterX++;
									break;
								case '1': // 나가기
									iExit = 1;

								}

								// 맵 크기 설정
								if (iCenterX <= 6)
								{
									iCenterX++;
								}
								else if (iCenterX >= 49)
								{
									iCenterX--;
								}
								else if (iCenterY <= 6)
								{
									iCenterY++;
								}
								else if (iCenterY >= 25)
								{
									iCenterY--;
								}
								gotoXY(iCenterX, iCenterY);
								//setColor(lightgreen, lightgreen);
								printf("*");
								Sleep(10);
							}

							// 현재위치와 map의 이벤트 발생 위치 비교
							iEvent = GetEventFormMap(iCenterX, iCenterY);

							if (iEvent == 0)
							{
								iMenu = 0;
								iCenterX++;
								break;
							}

							if (iExit == 1) // 나가기
							{
								ClearMap();
								iMenu = 1;
								break;
							}
						}
						//scanf_s("%d", &iMenu);

						if (iMenu == 0)		// 이동
						{
							printf("이동\n");
							Sleep(1000);

							system("cls");

							int iRandomMove = RPGRandom(10);
							///////////////////////////////////////////////
							// 이벤트 발생
							if (iRandomMove < 1) // 20%
							{
								DrawScreenLine();
								ClearTextBox();
								DrawMap();
								gotoXY(2, 32);
								printf("돈을 200원 획득");
								money += 200;
							}
							///////////////////////////////////////////////
							// 그냥 이동
							else if (iRandomMove > 6) // 30%
							{
								DrawScreenLine();
								ClearTextBox();
								DrawMap();
								gotoXY(2, 32);
								printf("아무일도 일어나지 않았습니다.");
							}
							///////////////////////////////////////////////
							// 전투
							else
							{
								// return값이 0~2인 랜덤 함수
								int iRandomMove = RPGRandom(3);

								if (iRandomMove == 0)
								{
									// 전투 메인 화면
									DrawScreenLine();
									ClearMap();
									gotoXY(30, 15);
									printf("Mop1 전투 시작");

									ClearTextBox();
									gotoXY(2, 32);
									printf("Mop1을 만났습니다.");
									strMopFight = strMop1;
								}
								else if (iRandomMove == 1)
								{
									// 전투 메인 화면
									DrawScreenLine();
									ClearMap();
									gotoXY(30, 15);
									printf("Mop2 전투 시작");

									ClearTextBox();
									gotoXY(2, 32);
									printf("Mop2을 만났습니다.");
									strMopFight = strMop2;
								}
								else
								{
									// 전투 메인 화면
									DrawScreenLine();
									ClearMap();
									gotoXY(30, 15);
									printf("Mop3 전투 시작");

									ClearTextBox();
									gotoXY(2, 32);
									printf("Mop3을 만났습니다.");
									strMopFight = strMop3;
								}

								while (1)
								{
									// 전투 메뉴 화면
									ClearMenu();
									gotoXY(50, 31);
									printf("## 전투 메뉴 ##");
									gotoXY(50, 32);
									printf("공격(0)");
									gotoXY(50, 33);
									printf("방어(1)");
									gotoXY(50, 34);
									printf("후퇴(기타)");
									scanf_s("%d", &iMenu);


									// 데미지 계산식
									// 방어력 - 공격력
									int iDamage = 0;

									if (iMenu == 0) 		// 전투
									{
										//printf("공격\n");
										//printf("\n");

										ClearTextBox();
										gotoXY(2, 32);
										// 주인공 1회 공격
										printf("주인공이 몬스터를 공격합니다.");
										strMopFight.dHp = AttackAtoB(iHeroAtk, strMopFight.dDef, strMopFight.dHp, 32);

										gotoXY(2, 35);
										// 몬스터 1회 반격
										printf("몬스터가 반격 합니다.");
										iHeroHp = AttackAtoB(strMopFight.dAtk, iHeroDef, iHeroHp, 35);
									}
									else if (iMenu == 1)		// 방어
									{
										//printf("방어\n");

										ClearTextBox();
										gotoXY(2, 32);
										// 주인공이 방어(방어력 +2)
										printf("주인공이 방어 자세를 취합니다.");
										gotoXY(2, 34);
										printf("몬스터가 반격 합니다.");
										iHeroHp = AttackAtoB(strMopFight.dAtk, iHeroDef + 2, iHeroHp, 34);
									}
									else                    // 후퇴
									{
										ClearTextBox();
										gotoXY(2, 32);
										printf("주인공이 후퇴를 시도합니다.");
										gotoXY(2, 34);
										printf("몬스터가 반격 합니다.");
										iHeroHp = AttackAtoB(strMopFight.dAtk - 2, iHeroDef, iHeroHp, 34);
										Sleep(2000);

										ClearMainScreen();
										//gotoXY(30, 15);
										//printf("던전");

										ClearTextBox();
										gotoXY(2, 32);
										printf("던전으로 이동.");
										Sleep(2000);
										system("cls");
										DrawMap();
										break;
									}
									if (strMopFight.dHp <= 0)
									{
										ClearMainScreen();
										//gotoXY(30, 15);
										//printf("던전");
										DrawMap();

										ClearTextBox();
										gotoXY(2, 32);
										printf("전투에 승리하였습니다.");
										gotoXY(2, 34);
										printf("돈을 1000원 획득");
										money += 1000;
										break;
									}
								}
							}
						}
						else                // 나가기
						{
							ClearMainScreen();
							gotoXY(30, 15);
							printf("게임 메뉴");

							ClearTextBox();
							gotoXY(2, 32);
							printf("게임 메뉴로 이동.");
							break;
						}
					}

				}
				else               // 나가기 
				{
					// 메인 화면 
					ClearMainScreen();
					gotoXY(30, 15);
					printf("메인 메뉴");

					ClearTextBox();
					gotoXY(2, 32);
					printf("메인메뉴로 이동.");
					break;
				}
			}

		}
		else                // 나가기
		{
			// 게임 종료
			ClearMainScreen();
			gotoXY(30, 15);
			printf("종료");

			ClearTextBox();
			gotoXY(2, 32);
			printf("게임을 종료합니다.\n\n\n\n");
			break;
		}
	}


	return 0;
}