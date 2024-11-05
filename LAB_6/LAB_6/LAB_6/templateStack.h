#pragma once
#include "type.h"
#include <cmath>

template <class T>

class templateStack
{

private:
	typedef struct Stack {
		T value;
		int index;
		Stack* next;
	}Stack;

private: type t;
private: Stack* sHead; // Указатель на структура данных Stack
	   //
	   // Конструктор класса myStack
	   //   
public: templateStack(type t)
{
	this->t = t;
	sHead = nullptr;
}
	  //
	  // Деструктор класса myStack
	  //
public: ~templateStack()
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
	  /// Функция вывода структуры данных в целочисленном формате
	  /// </summary>
	  /// <returns>Строка std::string</returns>
private: std::string output_not_char()
{
	std::string stack = "";
	if (sHead == nullptr) return "Стек пуст";
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
	  /// Функция вывода структуры данных в символьном формате
	  /// </summary>
	  /// <returns>Строка std::string</returns>
private: std::string output_char()
{
	std::string stack = "";
	if (sHead == nullptr) return "Стек пуст";
	else
	{
		Stack* curr = sHead;
		while (curr != nullptr)
		{
			if (curr->value == '\0')
				stack += "[" + std::to_string(curr->index) + "] = " + "Ошибка перевода" + ";\r\n";
			else
				stack += "[" + std::to_string(curr->index) + "] = " + (char(curr->value)) + ";\r\n";
			curr = curr->next;
		}
		return stack;
	}
}
	  /// <summary>
	  /// Процедура добавления нового элемента в вектор
	  /// </summary>
	  /// <param name="val">Значение нового элемента</param>
public:	void push(T val)
{
	if (sHead == nullptr) stack_start(val);
	else add_element(val);
}
	  /// <summary>
	  /// Процедура удаления последнего элемента
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
	  /// Процедура изменения значения элемента по его индексу
	  /// </summary>
	  /// <param name="index">Индекс элемента для изменения</param>
	  /// <param name="new_val">Новое значение элемента</param>
public: void change_by_index(int index, T new_val)
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
	else
		MessageBox::Show("Введенного индекса не существует", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
	  /// <summary>
	  /// Функция поиска индекса элемента по его значению
	  /// </summary>
	  /// <param name="val">Значение элемента для поиска</param>
	  /// <returns name="">Индекс элемента в переданным значением</returns>
public: int find_index(T val)
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
	  /// Функция поиска наибольшего элемента в структуре
	  /// </summary>
	  /// <returns>Значение наибольшего элемента структуры</returns>
public: T find_max()
{
	Stack* curr = sHead;
	if (curr != nullptr)
	{
		T max = curr->value;
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
	  /// Процедура очистки структуры данных
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
	  /// Процедура заполнения структуры данных тестовыми значениями
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
	else if (t == char_type)
	{
		for (int i = 1; i < 302; i += 5)
		{
			if (i > 33 && i < 128)
				push(i);
			else
				push('\0');
		}
	}
	else if (t == double_type)
	{
		for (float i = 1; i < 48; i += 0.7778)
		{
			push(i);
		}
	}
}
	  /// <summary>
	  /// Процедура добавления первого элемента
	  /// </summary>
private: void stack_start(T val)
{
	Stack* temp = new Stack{ val, 0, nullptr };

	sHead = temp;
}
	   /// <summary>
	   /// Процедура добавления элементов с индексом > 0
	   /// </summary>
	   /// <param name="val"></param>
private: void add_element(T val)
{
	Stack* curr = sHead;

	while (curr->next != nullptr)
		curr = curr->next;
	Stack* new_el = new Stack{ val, (curr->index + 1), nullptr };
	curr->next = new_el;
}

public: T sum()
{
	T result = 0;
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

public: T difference()
{
	T result = 0;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr)
			result -= curr->value;
	}
	return result;
}

public: T product()
{
	int max = (std::pow(2, (sizeof(int) * 4)));
	T result = 1;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr && result < max)
			result *= curr->value;
		else break;
	}
	return result;
}

public: T quotient()
{
	T result = 1;
	for (Stack* curr = sHead; curr != nullptr; curr = curr->next)
	{
		if (curr != nullptr && curr->value != 0)
			result /= curr->value;
	}
	return result;
}
};