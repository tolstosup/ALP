#pragma once
#include "..\LAB_6\type.h"
#include <cmath>
#include <iostream>
#include <string>

class tempStack
{

private:
	typedef struct Stack {
		int value;
		int index;
		Stack* next;
	}Stack;

private: type t;
private: Stack* sHead; // ��������� �� ��������� ������ Stack
	   //
	   // ����������� ������ myStack
	   //   
public: tempStack(type t)
{
	this->t = t;
	sHead = nullptr;
}
	  //
	  // ���������� ������ myStack
	  //
public: ~tempStack()
{
	clear();
}

public: std::string output()
{
	if (t == char_type)
		return output_char();
	else
		return output_not_char();
}
	  /// <summary>
	  /// ������� ������ ��������� ������ � ������������� �������
	  /// </summary>
	  /// <returns>������ std::string</returns>
private: std::string output_not_char()
{
	std::string stack = "";
	if (sHead == nullptr) return "���� ����";
	else
	{
		Stack* curr = sHead;
		while (curr != nullptr)
		{
			stack += "[" + std::to_string(curr->index) + "] = " + std::to_string(curr->value) + ";\r\n";
			curr = curr->next;
		}
		return stack;
	}
}
	  /// <summary>
	  /// ������� ������ ��������� ������ � ���������� �������
	  /// </summary>
	  /// <returns>������ std::string</returns>
private: std::string output_char()
{
	std::string stack = "";
	if (sHead == nullptr) return "���� ����";
	else
	{
		Stack* curr = sHead;
		while (curr != nullptr)
		{
			if (curr->value == '\0')
				stack += "[" + std::to_string(curr->index) + "] = " + "������ ��������" + ";\r\n";
			else
				stack += "[" + std::to_string(curr->index) + "] = " + (char(curr->value)) + ";\r\n";
			curr = curr->next;
		}
		return stack;
	}
}
	  /// <summary>
	  /// ��������� ���������� ������ �������� � ������
	  /// </summary>
	  /// <param name="val">�������� ������ ��������</param>
public:	void push(int val)
{
	if (sHead == nullptr) stack_start(val);
	else add_element(val);
}
	  /// <summary>
	  /// ��������� �������� ���������� ��������
	  /// </summary>
public: void pop()
{
	if (sHead != nullptr)
	{
		Stack* curr = sHead;
		while (curr->next != nullptr) curr = curr->next;
		if (curr == sHead)
		{
			sHead = nullptr;
			delete curr;
		}
		else
		{
			Stack* prev = sHead;
			while (prev->next != curr) prev = prev->next;
			prev->next = nullptr;
			delete curr;
		}
	}
}
	  /// <summary>
	  /// ��������� ��������� �������� �������� �� ��� �������
	  /// </summary>
	  /// <param name="index">������ �������� ��� ���������</param>
	  /// <param name="new_val">����� �������� ��������</param>
public: void change_by_index(int index, int new_val)
{
	Stack* curr = sHead;
	while (curr != nullptr)
	{
		if (curr->index == index)
			break;
		else if (curr != nullptr)
			curr = curr->next;
	}
	if (curr != nullptr)
		curr->value = new_val;
}
	  /// <summary>
	  /// ������� ������ ������� �������� �� ��� ��������
	  /// </summary>
	  /// <param name="val">�������� �������� ��� ������</param>
	  /// <returns name="">������ �������� � ���������� ���������</returns>
public: int find_index(int val)
{
	Stack* curr = sHead;
	while (curr->next != nullptr)
	{
		if (curr->value == val) break;
		curr = curr->next;
	}
	if (curr != nullptr && curr->value == val)
		return curr->index;
	else
		return -1;
}
	  /// <summary>
	  /// ������� ������ ����������� �������� � ���������
	  /// </summary>
	  /// <returns>�������� ����������� �������� ���������</returns>
public: int find_max()
{
	Stack* curr = sHead;
	if (curr != nullptr)
	{
		int max = curr->value;
		while (curr != nullptr)
		{
			if (max < curr->value)
				max = curr->value;
			curr = curr->next;
		}
		return max;
	}
	return -1;
}
	  /// <summary>
	  /// ��������� ������� ��������� ������
	  /// </summary>
public: void clear()
{
	if (sHead != nullptr)
	{
		while (sHead != nullptr)
		{
			Stack* curr = sHead;
			while (curr->next != nullptr) curr = curr->next;
			if (curr == sHead)
			{
				sHead = nullptr;
				delete curr;
			}
			else
			{
				Stack* prev = sHead;
				while (prev->next != curr) prev = prev->next;
				prev->next = nullptr;
				delete curr;
			}
		}
	}
}
	  /// <summary>
	  /// ��������� ���������� ��������� ������ ��������� ����������
	  /// </summary>
public: void fill_test()
{
	clear();
	if (t == int_type)
	{
		for (int i = 1; i < 302; i += 5)
		{
			push(i);
		}
	}
}
	  /// <summary>
	  /// ��������� ���������� ������� ��������
	  /// </summary>
private: void stack_start(int val)
{
	Stack* temp = new Stack{ val, 0, nullptr };

	sHead = temp;
}
	   /// <summary>
	   /// ��������� ���������� ��������� � �������� > 0
	   /// </summary>
	   /// <param name="val"></param>
private: void add_element(int val)
{
	Stack* curr = sHead;

	while (curr->next != nullptr)
		curr = curr->next;
	Stack* new_el = new Stack{ val, (curr->index + 1), nullptr };
	curr->next = new_el;
}

public: int sum()
{
	int result = 0;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr)
			result += curr->value;
	}
	return result;
}

public: std::string sum_of_char()
{
	std::string result = "";
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr)
			if(curr->value > 33 && curr->value < 128)
				result += (char)curr->value;
	}
	return result;
}

public: int difference()
{
	int result = 0;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr)
			result -= curr->value;
	}
	return result;
}

public: int product()
{
	int max = (std::pow(2, (sizeof(int) * 4)));
	int result = 1;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr && result < max)
			result *= curr->value;
		else break;
	}
	return result;
}

public: int quotient()
{
	int result = 1;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr && curr->value != 0)
			result /= curr->value;
	}
	return result;
}
};