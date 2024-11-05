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

private: Queue* qHead; // ��������� �� ��������� ������ Queue
//
// ����������� ������ myQueue
//
public: myQueue()
{
	qHead = nullptr;
}
//
// ���������� ������ myQueue
//
public: ~myQueue()
{
	clear();
}
/// <summary>
/// ������� ������ ��������� ������ � ������������� �������
/// </summary>
/// <returns>������ std::string</returns>
public: std::string output()
{
	std::string queue = "";
	if (qHead == nullptr) return "������� �����";
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
/// ������� ������ ��������� ������ � ���������� �������
/// </summary>
/// <returns>������ std::string</returns>
public: std::string output_char()
{
	std::string queue = "";
	if (qHead == nullptr) return "������� ����";
	else
	{
		Queue* curr = qHead;
		while (curr != nullptr)
		{
			if (curr->value == char(0))
				queue += "[" + std::to_string(curr->index) + "] = " + "������ ��������" + ";\r\n";
			else
				queue += "[" + std::to_string(curr->index) + "] = " + (char(curr->value)) + ";\r\n";
			curr = curr->next;
		}
		return queue;
	}
}
/// <summary>
/// ��������� ���������� ������ �������� � ������
/// </summary>
/// <param name="val">�������� ������ ��������</param>
public:	void push(T val)
{
	if (qHead == nullptr) queue_start(val);
	else add_element(val);
}
/// <summary>
/// ��������� �������� ���������� ��������
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
/// ��������� ��������� �������� �������� �� ��� �������
/// </summary>
/// <param name="index">������ �������� ��� ���������</param>
/// <param name="new_val">����� �������� ��������</param>
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
		MessageBox::Show("���������� ������� �� ����������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
/// <summary>
/// ������� ������ ������� �������� �� ��� ��������
/// </summary>
/// <param name="val">�������� �������� ��� ������</param>
/// <returns name="">������ �������� � ���������� ���������</returns>
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
/// ������� ������ ����������� �������� � ���������
/// </summary>
/// <returns>�������� ����������� �������� ���������</returns>
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
/// ��������� ������� ��������� ������
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
private: void queue_start(T val)
{
	Queue* temp = new Queue{ val, 0, nullptr };
	qHead = temp;
}
/// <summary>
/// ��������� ���������� ��������� � �������� > 0
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
/// ��������� ���������� ��������� � ���������
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
/// ��������� ����������� ������������� ��������� ������ � ���������� ������
/// </summary>
/// <param name="a">��������� ������ myQueue (��������� ��� �����������)</param>
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