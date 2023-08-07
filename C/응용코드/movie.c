#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 상영 시각을 설정할 때 난수 설정을 위해 사용한 헤더파일
#include <time.h> // 완벽한 난수를 받기위해 사용한 헤더파일
#include <string.h> // 배열과 관련된 함수 사용을 위해 사용한 헤더파일

int price = 14000; // 영화표 가격 변수
char cinema_name[40]; // 선택한 영화관 변수
char a[] = { "올빼미" }, b[] = { "데시벨" }, c[] = { "블랙 팬서" }, d[] = { "동감" }, e[] = { "스트레인지 월드" }; //현재 상영 영화 변수
char date[40]; // 영화 관람 날짜 변수
int hh1, hh2, hh3, hh4, hh5, mm1, mm2, mm3, mm4, mm5 = 0; // 영화 상영 시각 변수
char decision_time[40]; // 선택 시간 변수
char decision_movie[40]; // 선택 영화 변수
int people; // 선택 좌석 개수 변수
int seats[9][12] = { 0 }; // 영화관 좌석 배열, A~I열, 11행까지 있다.
int total_price = 0; // 총 가격 변수

int main()
{

	int service; // 원하는 서비스 변수

	printf("\n안녕하세요 영화 예매 프로그램입니다.\n");
	printf("\n=========MAIN MENU=========\n");
	printf("|                        |\n");
	printf("|   1. 영화 예매하기     |\n");
	printf("|   2. 관리자 모드       |\n");
	printf("|   3. 종료하기          |\n");
	printf("|                        |\n");
	printf("===========================\n");

	while (1) { //1번, 2번, 3번이 아닌 다른 숫자를 입력할 경우를 고려.

		printf("\n원하시는 서비스 번호를 입력해주세요. : ");
		scanf("%d", &service);

		if (service < 1 || service > 3) {

			printf(" \n잘못된 번호 입니다. 다시 입력해주세요. \n");

			continue;

		}

		break;

	}

	if (service == 1) { // 사용자가 영화 예매 서비스를 선택할 경우
		reservation();
	}

	if (service == 2) { // 사용자가 관리자 모드를 선택할 경우
		admin_mode();
	}

	if (service == 3) { // 사용자가 종료를 선택할 경우를 고려

		printf("================================\n");
		printf("\n이용해 주셔서 감사합니다. :D  \n");
		printf("\n================================\n");

		return 0;

	}

}

int reservation() // 영화예매 진행 함수
{
	int x, y = 0;

	Choose_cinema(); // 영화관 선택 함수
	choose_movie(); // 관람할 영화 선택 함수
	movie_time(); // 상영 시각 생성 함수
	choose_time(); // 상영 시각 선택 함수
	decision_seats(); //좌석 선택 함수
	calculation_price(); //가격 계산 함수

	printf("\n=========================================================================\n");
	printf("\n고객님의 영화 예매 정보는 %s에서 %s, %s에 상영하는 %s입니다.\n좌석은", cinema_name, date, decision_time, decision_movie);
	for (y = 0; y < 9; y++) { // 예매된 좌석 출력
		for (x = 0; x < 11; x++) {

			if (seats[y][x] == 1) { // 에매한 자리

				printf(" %c열 %d번", 65 + y, x + 1);
			}
		}
	}
	printf("이고, 총 가격은 %d입니다.\n", total_price);
	printf("\n이용해 주셔서 감사합니다. :D  \n");
	printf("\n=========================================================================\n");
}

