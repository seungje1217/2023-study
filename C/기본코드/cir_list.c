#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;
typedef struct ListNode 
{ 	// 노드 타입
	char name[MAX]; // 이름
	double score; // 학점
	element num; // 학번
	struct ListNode *link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%s->%.1lf->%d->", p->name,p->score,p->num);
		p = p->link;
	} while (p != head);
	printf("%s->%.1lf->%d", p->name, p->score, p->num); // 마지막 노드 출력
}

ListNode* insert_first(ListNode* head, const char* name, double score, element num)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	strcpy(node->name, name);
	node->score = score;
	node->num = num;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* insert_last(ListNode* head, const char* name, double score, element num)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	strcpy(node->name, name);
	node->score = score;
	node->num = num;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}
ListNode* count_students(ListNode* head, double low_score)
{
	ListNode* p = head->link;
	int count = 0;

	do {
		if (p->score <= low_score) 
		{
			count++;
		}
		p = p->link;
	} while (p != head);

	return count;
}
// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode *head = NULL;

	head = insert_first(head, "lim", 4.5, 2022156033);
	head = insert_first(head, "jung", 2.5, 2022156036);
	head = insert_last(head, "song", 2.0, 2022158018);
	print_list(head);

	double low_score;
	printf("\n찾을 학점:");
	scanf("%lf", &low_score); 

	int count = count_students(head, low_score);
	printf("%.1lf 이하의 학생은 %d명입니다.\n", low_score, count);

	return 0;
 }