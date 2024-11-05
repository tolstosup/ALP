#pragma once

template <class T>

class myQueue
{

private:
	typedef struct Queue {
		T value;
		int index;
		Queue* next;
	}Queue;

private: Queue* qHead; // Указатель на структуру данных Queue
//
// Конструктор класса myQueue
//
public: myQueue()
{
	qHead = nullptr;
}
//
// Деструктор класса myQueue
//
public: ~myQueue()
{
	clear();
}
/// <summary>
/// Функция вывода структуры данных в целочисленном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output()
{
	std::string queue = "";
	if (qHead == nullptr) return "Очередь пуста";
	else
	{
		Queue* curr = qHead;
		while (curr != nullptr)
		{
			queue += "[" + std::to_string(curr->index) + "] = " + std::to_string(curr->value) + ";\r\n";
			curr = curr->next;
		}
		return queue;
	}
}
/// <summary>
/// Функция вывода структуры данных в символьном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output_char()
{
	std::string queue = "";
	if (qHead == nullptr) return "Очередь пуст";
	else
	{
		Queue* curr = qHead;
		while (curr != nullptr)
		{
			if (curr->value == char(0))
				queue += "[" + std::to_string(curr->index) + "] = " + "Ошибка перевода" + ";\r\n";
			else
				queue += "[" + std::to_string(curr->index) + "] = " + (char(curr->value)) + ";\r\n";
			curr = curr->next;
		}
		return queue;
	}
}
/// <summary>
/// Процедура добавления нового элемента в вектор
/// </summary>
/// <param name="val">Значение нового элемента</param>
public:	void push(T val)
{
	if (qHead == nullptr) queue_start(val);
	else add_element(val);
}
/// <summary>
/// Процедура удаления последнего элемента
/// </summary>
public: void pop()
{
	if (qHead != nullptr)
	{
		Queue* curr = qHead;
		if (curr == qHead)
		{
			qHead = curr->next;
			delete curr;
		}
		else
		{
			qHead = nullptr;
			delete curr;
		}
		refresh_index();
	}
}
/// <summary>
/// Процедура изменения значения элемента по его индексу
/// </summary>
/// <param name="index">Индекс элемента для изменения</param>
/// <param name="new_val">Новое значение элемента</param>
public: void change_by_index(int index, T new_val)
{
	Queue* curr = qHead;
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
public: int find_index(int val)
{
	Queue* curr = qHead;
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
public: int find_max()
{
	Queue* curr = qHead;
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
/// Процедура очистки структуры данных
/// </summary>
public: void clear()
{
	if (qHead != nullptr)
	{
		while (qHead != nullptr)
		{
			Queue* curr = qHead;
			while (curr->next != nullptr) curr = curr->next;
			if (curr == qHead)
			{
				qHead = nullptr;
				delete curr;
			}
			else
			{
				Queue* prev = qHead;
				while (prev->next != curr) prev = prev->next;
				delete curr;
				prev->next = nullptr;
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
private: void queue_start(T val)
{
	Queue* temp = new Queue{ val, 0, nullptr };
	qHead = temp;
}
/// <summary>
/// Процедура добавления элементов с индексом > 0
/// </summary>
/// <param name="val"></param>
private: void add_element(T val)
{
	Queue* curr = qHead;

	while (curr->next != nullptr) curr = curr->next;
	Queue* new_el = new Queue{ val, (curr->index + 1), nullptr };
	curr->next = new_el;
}
/// <summary>
/// Процедура обновления нумерации в структуре
/// </summary>
private: void refresh_index()
{
	int index = 0;
	Queue* curr = qHead;
	while (curr != nullptr)
	{
		curr->index = index++;
		curr = curr->next;
	}
}
/// <summary>
/// Процедура конвертации целочисленной структуры данных в символьный формат
/// </summary>
/// <param name="a">Экземпляр класса myQueue (структура для конвертации)</param>
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
/// <returns>Массив значений этого экземпляра класса</returns>
public: std::vector<int> get_values()
{
	std::vector<int> values;
	Queue* curr = qHead;
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