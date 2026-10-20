#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void printTasks()
{
	printf("100) Дано дiйснi числа a, b, c (a > 0). Повнiстю дослiджувати бiквадратичне рiвняння ах^4 + bx^2 + c = 0 (якщо речових коренiв немає, то має бути видано повiдомлення про це, iнакше знайти речовi коренi, повiдомивши, скiльки серед них рiзних).\n");
	printf("107) Задано координати вершин прямокутника: (x1, y1), (x2, y2), (x3, y3), (x4, y4). Визначити площу частини прямокутника, розташованої у першому квадрантi.\n");
	printf("13) Дано двозначне число a. Визначити: а) чи є сума його цифр двозначним числом; б) бiльше числа a сума його цифр.\n");
	printf("50) З клавiатури вводяться довжини вiдрiзкiв a, b, c i d. Оцiнити їх у можливiсть побудови трикутникiв.\n");
	printf("111) Скласти програму знаходження суми двох найбiльших iз трьох рiзних чисел.\n");
	printf("89) Дано речовi позитивнi числа a, b, c, d. З'ясувати, чи можна прямокутник зi сторонами a, b помiстити всерединi прямокутника зi сторонами c, d так, щоб кожна зi сторiн одного прямокутника була паралельна або перпендикулярна кожнiй сторонi другого прямокутника.\n");
	printf("103) Якщо сума трьох попарно рiзних речових чисел X, Y, Z менше одиницi, то найменше iз цих трьох чисел замiнити напiвсумою двох iнших; в iншому випадку замiнити менше з X, Y напiвсумою двох значень, що залишилися.\n");
	printf("46) Задано два натуральнi числа. Визначити, чи середнє арифметичне цих чисел є цiлим числом.\n");
	printf("37) Перерозподiл значення змiнних a i b так, щоб у a виявилося бiльшим iз цих значень, а в b - менше.\n");
	printf("82) Визначити, чи правильно, що з подiлу неотрицательного цiлого числа a на позитивне число b виходить залишок, що дорiвнює одному з двох заданих чисел c або d.\n\n");
}

void task1()
{
	printf("100(1)) ");
	double a, b, c;
	printf("Enter a, b, c: ");
	while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	double D = b * b - 4 * a * c;

	if (D < 0)
	{
		printf("Error!\n");
		return;
	}
	else if (D == 0)
	{
		double t = -(b / (2 * a));
		if (t < 0)
		{
			printf("Error!\n");
			return;
		}
		printf("Two roots: %g, %g.\n", sqrt(t), -sqrt(t));
		return;
	}

	double t1 = (-b + sqrt(D)) / (2 * a), t2 = (-b - sqrt(D)) / (2 * a);

	if (t1 < 0 && t2 < 0)
	{
		printf("Error!\n");
	}
	else if (t1 > 0 && t2 > 0)
	{
		printf("Four roots: %g, %g, %g, %g.\n", sqrt(t2), -sqrt(t2), sqrt(t1), -sqrt(t1));
	}
	else if ((t1 > 0 && t2 < 0) || (t1 < 0 && t2 > 0))
	{
		if (t1 < 0)
		{
			printf("Two roots: %g, %g.\n", sqrt(t2), -sqrt(t2));
		}
		else
		{
			printf("Two roots: %g, %g.\n", sqrt(t1), -sqrt(t1));
		}
	}
	else if ((t1 > 0 && t2 == 0) || (t1 == 0 && t2 > 0))
	{
		if (t1 == 0)
		{
			printf("Three roots: %g, %g, 0.\n", sqrt(t2), -sqrt(t2));
		}
		else
		{
			printf("Three roots: %g, %g, 0.\n", sqrt(t1), -sqrt(t1));
		}
	}
	else
	{
		printf("One root: 0.\n");
	}
}

