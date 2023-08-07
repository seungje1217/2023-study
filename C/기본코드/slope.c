#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 5

FILE* p1;

typedef struct DListNode {
	int x;
	int y;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결리스트 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}
// 이중 연결리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		fprintf(stdout,"<-| |%d||%d| |-> ", p->x, p->y);
		fprintf(p1,"<-| |%d||%d| |-> ", p->x, p->y);
	}
	fprintf(stdout,"\n");
	fprintf(p1,"\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, int x, int y)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->x = x;
	newnode->y = y;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 두 노드 사이의 기울기를 계산
double calculate_slope(DListNode* node1, DListNode* node2)
{
	if (node1 == NULL || node2 == NULL)
		return 0.0;  // 노드가 NULL인 경우 0.0을 반환

	double slope = (double)(node2->y - node1->y) / (double)(node2->x - node1->x);
	return slope;  // 두 노드 사이의 기울기 반환
}

int main(void)
{
	p1 = fopen("13.txt", "w"); // 파일포인터 생성 후 write 모드로 오픈

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	for (int i = 0; i < MAX; i++)
	{   // 10이하의 난수로 설정
		int x = rand() % 11;
		int y = rand() % 11;
		dinsert(head, x, y);
		print_dlist(head);
	}

	DListNode* current = head->rlink;
	while (current != head && current->rlink != head)
	{
		double slope = calculate_slope(current, current->rlink);
		fprintf(stdout,"기울기 : %.2lf\n", slope);
		fprintf(p1,"기울기 : %.2lf\n", slope);
		current = current->rlink;
	}

	fclose(p1);
	system("notepad.exe 13.txt");    // 저장된 파일 오픈 

	return 0;
}
