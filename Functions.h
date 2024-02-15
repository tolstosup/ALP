#pragma once

// Формула первой рекурсивной функции
int recursion_1(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n % 2 == 0)
	{
		return (n + 3 * recursion_1(n - 1));
	}
	else if (n > 1 && n % 2 == 1)
	{
		return (2 + 2 * recursion_1(n - 2));
	}
}

// Формула второй рекурсивной функции
int recursion_2(int n)
{
	if (n < 3)
	{
		return 1;
	}
	else if (n > 2 && n % 2 == 1)
	{
		return (recursion_2(n - 1) + recursion_2(n - 2));
	}
	else if (n > 2 && n % 2 == 0)
	{
		int sum = 0;
		for (int i = 1; i <= n - 1; i++)
			sum += recursion_2(i);
		return sum;
	}
}

// Определение максимального элемента из двух, для дополнительной программы
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}