/*
100개 이하의 정수를 입력받아
첫 줄에 짝수 번째 숫자들을 순서대로 출력하고,
다음 줄에 홀수 번째 숫자들을 순서대로 출력하는 프로그램 만들기.
*/
/*
10 * 10 이하의 정수형 이차원 배열을 입력받아
그 배열의 각 행의 요소의 합을 출력하는 프로그램을 만들기.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//===========1번 문제
	/*
	int n; //정수의 개수 입력받기
	int arr[105]; //넉넉하게
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n; i += 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i += 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/

	//===========2번 문제

	int arr[12][12]; // 넉넉하게
	int n, m;		 //행, 열

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += arr[i][j];
		}
		printf("%d\n", sum);
	}
}