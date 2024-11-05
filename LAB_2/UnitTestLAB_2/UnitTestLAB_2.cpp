/*

АЯиП Лабораторная работа #2
Тестовый файл проекта LAB_2
Михайлов Роман, группа 3091, 1 курс
28.02.2024 - 05.03.2024

*/

#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_2/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int arr_test[5] = { 1, 2, 3, 4, 5 };

namespace UnitTestLAB2
{
	TEST_CLASS(UnitTestLAB2)
	{
	public:
		
		TEST_METHOD(radix_sort_test)
		{
			int arr[5] = {5, 4, 3, 2, 1};
			radix_sort(arr, 5);
			Assert::IsTrue(compare_arrays(arr, arr_test));
		}

		TEST_METHOD(insertion_sort_test)
		{
			int arr[5] = { 5, 4, 3, 2, 1 };
			insertion_sort(arr, 5);
			Assert::IsTrue(compare_arrays(arr, arr_test));
		}

		TEST_METHOD(bubble_sort_test)
		{
			int arr[5] = { 5, 4, 3, 2, 1 };
			bubble_sort(arr, 5);
			Assert::IsTrue(compare_arrays(arr, arr_test));
		}

		TEST_METHOD(shaker_sort_test)
		{
			int arr[5] = { 5, 4, 3, 2, 1 };
			shaker_sort(arr, 5);
			Assert::IsTrue(compare_arrays(arr, arr_test));
		}

		TEST_METHOD(quick_sort_test)
		{
			int arr[5] = { 5, 4, 3, 2, 1 };
			quick_sort(arr, 0, 4);
			Assert::IsTrue(compare_arrays(arr, arr_test));
		}
	};
}
