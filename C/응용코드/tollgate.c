#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

void tollgate(int day, int start, int destination, int car); // 함수 선언

void main()
{
	while (1) // 무한 루프 문 사용  for (; ;) 도 사용가능
	{
		printf("경부고속도로에 오신것을 환영합니다.\n");

		int day;
		printf("오늘은 평일입니까? : \n");
		printf("평일 : 1  주말 : 2 \n>>");
		scanf("%d", &day);

		if (day < 1 || day>2)  // 잘못 입력 시
		{
			printf("잘못 입력되었습니다. 다시 입력해주세요.\n");
			continue;
		}

		int start;
		printf("당신의 출발지를 선택해주세요. \n");
		printf("------------------------------\n");
		printf("1. 서울\n2. 수원신갈\n3. 오산\n4. 천안\n5. 청주\n6. 대전\n7. 동대구\n8. 경주\n9. 부산\n>>");
		scanf("%d", &start);

		if (start < 1 || start>9)  // 잘못 입력 시
		{
			printf("잘못 입력되었습니다. 다시 입력해주세요.\n");
			continue;
		}
		int destination;
		printf("당신의 목적지를 선택해주세요. \n");
		printf("------------------------------\n");
		printf("1. 서울\n2. 수원신갈\n3. 오산\n4. 천안\n5. 청주\n6. 대전\n7. 동대구\n8. 경주\n9. 부산\n>>");
		scanf("%d", &destination);

		if (destination < 1 || destination>9)  // 잘못 입력 시
		{
			printf("잘못 입력되었습니다. 다시 입력해주세요.\n");
			continue;
		}

		if (start == destination) // 출발지가 도착지가 같을수는 없음
		{
			printf("잘못 입력되었습니다. 다시 입력해주세요.\n");
			continue;
		}

		int car;
		printf("당신의 차종은 무엇입니까? : \n");
		printf("------------------------------\n");
		printf("1. 1종 (소형차)\n2. 2종 (중형차)\n3. 3종 (대형차)\n4. 4종 (대형화물차)\n5. 5종 (특수화물차)\n");
		printf("1종 = km 당 44.3원 2종 = km 당 45.2원 3종 = km 당 47.0원 4종 = km 당 62.9원 5종 = km 당 74.4원\n>>");
		scanf("%d", &car);

		if (car < 1 || car>5) // 잘못 입력 시
		{
			printf("잘못 입력되었습니다. 다시 입력해주세요.\n");
			continue;
		}

		tollgate(day, start, destination, car);
		break;

	}
}	

void tollgate(int day, int start, int destination, int car)
{
	// 배열로 distance (거리) 선언
	float distance[9][9] = {
		{0, 17.2, 31.3, 69.4, 104.4, 137.6, 276.0, 327.2, 385.8}, // 서울
	   {17.2, 0, 14.1, 52.1, 87.2, 120.3, 263.4, 314.7, 373.3}, // 수원신갈
	   {31.3, 14.1, 0, 38.1, 73.1, 106.3, 249.4, 300.6, 359.2}, // 오산
	   {69.4, 52.1, 38.1, 0, 35.0, 68.2, 211.3, 262.6, 321.1}, // 천안
	   {104.4, 87.2, 73.1, 35.0, 0, 33.2, 176.3, 227.5, 286.1}, // 청주
	   {137.6, 120.3, 106.3, 68.2, 33.2, 0, 151.8, 203.1, 261.6}, // 대전
	   {276.0, 263.4, 249.4, 211.3, 176.3, 151.8, 0, 56.5, 124.0}, // 동대구
	   {327.2, 314.7, 300.6, 262.6, 227.5, 203.1, 56.5, 0, 67.6}, // 경주
	   {385.8, 373.3, 359.2, 321.1, 286.1, 261.6, 124.0, 67.6, 0} // 부산
	};

	int defaultmoney = 900;  // 기본값인 900원 변수 선언 후 저장
	float carmoney, finalmoney;  // carmoney = 차종별 요금,  finalmoney = 최종 요금

	switch (car)   // 차종에 따른 상이한 요금 계산
	{
	case 1:
		carmoney = 44.3;
		break;
	case 2:
		carmoney = 45.5;
		break;
	case 3:
		carmoney = 47.0;
		break;
	case 4:
		carmoney = 62.9;
		break;
	default:
		carmoney = 74.4;
		break;
	}
	
	finalmoney = defaultmoney + (distance[start-1][destination-1] * carmoney);
	// 통행요금 = 기본값 + 주행거리 + 차종 km당 요금

	if (day == 2 && car == 1) // 주말 1종 차량 50%할인
	{
		finalmoney = finalmoney * 0.5;
	}
		
	printf("\n출발지 : %d\n목적지 : %d\n통행요금은 %.0f원 입니다", start, destination, finalmoney);
}