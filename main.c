#include "main.h"
#include "functions.h"

// 구조체
struct Mop
{
	double dHp;
	double dAtk;
	double dDef;
};

int main(int argc, char* argv[])
{

	// 캐릭터 이동


	int iHeroHp = 100, iHeroAtk = 10, iHeroDef = 5;
	int iMenu = -1;

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

	// 메인 화면
	gotoXY(30, 15);
	printf("RPG");

	while (1)
	{
;
		// 메뉴 화면
		gotoXY(50, 31);
		printf("## 메인 메뉴 ##");
		gotoXY(50, 32);
		printf("새 게임(0)");
		gotoXY(50, 33);
		printf("불러오기(1)");
		gotoXY(50, 34);
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
					gotoXY(30, 15);
					printf("던전 입장");
					while (1)
					{
						// 던전 메뉴 화면
						ClearMenu();
						gotoXY(50, 31);
						printf("던전 메뉴");
						gotoXY(50, 32);
						printf("이동(0)");
						gotoXY(50, 33);
						printf("나가기(기타)");
						scanf_s("%d", &iMenu);

						if (iMenu == 0)		// 이동
						{
							printf("이동\n");
							Sleep(2000);
							system("cls");

							int iRandomMove = RPGRandom(10);
							///////////////////////////////////////////////
							// 이벤트 발생
							if (iRandomMove <= 1) // 20%
							{
								printf("금화를 10원 획득\n");
								printf("\n");
							}
							///////////////////////////////////////////////
							// 그냥 이동
							else if (iRandomMove > 6) // 30%
							{
								printf("아무일도 일어나지 않았습니다.\n");
								printf("\n");
							}
							///////////////////////////////////////////////
							// 전투
							else
							{
								// return값이 0~2인 랜덤 함수
								int iRandomMove = RPGRandom(3);

								if (iRandomMove == 0)
								{
									printf("Mop1을 만났습니다.\n");
									strMopFight = strMop1;
								}
								else if (iRandomMove == 1)
								{
									printf("Mop2을 만났습니다.\n");
									strMopFight = strMop2;
								}
								else
								{
									printf("Mop3을 만났습니다.\n");
									strMopFight = strMop3;
								}

								while (1)
								{
									// 전투 메인 화면
									ClearMainScreen();
									gotoXY(30, 15);
									printf("전투 시작");

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
										printf("공격\n");
										printf("\n");

										// 주인공 1회 공격
										printf("주인공이 몬스터를 공격합니다.\n");
										strMopFight.dHp = AttackAtoB(iHeroAtk, strMopFight.dDef, strMopFight.dHp);

										// 몬스터 1회 반격
										printf("몬스터가 반격 합니다.\n");
										iHeroHp = AttackAtoB(strMopFight.dAtk, iHeroDef, iHeroHp);
									}
									else if (iMenu == 1)		// 방어
									{
										printf("방어\n");

										// 주인공이 방어(방어력 +2)
										printf("주인공이 방어 자세를 취합니다.\n");
										printf("몬스터가 반격 합니다.\n");
										iHeroHp = AttackAtoB(strMopFight.dAtk, iHeroDef + 2, iHeroHp);
									}
									else                    // 후퇴
									{
										printf("주인공이 후퇴를 시도합니다.\n");
										printf("몬스터가 반격 합니다.\n");
										iHeroHp = AttackAtoB(strMopFight.dAtk - 2, iHeroDef, iHeroHp);

										printf("던전으로 이동.\n");
										Sleep(2000);
										system("cls");
										break;
									}
									if (strMopFight.dHp <= 0)
									{
										printf("전투에 승리하였습니다.\n");
										break;
									}
								}
							}
						}
						else                // 나가기
						{
							printf("게임 메뉴료 이동.\n");
							break;
						}
					}

				}
				else               // 나가기 
				{
					printf("메인메뉴로 이동.\n");
					break;
				}
			}

		}
		else                // 나가기
		{
			printf("게임을 종료합니다.\n");
			break;
		}
	}


	return 0;
}