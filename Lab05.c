#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void printTasks()
{
	printf("116) На k-e місце одновимірного масиву цілих чисел вставити елемент, що дорівнює різниці двох введених з клавіатури елементів.\n");
	printf("123) Дано послідовність цілих позитивних чисел. Знайти твір тільки тих з них, які більші за задану кількість М. Якщо таких чисел немає, видати повідомлення про це.\n");
	printf("142) Дано послідовність дійсних чисел a1, a2, ..., aп. Потрібно помножити всі члени послідовності a1, a2, ..., aп на квадрат її найменшого члена, якщо ak ≥ 0, і на квадрат її найбільшого члена, якщо ak < 0 (1 ≤ k ≤ п).\n");
	printf("179) Задано масив дійсних чисел та натуральні числа R і H < R. Створити та заповнити масив номерів таких чисел вихідного масиву, які відрізняються від R не більше ніж на H.\n");
	printf("30) Дано послідовність натуральних чисел a1, a2, ..., aп. Створити масив із парних чисел цієї послідовності. Якщо таких чисел немає, вивести повідомлення про цей факт.\n");
	printf("121) Дано одновимірний масив А[Н]. Знайти mах(a2, a4, ..., a2k) + min(a1, a3, ..., a2k+1).\n\n");
}

void task1()
{
	printf("116(1) ");

	printf("Enter array size: ");

	int n;
	while (scanf("%d", &n) != 1 || n < 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	int arr[n];
	printf("\nEnter array: ");

	for (int i = 0; i < n; i++)
	{
		while (scanf("%d", &arr[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}
	}

	int k, k1, k2;
	printf("\nEnter k, k1, k2: ");

	while (scanf("%d %d %d", &k, &k1, &k2) != 3 || k < 1 || k > n)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	arr[k - 1] = k1 - k2;
	printf("Answer: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void task2()
{
	printf("\n123(2)) ");

	printf("Enter array size: ");

	int n;
	while (scanf("%d", &n) != 1 || n < 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	int arr[n];
	printf("\nEnter array: ");

	for (int i = 0; i < n; i++)
	{
		while (scanf("%d", &arr[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}
	}

	printf("Enter M: ");
	double M;

	while (scanf("%lf", &M) != 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	int res = 1;
	bool has_number = false;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > M)
		{
			has_number = true;
			res *= arr[i];
		}
	}

	if (!has_number)
	{
		printf("No numbers bigger than M.\n");
	}
	else
	{
		printf("Answer: %d", res);
	}
}

void task3()
{
	printf("\n142(3)) ");

	printf("Enter array size: ");

	int n;
	while (scanf("%d", &n) != 1 || n < 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	double arr[n];
	double min_a, max_a;
	printf("\nEnter array: ");

	for (int i = 0; i < n; i++)
	{
		while (scanf("%lf", &arr[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}

		if (i == 0)
		{
			min_a = arr[0];
			max_a = arr[0];
		}
		else
		{
			if (arr[i] > max_a)
			{
				max_a = arr[i];
			}
			if (arr[i] < min_a)
			{
				min_a = arr[i];
			}
		}
	}

	int k;
	printf("\nEnter k: ");

	while (scanf("%d", &k) != 1 || k < 1 || k > n)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if (arr[k - 1] >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] *= min_a * min_a;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] *= max_a * max_a;
		}
	}

	printf("Answer: ");
	for (int i = 0; i < n; i++)
	{
		printf("%g ", arr[i]);
	}
}

void task4()
{
	printf("\n179(4)) ");

	printf("Enter array size: ");

	int n;
	while (scanf("%d", &n) != 1 || n < 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	double arr[n];
	printf("\nEnter array: ");

	for (int i = 0; i < n; i++)
	{
		while (scanf("%lf", &arr[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}
	}

	int R, H;
	printf("\nEnter R, H: ");

	while (scanf("%d %d", &R, &H) != 2 || H >= R)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	printf("Answer: ");

	for (int i = 0; i < n; i++)
	{
		if (fabs(arr[i] - R) <= H)
		{
			printf("%d ", i + 1);
		}
	}
}

void task5()
{
	printf("\n30(5)) ");

	printf("Enter array size: ");

	int n;
	while (scanf("%d", &n) != 1 || n < 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	int arr[n];
	printf("\nEnter array: ");

	for (int i = 0; i < n; i++)
	{
		while (scanf("%d", &arr[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}
	}

	printf("Answer: ");

	for (int i = 0; i < n; i++)
	{
		if (fmod(arr[i], 2) == 0)
		{
			printf("%d ", arr[i]);
		}
	}
}

void task6()
{
	printf("\n121(6)) ");

	printf("Enter array size: ");

	int n;
	while (scanf("%d", &n) != 1 || n < 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	double arr[n];
	double min_a, max_a;
	printf("\nEnter array: ");

	for (int i = 0; i < n; i++)
	{
		while (scanf("%lf", &arr[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}

		if ((i + 1) % 2 == 0)
		{
			if (i == 0)
			{
				max_a = arr[i];
			}
			else if (arr[i] > max_a)
			{
				max_a = arr[i];
			}
		}
		else
		{
			if ((i + 1) == 1)
			{
				min_a = arr[i];
			}
			else if (arr[i] < min_a)
			{
				min_a = arr[i];
			}
		}
	}

	printf("Answer: %g", min_a + max_a);
}

int main()
{
	setlocale(LC_ALL, "");

	printTasks();

	task1();
	task2();
	task3();
	task4();
	task5();
	task6();

	return 0;
}