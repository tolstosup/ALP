/*

АЯиП Лабораторная работа #3
Тестовый файл проекта LAB_3
Михайлов Роман, группа 3091, 1 курс
25.03.2024

*/

#include "pch.h"
#include "CppUnitTest.h"
#include "..\LAB_3\Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLAB3
{
	TEST_CLASS(UnitTestLAB3)
	{
	public:
		
		TEST_METHOD(count_test)
		{
			string test = "abc11";
			Assert::IsTrue(count(&test) == "Буквы\nabc11");
		}

		TEST_METHOD(insert_test)
		{
			string test = "a?b?c";
			Assert::IsTrue(insert_percent(&test) == "a?%b?%c");
		}

		TEST_METHOD(file_info_test)
		{
			string file_name = "C:\\Users\\name.txt", extension = "", name_of_file = "";
			file_info(file_name, &extension, &name_of_file);
			Assert::IsTrue(extension == ".txt" && name_of_file == "name");
		}
	};
}
