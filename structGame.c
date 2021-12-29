#include <stdio.h>
#include <time.h>

// 5마리의 고영이 랜덤으로 뽑되, 중복발생 가능. 다 뽑으면 종료

typedef struct
{
	char *name;		 // 이름
	int age;		 // 나이
	char *character; // 성격
	int level;		 // 키우기 난이도 (1-5, 5가 어려움)
} CAT;

// 현재까지 보유한 고양이
int collection[5] = {0, 0, 0, 0, 0};

// 전체 고양이 리스트
CAT cats[5];

void initCats();
void printCat(int selected);
int checkCollection();

int main(void)
{
	srand(time(NULL));

	initCats();
	while (1)
	{
		printf("두근두근~! 어느 고양이의 집사가 될까요?\n아무키나 눌러서 확인하세요!");
		getchar();

		int random = rand() % 100; // 0-4 사이의 숫자 반환
		int selected = 0;
		// 1번, 2번 => 25 %
		// 3번, 4번 => 20 %
		// 5번 => 10 %
		if (random < 24)
		{
			selected = 0;
		}
		else if (random < 49)
		{
			selected = 1;
		}
		else if (random < 69)
		{
			selected = 2;
		}
		else if (random < 89)
		{
			selected = 3;
		}
		else if (random < 99)
		{
			selected = 4;
		}
		printCat(selected);		  // 뽑은 고양이 정보 출력
		collection[selected] = 1; // 고양이 뽑기 처리

		int collecAll = checkCollection();
		if (collecAll == 1)
		{
			break;
		}
	}

	return 0;
}

void initCats()
{
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순함";
	cats[0].level = 1;

	cats[1].name = "귀요미";
	cats[1].age = 2;
	cats[1].character = "애교쟁이";
	cats[1].level = 2;

	cats[2].name = "돼냥이";
	cats[2].age = 6;
	cats[2].character = "많이 먹음";
	cats[2].level = 3;

	cats[3].name = "수줍이";
	cats[3].age = 4;
	cats[3].character = "낯가림";
	cats[3].level = 4;

	cats[4].name = "도도냥";
	cats[4].age = 7;
	cats[4].character = "까칠함";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("\n\n=== 당신은 이 고야이의 집사가 되었어요! ===\n\n");
	printf(" 이름		: %s\n", cats[selected].name);
	printf(" 나이		: %d\n", cats[selected].age);
	printf(" 특징(성격)  : %s\n", cats[selected].character);
	printf(" 레벨		: ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "★");
	}
	printf("\n\n");
}

int checkCollection()
{
	//현재 보유한 고양이 목록도 출력, 다 모았는지 여부 반환
	int collecAll = 1;

	printf("\n\n === 보유한 고양이 목록 === \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0)
		{ // 고양이 수집 X
			printf("%10s", "(빈 박스)");
			collecAll = 0; // 다 모으지 못한 상태
		}
		else
		{ // 고양이 수집 O
			printf("%10s", cats[i].name);
		}
	}
	printf("\n====================================================\n\n");

	if (collecAll)
	{
		printf("\n\n 축축 다 모았넹 \n\n");
	}

	return collecAll;
}