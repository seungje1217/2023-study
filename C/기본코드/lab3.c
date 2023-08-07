#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef int element;

typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;



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
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* concat_list(ListNode *head1, ListNode *head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head2;
	else {
		ListNode *p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
// 테스트 프로그램
int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	int ary[MAX] = { 0 }; // 파일 저장 배열

	int i = 0; // 반복문에서 사용할 변수

	clock_t start, stop; // 시간 측정 함수
	double duration; // 측정시간 함수

	start = clock();    // 측정 시작

	FILE* p1 = fopen("lab3-1.txt", "r"); // 파일포인터 생성 후 read 모드로 파일 오픈
	FILE* p2 = fopen("lab3-2.txt", "r"); // 파일포인터 생성 후 read 모드로 파일 오픈

	if (p1 == NULL || p2 == NULL) // 파일 오픈 에러시
	{
		printf("파일을 열지 못했습니다.");
		return -1;
	}
	for (i = 0; i < MAX; i++) 
	{ // head1 
		if (fscanf(p1, "%d", &ary[i]) == EOF) // 파일의 끝까지 읽음
			break;
		head1 = insert_first(head1, ary[i]); // 배열 값을 리스트의 처음에 삽입
		print_list(head1); // 리스트 출력
	}
	printf("\n");
	for (i = 0; i < MAX; i++)
	{ // head2
		if (fscanf(p2, "%d", &ary[i]) == EOF) // 파일의 끝까지 읽음
			break;
		head2 = insert_first(head2, ary[i]); // 배열 값을 리스트의 처음에 삽입
		print_list(head2); // 리스트 출력
	}
	printf("\n");

	ListNode *total = concat_list(head1, head2); // 리스트 합치기
	print_list(total); // 리스트 출력

	stop = clock();   // 측정 종료

	duration = (double)(stop - start) / CLOCKS_PER_SEC;  // 측정시간 계산

	printf("\n수행시간: %.2lf초\n", duration); // 측정시간 출력

	fclose(p1); // 파일 닫기
	fclose(p2); // 파일 닫기

	//system("notepad.exe lab3-1.txt");  // 저장된 파일 오픈
	//system("notepad.exe lab3-2.txt");  // 저장된 파일 오픈

	return 0;
}
