// 볼펜 공장 연결리스트 ( 하나의 연결리스트에 모두 삽입)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int black_cnt, red_cnt, blue_cnt, error_cnt, error_percent, total_cnt;

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	if (pre == NULL) // pre에 널이 들어올때 -> 맨 처음에 삽입하는 경우
	{
		p->link = head;
		head = p;
	}
	else {
		p->link = pre->link;	//(3)	
		pre->link = p;		//(4)
	}
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	if (pre == NULL) // 첫 번째 노드 삭제
	{
		removed = head;
		head = head->link;
	}
	else  // 중간이나 마지막 노드 삭제
	{
		removed = pre->link;
		pre->link = removed->link;
	}
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}
int main()
{

	ListNode* head = NULL;

	int record; // 노드 변수

	srand(time(NULL));
	const int error_percent = MAX * 5 / 100; // 5%의 불량률

	for (int i = 0; i < MAX; i++)
	{

		int rand1 = rand();

		printf("%03d개 볼펜생산 -> 볼펜번호%d\n\n", i, rand1);

		if (rand1 % 10 == 0) // 빨간색 볼펜
		{
			red_cnt++;
			head = insert_first(head, rand1);

		}


		else if (rand1 % 10 == 1)  // 파란색 볼펜
		{
			blue_cnt++;
			head = insert_first(head, rand1);

		}


		else if ((rand1 % 10 >= 2) && (rand1 % 10 <= 9))  // 검정색 볼펜
		{
			black_cnt++;
			head = insert_first(head, rand1);

		}

	}
	total_cnt = black_cnt + red_cnt + blue_cnt; // 총 개수

	print_list(head);

	printf("\n\n총생산볼펜 %d=> 검%d, 빨%d, 파%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt);
	printf("불량률%d%%\n\n", error_percent);

	return 0;
}
// 1번 색 별 리스트를 따로 만들고 따로 출력하는 경우
//색별 리스트를 3개 만든후 insert를 통해서 각각의 색에 삽입을 해야함
// 후에 파일에 리스트 별로 출력을 함

// 2번 하나의 연결리스트에 볼펜을 삽입하고 한번에 출력하는 경우