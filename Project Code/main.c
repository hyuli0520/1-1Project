#include "main.h"


#define MAX_PROBABILITY 100.0f  
#define WAIT_TIME 2 
#define SWORDA 60
#define GOTOY 12


int Main1();
int Main2();
int store();
int store_buy();
int store_buy1(int buyanswer);
int store_sell();
int sword();
int sword3();
int swordChoice();
int rpg();

void gotoxy(int xpos, int ypos);
void Titlebar(const char* ap_strting, int a_space_count);
void ColorSet(int backColor, int textColor);
void square();
void PrintMiddleLine(const char* ap_strting, int a_space_count);
void PT_TXT(char a[]);                  // 출력 함수
float probability = MAX_PROBABILITY;    // 현재 강화 성공확률
char name[256];
int x = 34, y = 13;
int defenceanswer = 0;						// 강화 대기시간
int defenceitem = 0;
int isTry = 0;                          // 강화를 할 것인지 선택
time_t retTime = 0;                     // 대기시간 임시저장 변수
int randNum = 0;                        // 랜덤값을 저장할 변수
int defence = 0;                        // 방어권 
int money = 0;                          // 현재 소지하고있는 돈 
int level = 0;                          // 현재 무기의 레벨
char text[100];
typedef enum ColorKinds
{
	black,
	blue,
	green,
	skyBlue,
	red,
	pink,
	Orange,
	white,
	gray,
	lightBlue,
	brightGreen,
	sky,
	brightRed,
	brightpink,
	brightyellow,
	brightwhite
}ColorKinds;

int main(void) {
	system("mode con cols=100 lines=25");
	int c;
	gotoxy(28, GOTOY);
	strcpy(text, "게임을 시작하시려면 enter을 눌러주세요.");
	PT_TXT(text);
	for (;;) {
		if (_kbhit())
		{
			c = _getch();
			if (c == 13)
			{
				system("cls");
				gotoxy(35, GOTOY);
				strcpy(text, "게임을 시작합니다.");
				PT_TXT(text);
				Sleep(1000);
				system("cls");
				Main1(text);
				break;
			}
			else
			{
				continue;
			}
		}
	}
	return 0;
}

int Main1()
{

	system("cls");
	gotoxy(32, GOTOY);
	strcpy(text, "당신의 이름을 적어주세요 : ");
	PT_TXT(text);
	scanf("%s", &name);
	system("cls");
	Main2();
}

int Main2()
{
	int x = 42, y = 12;
	Sleep(200);
	system("cls");
	gotoxy(32, GOTOY);
	printf("반갑습니다 %s님 선택해주세요", name);
	Sleep(1000);
	system("cls");
	while (1)
	{
		system("cls");
		gotoxy(43, GOTOY - 6);
		printf("이름 : %s", name);
		gotoxy(43, GOTOY - 4);
		printf("돈 : %4d", money);
		gotoxy(39, GOTOY - 2);
		printf("강화 실패 방어권 : %d", defenceitem);
		gotoxy(43, GOTOY);
		printf("1. 검 강화\n");
		gotoxy(43, GOTOY + 2);
		printf("2. RPG\n");
		gotoxy(43, GOTOY + 4);
		printf("3. 상점\n");
		gotoxy(43, GOTOY + 6);
		printf("4. 나가기\n");
		gotoxy(x, y);
		printf(">");

		if (_kbhit())
		{
			int key = _getch();
			if (y > 11 & y < 19)
			{
				switch (key)
				{
				case 'w':
				case 72:
					y -= 2;
					if (y <= 11)
						y = 12;
					break;
				case 's':
				case 80:
					y += 2;
					if (y >= 19)
						y = 18;
					break;
				case 13:
					if (y == 12)
					{
						strcpy(text, "   검 강화로 이동합니다.");
						PT_TXT(text);
						Sleep(1000);
						sword();
					}
					else if (y == 14)
					{
						strcpy(text, "   RPG로 이동합니다.");
						PT_TXT(text);
						Sleep(1000);
						rpg();
						system("mode con cols=100 lines=25");
					}
					else if (y == 16)
					{
						strcpy(text, "   상점으로 이동합니다.");
						PT_TXT(text);
						Sleep(1000);
						store();

					}
					else if (y == 18)
					{
						strcpy(text, "  프로그램을 종료합니다.");
						PT_TXT(text);
						Sleep(1000);
						return 0;
					}
					else
					{
						continue;
					}
					break;

				}
			}


		}
		Sleep(50);
	}
}

