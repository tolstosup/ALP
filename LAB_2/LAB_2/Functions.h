/*

АЯиП Лабораторная работа #2
Файл с функциями для тестирования проекта LAB_2
Михайлов Роман, группа 3091, 1 курс
28.02.2024 - 05.03.2024

*/

#pragma once

#include <iostream>

int* shaker_sort(int* a, int quantity)
{
	int left = 0, right = quantity - 1;
	int flag = 1;
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				unsigned int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (a[i - 1] > a[i])
			{
				unsigned int t = a[i];
				a[i] = a[i - 1];
				a[i - 1] = t;
				flag = 1;
			}
		}
		left++;
	}
	return a;
}

int* insertion_sort(int* a, int quantity)
{
	for (int i = 1; i < quantity; i++)
	{
		for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
		{
			unsigned int t = a[j];
			a[j] = a[j - 1];
			a[j - 1] = t;
		}
	}
	return a;
}

int* bubble_sort(int* a, int quantity)
{

	for (int i = 0; i < quantity - 1; i++)
	{
		for (int j = 0; j < quantity - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				unsigned int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	return a;
}

void quick_sort(int arr[], int start, int end)
{
	int l = start;
	int r = end;
	int piv = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < piv) l++;
		while (arr[r] > piv) r--;
		if (l <= r)
		{
			int t = arr[l];
			arr[l] = arr[r];
			arr[r] = t;
			l++;
			r--;
		}
	}
	if (start < r)
		quick_sort(arr, start, r);
	if (end > l)
		quick_sort(arr, l, end);
}
	
unsigned int max_value(int* a, int quantity)
{
	int max = a[0];
	for (int i = 1; i < quantity; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int* radix_sort(int* a, int quantity)
{

	unsigned int exp, i;
	i = max_value(a, quantity);
	for (exp = 1; i / exp > 0; exp *= 10)
	{
		int i, count[10] = { 0 };
		int* result = new int(quantity);

		for (i = 0; i < quantity; i++)
			count[(a[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = quantity - 1; i >= 0; i--)
		{
			result[count[(a[i] / exp) % 10] - 1] = a[i];
			count[(a[i] / exp) % 10]--;
		}
		for (i = 0; i < quantity; i++)
			a[i] = result[i];
	}

	return a;
}

bool compare_arrays(int* a, int* b)
{
	for (int i = 0; i < 5; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}