#include <stdio.h>
#include <math.h>

void printTasks()
{
	printf("\n40) (a*d + b*c) / (a*d)\n");
	printf("43) (sqrt(x+1) + sqrt(x-1)) / 2√x\n");
	printf("46) (b * a^(1/b)) / a\n");
	printf("49) tg a * (cos 2x / a)\n");
	printf("52) sqrt(x^2 - 4x) / (x^2 - 9)\n\n");
}

double a, b, c, d, x;

void task1()
{
	
	printf("Task 40: ");
	if (a == 0)
	{
		printf("Error! Variable 'a' can't be 0.\n");
		return;
	}

	if (d == 0)
	{
		printf("Error! Variable 'd' can't be 0.\n");
		return;
	}

	printf("%g%s", (a * d + b * c) / (a * d), "\n");

	return;
}

void task2()
{
	printf("Task 43: ");
	if (x - 1 < 0)
	{
		printf("Error! Variable 'x' can't be less than 1.\n");
		return;
	}

	printf("%g%s", (sqrt(x + 1) + sqrt(x - 1)) / (2 * sqrt(x)), "\n");
	return;
}

void task3()
{
	printf("Task 46: ");
	if (a == 0)
	{
		printf("Error! Variable 'a' can't be 0.\n");
		return;
	}

	if (floor(b) != b || b < 2)
	{
		printf("Error! Incorrect variable 'b'.\n");
		return;
	}

	if ((int)b % 2 == 0 && a < 0)
	{
		printf("Error! Variable 'a' can't be less than 0.\n");
		return;
	}

	printf("%g%s", (b * pow(a, (1 / b))) / a, "\n");
}

void task4()
{
	printf("Task 49: ");
	if (a == 0)
	{
		printf("Error! Variable 'a' can't be 0.\n");
		return;
	}

	printf("%g%s", tan(a) * (cos(2 * x) / a), "\n");
}

void task5()
{
	printf("Task 52: ");
	if (x * x - 4 * x < 0 || x * x - 9 == 0)
	{
		printf("Error! Variable 'x' uncorrect.\n");
		return;
	}

	printf("%g%s", sqrt(x * x - 4 * x) / (x * x - 9), "\n");
	return;
}

int main()
{
	printf("Enter a, b, c, d, x: ");
	scanf_s("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &x);
	
	printTasks();

	task1();
	task2();
	task3();
	task4();
	task5();

	return 0;
}