int sword(void)
{
	while (1)
	{
		// 화면 정리
		system("@cls||clear");
		// 현재 상태와 강화 도전 질의 출력
		while (1)
		{
			system("cls");
			gotoxy(35, GOTOY - 4);
			printf("무기레벨 : + %d\n", level);
			gotoxy(35, GOTOY - 3);
			printf("성공확률 : %.2f%%\n", probability);
			gotoxy(35, GOTOY - 2);
			printf("강화 실패 방어권 : %d개\n", defence);
			gotoxy(35, GOTOY - 1);
			printf("도전하시겠습니까?\n");
			gotoxy(35, GOTOY + 1);
			printf("[1.강화]       [2.포기] \n");
			gotoxy(x, y);
			printf(">");

			if (_kbhit())
			{
				int key = _getch();
				if (x > 33 & x < 50)
				{
					switch (key)
					{
					case 'a':
					case 75:
						x -= 15;
						if (x <= 33)
							x = 34;
						continue;
					case 'd':
					case 77:
						x += 15;
						if (x >= 50)
							x = 49;
						continue;
					case 13:
						if (x == 34)
						{
							sword2(1);
							break;
						}
						else if (x == 49)
						{
							sword2(2);
							break;
						}
					}
				}


			}
			Sleep(50);
		}

		return 0;
	}
}

int sword2(int isTry) {
	int x = 31, y = GOTOY + 9;
	int x2 = 30, y2 = GOTOY + 9;
	srand((int)time(NULL));                 // 랜덤 시드값 설정
	switch (isTry)
	{
	case 1:        // 강화에 도전 할 경우
		system("cls");
		gotoxy(43, GOTOY);
		printf("강화중..");
		isTry = 0;

		// 지정된 시간(초) 만큼 대기
		retTime = time(0) + WAIT_TIME;
		while (time(0) < retTime);

		// 랜덤 값 추출
		randNum = rand() % 100;
		// 추출한 랜덤 값이 성공확률 보다 작으면 성공
		if (randNum < probability) {
			// 성공화면 출력
			system("cls");
			gotoxy(35, GOTOY - 4);
			printf("***** SUCCESS *****\n");
			gotoxy(35, GOTOY - 3);
			printf("*                 *\n");
			gotoxy(35, GOTOY - 2);
			printf("*   + %d  ->  + %d  *\n", level, level + 1);
			gotoxy(35, GOTOY - 1);
			printf("*                 *\n");
			gotoxy(35, GOTOY);
			printf("***** SUCCESS *****\n");

			// 강화에 성공 했을 시, 레벨을 하나 증가 시키고, 성공확률을 보정
			// 이 때, 현재 성공확률의 10%에 현재 레벨로 가중치를 추가로 적용
			level++;
			probability -= (probability / 22.5f) * level;
			switch (level)
			{
			case 1:
				gotoxy(30, GOTOY + 1);
				square();
				gotoxy(36, GOTOY + 3);
				strcpy(text, "-l-->");
				PT_TXT(text);
				break;
			case 2:
				gotoxy(30, GOTOY + 1);
				square();
				gotoxy(36, GOTOY + 3);
				strcpy(text, "＝lニニフ");
				PT_TXT(text);
				break;
			case 3:
				gotoxy(30, GOTOY + 1);
				square();
				gotoxy(32, GOTOY + 3);
				strcpy(text, "@==||::::::::::::>");
				PT_TXT(text);
				break;
			case 4:
				gotoxy(30, GOTOY + 1);
				square();
				gotoxy(28, GOTOY + 3);
				strcpy(text, " cxxx{}:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;:;>");
				PT_TXT(text);
				break;

			case 5:
				gotoxy(30, GOTOY + 1);
				square();
				gotoxy(28, GOTOY + 3);
				strcpy(text, " <--=-=-=-=-=-=-=()=()=-=-=-=-=-=-=-=-->");
				PT_TXT(text);
				break;
			default:
				gotoxy(30, GOTOY + 1);
				square();
				gotoxy(24, GOTOY + 3);
				strcpy(text, "< ::::::::::::::::::{}xxx) = (ㅇ - ㅇ) = cxxx{}:::::::::::::::::::::::::::: > ");
				PT_TXT(text);
				break;
			}
			// 진행상황 확인이 용이 하도록 대기
			gotoxy(32, GOTOY + 6);
			system("pause");
			break;
		}
		else
		{
			while (1) {
				system("cls");
				// 실패화면 출력
				gotoxy(32, GOTOY + 7);
				printf("어익후.. 손이 미끌어졌네..\n");
				gotoxy(32, GOTOY + 8);
				printf("강화 실패 방어권을 사용하시겠습니까?\n");
				gotoxy(32, GOTOY + 9);
				printf(" 네 ");
				gotoxy(32, GOTOY + 11);
				printf(" 아니요");
				gotoxy(x2, y2);
				printf(">");

				if (_kbhit())
				{
					int key = _getch();
					if (y2 > GOTOY + 8 & y2 < GOTOY + 12)
					{
						switch (key)
						{
						case 'w':
						case 72:
							y2 -= 2;
							if (y2 <= GOTOY + 8)
								y2 = GOTOY + 9;
							continue;
						case 's':
						case 80:
							y2 += 2;
							if (y2 >= GOTOY + 12)
								y2 = GOTOY + 11;
							continue;
						case 13:
							if (y2 == GOTOY + 9)
							{
								sword3(1);
								break;
							}
							else if (y2 == GOTOY + 11)
							{
								sword3(2);
								break;
							}
						}
					}
				}
				Sleep(50);
			}
			// 진행상황 확인이 용이 하도록 대기
			gotoxy(32, GOTOY + 6);
			system("pause");
		}
	case 2:
	{
		system("cls");
		gotoxy(35, GOTOY);
		strcpy(text, "메인으로 돌아갑니다.");
		PT_TXT(text);
		Main2();
		break;
	}

	// 진행상황 확인이 용이 하도록 대기
	gotoxy(32, GOTOY + 6);
	system("pause");
	}
}

