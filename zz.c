#include <stdio.h>

int main() {
	typedef int Pair[2];
	Pair point[2] = { {1, 2}, {3, 4} };
	printf("%d, %d\n", point[0][0], point[0][1]);
	printf("%d, %d", point[1][0], point[1][1]);
}