int Choose_cinema()// 영화관 선택 함수
{
	int cinema; // 영화관 종류 변수

	printf("\n==========영화관 목록==========\n");
	printf("\n      1. MEGABOX \n");
	printf("      2. 롯데 시네마 \n");
	printf("      3. CGV \n");
	printf("      4. 종료 \n");
	printf("\n===============================\n");

	while (1) // 1~4번을 선택하지 않을 경우를 고려
	{
		printf("\n어떤 영화관을 이용하시겠습니까? : ");
		scanf("%d", &cinema);

		if (cinema < 1 || cinema > 4)
		{
			printf("\n잘못된 번호 입니다. 다시 입력해주세요.\n");
			continue;
		}

		break;
	}

	switch (cinema) // 입력받은 정수값을 통해 선택한 영화관을 문자열로 저장
	{
	case 1:
		strcpy(cinema_name, "MEGABOX");
		break;
	case 2:
		strcpy(cinema_name, "롯데 시네마");
		break;
	case 3:
		strcpy(cinema_name, "CGV");
		break;
	case 4:
		break;
	}

	if (cinema == 4) //사용자가 종료를 선택할 경우
	{
		printf("================================\n");
		printf("\n이용해 주셔서 감사합니다. :D  \n");
		printf("\n================================\n");

		return 0;
	}

}
int movie_time() { // 상영 시각 생성 함수
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

int choose_movie() { // 영화 선택 함수

	int num;

	printf("\n영화를 관람하시려는 날짜는 언제입니까?(yyyy/mm/dd) : "); // 영화 관람 날짜 입력받기
	scanf("%s", &date);

	printf("\n========영화 목록========\n");
	printf("\n1. %s\n", a);
	printf("2. %s\n", b);
	printf("3. %s\n", c);
	printf("4. %s\n", d);
	printf("5. %s\n", e);
	printf("\n=======================\n");

	while (1) // 1~5번을 선택하지 않을 경우를 고려
	{
		printf("\n어떤 영화를 관람하시겠습니까?(번호를 입력해주세요.) : ");
		scanf("%d", &num);

		if (num < 1 || num > 5)
		{
			printf("\n잘못된 번호 입니다. 다시 입력해주세요.\n");
			continue;
		}

		break;
	}

	switch (num) // 입력 받은 정수값을 통해 선택한 영화를 문자열로 저장
	{
	case 1:
		strcpy(decision_movie, a);
		break;
	case 2:
		strcpy(decision_movie, b);
		break;
	case 3:
		strcpy(decision_movie, c);
		break;
	case 4:
		strcpy(decision_movie, d);
		break;
	case 5:
		strcpy(decision_movie, e);
		break;
	}
}

int choose_time() { //선택한 영화의 상영 시각 선택 함수

	printf("===========상영 시각===========\n");
	printf("\n1. %d : %d\n", hh1, mm1);
	printf("2. %d : %d\n", hh2, mm2);
	printf("3. %d : %d\n", hh3, mm3);
	printf("4. %d : %d\n", hh4, mm4);
	printf("5. %d : %d\n", hh5, mm5);
	printf("\n===============================\n");

	printf("\n원하시는 시각을 입력해주세요. (hh시mm분) : ");
	scanf("%s", &decision_time);

}

int decision_seats() { // 좌석 선택을 하는 함수
	int reserved_people = 0; // 예약에 성공한 사람 수를 저장함
	printf("\n예매할 좌석의 개수는 몇개입니까? (최대 3개) : ");
	scanf("%d", &people);

	printf("\n=========좌석 선택=========");
	while (reserved_people != people) {
		seat_list();
		reserved_people += choose_seats();
	}
}


int seat_list() { // 영화관 좌석 표 함수

	int y, x;

	printf("\n-----screen-----\n");
	printf("\n 123 45678 91011\n");
	for (y = 0; y < 9; y++) {

		printf("%c", 65 + y);
		for (x = 0; x < 11; x++) {

			if (x == 3) {
				printf(" ");
			}
			else if (x == 8) {
				printf(" ");
			}

			if (seats[y][x] == 1) { // 이미 선택된 자리

				printf("X");
			}
			else // 선택 가능 자리
			{
				printf("O");
			}
		}
		printf("\n");
	}
}

int choose_seats() { // 선택한 좌석의 매진 여부를 판단하고 좌석을 예매하는 함수

	char line; // 열 변수
	int number; // 행 변수

	rewind(stdin); //잘못된 값이 입력되는 것을 막기 위해 버퍼초기화

	printf("\n좌석을 선택해주세요.(ex : A 3) : ");
	scanf("%c%d", &line, &number);

	if (seats[line - 65][number - 1] == 1) { // 매진 좌석 선택 경우
		printf("\n매진된 좌석입니다. 다른 좌석을 선택해주세요\n");
		return 0;
	}
	else if (seats[line - 65][number - 1] == 0) { // 예매 가능한 좌석 선택한 경우
		seats[line - 65][number - 1] = 1;
		printf("\n좌석이 선택되었습니다.\n");
		return 1;
	}

}

int calculation_price() { // 총 금액을 계산해주는 함수
	total_price = price * people;
}


int admin_mode() { // 관리자 모드 함수

	int tool; // 원하는 관리자 기능 변수
	printf("\n=========관리자 모드=========\n");
	printf("\n  1. 영화 목록 수정    \n");
	printf("  2. 가격 변경\n");
	printf("  3. 관리자 모드 종료\n");
	printf("\n=============================\n");

	while (1) { //1번, 2번, 3번이 아닌 다른 숫자를 입력할 경우를 고려.

		printf("\n원하시는 기능의 번호를 입력해주세요. : ");
		scanf("%d", &tool);

		if (tool < 1 || tool > 3) { // 1~3번을 선택하지 않을 경우

			printf(" \n다시 입력해주세요 \n");

			continue;

		}

		break;

	}

	if (tool == 1) { //관리자가 영화 목록 수정을 선택할 경우
		movie_list();
	}
	if (tool == 2) { //관리자가 가격 변경을 선택할 경우
		change_price();
	}
	if (tool == 3) { //관리자가 관리자 모드 종료를 선택할 경우
		main();
	}
}

int movie_list() { // 영화 목록을 수정하는 함수
	char original_title[40]; // 제거하려는 영화 이름
	char change_title[40]; // 새로 추가하는 영화 이름
	int num = 0;
	while (1) {

		printf("제거하려는 영화의 제목을 입력해주세요 : ");
		scanf("%s", &original_title);
		printf("추가하려는 영화의 제목을 입력해주세요 : ");
		scanf("%s", &change_title);

		if (strcmp(a, original_title) == 0) { // strcpy함수를 통해 두 배열 비교 후 동일한 영화를 찾아냄
			strcpy(a, change_title);
			break;
		}
		else if (strcmp(b, original_title) == 0) {
			strcpy(b, change_title);
			break;
		}
		else if (strcmp(c, original_title) == 0) {
			strcpy(c, change_title);
			break;
		}
		else if (strcmp(d, original_title) == 0) {
			strcpy(d, change_title);
			break;
		}
		else if (strcmp(e, original_title) == 0) {
			strcpy(e, change_title);
			break;
		}
		else { // 제거하려는 영화 이름을 잘못 입력한 경우
			printf("제거하려는 영화가 목록에 없습니다.\n");
			printf("영화 제목을 다시한번 확인해주세요.\n");
			continue;
		}

	}

	printf("\n수정이 완료되었습니다. 메인 메뉴로 돌아갑니다.");
	admin_mode();
}

int change_price() { // 가격을 수정하는 함수
	printf("영화표의 값을 얼마로 변경하시겠습니까? : ");
	scanf("%d", &price);
	printf("\n변경이 완료되었습니다. 메인메뉴로 돌아갑니다.");
	main();
}
