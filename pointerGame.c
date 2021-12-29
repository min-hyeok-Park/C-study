#include <stdio.h>
#include <time.h>

//어항에 물을 줘서 물고기를 살리기

int level;
int arrayFish[6];
int *cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);

int main(void)
{
	long startTime = 0;		   // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0;  // 직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
	initData();

	cursor = arrayFish; // cursor[0] .. cursor[1] 같이 사용하기 위해

	startTime = clock();
	while (1)
	{
		printFishes();
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf_s("%d", &num);

		// 입력값 체크
		if (num < 1 || num > 6)
		{
			printf("입력값이 잘못되었습니다\n");
			continue;
		}
		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

		// 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		// 어항의 물을 감소 (증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1. 어항의 물이 0 이면? 물을 주지 않는다
		if (cursor[num - 1] <= 0)
		{
			printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다\n", num);
		}
		// 2. 어항의 물이 0 이 아닌 경우? 물을 준다 ! 100 을 넘지 않는지 체크
		else if (cursor[num - 1] + 1 <= 100)
		{
			// 물을 준다
			printf("%d 번 어항에 물을 줍니다\n\n", num);
			cursor[num - 1] += 1;
		}
		// 레벨업을 할 건지 확인 (레벨업은 20초마다 한번씩 수행)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf(" *** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level - 1, level);

			//최종 레벨 : 5
			if (level == 5)
			{
				printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다.\n\n");
				exit(0);
			}
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			printf("모든 물고기가.. 주금..\n");
			exit(0);
		}
		else
		{
			printf("물고기가 아직 살아 있어요!\n");
		}
		prevElapsedTime = totalElapsedTime;
	}
	return 0;
}

void initData()
{
	level = 1; // 게임 레벨 (1~5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100;
	}
}

void printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 : 난이도 조절을 위한 값
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			return 1;
		}
	}
	return 0;
}