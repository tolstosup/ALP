#pragma once

template <class T>

class myArray
{

private: static const unsigned int n = 2500; // ������ �������
private: T arr[n];							 // ��������� ������
private: unsigned int curr_index = 0;		 // ��������� ����������� ������
/// <summary>
/// ����������� ������ myArray, ������������� ������� ������ (0)
/// </summary>
public: myArray()
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
}
/// <summary>
/// ���������� ������ myArray
/// </summary>
public: ~myArray()
{
	clear();
}
/// <summary>
/// ������� ������ ��������� ������ � ������������� �������
/// </summary>
/// <returns>������ std::string</returns>
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
	else return "������ ����";
}
/// <summary>
/// ������� ������ ��������� ������ � ���������� �������
/// </summary>
/// <returns>������ std::string</returns>
public: std::string output_char()
{
	if (curr_index > 0)
	{
		std::string data = "";
		for (int i = 0; i < curr_index; i++)
		{
			if(arr[i] == 0)
				data += "[" + std::to_string(i) + "] = " + "������ ��������" + ";\r\n";
			else
				data += "[" + std::to_string(i) + "] = " + (char(arr[i])) + ";\r\n";
		}
		return data;
	}
	else return "������ ����";
}
/// <summary>
/// ��������� ���������� ������ �������� � ������
/// </summary>
/// <param name="val">�������� ������ ��������</param>
public: void push(T val)
{
	if (curr_index < 2500)
	{
		arr[curr_index] = val;
		curr_index++;
	}
	else
		MessageBox::Show("������ ��������", "������", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
}
/// <summary>
/// ��������� �������� ���������� ��������
/// </summary>
public: void pop()
{
	arr[curr_index] = 0;
	curr_index--;
}
/// <summary>
/// ��������� ��������� �������� �������� �� ��� �������
/// </summary>
/// <param name="index">������ �������� ��� ���������</param>
/// <param name="new_val">����� �������� ��������</param>
public: void change_by_index(int index, T new_val)
{
	if (index < curr_index)
		arr[index] = new_val;
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
	while (arr[i] != val && i < n)
	{
		i++;
	}
	if (i >= n - 1) return -1;
	else return i;
}
/// <summary>
/// ������� ������ ����������� �������� � ���������
/// </summary>
/// <returns>�������� ����������� �������� ���������</returns>
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
/// ��������� ������� ��������� ������
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
/// ��������� ���������� ��������� ������ ��������� ����������
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
/// ��������� ����������� ������������� ��������� ������ � ���������� ������
/// </summary>
/// <param name="a">��������� ������ myArray, ��������� ��� �����������</param>
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
				MessageBox::Show("� ��������� ������������ ��������, ������� ���������� ��������� � �������", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
}
/// <summary>
/// ������� ��������� �������� �������� �� �������
/// </summary>
/// <param name="a">��������� ������ myArray</param>
/// <param name="index">������ ��������</param>
/// <returns>�������� �� ����������� �������</returns>
private: int get_el(myArray<int> a, int index)
{
	return a.get_value(index);
}
/// <summary>
/// ������� ��������� �������� ������� ��������� �������
/// </summary>
/// <returns>������� �������� ������� (������ ���������)</returns>
public: int get_index()
{
	return curr_index;
}
/// <summary>
/// ������� ��������� �������� �������� �� �������
/// </summary>
/// <param name="index"></param>
/// <returns>�������� �� ����������� �������</returns>
public: int get_value(int index)
{
	return arr[index];
}
};