int sword3(int defenceanswer) {
	while (1)
	{
		if (defenceanswer == 1)
		{
			if (defence >= defenceitem)
			{
				gotoxy(32, GOTOY + 11);
				printf("강화 실패 방어권을 사용하셨습니다.\n");
				Sleep(1000);
				switch (level)
				{
				case 1:
					defenceitem = 1;
					break;
				case 2:
					defenceitem = 2;
					break;
				case 3:
					defenceitem = 4;
					break;
				case 4:
					defenceitem = 7;
					break;
				case 5:
					defenceitem = 10;
					break;
				case 6:
					defenceitem = 12;
					break;
				case 7:
					defenceitem = 14;
					break;
				case 8:
					defenceitem = 16;
					break;
				case 9:
					defenceitem = 18;
					break;
				default:
					defenceitem = 20;
					break;
				}
			}
			else
			{
				// 각종 수치 초기화
				probability = MAX_PROBABILITY;
				system("cls");
				gotoxy(32, GOTOY + 12);
				printf("강화 실패 방어권이 %d개 부족합니다.\n\n", defenceitem - defence);
				Sleep(1000);
				gotoxy(32, GOTOY + 13);
				printf("+ %d까지 강화한 무기를 잃었습니다.\n", level);
				level = 0;
				break;
				gotoxy(32, GOTOY + 14);
				printf("\n계속하려면 아무 키나 누르십시오.\n");
				_getch();
			}
			// 각종 수치 초기화
			probability = MAX_PROBABILITY;
			system("cls");
			gotoxy(32, GOTOY);
			printf("+ %d 무기를 잃었습니다.\n", level);
			Sleep(1000);
			level = 0;
			break;
		}
		else if (defenceanswer == 2)
		{
			isTry = 0;
			system("cls");
			Main2();
		}
		else
		{
			printf("다시 입력하세요!");
			continue;
		}
	}

}

