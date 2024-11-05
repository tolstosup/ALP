#pragma once

template <class T>

class myArray
{

private: static const unsigned int n = 2500; // Размер массива
private: T arr[n];							 // Шаблонный массив
private: unsigned int curr_index = 0;		 // Следующий заполняемый индекс
/// <summary>
/// Констркутор класса myArray, инициализация массива нулями (0)
/// </summary>
public: myArray()
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
}
/// <summary>
/// Деструктор класса myArray
/// </summary>
public: ~myArray()
{
	clear();
}
/// <summary>
/// Функция вывода структуры данных в целочисленном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output()
{
	if (curr_index > 0)
	{
		std::string data = "";
		for (int i = 0; i < curr_index; i++)
		{
			data += "[" + std::to_string(i) + "] = " + std::to_string(arr[i]) + ";\r\n";
		}
		return data;
	}
	else return "Массив пуст";
}
/// <summary>
/// Функция вывода структуры данных в символьном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output_char()
{
	if (curr_index > 0)
	{
		std::string data = "";
		for (int i = 0; i < curr_index; i++)
		{
			if(arr[i] == 0)
				data += "[" + std::to_string(i) + "] = " + "Ошибка перевода" + ";\r\n";
			else
				data += "[" + std::to_string(i) + "] = " + (char(arr[i])) + ";\r\n";
		}
		return data;
	}
	else return "Массив пуст";
}
/// <summary>
/// Процедура добавления нового элемента в массив
/// </summary>
/// <param name="val">Значение нового элемента</param>
public: void push(T val)
{
	if (curr_index < 2500)
	{
		arr[curr_index] = val;
		curr_index++;
	}
	else
		MessageBox::Show("Массив заполнен", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
}
/// <summary>
/// Процедура удаления последнего элемента
/// </summary>
public: void pop()
{
	arr[curr_index] = 0;
	curr_index--;
}
/// <summary>
/// Процедура изменения значения элемента по его индексу
/// </summary>
/// <param name="index">Индекс элемента для изменения</param>
/// <param name="new_val">Новое значение элемента</param>
public: void change_by_index(int index, T new_val)
{
	if (index < curr_index)
		arr[index] = new_val;
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
	int i = 0;
	while (arr[i] != val && i < n)
	{
		i++;
	}
	if (i >= n - 1) return -1;
	else return i;
}
/// <summary>
/// Функция поиска наибольшего элемента в структуре
/// </summary>
/// <returns>Значение наибольшего элемента структуры</returns>
public: T find_max()
{
	if (curr_index != 0)
	{
		T max = arr[0];
		for (int i = 0; i < curr_index; i++)
		{
			if (arr[i] > max) max = arr[i];
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
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	curr_index = 0;
}
/// <summary>
/// Процедура заполнения структуры данных тестовыми значениями
/// </summary>
public: void fill_test()
{
	clear();
	{
		for (int i = 0; i < 301; i += 5)
		{
			push(i);
		}
	}
}
/// <summary>
/// Процедура конвертации целочисленной структуры данных в символьный формат
/// </summary>
/// <param name="a">Экземпляр класса myArray, структура для конвертации</param>
public: void copy_to_char(myArray<int> a)
{
	int n = 0;
	for (int i = 0; i < a.get_index(); i++)
	{
		if (get_el(a, i) > 32 && get_el(a, i) < 128)
		{
			push(get_el(a, i));
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
	}
}
/// <summary>
/// Функция получения значения элемента по индексу
/// </summary>
/// <param name="a">Экземпляр класса myArray</param>
/// <param name="index">Индекс элемента</param>
/// <returns>Значение по переданному индексу</returns>
private: int get_el(myArray<int> a, int index)
{
	return a.get_value(index);
}
/// <summary>
/// Функция получения текущего размера структуры даннных
/// </summary>
/// <returns>Позиция текущего индекса (размер структуры)</returns>
public: int get_index()
{
	return curr_index;
}
/// <summary>
/// Функция получения значения элемента по индексу
/// </summary>
/// <param name="index"></param>
/// <returns>Значение по переданному индексу</returns>
public: int get_value(int index)
{
	return arr[index];
}
};

