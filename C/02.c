// 함수 응용
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 10

typedef struct studentTag {
	char name[MAX_ELEMENTS];  // 이름
	double score; // 학점
	int student_id;  // 학번 
}student;

double score[MAX_ELEMENTS];

double get_max_score(student students[], int n);

int main(void)
{
	FILE* p;  // 파일 포인터 생성
	p = fopen("02.txt", "a+");  // a+ 모드로 파일 오픈

	int result;
	
	srand(time(NULL));   // srand로 시드값 초기화

	student students[MAX_ELEMENTS] = {
	   { "kim",  rand() % 501 / 100.0, 2022156001 },  // rand()%501/100.0 -> 0부터 5까지의 실수값 난수
	   { "Park", rand() % 501 / 100.0, 2022156002 },
	   { "Lim",  rand() % 501 / 100.0, 2022156003 },
	   { "Lee",  rand() % 501 / 100.0, 2022156004 },
	   { "ki",   rand() % 501 / 100.0, 2022156005 },
	   { "Song", rand() % 501 / 100.0, 2022156006 },
	   { "Min",  rand() % 501 / 100.0, 2022156007 },
	   { "kang", rand() % 501 / 100.0, 2022156008 },
	   { "Do",   rand() % 501 / 100.0, 2022156009 },
	   { "Heon", rand() % 501 / 100.0, 2022156010 }
	};

	for (int i = 0; i < MAX_ELEMENTS; i++) {
		score[i] = students[i].score;
	}

	result = get_max_score(students, MAX_ELEMENTS);  // 함수 호출 (최대 학점 result에 할당)
	
	fprintf(p, "[1등]\n%s %d %.2lf\n\n",
		students[result].name, students[result].student_id, students[result].score);
	// 파일을 통하여 출력

	fclose(p);  //파일 닫기

	system("notepad.exe 02.txt");    // 저장된 파일 오픈

	return 0;
}

double get_max_score(student students[], int n)
{
	int i, result = 0;

	for (i = 1; i < n; i++)  // 최대 학점 찾기
	{
		if (students[i].score > students[result].score)
		{
			result = i;
		}
	}
	return result;
}