int store()
{
	int x = 41, y = 13;
	int answer;
	while (1)
	{
		system("cls");
		gotoxy(35, GOTOY - 3);
		printf("%s님 상점에 오신것을 환영합니다.\n", name);
		gotoxy(32, GOTOY - 2);
		printf("%s님이 현제 소유하고 계신 돈은 %d원입니다.\n", name, money);
		gotoxy(36, GOTOY - 1);
		printf("어떤것을 하시겠습니까?? ");
		gotoxy(43, GOTOY + 1);
		printf("[1. 구매]");
		gotoxy(43, GOTOY + 3);
		printf("[2. 판매]");
		gotoxy(43, GOTOY + 5);
		printf("[3. 나가기]");
		gotoxy(x, y);
		printf(">");

		if (_kbhit())
		{
			int key = _getch();
			if (y > 12 & y < 20)
			{
				switch (key)
				{
				case 'w':
				case 72:
					y -= 2;
					if (y <= 12)
						y = 13;
					continue;
				case 's':
				case 80:
					y += 2;
					if (y >= 18)
						y = 17;
					continue;
				case 13:
					if (y == 13)
					{
						store_buy();
						break;
					}
					else if (y == 15)
					{
						store_sell();
						break;
					}
					else if (y == 17)
					{
						system("cls");
						gotoxy(37, GOTOY);
						printf("메인으로 이동합니다..");
						Main2();
						break;
					}
				}
			}


		}
		Sleep(50);

	}
}

int store_buy()
{
	int buyanswer1;
	int buyanswer2;
	int c;
	int answer;
	int x = 28, y = 11;
	system("cls");
	gotoxy(38, GOTOY - 3);
	printf("무엇을 구매하시겠습니까?\n\n");
	gotoxy(30, GOTOY - 1);
	printf("1. [강화 실패 방어권 * 1]          1000원\n");
	while (1) {
		gotoxy(42, GOTOY);
		scanf("%d", &buyanswer1);
		if (buyanswer1 == 1) {
			gotoxy(32, GOTOY);
			printf("몇개를 구매하시겠습니까 : ");
			scanf("%d", &buyanswer2);
			if (money >= 1000 * buyanswer2)
			{
				defence += buyanswer2;
				money -= 1000 * buyanswer2;
				system("cls");
				gotoxy(29, GOTOY + 1);
				printf("구매가 완료되었습니다 감사합니다.\n");
				gotoxy(29, GOTOY + 2);
				printf("현제 가지고계시는 강화 실패 방어권은 %d개 입니다.\n", defence);
				gotoxy(29, GOTOY + 3);
				printf("구매를 종료하시려면 E를 다시 상점으로 돌아가시려면 R을 누르세요\n");
				for (;;) {
					if (_kbhit())
					{
						c = _getch();
						if (c == 69 || c == 101)
						{
							system("cls");
							gotoxy(30, GOTOY);
							printf("구매를 종료합니다. 메인으로 돌아갑니다...\n");
							Sleep(1000);
							system("cls");
							Main2();
							break;
						}
						else if (c == 82 || c == 114)
						{
							system("cls");
							gotoxy(30, GOTOY);
							printf("다시 상점으로 이동합니다...\n");
							Sleep(1000);
							system("cls");
							store();
							break;
						}
					}
				}
			}
			else
			{
				system("cls");
				gotoxy(30, GOTOY);
				printf("돈이 부족합니다. 상점으로 다시 돌아갑니다.");
				Sleep(1000);
				store();
				break;
			}
		}
		else if (buyanswer1 == 0)
		{
			system("cls");
			gotoxy(30, GOTOY);
			printf("메인으로 돌아갑니다...");
			Main2();
			break;
		}
		else {
			system("cls");
			gotoxy(30, GOTOY);
			printf("다시 입력하세요.");
			store_buy();
			break;
		}
	}

}

