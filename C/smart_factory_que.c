#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

int black_cnt, red_cnt, blue_cnt, error_cnt, total_cnt;

struct pen {
	int num;            // 생산순서번호
	int ID[MAX];   // 볼펜ID
	char color[MAX];         // 색 
};

int main()
{
	FILE* p; // 파일 포인터 생성
	p = fopen("04.txt", "a+");  // 덮어쓰기 모드로 파일 오픈
	if (p == NULL) // 파일 오픈 에러시
	{
		printf("파일을 열지 못했습니다.");
		return -1;
	}

	struct pen bolpen[MAX] = { 0 }; // 구조체 배열 -> 출력 시 사용
	int black_cnt = 0, red_cnt = 0, blue_cnt = 0, total_cnt = 0;  // 생산 전 볼펜의 수량

	clock_t start, stop;  // 시간측정 함수
	double duration;

	start = clock();    // 측정 시작
	
	srand(time(NULL));  // srand로 시드값 초기화

	for (int i = 1; i <= MAX; i++)
	{
		int rand1 = rand();
		while (1) {            // 중복 방지
			int flag = 0;
			int arr[MAX] = { 0 };
			for (int j = 0; j < i; j++) {
				if (arr[j] == rand1) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				arr[i - 1] = rand1;
				break;
			}
			else {
				rand1 = rand();
			}
		}
		sprintf(bolpen[i].ID, "%d", rand1);  
		// 랜덤번호 부여하며 고유한 볼펜ID 생성
		// rand1값을 문자열로 변환하여 bolpen[i].ID에 저장
		bolpen[i].num = i; //  bolpen[i].num에 순차적으로 번호를 부여 -> 볼펜 생산 순서 표시

		if (rand1 % 10 == 0)  // 빨간색 볼펜
		{
			red_cnt++; // 수량 증가
			strcpy(bolpen[i].color, "RED"); // 색상 출력
		}

		if (rand1 % 10 == 1)  // 파란색 볼펜
		{
			blue_cnt++; // 수량 증가
			strcpy(bolpen[i].color, "BLUE"); // 색상 출력
		}

		if ((rand1 % 10 >= 2) && (rand1 % 10 <= 9))  // 검정색 볼펜
		{
			black_cnt++; // 수량 증가
			strcpy(bolpen[i].color, "BLACK"); // 색상 출력
		}
	}

	total_cnt = black_cnt + red_cnt + blue_cnt;  // 총 개수

	for (int i = 1; i <=MAX; i++)
	{  // 랜덤번호 부여하며 볼펜 생성
		fprintf(p,"생산순서 %05d번째 -> 볼펜ID: %s %s\n", bolpen[i].num, bolpen[i].ID, bolpen[i].color);
		fprintf(stdout, "생산순서 %05d번째 -> 볼펜ID: %s %s\n", bolpen[i].num, bolpen[i].ID, bolpen[i].color);
	}

	fprintf(stdout, "\n------------------------------------------------------");
	fprintf(p, "\n------------------------------------------------------");

	// 총 생산 볼펜 출력
	fprintf(stdout, "\n\n총생산볼펜 %d개: BLACK %d개, RED %d개, BLUE %d개\n", total_cnt, black_cnt, red_cnt, blue_cnt);  // 총 생산 볼펜 출력
	fprintf(p, "\n\n총생산볼펜 %d개: BLACK %d개, RED %d개, BLUE %d개\n", total_cnt, black_cnt, red_cnt, blue_cnt);

	stop = clock();   // 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC; // 측정시간 계산

	fprintf(stdout, "총 생산 시간: %.2lf초\n\n", duration);  // 시간 출력
	fprintf(p, "총 생산 시간: %.2lf초\n\n", duration);

	fclose(p);  // 파일 종료

	system("notepad.exe 04.txt");  // 파일 오픈

	return 0;
}