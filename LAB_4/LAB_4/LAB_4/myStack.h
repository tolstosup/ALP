#pragma once

template <class T>

class myStack
{

private:
	typedef struct Stack {
		T value;
		int index;
		Stack* next;
	}Stack;

private: Stack* sHead; // Указатель на структура данных Stack
//
// Конструктор класса myStack
//   
public: myStack()
{
	sHead = nullptr;
}
//
// Деструктор класса myStack
//
public: ~myStack()
{
	clear();
}
/// <summary>
/// Функция вывода структуры данных в целочисленном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output()
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
public: std::string output_char()
{
	std::string stack = "";
	if (sHead == nullptr) return "Стек пуст";
	else
	{
		Stack* curr = sHead;
		while (curr != nullptr)
		{
			if(curr->value == char(0))
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
	if(curr != nullptr)
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
	while (curr->value != val) curr = curr->next;
	if (curr != nullptr)
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
	for (int i = 0; i < 301; i += 5)
	{
		push(i);
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
/// <summary>
/// Процедура конвертации целочисленной структуры данных в символьный формат
/// </summary>
/// <param name="a">Экземпляр класса myArray, структура для конвертации</param>
public: void copy_to_char(std::vector<int> values)
{
	int n = 0, i = 0;
	if (values.size() != 0)
	{
		while (i != values.size())
		{
			if (values[i] > 32 && values[i] < 128)
			{
				push(Convert::ToChar(values[i]));
			}
			else
			{
				push(0);
				if (n == 0)
				{
					n = 1;
					MessageBox::Show("В структуре присутствуют значения, которые невозможно перевести в символы", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			i++;
		}
	}
}
/// <summary>
/// Функция получения массива значений текущего экземпляра класса
/// </summary>
/// <returns>Массив значений этого эезмепляра класса</returns>
public: std::vector<int> get_values()
{
	std::vector<int> values;
	Stack* curr = sHead;
	while (curr != nullptr)
	{
		if (curr != nullptr)
		{
			values.push_back(curr->value);
		}
		curr = curr->next;
	}
	return values;
}
};