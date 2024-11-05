template <class T>

class myVector
{

private: typedef struct vector
{
	T* arr_ptr;
	int size;
	int curr_index;
}vector;

private: vector* Vector; // Указатель на структуру данных vector
/// <summary>
/// Конструктор класса myVector
/// </summary>
public: myVector()
{
	Vector = new vector{ nullptr, 0, 0 };
}
/// <summary>
/// Деструктор класса myVector
/// </summary>
public: ~myVector()
{
	clear();
}
/// <summary>
/// Функция вывода структуры данных в целочисленном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output()
{
	if (Vector->size > 0)
	{
		std::string data = "";
		for (int i = 0; i < Vector->curr_index; i++)
		{
			data += "[" + std::to_string(i) + "] = " + std::to_string(Vector->arr_ptr[i]) + ";\r\n";
		}
		return data;
	}
	else return "Вектор пуст";
}
/// <summary>
/// Функция вывода структуры данных в символьном формате
/// </summary>
/// <returns>Строка std::string</returns>
public: std::string output_char()
{
	if (Vector->curr_index > 0)
	{
		std::string data = "";
		for (int i = 0; i < Vector->curr_index; i++)
		{
			char ch = char(0);
			if (Vector->arr_ptr[i] == ch)
				data += "[" + std::to_string(i) + "] = " + "Ошибка перевода" + ";\r\n";
			else
				data += "[" + std::to_string(i) + "] = " + (char(Vector->arr_ptr[i])) + ";\r\n";
		}
		return data;
	}
	else return "Вектор пуст";
}
/// <summary>
/// Процедура добавления первого элемента
/// </summary>
private: void start()
{
	T* arr = new T[1];
	Vector->arr_ptr = arr;
	Vector->size = 1;
}
/// <summary>
/// Процедура выделения памяти для нового элемента
/// </summary>
private: void new_mem()
{
	T* new_arr = new T[++Vector->size];
	for (int i = 0; i < Vector->size - 1; i++)
	{
		new_arr[i] = Vector->arr_ptr[i];
	}
	delete[] Vector->arr_ptr;
	Vector->arr_ptr = new_arr;
}
/// <summary>
/// Процедура добавления нового элемента в вектор
/// </summary>
/// <param name="val">Значение нового элемента</param>
public: void push(T val)
{
	if (Vector->size == 0) 
		start();
	if (Vector->curr_index != 0 && Vector->curr_index == Vector->size)
		new_mem();
	Vector->arr_ptr[Vector->curr_index] = val;
	Vector->curr_index++;
}
/// <summary>
/// Процедура удаления последнего элемента
/// </summary>
public: void pop()
{
	if (Vector->size > 0)
	{
		T* new_arr = new T[--Vector->size];
		for (int i = 0; i < Vector->size; i++)
		{
			new_arr[i] = Vector->arr_ptr[i];
		}
		delete[] Vector->arr_ptr;
		Vector->arr_ptr = new_arr;
		Vector->curr_index--;
	}
}
/// <summary>
/// Процедура изменения значения элемента по его индексу
/// </summary>
/// <param name="index">Индекс элемента для изменения</param>
/// <param name="new_val">Новое значение элемента</param>
public: void change_by_index(int index, T new_val)
{
	if(index < Vector->curr_index)
		Vector->arr_ptr[index] = new_val;
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
	while (Vector->arr_ptr[i] != val && i < Vector->size)
	{
		i++;
	}
	if (i >= Vector->size) return -1;
	else return i - 1;
}
/// <summary>
/// Функция поиска наибольшего элемента в структуре
/// </summary>
/// <returns>Значение наибольшего элемента структуры</returns>
public: int find_max()
{
	if (Vector->curr_index != 0)
	{
		T max = Vector->arr_ptr[0];
		for (int i = 0; i < Vector->curr_index; i++)
		{
			if (Vector->arr_ptr[i] > max) max = Vector->arr_ptr[i];
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
	delete[] Vector->arr_ptr;
	Vector->arr_ptr = nullptr;
	Vector->curr_index = 0;
	Vector->size = 0;
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
/// Процедура конвертации целочисленной структуры данных в символьный формат
/// </summary>
/// <param name="a">Экземпляр класса myArray, структура для конвертации</param>
public: void copy_to_char(int arr[], int n)
{
	int k = 0;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 32 && arr[i] < 128)
			{
				push(arr[i]);
			}
			else
			{
				push(0);
				if (k == 0)
				{
					k = 1;
					MessageBox::Show("В структуре присутствуют значения, которые невозможно перевести в символы", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
	}
}
/// <summary>
/// Функция получения массива значений
/// </summary>
/// <returns>Массив значений</returns>
public: int* get_arr()
{
	return Vector->arr_ptr;
}
/// <summary>
/// Функция получения размера вектора
/// </summary>
/// <returns>Размер вектора</returns>
public: int get_size()
{
	return Vector->size;
}
/// <summary>
/// Функция получения значения по индексу
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
public: int get_value(int index)
{
	return Vector->arr_ptr[index];
}
};