#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_STACK_SIZE 100

typedef char element;      // 교체!
// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 

int check_matching(const char* in)  // 괄호검사 함수
{
    StackType s;  // 스택 초기화
    char ch, open_ch;
    int i, n = strlen(in);     // n= 문자열의 길이
    init_stack(&s);         // 스택의 초기화

    for (i = 0; i < n; i++) {
        ch = in[i];      // ch = 다음 문자
        switch (ch) {
        case '(':   case '[': case '<':   case '{':
            push(&s, ch);  
            break;
        case ')':   case ']':  case '>':  case '}':
            if (is_empty(&s))  return 0;
            else {
                open_ch = pop(&s);  
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '<' && ch != '>') ||
                    (open_ch == '{' && ch != '}')) {
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
    return 1;
}

int main(void)
{
    FILE* p1;  // 읽기 용 파일포인터 생성 
    FILE* p2;  // 쓰기 용 파일포인터 생성 

    p1 = fopen("07-1.txt", "r"); // read모드 파일 오픈
    p2 = fopen("07-2.txt", "w"); // write모드 파일 오픈

    if (p1 == NULL || p2 == NULL) // 파일 오픈 에러시
    {
        printf("파일을 열지 못했습니다.");
        return -1;
    }

    char line[MAX_STACK_SIZE]; // 문자열을 저장할 배열
    
    int OK_num = 0; // OK 개수 
    int ERROR_num = 0; // ERROR 개수
    
    while (fgets(line, MAX_STACK_SIZE, p1) != NULL) 
    { // p1 파일에서 최대 MAX_STACK_SIZE 길이의 문자열을 line 배열에서 읽어옴 -> 파일 끝까지
        if (check_matching(line)==1) // 괄호검사 성공 시
        {
            fprintf(p2, "OK\n");
            OK_num++;
        }
        else // 괄호검사 실패 시
        {
            fprintf(p2, "ERROR\n");
            ERROR_num++;
        }
  
    }

    double ERROR_RATE = (double)ERROR_num / (OK_num + ERROR_num) * 100; // ERROR 비율

    fprintf(p2, "\nTotal: OK %d, ERROR %d, ERROR-RATE %.1lf%%", OK_num, ERROR_num, ERROR_RATE); // OK, ERROR, ERROR-RATE 출력

    fclose(p1); // 파일 닫기 
    fclose(p2); // 파일 닫기

    //system("notepad.exe 07-1.txt");  // 저장된 파일 오픈
    system("notepad.exe 07-2.txt");  // 저장된 파일 오픈

    return 0;
}
