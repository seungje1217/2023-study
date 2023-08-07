#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

typedef struct hanoi {
	int num_disks;        // 원판 개수
	int num_moves;        // 총 연산 횟수
	double duration;  // 수행 시간
} hanoi;

void hanoi_tower(int, char, char, char);

int num_moves = 0;   // 총연산 횟수

FILE* p;    // 파일 포인터 전역변수 선언

int main(void)
{

	p = fopen("03.txt", "a+");   // 덮어쓰기 모드로 파일 오픈
	clock_t start, stop;
	double duration;

	srand(time(NULL));   // srand로 시드값 초기화
	int num_disks = rand() % MAX;  // 원판 개수: 15 이하의 난수 생성
	 
	start = clock();    // 측정 시작

	hanoi_tower(num_disks, 'A', 'B', 'C'); // 함수 호출

	stop = clock();   // 측정 종료

	duration = (double)(stop - start) / CLOCKS_PER_SEC;  // 측정시간 계산

	hanoi hanoi_tower = { num_disks, num_moves, duration };  // 구조체 변수 초기화

	fprintf(p, "\n원판의 개수 %d개, 총연산 %02d회, 수행시간: %.2lf초\n\n", hanoi_tower.num_disks, hanoi_tower.num_moves, hanoi_tower.duration);
	fprintf(stdout, "\n원판의 개수 %d개, 총연산 %02d회, 수행시간: %.2lf초\n\n", hanoi_tower.num_disks, hanoi_tower.num_moves, hanoi_tower.duration);
	
	fclose(p);  // 파일 닫기
	system("notepad.exe 03.txt");  // 저장된 파일 오픈

	return 0;
}

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
	{
		num_moves++;
		fprintf(stdout, "%02d 원판 1을 %c 에서 %c으로 옮긴다.\n", num_moves, from, to);
		fprintf(p, "%02d 원판 1을 %c 에서 %c으로 옮긴다.\n", num_moves, from, to);    // 파일 저장
	}
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		num_moves++;
		fprintf(stdout, "%02d 원판 %d을 %c에서 %c으로 옮긴다.\n", num_moves, n, from, to);
		fprintf(p, "%02d 원판 %d을 %c에서 %c으로 옮긴다.\n", num_moves, n, from, to);   // 파일 저장
		hanoi_tower(n - 1, tmp, from, to);
	}
}