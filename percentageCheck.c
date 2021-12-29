#include <stdio.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int n = 10000;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (int i = 0; i < n; i++)
	{
		int random = rand() % 100;

		if (random < 24)
		{
			a++;
		}
		else if (random < 49)
		{
			b++;
		}
		else if (random < 69)
		{
			c++;
		}
		else if (random < 89)
		{
			d++;
		}
		else if (random < 99)
		{
			e++;
		}
	}

	printf("a : %d , 확률 = %.2f %%\n", a, ((double)a / n) * 100);
	printf("b : %d , 확률 = %.2f %%\n", b, ((double)b / n) * 100);
	printf("c : %d , 확률 = %.2f %%\n", c, ((double)c / n) * 100);
	printf("d : %d , 확률 = %.2f %%\n", d, ((double)d / n) * 100);
	printf("e : %d , 확률 = %.2f %%\n", e, ((double)e / n) * 100);

	return 0;
}