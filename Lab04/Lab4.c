#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

void printTasks()
{
	printf("46) Знайти:\nа) суму квадратів усіх цілих чисел від 10 до 50;\nб) суму квадратів усіх цілих чисел від a до 50 (значення a вводиться із клавіатури; a ≤ 50);\nв) суму квадратів усіх цілих чисел від a до b(значення b вводиться із клавіатури; b ≥ –10);\nг) суму квадратів усіх цілих чисел від a до b(значення a і b вводяться з клавіатури; b ≥ а).\n");
	printf("53) Знайти суму 2^2 + 2^3 + 2^4 + ... + 2^10 без зведення у ступінь.\n");
	printf("72) Обчислити суму 1! + 2! + 3! + ... + n! (значення n вводиться із клавіатури; 1 < п ≤ 10).\n");
	printf("109) Скласти програму для перевірки твердження про те, що результатами обчислень за формулою x^2 + x + 17 при 0≤x≤15 є простими числами. Усі результати вивести на екран.\n");
	printf("170) Дано послідовність дійсних чисел a1, a2, ..., a15, упорядкована за зростанням, та число п, не рівне жодному з чисел послідовності і таке, що a1 < п < a15.\nа) Вивести всі числа послідовності, менші п.\nб) Знайти два елементи послідовності(їх порядкові номери та значення), в інтервалі між якими знаходиться значення п.\nВ обох завданнях умовну інструкцію не використовувати.\n");
	printf("261) Написати програму обчислення функції y = (0.3*a*b*x)/(2*a-b*x) - 3*sqrt((2*a-arctg(x))/abs(a - x)) при a = 1, b = -2. Аргумент  приймає значення від –1 до 5 із кроком 0,5.\n");
	printf("108) Скільки можна купити бугаїв, корів і телят, платячи за бика 7000 грн., за корову - 3000 грн., а за теля - 1000 грн., якщо на 100000 грн. треба купити 100 голів худоби? Для розв'язання задачі скласти алгоритм.\n");
	printf("277) Дано натуральне число, де всі цифри різні. Визначити, яка цифра розташована в ньому лівіше: максимальна чи мінімальна.\n");
	printf("214) a_n = 0.5 * cos(a_(n-1))\n");
	printf("205) a_n = (2^n * n!) / n^n\n\n");
}

void task1()
{
	printf("\n46(1))\na) ");

	long long sum = 0;
	for (int i = 10; i <= 50; i++)
	{
		sum += i * i;
	}
	printf("%d\nb) ", sum);

	int a;
	printf("enter a: ");
	while (scanf("%d", &a) != 1 || a > 50)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	sum = 0;
	for (int i = a; i <= 50; i++)
	{
		sum += i * i;
	}

	printf("Answer: %d\nc) ", sum);
	sum = 0;
	int b;

	printf("enter a, b: ");
	while (scanf("%d %d", &a, &b) != 2 || a > b || b < -10)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	for (int i = a; i <= b; i++)
	{
		sum += i * i;
	}
	printf("Answer: %d\n", sum);
}

void task2()
{
	printf("\n53(2)) ");

	int current = 4; //2^2
	int res = 0;

	for (int i = 0; i < 9; i++)
	{
		res += current;
		current *= 2;
	}

	printf("%d\n", res);
}

void task3()
{
	int n;
	long long sum = 0;
	printf("\n72(3)) ");
	printf("enter n: ");
	while (scanf("%d", &n) != 1 || n < 1 || n > 10)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	for (int i = 1; i <= n; i++)
	{
		int k = 1;

		for (int j = 2; j <= i; j++)
		{
			k *= j;
		}

		sum += k;
	}

	printf("Answer: %d\n", sum);
}

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

void task4()
{
	printf("\n109(4)) ");

	for (int i = 0; i <= 15; i++)
	{
		int res = i * i + i + 17;
		printf("x^2 + x + 17; x = %d; result: %d", i, res);

		if (isPrime(res))
		{
			printf(" - prime\n");
		}
		else
		{
			printf(" - complex\n");
		}
	}
}

void task5()
{
	printf("\n170(5)) ");

	double numbers[15];
	double n;
	printf("enter numbers: ");
	for (int i = 0; i < 15; i++)
	{
		while (scanf("%lf", &numbers[i]) != 1)
		{
			printf("Uncorrect input!\n");
			while (getchar() != '\n');
		}
	}
	printf("\nEnter n: ");
	while (scanf("%lf", &n) != 1)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	int k = 0;

	printf("a) ");
	for (int i = 0; numbers[i] < n && i < 15; i++)
	{
		printf("%g ", numbers[i]);
		k = i;
	}

	printf("\nb) %g(%d), %g(%d)\n", numbers[k], k + 1, numbers[k + 1], k + 2);
}

void task6()
{
	printf("\n261(6)) \n");

	int a = 1, b = -2;

	for (double x = -1; x <= 5; x += 0.5)
	{
		double y = (0.3 * a * b * x) / (2 * a - b * x) - 3 * sqrt((2 * a - atan(x)) / fabs(a - x));
		printf("y = %g, x = %g\n", y, x);
	}
}

void task7()
{
	printf("\n108(7)) ");

	printf("Якщо треба купити мінімум 100 голів, то можна купити лише 100 телят, бо якщо купити навіть хочаб одну корову, а далі лише телят, то 100 голів не набереться.\n");
}

void task8()
{
	printf("\n277(8)) ");
	int n;
	printf("Enter n: ");
	while (scanf("%d", &n) != 1 || n < 10)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	if (n < 10)
	{
		printf("У числі лише одна цифра.\n");
	}

	int min_i, min_d = 10, max_i, max_d = -1, current_idx = 0;

	while (n > 0)
	{
		current_idx++;
		int d = n % 10;

		if (d > max_d)
		{
			max_d = d;
			max_i = current_idx;
		}
		if (d < min_d)
		{
			min_d = d;
			min_i = current_idx;
		}

		n /= 10;
	}

	if (min_i > max_i)
	{
		printf("Мінімальна цифра лівіше.\n");
	}
	else
	{
		printf("Максимальна цифра лівіше.\n");
	}
}

void task9()
{
	double e = 0.001;
	printf("\n214(9)) 0.5 ");
	double a_l = 0.5, a_n = -100;

	do
	{
		if (a_n != -100)
		{
			a_l = a_n;
			printf("%g ", a_l);
		}

		a_n = 0.5 * cos(a_l);
	} while (fabs(a_n - a_l) > e);

	printf("%g", a_n);
}

int factorial(int n)
{
	long long f = 1;

	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}

	return f;
}

void task10()
{
	printf("\n\n205(10)) ");
	double e, a, sum = 0;
	int i = 1;

	printf("\nEnter e: ");
	while (scanf("%lf", &e) != 1 || e < 0)
	{
		printf("Uncorrect input!\n");
		while (getchar() != '\n');
	}

	do
	{
		a = pow(2, i) * factorial(i) / pow(i, i);

		if (fabs(a) >= e)
		{
			sum += a;
		}

		i++;
	} while (fabs(a) >= e);

	printf("Answer: %g\n", sum);
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