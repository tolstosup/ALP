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

private: Stack* sHead; // ��������� �� ��������� ������ Stack
//
// ����������� ������ myStack
//   
public: myStack()
{
	sHead = nullptr;
}
//
// ���������� ������ myStack
//
public: ~myStack()
{
	clear();
}
/// <summary>
/// ������� ������ ��������� ������ � ������������� �������
/// </summary>
/// <returns>������ std::string</returns>
public: std::string output()
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
public: std::string output_char()
{
	std::string stack = "";
	if (sHead == nullptr) return "���� ����";
	else
	{
		Stack* curr = sHead;
		while (curr != nullptr)
		{
			if(curr->value == char(0))
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
public:	void push(T val)
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
		MessageBox::Show("���������� ������� �� ����������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
/// <summary>
/// ������� ������ ������� �������� �� ��� ��������
/// </summary>
/// <param name="val">�������� �������� ��� ������</param>
/// <returns name="">������ �������� � ���������� ���������</returns>
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
/// ������� ������ ����������� �������� � ���������
/// </summary>
/// <returns>�������� ����������� �������� ���������</returns>
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
	for (int i = 0; i < 301; i += 5)
	{
		push(i);
	}
}
/// <summary>
/// ��������� ���������� ������� ��������
/// </summary>
private: void stack_start(T val)
{
	Stack* temp = new Stack{ val, 0, nullptr };

	sHead = temp;
}
/// <summary>
/// ��������� ���������� ��������� � �������� > 0
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
/// ��������� ����������� ������������� ��������� ������ � ���������� ������
/// </summary>
/// <param name="a">��������� ������ myArray, ��������� ��� �����������</param>
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
					MessageBox::Show("� ��������� ������������ ��������, ������� ���������� ��������� � �������", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			i++;
		}
	}
}
/// <summary>
/// ������� ��������� ������� �������� �������� ���������� ������
/// </summary>
/// <returns>������ �������� ����� ���������� ������</returns>
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