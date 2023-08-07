#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char element[MAX];
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

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
		if (p == current)
			printf("<-| #%s# |-> ", p->data);
		else
			printf("<-| %s |-> ", p->data);
	}
	printf("\n");
}
// 노드 newnode를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
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
// 파일에서 문자열을 읽어와 이중 연결 리스트에 삽입
void read_file(DListNode* head, const char* filename)
{
	FILE* p1 = fopen("04.txt", "r"); // 파일 포인터 생성 후 read모드로 파일 오픈
	if (p1 == NULL) // 파일 오픈 에러시
	{
		printf("파일을 열지 못했습니다.\n");
		return;
	}
	char line[MAX];
	while (fgets(line, sizeof(line), p1) != NULL)
	{
		// 개행 문자 제거
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		// 초기 데이터 삽입
		dinsert(head, line);
	}

	fclose(p1);
}
// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	char ch;
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	read_file(head, "04.txt"); // 파일에서 데이터 읽어오기
	current = head->rlink; // current 포인터를 헤드의 오른쪽 노드로 초기화
	print_dlist(head); // 초기 리스트 출력

	do {
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink; // current를 이전 노드로 이동
			if (current == head)
				current = current->llink; // 헤드를 지나치지 않도록 조정
		}
		else if (ch == '>') {
			current = current->rlink;  // current를 다음 노드로 이동
			if (current == head)
				current = current->rlink; // 헤드를 지나치지 않도록 조정
		}
		print_dlist(head); // 현재 리스트 출력
		getchar(); // 입력 버퍼 비우기
	} while (ch != 'q'); // q 입력 시 프로그램 종료

	// 동적 메모리 해제 코드
	DListNode* p = head->rlink;
	while (p != head) {
		DListNode* temp = p;
		p = p->rlink;
		free(temp); // 각 노드 동적 메모리 해제
	}
	free(head); // 헤드 노드 동적 메모리 해제
	system("notepad.exe 04.txt");  // 저장된 파일 오픈
	return 0;
}