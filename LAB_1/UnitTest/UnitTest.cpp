/*

АЯиП Лабораторная работа #1
Файл с Unit-тестами для функций из проекта LAB_1
Михайлов Роман, группа 3091, 1 курс
13.02.2024 - 14.02.2024

*/

#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_1/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		// Тест первой рекурсивной функции, при аргументе = 1, ожидаемый результат = 1
		TEST_METHOD(rec1_test1)
		{
			Assert::IsTrue(recursion_1(1) == 1);
		}

		// Тест первой рекурсивной функции, при аргументе = 2, ожидаемый результат = 5
		TEST_METHOD(rec1_test2)
		{
			Assert::IsTrue(recursion_1(2) == 5);
		}

		// Тест второй рекурсивной функции, при аргументе = 2, ожидаемый результат = 1
		TEST_METHOD(rec2_test1)
		{
			Assert::IsTrue(recursion_2(2) == 1);
		}

		// Тест второй рекурсивной функции, при аргументе = 3, ожидаемый результат = 2
		TEST_METHOD(rec2_test2)
		{
			Assert::IsTrue(recursion_2(3) == 2);
		}

		// Тест функции по определению максимального элемента из двух, при аргументах = 1 и 0, ожидаемый результат = 1
		TEST_METHOD(max_test)
		{
			Assert::IsTrue(max(1, 0) == 1);
		}

		// Тест функции по определению максимального элемента последовательности, при аргументах = {1, 2, 3, 4, 0}, ожидаемый результат = 4
		TEST_METHOD(dop_test)
		{
			Assert::IsTrue(dop() == 4);
		}
	};
}
