#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void printTasks()
{
	printf("26) (cos(sin(1/z)))^2\n");
	printf("33) cbrt(m*g*cos(a))\n");
	printf("52) sqrt(x^2 - 4x) / (x^2 - 9)\n");
	printf("29) (x1*x2 + x1*x3 + x2*x3) / x\n");
	printf("30) v0*t + (a * t^2) / 2\n\n");
}

void task1(double z)
{
	
	printf("Task 26: ");
	if (z == 0)
	{
		printf("Error! Variable 'z' can't be 0.\n");
		return;
	}

	printf("%g\n", pow(cos(sin(1 / z)), 2));

	return;
}

void task2(double m, double a)
{
	printf("Task 33: ");
	if (m < 0)
	{
		printf("Error! Variable 'm' can't be less than 0.\n");
		return;
	}

	printf("%g\n", cbrt(m * 9.8 * cos(a)));
	return;
}

void task3(double x)
{
	printf("Task 52: ");
	if (x * x - 4 * x < 0 || x * x - 9 == 0)
	{
		printf("Error! Variable 'x' uncorrect.\n");
		return;
	}

	printf("%g\n", sqrt(x * x - 4 * x) / (x * x - 9));
	return;
}

void task4(double x, double x1, double x2, double x3)
{
	printf("Task 29: ");
	if (x == 0)
	{
		printf("Error! Variable 'x' can't be 0.\n");
		return;
	}

	printf("%g\n", (x1 * x2 + x1 * x3 + x2 * x3) / x);
}

void task5(double v0, double t, double a)
{
	printf("Task 30: ");
	if (t < 0)
	{
		printf("Error! Variable 't' can't be less than 0.\n");
		return;
	}

	printf("%g\n", v0 * t + ((a * t * t) / 2));
}

int main()
{
	double a, t, m, z, x, x1, x2, x3, v0;
	printTasks();
	printf("Enter a, t, m, z, x, x1, x2, x3, v0 (total 9 digits): ");

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &a, &t, &m, &z, &x, &x1, &x2, &x3, &v0) != 9)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	printf("\na: %g\nt: %g\nm: %g\nz: %g\nx: %g\nx1: %g\nx2: %g\nx3: %g\nv0: %g\n\n", a, t, m, z, x, x1, x2, x3, v0);

	task1(z);
	task2(m, a);
	task3(x);
	task4(x, x1, x2, x3);
	task5(v0, t, a);

	return 0;
}
