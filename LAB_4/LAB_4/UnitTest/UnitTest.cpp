#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(pushArray)
		{
			myArray<int> a;
			a.push(1);
			Assert::IsTrue(a.output() == "[0] = 1;\r\n");
		}

		TEST_METHOD(pushVector)
		{
			myVector<int> v;
			v.push(2);
			Assert::IsTrue(v.output() == "[0] = 2;\r\n");
		}

		TEST_METHOD(pushStack)
		{
			myStack<int> s;
			s.push(3);
			Assert::IsTrue(s.output() == "[0] = 3;\r\n");
		}

		TEST_METHOD(pushQueue)
		{
			myQueue<int> q;
			q.push(4);
			Assert::IsTrue(q.output() == "[0] = 4;\r\n");
		}
	};
}
