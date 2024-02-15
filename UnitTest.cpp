#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_1/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		// Тест первой рекурсивной функции, при аргументе = 5, ожидаемый результат = 10
		TEST_METHOD(rec1_test1)
		{
			Assert::IsTrue(recursion_1(5) == 10);
		}

		// Тест первой рекурсивной функции, при аргументе = 1, ожидаемый результат = 1
		TEST_METHOD(rec1_test2)
		{
			Assert::IsTrue(recursion_1(1) == 1);
		}

		// Тест второй рекурсивной функции, при аргументе = 2, ожидаемый результат = 1
		TEST_METHOD(rec2_test1)
		{
			Assert::IsTrue(recursion_2(2) == 1);
		}

		// Тест второй рекурсивной функции, при аргументе = 4, ожидаемый результат = 4
		TEST_METHOD(rec2_test2)
		{
			Assert::IsTrue(recursion_2(4) == 4);
		}

		// Тест функции по определению максимального элемента из двух, при аргументах = 5 и 0, ожидаемый результат = 5
		TEST_METHOD(max_test)
		{
			Assert::IsTrue(max(5, 0) == 5);
		}
	};
}
