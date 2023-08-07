#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shuffleTeam();
void fightTeam();
void finalRank();

char originTeams[8][60] = { "삼성 라이온스", "NC 다이노스", "두산 베어스", "한화 이글스", "롯데 자이언츠", "LG 트윈스", "키움 히어로즈", "기아 타이거즈" };
char shuffledTeams[8][60]; /* 섞이게 된 야구팀을 정렬하는 배열 */

int shuffled[8] = { -1, };
int playResult[7][4]; /* 승패 결과를 저장하는 2차원 배열 */

int winnerTeam4[4];
int winnerTeam2[2];
int finalWinner;
int secondWinner;
int thirdWinner[2];

int teams = 8;
int seed = 0;

int main() {
    printf("seed 값 입력 : "); 
    scanf("%d", &seed);
    srand(seed);
    shuffleTeam();

    fightTeam();
    finalRank();
    printf("0을 입력하여 종료 : ");
    int a; scanf("%d", &a);
}

// 랜덤한 수를 이용하여 팀을 섞는 함수 
void shuffleTeam() {

    int same, cnt = 0, r = 0;
    while (cnt < 8) {
        same = 0;
        r = rand() % 8;
        for (int i = 0; i < cnt; i++) {
            if (r == shuffled[i]) {
                same = 1;
                break;
            }
        }
        if (same == 0) {
            shuffled[cnt] = r;
            cnt++;
        }
    }
    // shuffled 정수형 배열 내에 랜덤한 수(0~7)을 집어넣음. 만일 랜덤하게 뽑힌 수가 이미 배열 내에 있다면 배열에 넣지 않고 랜덤한 수를 다시 돌림. 

    for (int j = 0; j < 8; j++) {
        strcpy(shuffledTeams[shuffled[j]], originTeams[j]);
    }
    // shuffled 배열 내에는 랜덤한 0~7까지의 수가 있음. 예 ) 0, 2, 3, 5, 1..
   // originTeams 배열(팀 이름이 들어가 있는 배열)의 첫 번째 팀 이름부터 shuffledTeams 배열의 랜덤한 위치(0~7)에 집어넣음. 
    printf("\n팀 섞기 완료.");
    for (int p = 0; p < 8; p++) {
        printf("\n%d. %s", p, shuffledTeams[p]);
    }
    // 섞인 팀을 한 번 출력해줌. 
}


// 8강, 4강, 결승전을 치르면서 각각의 점수와 팀을 기록함. 
void fightTeam() {
    printf("\n\n8강전을 시작합니다.\n");
    int a, b, i = 0;
    int team = 0;
    while (i < 4) {
        a = rand() % 16;
        b = rand() % 16;
        // 각각의 점수를 0~16점까지 랜덤하게 뽑아냄. 

        printf("\n* %s vs %s *\n", shuffledTeams[team], shuffledTeams[team + 1]);
        // shuffledTeams(랜덤하게 섞인 팀)의 n번째와 n+1번째의 경기를 시작함. 
        printf("\t|| %d vs %d ||\n\n", a, b);
        if (a > b) { // n번째 팀이 승리한 경우 
            printf("\t%s 승리\n", shuffledTeams[team]);
            winnerTeam4[i] = team;
        }
        else if (b > a) { // n+1번째 팀이 승리한 경우 
            printf("\t%s 승리\n", shuffledTeams[team + 1]);
            winnerTeam4[i] = team + 1;

        }
        else {
            printf("동점이므로 재경기를 진행\n");
            continue;
        }

        playResult[i][0] = a;
        playResult[i][1] = b;
        playResult[i][2] = team;
        playResult[i][3] = team + 1;
        /*
      oooo
      oooo
      oooo
      oooo
      oooo
      oooo
      oooo

      형식으로 playResult 2차원 배열이 되어있음.
      oooo - 각각 n번째 팀의 점수, n+1번째 팀의 점수, n번째 팀의 shuffledTeam 배열 내의 위치, n+1번째 팀의..(중략)가 정수형으로 저장됨.
      그리고 첫번째 줄부터 각각 8강 1, 2, 3, 4차전, 4강 1, 2차전, 결승전의 결과가 위와 같은 방식으로 저장됨.
      */
        team += 2; // n, n+1번째 팀이 경기를 마쳤으므로, 이제 n+2번째 팀과 n+3, 즉 (n+2)+1번쨰 팀이 경기를 해야 하므로 2를 추가함. 
        i++; // i도 1 더해줌. 
    }

    printf("\n8강 승리팀 : \n");
    for (int j = 0; j < 4; j++) {
        printf("\n || %s || ", shuffledTeams[winnerTeam4[j]]);
    }

    printf("\n\n4강전을 시작합니다.");
    team = 0;
    // 이 시점에서 i = 4
    while (i < 6) {
        a = rand() % 16;
        b = rand() % 16;

        printf("\n* %s vs %s *\n", shuffledTeams[winnerTeam4[team]], shuffledTeams[winnerTeam4[team + 1]]);
        printf("\t|| %d vs %d ||\n\n", a, b);
        if (a > b) {
            printf("\t%s 승리\n", shuffledTeams[winnerTeam4[team]]);
            winnerTeam2[i - 4] = winnerTeam4[team];
        }
        else if (b > a) {
            printf("\t%s 승리\n", shuffledTeams[winnerTeam4[team + 1]]);
            winnerTeam2[i - 4] = winnerTeam4[team + 1];

        }
        else {
            printf("동점이므로 재경기를 진행\n");
            continue;
        }

        playResult[i][0] = a;
        playResult[i][1] = b;
        playResult[i][2] = winnerTeam4[team];
        playResult[i][3] = winnerTeam4[team + 1];
        team += 2;
        i++;
    }

    printf("\n4강(준결승) 승리팀 : \n");
    printf("|| %s vs %s ||", shuffledTeams[winnerTeam2[0]], shuffledTeams[winnerTeam2[1]]);

    printf("\n\n결승전을 시작합니다.");
    while (1) {
        a = rand() % 16;
        b = rand() % 16;

        printf("\n* %s vs %s *\n", shuffledTeams[winnerTeam2[0]], shuffledTeams[winnerTeam2[1]]);
        printf("\t|| %d vs %d ||\n", a, b);

        if (a > b) {
            printf("  %s 승리\n", shuffledTeams[winnerTeam2[0]]);
            finalWinner = winnerTeam2[0];
            secondWinner = winnerTeam2[1];
            break;
        }
        else if (b > a) {
            printf("  %s 승리\n", shuffledTeams[winnerTeam2[1]]);
            finalWinner = winnerTeam2[1];
            secondWinner = winnerTeam2[0];
            break;
        }
        else {
            printf("동점이므로 재경기를 진행\n");
            continue;
        }
    }

    int pos = 0;
    for (int t = 0; t < 4; t++) {
        if ((winnerTeam4[t] != finalWinner) && (winnerTeam4[t] != secondWinner)) {
            thirdWinner[pos] = winnerTeam4[t];
            pos++;
        }
    }

    playResult[6][0] = a;
    playResult[6][1] = b;
    playResult[6][2] = winnerTeam2[0];
    playResult[6][3] = winnerTeam2[1];

}

