#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 상영 시각을 설정할 때 난수 설정을 위해 사용한 헤더파일
#include <time.h> // 완벽한 난수를 받기위해 사용한 헤더파일
#include <string.h> // 배열과 관련된 함수 사용을 위해 사용한 헤더파일

char date[40]; // 예약 날짜 변수
int hh1, hh2, hh3, hh4, hh5, mm1, mm2, mm3, mm4, mm5 = 0; // 시각 변수
char decision_time[40]; // 선택 시간 변수
int people; // 선택 좌석 개수 변수
int seats[9][12] = { 0 }; // 좌석 배열, A~I열, 11행까지 있다.

int main()
{
	int menu;

	printf("\n안녕하세요. 서울에서 제주행 비행기 예매 프로그램입니다.\n");
	printf("\n==========MENU=============\n");
	printf("||                       ||\n");
	printf("||   1. 예매하기         ||\n");
	printf("||   2. 종료하기         ||\n");
	printf("||                       ||\n");
	printf("===========================\n");

	while (1) 
	{
		printf("\n무엇을 하시겠습니까?\n>> ");
		scanf("%d", &menu);

		if (menu < 1 || menu > 3)
		{

			printf(" \n잘못된 번호 입니다. 다시 입력해주세요. \n");

			continue;

		}
		break;
	}

	if (menu == 1) 
	{
		reservation();
	}

	if (menu == 2) 
	{ 
		printf("================================\n");
		printf("\n이용해 주셔서 감사합니다. :D  \n");
		printf("\n================================\n");

		return 0;
	}
}

int reservation()  // 예매 진행 함수
{
	int x, y = 0;
	movie_time(); // 출발 시각 생성 함수
	choose_time(); // 출발 시각 선택 함수
	decision_seats(); //좌석 선택 함수

	printf("\n=========================================================================\n");
	printf("\n고객님의 예약 날짜는 %s, 시간은 %s입니다.\n예약 좌석은",date, decision_time);

	for (y = 0; y < 9; y++) 
	{ // 예매된 좌석 출력
		for (x = 0; x < 11; x++) 
		{

			if (seats[y][x] == 1) 
			{ // 에매한 자리

				printf(" %c열 %d번입니다.", 65 + y, x + 1);
			}
		}
	}
	printf("\n이용해 주셔서 감사합니다.\n즐거운 여행되세요. :D  \n");
	printf("\n=========================================================================\n");
}
int movie_time()
{ // 출발 시각 생성 함수
	srand((unsigned int)time(NULL)); // 완전한 난수 생성

	hh1 = (rand() % 17) + 7;
	hh2 = (rand() % 17) + 7;
	hh3 = (rand() % 17) + 7;
	hh4 = (rand() % 17) + 7;
	hh5 = (rand() % 17) + 7;
	mm1 = (rand() % 59);
	mm2 = (rand() % 59);
	mm3 = (rand() % 59);
	mm4 = (rand() % 59);
	mm5 = (rand() % 59);
}

int decision_seats() 
{ // 좌석 선택을 하는 함수

	int reserved_people = 0; // 예약에 성공한 사람 수를 저장함

	while (1)
	{
		printf("\n예매할 인원은 몇명입니까? (최대 3명)\n>> ");
		scanf("%d", &people);
		if (people < 1 || people>3) {
			printf("예약은 1명에서 3명까지만 가능합니다.\n다시 선택해주세요.");
			continue;
		}
	}
	
	printf("\n=========좌석 선택=========");
	while (reserved_people != people) 
	{
		seat_list();
		reserved_people += choose_seats();
	}
}

int seat_list() 
{ // 좌석 표 함수

	int y, x;

	printf("\n 123 45678 91011\n");
	for (y = 0; y < 9; y++) 
	{
		printf("%c", 65 + y);
		for (x = 0; x < 11; x++) 
		{

			if (x == 3) 
			{
				printf(" ");
			}
			else if (x == 8) 
			{
				printf(" ");
			}

			if (seats[y][x] == 1)
			{ // 이미 선택된 자리

				printf("X");
			}
			else
			{ // 선택 가능 자리
				printf("O");
			}
		}
		printf("\n");
	}
}

int choose_time()
{ //선택한 날짜 출발 시간 선택 함수

	printf("\n예약하시는 날짜를 입력해주세요. (yyyy년mm월dd일)\n>> ");
	scanf("%s", &date);

	printf("===========비행 출발 시간===========\n");
	printf("\n1. %d : %d\n", hh1, mm1);
	printf("2. %d : %d\n", hh2, mm2);
	printf("3. %d : %d\n", hh3, mm3);
	printf("4. %d : %d\n", hh4, mm4);
	printf("5. %d : %d\n", hh5, mm5);
	printf("\n===============================\n");

	printf("\n원하시는 시간을 입력해주세요. (hh:mm)\n>> ");
	scanf("%s", &decision_time);

}

int choose_seats()
{ // 선택한 좌석의 매진 여부를 판단하고 좌석을 예매하는 함수

	char line; // 열 변수
	int number; // 행 변수

	rewind(stdin); //잘못된 값이 입력되는 것을 막기 위해 버퍼초기화

	printf("\n좌석을 선택해주세요.(ex : A 1)\n>> ");
	scanf("%c%d", &line, &number);

	if (seats[line - 65][number - 1] == 1)
	{ // 매진 좌석 선택 경우
		printf("\n매진된 좌석입니다. 다른 좌석을 선택해주세요\n");
		return 0;
	}
	else if (seats[line - 65][number - 1] == 0)
	{ // 예매 가능한 좌석 선택한 경우
		seats[line - 65][number - 1] = 1;
		printf("\n좌석이 선택되었습니다.\n");
		return 1;
	}

}