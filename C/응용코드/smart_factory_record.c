#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
    int pen_number;
    int pen_id;
    char color[20];
    int dice1;
    int dice2;
} PenRecord;

void printPenRecord(PenRecord record)
{
    printf("볼펜 순서 번호: %02d, 볼펜 ID: %02d, 색상: %s dice1: %d dice2: %d\n",
        record.pen_number, record.pen_id, record.color, record.dice1, record.dice2);
}

int main()
{
    FILE* file = fopen("04.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    PenRecord record;
    printf("주사위 값의 합이 홀수이고 볼펜 ID가 홀수인  볼펜 레코드:\n");
    while (fscanf(file, "볼펜 순서 번호: %02d, 볼펜 ID: %02d, 색상: %s dice1: %d dice2: %d\n",
        &record.pen_number, &record.pen_id, record.color, &record.dice1, &record.dice2) == 5)
    {
        int diceSum = record.dice1 + record.dice2;
        if (diceSum % 2 != 0)
        {
            printPenRecord(record);
        }
    }

    fseek(file, 0, SEEK_SET); // Reset the file pointer to the beginning

    printf("\n주사위 값의 합이 짝수이고 볼펜 ID가 짝수인 볼펜 레코드:\n");
    while (fscanf(file, "볼펜 순서 번호: %02d, 볼펜 ID: %02d, 색상: %s dice1: %d dice2: %d\n",
        &record.pen_number, &record.pen_id, record.color, &record.dice1, &record.dice2) == 5)
    {
        int diceSum = record.dice1 + record.dice2;
        if (diceSum % 2 == 0 && record.pen_id % 2 == 0)
        {
            printPenRecord(record);
        }
    }

    fclose(file);
    return 0;
}
