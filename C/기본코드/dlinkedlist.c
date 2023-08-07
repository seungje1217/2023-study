#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10


typedef int element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	//strcpy(newnode->data, data);
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode)); // head 노드 동적메모리 할당
	init(head); // 초기화

	FILE* p = fopen("03.txt", "r"); // 파일 포인터 생성 후 read모드로 파일 오픈
	if (p == NULL) // 파일 오픈 에러시
	{
		printf("파일을 열지 못했습니다.");
		return -1;
	}
	int i = 0; // 반복문에서 사용될 변수
	int ary[MAX] = { 0 }; // fscanf로 받은 값을 저장할 배열

	printf("추가 단계\n");
	while (i < MAX && fscanf(p, "%d", &ary[i]) != EOF) // 파일 끝까지 읽으며 복사 -> 배열에 저장
	{
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, ary[i]);
		print_dlist(head);
		i++;
	}

	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) 
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head); // head노드 메모리 해제

	fclose(p);  // 파일 닫기
	system("notepad.exe 03.txt");  // 저장된 파일 오픈
	return 0;
}

//for (int i = 0; i < 5; i++) {
	//	// 헤드 노드의 오른쪽에 삽입
	//	dinsert(head, i);
	//	print_dlist(head);
	//}