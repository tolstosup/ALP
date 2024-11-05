/*

АЯиП Лабораторная работа #3
Файл с функциями для тестирования проекта LAB_3
Михайлов Роман, группа 3091, 1 курс
25.03.2024

*/

#pragma once
#include <string>

using namespace std;

string count(string *text)
{
	int int_q = 0, char_q = 0;

	string str = *text;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int_q++;
		}
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 1040 && str[i] <= 1103))
		{
			char_q++;
		}
	}

	if (char_q > int_q)
	{
		*text = "Буквы\n" + *text;
	}
	else if (char_q < int_q)
	{
		*text = "Цифры\n" + *text;
	}
	return *text;
}

string insert_percent(string* input)
{
	string str = *input;
	if (str == "?")	str += "%";
	else
	{
		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str.length() > 1 && str[i] == '?' && str[i + 1] != '%')
			{
				str = str.insert(i + 1, "%");
			}
		}
	}
	if (str[str.length() - 1] == '?') str += " % ";
	*input = str;
	return *input;
}

int last_indx_of(string str, char sym)
{
	int indx = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == sym) indx = i;
	}
	return indx;
}

void file_info(string info, string* extension, string* name_of_file)
{
	int dot = last_indx_of(info, '.');
	int slash = last_indx_of(info, '\\');
	string temp = info;
	*extension = temp.erase(0, temp.length() - (temp.length() - dot));

	temp = info.erase(0, slash + 1);
	dot = last_indx_of(temp, '.');
	temp = temp.erase(temp.length() - (temp.length() - dot), 4);

	*name_of_file = temp;
}