int store_sell()
{
	int sellanswer;
	int sellanswer2;
	int sellanswer3;
	int selldefence;
	int money2;
	system("cls");
	gotoxy(37, GOTOY - 2);
	printf("무엇을 판메하시겠습니까?");
	gotoxy(38, GOTOY - 1);
	printf("[1. 검]");
	gotoxy(38, GOTOY);
	printf("[2. 강화 실패 방어권] \n");
	gotoxy(32, GOTOY + 1);
	printf("메인화면으로 나가시려면 0을 입력해주세요\n");
	while (1)
	{
		gotoxy(43, GOTOY + 2);
		scanf("%d", &sellanswer);
		if (sellanswer == 1)
		{
			system("cls");
			gotoxy(38, GOTOY);
			printf("정말 검을 판매하시겠습니까?\n");
			Sleep(1000);
			gotoxy(42, GOTOY + 1);
			printf("1. 네  2. 아니요\n");
			while (1)
			{
				gotoxy(48, GOTOY + 2);
				scanf("%d", &sellanswer2);
				if (sellanswer2 == 1)
				{
					switch (level)
					{
					case 0:
						money2 = 0;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 1:
						money2 = 1000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 2:
						money2 = 2000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 3:
						money2 = 3000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 4:
						money2 = 4000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 5:
						money2 = 5000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 6:
						money2 = 6000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 7:
						money2 = 7000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 8:
						money2 = 8000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					case 9:
						money2 = 10000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;
						break;
					default:
						money2 = 20000;
						money += money2;
						level = 0;
						probability = MAX_PROBABILITY;

						break;
					}
					system("cls");
					gotoxy(40, GOTOY);
					printf("%d원을 벌었습니다!!\n", money2);
					Sleep(1000);
					gotoxy(44, GOTOY + 1);
					printf("이얏호!!\n");
					store_sell();
					break;
				}
			}

		}
		else if (sellanswer == 2)
		{
			gotoxy(32, GOTOY - 1);
			printf("강화 실패 방어권을 파시려면 수수료가 50%붙습니다 그래도 하시겠습니까?\n");
			gotoxy(42, GOTOY);
			printf("1. 네  2. 아니요");
			while (1)
			{
				scanf("%d", &sellanswer3);
				if (sellanswer3 == 1)
				{
					printf("몇개를 파시겠습니까? : ");
					scanf("%d", &selldefence);
					if (selldefence <= defence)
					{
						defence -= selldefence;
						money += selldefence * 500;
						printf("%d원을 벌었습니다!!", selldefence * 500);
						break;
					}
					else
					{
						printf("강화 실패 방어권의 갯수가 부족합니다.\n");
						Sleep(1000);
						printf("상점으로 돌아갑니다.");
						break;
					}
				}
				else if (sellanswer3 == 2)
				{
					printf("상점으로 다시 이동합니다.\n");
					store();
					break;
				}
			}
		}
		else if (sellanswer == 0)
		{
			printf("메인으로 돌아갑니다.");
			store();
			break;
		}
		else
		{
			printf("다시 입력하세요");
			continue;
		}
	}

}

void gotoxy(int xpos, int ypos)
{
	COORD pos = { xpos,ypos };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void PrintMiddleLine(const char* ap_strting, int a_space_count)
{
	printf("|%-*s|\n", a_space_count, ap_strting);
}

void Titlebar(const char* ap_strting, int a_space_count)
{
	int i;
	printf("┌");
	for (i = 0; i < a_space_count; i++) {
		printf("─");
	}
	printf("┐\n");

	PrintMiddleLine("", a_space_count);
	PrintMiddleLine(ap_strting, a_space_count);
	PrintMiddleLine("", a_space_count);

	printf("└");
	for (i = 0; i < a_space_count; i++) printf("─");
	printf("┘\n");

}

void PT_TXT(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		printf("%c", a[i]);
		Sleep(30);
	}
}

void ColorSet(int backColor, int textColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (backColor << 4) + textColor);
}

void square()
{
	gotoxy(27, GOTOY + 1);
	printf("┌───────────────────────────────────────────────┐\n");
	gotoxy(27, GOTOY + 2);
	printf("|                                                |\n");
	gotoxy(27, GOTOY + 3);
	printf("|                                                |\n");
	gotoxy(27, GOTOY + 4);
	printf("|                                                |\n");
	gotoxy(27, GOTOY + 5);
	printf("└───────────────────────────────────────────────┘\n");
}


