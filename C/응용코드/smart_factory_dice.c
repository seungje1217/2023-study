#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 5

typedef struct
{
    int pen_number;
    int pen_id;
    char color[20];
} PenRecord;

int black_cnt, red_cnt, blue_cnt, total_cnt;
typedef struct
{
    int dice1;
    int dice2;
} DICE;

int main()
{
    FILE* p1 = fopen("04.txt", "w");

    srand(time(NULL));

    PenRecord* records = malloc(MAX * sizeof(PenRecord));  // 동적 메모리 할당

    if (records == NULL)
    {
        printf("메모리 할당 오류\n");
        return 1;
    }

    int sameCount = 0;  // 같은 주사위 값이 나온 횟수를 저장하는 변수

    DICE dice;
    dice.dice1 = rand() % 6 + 1;
    dice.dice2 = rand() % 6 + 1;

    for (int i = 0; i < MAX; i++)
    {
        int rand1 = rand() % 10;
        records[i].pen_number = i + 1;  // 볼펜 순서 번호 저장
        records[i].pen_id = rand1;  // 볼펜 ID 저장

        if (rand1 % 10 == 0)
        {
            strcpy(records[i].color, "빨간색");
            red_cnt++;
        }
        else if (rand1 % 10 == 1)
        {
            strcpy(records[i].color, "파란색");
            blue_cnt++;
        }
        else
        {
            strcpy(records[i].color, "검정색");
            black_cnt++;
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        fprintf(p1, "볼펜 순서 번호: %02d, 볼펜 ID: %02d, 색상: %s dice1: %d dice2: %d\n",
            records[i].pen_number, records[i].pen_id, records[i].color, dice.dice1, dice.dice2);

        if (sameCount <= 2 && i < MAX - 1) // 더블 횟수가 2번 이하이고 마지막 볼펜이 아닐 때
        {
            int rand1 = rand() % 10;
            PenRecord extra_pen;
            extra_pen.pen_number = MAX + i + 1;
            extra_pen.pen_id = rand1;

            if (rand1 % 10 == 0)
            {
                strcpy(extra_pen.color, "빨간색");
                red_cnt++;
            }
            else if (rand1 % 10 == 1)
            {
                strcpy(extra_pen.color, "파란색");
                blue_cnt++;
            }
            else
            {
                strcpy(extra_pen.color, "검정색");
                black_cnt++;
            }
            fprintf(p1, "더블이 발생하여 추가 볼펜 생성\n볼펜 순서 번호: %02d, 볼펜 ID: %02d, 색상: %s dice1: %d dice2: %d\n",
                extra_pen.pen_number, extra_pen.pen_id, extra_pen.color, dice.dice1, dice.dice2);
        }
    }

    free(records);  // 동적 메모리 해제
    fclose(p1);
    system("notepad.exe 04.txt");    // 저장된 파일 오픈

    return 0;
}
