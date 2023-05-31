#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

typedef char element[MAX];

typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

typedef struct CListType {
	ListNode *head;
} CListType;

// 리스트의 항목 출력
void print_list(CListType* L)
{
	ListNode* p;

	if (L->head == NULL) return;
	p = L->head->link;
	do {
		printf("%s->", p->data);
		p = p->link;
	} while (p != L->head);
	printf("%s->", p->data); // 마지막 노드 출력
}

void insert_first(CListType* L, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	strcpy(node->data, data);
	if (L->head == NULL) {
		L->head = node;
		node->link = L->head;
	}
	else {
		node->link = L->head->link;	// (1)
		L->head->link = node;		// (2)
	}
}
// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	CListType list = { NULL };

	srand(time(NULL));

	insert_first(&list, "KIM");
	insert_first(&list, "PARK");
	insert_first(&list, "CHOI");

	ListNode* p = list.head;

    FILE* p1 = fopen("02.txt", "w");

	int sameCount = 0;  // 같은 주사위 값이 나온 횟수를 저장하는 변수

    for (int i = 0; i < 10; i++)
    {
        int rand1, rand2;
 
        rand1 = rand() % 6 + 1;  // 1~6 까지의 난수 생성
        rand2 = rand() % 6 + 1;
     
        if (rand1 == rand2) // 주사위가 더블일 경우
        {
            fprintf(p1, "현재 차례=%s \n", p->data);
            fprintf(p1, "주사위 값:%d %d\n", rand1, rand2);
            sameCount++;
            if (sameCount <= 2) // 더블 횟수가 2번 이하일 때
            {
                rand1 = rand() % 6 + 1;  // 1~6 까지의 난수 생성
                rand2 = rand() % 6 + 1;

                fprintf(p1, "현재 차례=%s \n", p->data);
                fprintf(p1, "주사위 값:%d %d\n\n", rand1, rand2);
                p = p->link;
            }
            else // 더블이 2번 초과일 경우 그만 반복
            {
                sameCount = 0;  // 같은 값 횟수 초기화
                p = p->link;   // 다음 차례로 넘어감
            }
        }
        else // 주사위 값이 서로 틀릴 경우
        {
            fprintf(p1,"현재 차례=%s \n", p->data);
            fprintf(p1, "주사위 값:%d %d\n\n", rand1, rand2);
            
            p = p->link;
            sameCount = 0;  // 같은 값 횟수 초기화
        }
    }

    fclose(p1); // 파일 닫기
    system("notepad.exe 02.txt");    // 저장된 파일 오픈 

    return 0;
}
