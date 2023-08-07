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
ListNode* reverse(ListNode *head)
{
	// 순회 포인터로 p, q, r을 사용
	ListNode *p, *q, *r;

	p = head;         // p는 역순으로 만들 리스트
	q = NULL;        // q는 역순으로 만들 노드
	while (p != NULL) {
		r = q;          // r은 역순으로 된 리스트.    
						// r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r;      // q의 링크 방향을 바꾼다.
		//print_list(q);
	}
	return q;
}
// 테스트 프로그램
int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	int ary[MAX] = { 0 };

	int i = 0; // 반복문에서 사용할 변수

	clock_t start, stop; // 시간 측정 함수
	double duration; // 측정시간 함수

	start = clock();    // 측정 시작

	FILE* p = fopen("lab4.txt", "r"); // 파일포인터 생성 후 read 모드로 파일 오픈

	if (p == NULL)  // 파일 오픈 에러시
	{
		printf("파일을 열지 못했습니다.");
		return -1;
	}
	for (i = 0; i < MAX; i++)
	{
		if (fscanf(p, "%d", &ary[i]) == EOF) // 파일의 끝까지 읽음
			break;
		head1 = insert_first(head1, ary[i]); // 배열 값을 리스트의 처음에 삽입
		print_list(head1); // 리스트 출력
	}
	printf("reverse:\n");
	head2 = reverse(head1);
	print_list(head2);

	stop = clock();   // 측정 종료

	duration = (double)(stop - start) / CLOCKS_PER_SEC;  // 측정시간 계산

	printf("\n수행시간: %.2lf초\n", duration); // 측정시간 출력

	fclose(p);

	system("notepad.exe lab4.txt");  // 저장된 파일 오픈

	return 0;
}