void task2()
{
	printf("107(2)) ");
	double x1, y1, x2, y2, x3, y3, x4, y4;
	
	printf("\n(x1, y1) *---* (x3, y3)\n");
	printf("         |   |\n");
	printf("         |   |\n");
	printf("(x2, y2) *---* (x4, y4)\n\n");

	printf("Enter x1, y1, x2, y2, x3, y3, x4, y4: ");

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != 8 || 
		x1 != x2 || y1 != y3 || x4 != x3 || y4 != y2 ||
		x1 >= x3 || y4 >= y3)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}
	
	printf("Answear: ");

	if (x3 <= 0 || y3 <= 0)
	{
		printf("0.");
	}
	else if (x2 <= 0 && y2 <= 0)
	{
		printf("%g", x3 * y3);
	}
	else if (x2 > 0 && y2 > 0)
	{
		printf("%g", (x3 - x2) * (y3 - y4));
	}
	else if (x2 > 0)
	{
		printf("%g", (x3 - x2) * y3);
	}
	else if (y2 > 0)
	{
		printf("%g", x3 * (y3 - y4));
	}
	printf("\n");
}

void task3()
{
	printf("13(3)) ");
	int d;
	printf("Enter x: ");
	while (scanf("%d", &d) != 1 || d > 99 || d < 10)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if ((d / 10) + (d - ((d / 10) * 10)) > 9)
	{
		printf("a) yes (%d), б) no.\n", (d / 10) + (d - ((d / 10) * 10)));
	}
	else
	{
		printf("a) no (%d), б) no.\n", (d / 10) + (d - ((d / 10) * 10)));
	}
}

bool isTraingle(double a, double b, double c)
{
	return (a + b > c) && (a + c > b) && (b + c > a);
}

void task4()
{
	printf("50(4)) ");
	double a, b, c, d;
	printf("Enter a, b, c, d: ");
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != 4 || a <= 0 || b <= 0 || c <= 0 || d <= 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	bool tmp = false;

	if (isTraingle(a, b, c))
	{
		tmp = true;
		printf("a, b, c - traingle; ");
	}
	if (isTraingle(a, b, d))
	{
		tmp = true;
		printf("a, b, d - traingle; ");
	}
	if (isTraingle(a, d, c))
	{
		tmp = true;
		printf("a, d, c - traingle; ");
	}
	if (isTraingle(d, b, c))
	{
		tmp = true;
		printf("d, b, c - traingle; ");
	}

	if (!tmp)
	{
		printf("Any traingles!");
	}
	printf("\n");
}

double min(double a, double b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void task5()
{
	printf("111(5)) ");
	double a, b, c;
	printf("Enter a, b, c: ");
	while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	printf("Answear: %g\n", (a + b + c) - min(a, min(b, c)));
}

void task6()
{
	printf("89(6)) ");
	double a, b, c, d;
	printf("Enter a, b, c, d: ");
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != 4 || a <= 0 || b <= 0 || c <= 0 || d <= 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if ((a <= c && b <= d) || (a <= d && b <= c))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}

void task7()
{
	printf("103(7)) ");
	double X, Y, Z;
	printf("Enter X, Y, Z: ");
	while (scanf("%lf %lf %lf", &X, &Y, &Z) != 3 || X == Y || X == Z || Y == Z)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if (X + Y + Z < 1)
	{
		if (X < Y && X < Z)
		{
			X = (Y + Z) / 2;
		}
		else if (Y < X && Y < Z)
		{
			Y = (X + Z) / 2;
		}
		else
		{
			Z = (Y + X) / 2;
		}
	}
	else
	{
		if (X < Y)
		{
			X = (Y + Z) / 2;
		}
		else
		{
			Y = (X + Z) / 2;
		}
	}

	printf("Total: X - %g, Y - %g, Z - %g\n", X, Y, Z);
}

void task8()
{
	printf("46(8)) ");
	int a, b;
	printf("Enter a, b: ");
	while (scanf("%d %d", &a, &b) != 2)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if (((a + b) / 2) % 2 == 0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}

void task9()
{
	printf("37(9)) ");
	double a, b;
	printf("Enter a, b: ");
	while (scanf("%lf %lf", &a, &b) != 2 || a == b)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if (a < b)
	{
		double tmp = b;
		b = a;
		a = tmp;
	}
	
	printf("Total: a - %g, b - %g\n", a, b);
}

void task10()
{
	printf("82(10)) ");
	int a, b, c, d;
	printf("Enter a, b, c, d: ");
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != 4 || a < 0 || b <= 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if (a % b == c || a % b == d)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
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
	task7();
	task8();
	task9();
	task10();

	return 0;
}
