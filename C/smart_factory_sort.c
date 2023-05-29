#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
#define MAX_QUEUE_SIZE 100

void insertion_sort(int*, int);


struct pen {
    int num;     // 생산순서번호
    int ID;   // 볼펜ID
    char color[MAX];      // 색 
};

struct pen_ID {
    int black_ID[MAX];  // 검은색 볼펜ID
    int blue_ID[MAX];   // 파란색 볼펜ID
    int red_ID[MAX];   // 빨간색 볼펜ID
};
typedef int element;

typedef struct { // 큐 타입
    element  data[MAX_QUEUE_SIZE];
    element number[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
    fprintf(stdout, "QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            fprintf(stdout, "%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    fprintf(stdout, "\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

int main()
{
    FILE* p1;  // 읽기 용 파일포인터 생성 
    FILE* p2;  // 쓰기 용 파일포인터 생성 

    QueueType red_queue;  // 빨간 볼펜 큐
    QueueType blue_queue;  // 파란 볼펜 큐
    QueueType black_queue;  // 검정 볼펜 큐

    init_queue(&red_queue);  // 큐 초기화
    init_queue(&blue_queue);  // 큐 초기화
    init_queue(&black_queue);  // 큐 초기화

    struct pen bolpen[MAX];  // 구조체 배열

    int i = 0;  // 반복문에서 사용될 변수
   
    clock_t start, stop;
    double duration;

    start = clock();    // 측정 시작

    p1 = fopen("05.txt", "r");  // read모드 p1파일 오픈
    p2 = fopen("06.txt", "w");  //write모드 p2파일 오픈

    if (p1 == NULL || p2 == NULL) // 파일 오픈 에러시
    {
        printf("파일을 열지 못했습니다.");
        return -1;
    }

    while (fscanf(p1, "%05d %d %s\n", &bolpen[i].num, &bolpen[i].ID, bolpen[i].color) == 3)
    { //==3 비교는 fscanf가 입력 파일에서 3개의 값을 성공적으로 읽었는지 확인 -> 파일 끝까지 도달 시 종료
        if (strcmp(bolpen[i].color, "RED") == 0 && !is_full(&red_queue)) // 빨간색 볼펜
        { // bolpen[i].color 와 RED 비교 -> 같은 경우 0 -> if 조건문 참이된다
            enqueue(&red_queue, bolpen[i].ID); // red_queue에 볼펜ID 삽입
        }
        else if (strcmp(bolpen[i].color, "BLUE") == 0 && !is_full(&blue_queue)) // 파란색 볼펜
        {
            enqueue(&blue_queue, bolpen[i].ID); // blue_queue에 볼펜ID 삽입
        }
        else if (strcmp(bolpen[i].color, "BLACK") == 0 && !is_full(&black_queue)) // 검정색 볼펜
        {
            enqueue(&black_queue, bolpen[i].ID); // black_queue에 볼펜ID 삽입
        }
        i++;
    }

    fclose(p1);  // 파일 닫기

    insertion_sort(black_queue.data, black_queue.rear); // 삽입정렬 호출 -> 검정볼펜ID 정렬
    insertion_sort(blue_queue.data, blue_queue.rear); // 삽입정렬 호출 -> 파랑볼펜ID 정렬
    insertion_sort(red_queue.data, red_queue.rear); // 삽입정렬 호출 -> 빨간볼펜ID 정렬

    // 검정색 볼펜 출력
    for (i = black_queue.front + 1; i <= black_queue.rear; i++)
    {
        for (int j = 0; j < MAX; j++)
        { // 검정색 볼펜 정보 탐색
            if (bolpen[j].ID == black_queue.data[i] && strcmp(bolpen[j].color, "BLACK") == 0)
            {  // p1에서 가져온 bolpen 배열에서 ID가 큐의 data와 일치하며 볼펜색깔이 BLACK인 경우
                fprintf(p2, "%05d% 6d %s\n", bolpen[j].num, black_queue.data[i], "BLACK");
                break; // 탐색 완료 후 반복문 종료
            }
        }
    }

    // 파란색 볼펜 출력
    for (i = blue_queue.front + 1; i <= blue_queue.rear; i++)
    {
        for (int j = 0; j < MAX; j++)
        { // 파란색 볼펜 정보 탐색
            if (bolpen[j].ID == blue_queue.data[i] && strcmp(bolpen[j].color, "BLUE") == 0)
            { // p1에서 가져온 bolpen 배열에서 ID가 큐의 data와 일치하며 볼펜색깔이 BLUE인 경우
                fprintf(p2, "%05d% 6d %s\n", bolpen[j].num, blue_queue.data[i], "BLUE");
                break; // 탐색 완료 후 반복문 종료
            }
        }
    }

    // 빨간색 볼펜 출력
    for (i = red_queue.front + 1; i <= red_queue.rear; i++)
    {
        for (int j = 0; j < MAX; j++) { // 빨간색 볼펜 정보 탐색
            if (bolpen[j].ID == red_queue.data[i] && strcmp(bolpen[j].color, "RED") == 0)
            { // p1에서 가져온 bolpen 배열에서 ID가 큐의 data와 일치하며 볼펜색깔이 RED인 경우
                fprintf(p2, "%05d% 6d %s\n", bolpen[j].num, red_queue.data[i], "RED");
                break; // 탐색 완료 후 반복문 종료
            }
        }
    }

    stop = clock();   // 측정 종료

    duration = (double)(stop - start) / CLOCKS_PER_SEC;  // 측정시간 계산

    fprintf(p2, "\n수행시간: %.2lf초\n", duration); // 측정시간 출력

    fclose(p2);  // 파일 닫기

    //system("notepad.exe 05.txt");  // 저장된 파일 오픈
    system("notepad.exe 06.txt");  // 저장된 파일 오픈

    return 0;
}

void insertion_sort(int* list, int n) // 삽입정렬 함수
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
        list[j + 1] = key;
    }
}