/*

АЯиП Лабораторная работа #1
Заголовочный файл с функциями из проекта LAB_1 для тестов
Михайлов Роман, группа 3091, 1 курс
13.02.2024 - 14.02.2024

*/

// Формула первой рекурсивной функции
int recursion_1(unsigned int n)
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
int recursion_2(unsigned int n)
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

int arr[5] = {1, 2, 3, 4, 0}, i = 0;

unsigned int dop()
{
	unsigned int num = 0;
	num = arr[i];
	i++;
	if (num == 0)
	{
		return 0;
	}
	else
	{
		unsigned int tmp_max = dop();
		return max(tmp_max, num);
	}
}