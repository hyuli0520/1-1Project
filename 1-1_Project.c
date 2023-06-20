#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int AttackAtoB(int iAtkA, int iDefB, int iHpB);

int main(int argc, char* argv[])
{
	int iHeroHp = 100, iHeroAtk = 10, iHeroDef = 5;
	int iMopHp = 100, iMopAtk = 8, iMopDef = 3;
	int iMenu = -1;

	printf("RPG\n");

	while (1)
	{
		// 메인 메뉴
		printf("메인 메뉴\n");
		printf("새 게임(0), 불러오기(1), 돌아가기(기타)\n");
		scanf_s("%d", &iMenu);

		if (iMenu == 0)		// 새 게임
		{
			printf("새 게임\n");

			while (1)
			{
				// 게임 메뉴
				printf("게임 메뉴\n");
				printf("던전입장(0), 나가기(기타)\n");
				scanf_s("%d", &iMenu);

				if (iMenu == 0)		// 던전 입장
				{
					printf("던전 입장\n");
					while (1)
					{
						// 던전
						printf("던전 메뉴\n");
						printf("이동(0), 나가기(기타)\n");
						scanf_s("%d", &iMenu);

						if (iMenu == 0)		// 이동
						{
							printf("이동\n");
							Sleep(2000);
							system("cls");

							while (1)
							{
								// 전투
								printf("전투 메뉴\n");
								printf("공격(0), 방어(1), 후퇴(기타)\n");
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
									iMopHp = AttackAtoB(iHeroAtk, iMopDef,iMopHp);

									// 몬스터 1회 반격
									printf("몬스터가 반격 합니다.\n");
									iHeroHp = AttackAtoB(iMopAtk, iHeroDef, iHeroHp);
								}
								else if (iMenu == 1)		// 방어
								{
									printf("방어\n");

									// 주인공이 방어(방어력 +2)
									iDamage = (iHeroDef + 2) - iMopAtk;
									// 몬스터가 반격
									if (iDamage < 0)
									{
										iHeroHp += iDamage;
										printf("몬스터가 반격합니다.\n");
										printf("피해를 %d 입었습니다.\n", iDamage);
										printf("남은 체력 : %d\n", iHeroHp);
									}
									else
									{
										printf("몬스터가 공격에 실패 하셨습니다.\n");
									}
								}
								else                    // 후퇴
								{
									iDamage = iHeroDef - (iMopAtk - 2);
									if (iDamage < 0)
									{
										iHeroHp += iDamage;

										printf("몬스터가 반격 합니다.\n");
										printf("피해를 %d 입었습니다.\n", iDamage);
										printf("남은 체력 : %d\n", iHeroHp);
									}
									else
									{
										printf("몬스터가 공격에 실패 하셨습니다.\n");
									}

									printf("던전으로 이동.\n");
									Sleep(2000);
									system("cls");
									break;
								}
								if (iMopHp <= 0)
								{
									printf("전투에 승리하였습니다.\n");
									break;
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

int AttackAtoB(int iAtkA, int iDefB,int iHpB)
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