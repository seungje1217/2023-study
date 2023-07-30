// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // 수행시간 측정
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )  // 전처리를 통한 SWAP구현
#define GAP 3  // gap 값 지정

int list[MAX_SIZE];
int n;

void inc_insertion_sort(int*, int , int , int );
void shell_sort(int*, int);

int main(void)
{
	FILE* p1;  // 난수쓰기
	FILE* p2;  // 작성된 파일을 읽기+쓰기

	clock_t start, end;  // 시간 측정 함수

	int i;
	n = MAX_SIZE;
	srand(time(NULL));

	p1 = fopen("04.txt", "w");  // write 모드 p1파일 오픈  (전에 저장한것 삭제)

	start = clock(); // 시작 시간 계산

	fprintf(stdout, "정렬 전 : ");  // 정렬 전 난수 출력
	fprintf(p1, "정렬 전 : ");

	for (i = 0; i < n; i++)   // 난수 생성 및 출력
	{
		list[i] = rand() % 100; // 난수 발생 범위 0~99
		fprintf(stdout, "%d ", list[i]);
		fprintf(p1, "%d ", list[i]);
	}
	fprintf(stdout, "\n");
	fprintf(p1, "\n");

	fclose(p1);

	p2 = fopen("04.txt", "a+");  // a+ 모드로 p2 파일 오픈

	fprintf(stdout, "정렬 후 : ");
	fprintf(p2, "정렬 후 : ");

	shell_sort(list, n);  
	inc_insertion_sort(list, list[0], list[n-1], GAP);  // list, fist (리스트의 처음 인덱스)
	// list, first (리스트의 처음 인덱스), last (리스트의 마지막 인덱스), gap값 보냄

	for (i = 0; i < n; i++)
	{
		fprintf(stdout, "%d ", list[i]);
		fprintf(p2, "%d ", list[i]);
	}
	fprintf(stdout, "\n");
	fprintf(p2, "\n");

	end = clock(); // 종료 시간 계산

	fprintf(stdout, "소요 시간 : %.2lf초\n", (double)(end - start) / 1000.0); // 초 단위 계산
	fprintf(p2, "소요 시간 : %.2lf초\n", (double)(end - start) / 1000.0);

	fclose(p2);

	system("notepad.exe 04.txt");  // 04.txt 파일 오픈

	return 0;
}

void inc_insertion_sort(int*list, int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key<list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int*list, int n)   // n = size
{
	int i, gap;
	for (gap = n / 2; gap>0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i<gap; i++)		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
	}
}