// 종합 순위를 출력하고 각각의 1위, 2위, 공동 3위 팀의 전적을 출력함. 
void finalRank() {
    // 1등 팀 - 1, 2, 3차전 모두 승리
    int num = 1;
    printf("\n최종 결과\n");
    printf("(1위) : %s 팀\n", shuffledTeams[finalWinner]);
    for (int y = 0; y < 7; y++) {
        if (finalWinner == playResult[y][2]) {
            printf("<%d차전> - 승리", num);
            printf("\n* %d vs %d *", playResult[y][0], playResult[y][1]);
            printf("\n상대 : %s\n\n", shuffledTeams[playResult[y][3]]);
            num++;
        }
        if (finalWinner == playResult[y][3]) {
            printf("<%d차전> - 승리", num);
            printf("\n* %d vs %d *", playResult[y][0], playResult[y][1]);
            printf("\n상대 : %s\n\n", shuffledTeams[playResult[y][2]]);
            num++;
        }
    }


    // 2등 팀 - 1, 2차전 승리, 3차전 패배
    num = 1;
    printf("\n\n(2위) : %s팀\n", shuffledTeams[secondWinner]);
    for (int y = 0; y < 6; y++) {
        if (secondWinner == playResult[y][2]) {
            printf("<%d차전> - 승리", num);
            printf("\n* %d vs %d *", playResult[y][0], playResult[y][1]);
            printf("\n상대 : %s\n\n", shuffledTeams[playResult[y][3]]);
            num++;
        }
        if (secondWinner == playResult[y][3]) {
            printf("<%d차전> - 승리", num);
            printf("\n* %d vs %d *", playResult[y][0], playResult[y][1]);
            printf("\n상대 : %s\n\n", shuffledTeams[playResult[y][2]]);
            num++;
        }

    }
    printf("<3차전> - 패배");
    printf("\n* %d vs %d *", playResult[7][0], playResult[7][1]);
    printf("\n상대 : %s\n\n", shuffledTeams[finalWinner]);


    // 3등 팀 - 1차전 승리, 2차전 패배
    for (int i = 0; i < 2; i++) {
        num = 1;
        printf("\n\n(공동 3위) : %s팀\n", shuffledTeams[thirdWinner[i]]);
        for (int y = 0; y < 4; y++) {
            if (thirdWinner[i] == playResult[y][2]) {
                printf("<%d차전> - 승리", num);
                printf("\n* %d vs %d *", playResult[y][0], playResult[y][1]);
                printf("\n상대 : %s\n\n", shuffledTeams[playResult[y][3]]);
                num++;
            }
            if (thirdWinner[i] == playResult[y][3]) {
                printf("<%d차전> - 승리", num);
                printf("\n* %d vs %d *", playResult[y][0], playResult[y][1]);
                printf("\n상대 : %s\n\n", shuffledTeams[playResult[y][2]]);
                num++;
            }
        }

        printf("<2차전> - 패배");
        for (int x = 2; x <= 3; x++) {
            if (thirdWinner[i] == playResult[4][x]) {
                printf("\n* %d vs %d *", playResult[4][0], playResult[4][1]);
                if (x == 2) {
                    printf("\n상대 : %s\n\n", shuffledTeams[playResult[4][3]]);
                }
                if (x == 3) {
                    printf("\n상대 : %s\n\n", shuffledTeams[playResult[4][2]]);
                }

            }
            if (thirdWinner[i] == playResult[5][x]) {
                printf("\n* %d vs %d *", playResult[5][0], playResult[5][1]);
                if (x == 2) {
                    printf("\n상대 : %s\n\n", shuffledTeams[playResult[5][3]]);
                }
                if (x == 3) {
                    printf("\n상대 : %s\n\n", shuffledTeams[playResult[5][2]]);
                }

            }
        }
    }
}
