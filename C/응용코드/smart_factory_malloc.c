#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

typedef struct PenRecord {
    int pen_number;
    int pen_id;
    char color[20];
    struct PenRecord* next;
} PenRecord;
int black_cnt, red_cnt, blue_cnt, error_cnt, error_percent, total_cnt;
PenRecord* createNode(int pen_number, int pen_id, const char* color) {
    PenRecord* newNode = (PenRecord*)malloc(sizeof(PenRecord));
    if (newNode == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    newNode->pen_number = pen_number;
    newNode->pen_id = pen_id;
    strcpy(newNode->color, color);
    newNode->next = NULL;
    return newNode;
}

PenRecord* insertLast(PenRecord* head, PenRecord* newNode) {
    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else {
        PenRecord* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    return head;
}

void printList(PenRecord* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    PenRecord* current = head;
    do {
        printf("볼펜 순서 번호: %02d, 볼펜 ID: %02d, 색상: %s\n",
            current->pen_number, current->pen_id, current->color);
        current = current->next;
    } while (current != head);
}

void freeList(PenRecord* head) {
    if (head == NULL) {
        return;
    }
    PenRecord* current = head;
    while (current->next != head) {
        PenRecord* temp = current;
        current = current->next;
        free(temp);
    }
    free(current);
}

int main() {
    srand(time(NULL));

    PenRecord* head = NULL; // 원형 연결 리스트의 헤드 포인터

    for (int i = 0; i < MAX; i++) {
        int rand1 = rand();
        int pen_number = i + 1;
        int pen_id = rand1;
        char color[20];

        if (rand1 % 10 == 0) {
            strcpy(color, "빨간색");
            red_cnt++;
        }
        else if (rand1 % 10 == 1) {
            strcpy(color, "파란색");
            blue_cnt++;
        }
        else {
            strcpy(color, "검정색");
            black_cnt++;
        }

        PenRecord* newNode = createNode(pen_number, pen_id, color);
        head = insertLast(head, newNode);
    }

    printList(head);

    freeList(head);

    return 0;
}
