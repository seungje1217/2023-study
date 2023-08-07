#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

struct pen {
    int num;            // 생산순서번호
    int ID[MAX];   // 볼펜ID
    char color[MAX];         // 색 
};

int main()
{
    FILE* p1;  // 읽기 용 파일포인터 생성 
    FILE* p2;  // 쓰기 용 파일포인터 생성 

    struct pen bolpen[MAX];  // 구조체 배열
    int i = 0;  // 반복문에서 사용될 변수, bolpen의 인덱스

    p1 = fopen("04.txt", "r");  // read모드 p1파일 오픈
    p2 = fopen("05.txt", "w");  // write모드 p2파일 오픈

    if (p1 == NULL || p2 == NULL) // 파일 오픈 에러시
    {
        printf("파일을 열지 못했습니다.");
        return -1;
    }

    while (i < MAX && fscanf(p1, "생산순서 %05d번째 -> 볼펜ID: %d %s\n", &bolpen[i].num, &bolpen[i].ID[i], &bolpen[i].color) == 3)
    { //==3 비교는 fscanf가 입력 파일에서 3개의 값을 성공적으로 읽었는지 확인 -> 파일 끝까지 도달 시 종료
        fprintf(p2, "%05d %d %s\n", bolpen[i].num, bolpen[i].ID[i], bolpen[i].color);
        // p2파일에 p1파일 내용을 출력
        i++;
    }
     
    fclose(p1);  // 파일 닫기
    fclose(p2);  // 파일 닫기

    system("notepad.exe 04.txt");  // 저장된 파일 오픈
    system("notepad.exe 05.txt");  // 저장된 파일 오픈

    return 0;
}
