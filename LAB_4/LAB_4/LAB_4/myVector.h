template <class T>

class myVector
{

private: typedef struct vector
{
	T* arr_ptr;
	int size;
	int curr_index;
}vector;

private: vector* Vector; // ��������� �� ��������� ������ vector
/// <summary>
/// ����������� ������ myVector
/// </summary>
public: myVector()
{
	Vector = new vector{ nullptr, 0, 0 };
}
/// <summary>
/// ���������� ������ myVector
/// </summary>
public: ~myVector()
{
	clear();
}
/// <summary>
/// ������� ������ ��������� ������ � ������������� �������
/// </summary>
/// <returns>������ std::string</returns>
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
	else return "������ ����";
}
/// <summary>
/// ������� ������ ��������� ������ � ���������� �������
/// </summary>
/// <returns>������ std::string</returns>
public: std::string output_char()
{
	if (Vector->curr_index > 0)
	{
		std::string data = "";
		for (int i = 0; i < Vector->curr_index; i++)
		{
			char ch = char(0);
			if (Vector->arr_ptr[i] == ch)
				data += "[" + std::to_string(i) + "] = " + "������ ��������" + ";\r\n";
			else
				data += "[" + std::to_string(i) + "] = " + (char(Vector->arr_ptr[i])) + ";\r\n";
		}
		return data;
	}
	else return "������ ����";
}
/// <summary>
/// ��������� ���������� ������� ��������
/// </summary>
private: void start()
{
	T* arr = new T[1];
	Vector->arr_ptr = arr;
	Vector->size = 1;
}
/// <summary>
/// ��������� ��������� ������ ��� ������ ��������
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
/// ��������� ���������� ������ �������� � ������
/// </summary>
/// <param name="val">�������� ������ ��������</param>
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
/// ��������� �������� ���������� ��������
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
/// ��������� ��������� �������� �������� �� ��� �������
/// </summary>
/// <param name="index">������ �������� ��� ���������</param>
/// <param name="new_val">����� �������� ��������</param>
public: void change_by_index(int index, T new_val)
{
	if(index < Vector->curr_index)
		Vector->arr_ptr[index] = new_val;
	else
		MessageBox::Show("���������� ������� �� ����������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
/// <summary>
/// ������� ������ ������� �������� �� ��� ��������
/// </summary>
/// <param name="val">�������� �������� ��� ������</param>
/// <returns name="">������ �������� � ���������� ���������</returns>
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
/// ������� ������ ����������� �������� � ���������
/// </summary>
/// <returns>�������� ����������� �������� ���������</returns>
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
/// ��������� ������� ��������� ������
/// </summary>
public: void clear()
{
	delete[] Vector->arr_ptr;
	Vector->arr_ptr = nullptr;
	Vector->curr_index = 0;
	Vector->size = 0;
}
/// <summary>
/// ��������� ���������� ��������� ������ ��������� ����������
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
/// ��������� ����������� ������������� ��������� ������ � ���������� ������
/// </summary>
/// <param name="a">��������� ������ myArray, ��������� ��� �����������</param>
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
					MessageBox::Show("� ��������� ������������ ��������, ������� ���������� ��������� � �������", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
	}
}
/// <summary>
/// ������� ��������� ������� ��������
/// </summary>
/// <returns>������ ��������</returns>
public: int* get_arr()
{
	return Vector->arr_ptr;
}
/// <summary>
/// ������� ��������� ������� �������
/// </summary>
/// <returns>������ �������</returns>
public: int get_size()
{
	return Vector->size;
}
/// <summary>
/// ������� ��������� �������� �� �������
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
public: int get_value(int index)
{
	return Vector->arr_ptr[index];
}
};