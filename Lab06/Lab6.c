#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void printTasks()
{
	printf("1001) Квадратна матриця, симетрична щодо головної діагоналі, задана верхнім трикутником у вигляді одновимірного масиву. Відновити вихідну матрицю та надрукувати по рядках.\n");
	printf("1015) Визначити, чи є задана матриця ортонормованою, тобто чи скалярний добуток кожної пари різних рядків (стовпців) дорівнює нулю.\n");
	printf("924) Знайти максимальний елемент серед мінімальних елементів стовпців двовимірного масиву. Визначити номер рядка та стовпця для такого елемента.\n");
	printf("968) У двовимірному масиві зберігається інформація про оцінки кожного з 20 учнів класу з того чи іншого предмета (у першому рядку — інформація про оцінки першого учня, у другому — другого). Загальна кількість предметів дорівнює 10. Визначити середню оцінку п'ятого учня.\n");
	printf("919) У двовимірному масиві цілих чисел поміняти місцями рядки, симетричні щодо середини масиву (горизонтальної лінії).\n");
}

void task1()
{
	printf("\n1001(1)) ");
	int m[100][100];
	int n;

	printf("enter n: ");
	while (scanf("%d", &n) != 1 || n > 100 || n < 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}
	printf("enter nmbers: ");
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = n - i; j < n; j++)
		{
			while (scanf("%d", &m[n - (i + 1)][j]) != 1)
			{
				printf("Uncorrect input!\n");
				while (getchar() != '\n');
			}

			m[j][n - (i + 1)] = m[n - (i + 1)][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

void task2()
{
	printf("\n1015(2)) ");
	int a[100][100];
	int n, m;

	printf("enter n(r), m(c): ");
	while (scanf("%d %d", &n, &m) != 2 || n > 100 || n < 0 || m > 100 || m < 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	printf("enter nmbers: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (scanf("%d", &a[i][j]) != 1)
			{
				printf("Uncorrect input!\n");
				while (getchar() != '\n');
			}
		}
	}

	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			if (i1 == i2)
			{
				continue;
			}

			int sum = 0;

			for (int j = 0; j < m; j++)
			{
				sum += a[i1][j] * a[i2][j];
			}

			if (sum != 0)
			{
				printf("Answer: no.");
				return;
			}
		}
	}

	for (int i1 = 0; i1 < m; i1++)
	{
		for (int i2 = 0; i2 < m; i2++)
		{
			if (i1 == i2)
			{
				continue;
			}

			int sum = 0;

			for (int j = 0; j < n; j++)
			{
				sum += a[j][i1] * a[j][i2];
			}

			if (sum != 0)
			{
				printf("Answer: no.");
				return;
			}
		}
	}

	printf("Answer: yes.");
}

void task3()
{
	printf("\n924(3)) ");
	int a[100][100];
	int n, m;

	printf("enter n(r), m(c): ");
	while (scanf("%d %d", &n, &m) != 2 || n > 100 || n < 0 || m > 100 || m < 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	printf("enter nmbers: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (scanf("%d", &a[i][j]) != 1)
			{
				printf("Uncorrect input!\n");
				while (getchar() != '\n');
			}
		}
	}

	int x, y, max, min, x_t, y_t;

	max = a[0][0];
	y = 0;
	x = 0;

	for (int i = 0; i < m; i++)
	{
		if (a[i][0] < max)
		{
			max = a[i][0];
			y = i + 1;
			x = 1;
		}
	}

	min = max;
	x_t = x;
	y_t = y;

	for (int j = 0; j < m; j++)
	{
		min = a[0][j];

		for (int i = 0; i < n; i++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				x = j + 1;
				y = i + 1;
			}
		}

		if (min > max)
		{
			max = min;
			x_t = x;
			y_t = y;
		}
	}

	printf("Max: %d; r = %d; c = %d", max, y_t, x_t);
}

void task4()
{
	printf("\n968(4)) ");
	int a[20][10];

	printf("enter nmbers: ");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			while (scanf("%d", &a[i][j]) != 1)
			{
				printf("Uncorrect input!\n");
				while (getchar() != '\n');
			}
		}
	}

	double sum = 0;

	for (int j = 0; j < 10; j++)
	{
		sum += a[4][j];
	}

	printf("Answer: %g", sum / 10.0);
}

void task5()
{
	printf("\n919(5)) ");
	int a[100][100];
	int n, m;

	printf("enter n(r), m(c): ");
	while (scanf("%d %d", &n, &m) != 2 || n > 100 || n < 0 || m > 100 || m < 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	printf("enter nmbers: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (scanf("%d", &a[i][j]) != 1)
			{
				printf("Uncorrect input!\n");
				while (getchar() != '\n');
			}
		}
	}

	int tmp[100][100];

	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1, i1 = 0; i >= 0; i--, i1++)
		{
			tmp[i1][j] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", tmp[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	printTasks();

	task1();
	task2();
	task3();
	task4();
	task5();
}