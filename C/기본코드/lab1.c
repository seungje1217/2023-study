#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10 

typedef struct {
	char name[100];
} element;

typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

// 테스트 프로그램
int main(void)
{
	ListNode *head = NULL; // head 포인터 변수 NULL로 초기화

	element ary[MAX]; // fsanf 값을 저장할 문자열 배열

	int i = 0; // 반복문에서 사용할 변수

	clock_t start, stop; // 시간 측정 함수
	double duration; // 측정시간 함수

	start = clock();    // 측정 시작

	FILE* p = fopen("lab1.txt", "r"); // 파일포인터 생성 후 read 모드로 파일 오픈

	if (p == NULL)  // 파일 오픈 에러시
	{
		printf("파일을 열지 못했습니다.");
		return -1;
	}

	while (i < MAX && fscanf(p, "%s", ary[i].name) != EOF) 
	{ // 파일의 끝까지 fscanf로 복사 
		head = insert_first(head, ary[i]); // ary[i] 값을 첫 번째 노드에 추가
		print_list(head); // 리스트 출력
		i++;
	}

	stop = clock();   // 측정 종료
	
	duration = (double)(stop - start) / CLOCKS_PER_SEC;  // 측정시간 계산

	printf("\n수행시간: %.2lf초\n", duration); // 측정시간 출력

	fclose(p); // 파일 닫기

	system("notepad.exe lab1.txt");  // 저장된 파일 오픈

	return 0;
}

//strcpy(data.name, "APPLE"); // data,name 변수에 APPLE 문자열 복사 
	//head = insert_first(head, data);
	//print_list(head);

	//strcpy(data.name, "KIWI"); // data,name 변수에 KIWI 문자열 복사 
	//head = insert_first(head, data);
	//print_list(head);

	//strcpy(data.name, "BANANA");  // data,name 변수에 BANANA 문자열 복사 
	//head = insert_first(head, data);
	//print_list(head);