#include "pch.h"
#include "..\LAB_6\type.h"
#include "templateStackUnitTest.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(push)
		{
			tempStack stack = tempStack(int_type);
			stack.push(1);
			stack.push(1000);
			Assert::IsTrue(stack.output() == "[0] = 1;\r\n[1] = 1000;\r\n");
		}

		TEST_METHOD(max)
		{
			tempStack stack = tempStack(int_type);
			stack.push(1);
			stack.push(1000);
			Assert::IsTrue(stack.find_max() == 1000);
		}

		TEST_METHOD(clear)
		{
			tempStack stack = tempStack(int_type);
			stack.push(1);
			stack.push(1000);
			stack.clear();
			Assert::IsTrue(stack.output() == "Стек пуст");
		}
	};
}
