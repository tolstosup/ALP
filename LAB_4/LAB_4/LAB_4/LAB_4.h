#pragma once
#include <vector>
#include <string>

#include "myArray.h"
#include "myVector.h"
#include "myQueue.h"
#include "myStack.h"

#include "ChangeByIndex.h"
#include "AddElement.h"

namespace LAB4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;

	myArray<int> arr;			// ��������� ���������� ������ myArray ��������� ������ Array, ������ ���� int
	myVector<int> vector;		// ��������� ���������� ������ myVector ��������� ������ Vector, ������ ���� int 
	myStack<int> stack;			// ��������� ���������� ������ myStack ��������� ������ Stack, ������ ���� int
	myQueue<int> queue;			// ��������� ���������� ������ myQueue ��������� ������ Queue, ������ ���� int

	myArray<char> c_arr;		// ��������� ���������� ������ myArray ��������� ������ Array, ������ ���� char
	myVector<char> c_vector;	// ��������� ���������� ������ myVector ��������� ������ Vector, ������ ���� char
	myStack<char> c_stack;		// ��������� ���������� ������ myStack ��������� ������ Stack, ������ ���� char
	myQueue<char> c_queue;		// ��������� ���������� ������ myQueue ��������� ������ Queue, ������ ���� char

	/// <summary>
	/// ������ ��� LAB_4
	/// </summary>
	public ref class LAB_4 : public System::Windows::Forms::Form
	{
	public:
		LAB_4(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			test_cases();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~LAB_4()
		{
			vector.clear();
			stack.clear();
			queue.clear();
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: String^ current_struct = ""; // ������ � ���� �������� ������� ��������� ������
	private: bool char_is_enable = false; // ������ ���������� � ������� ������ ����������
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ arrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vectorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ queueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ASCIIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ char_textBox;
	private: System::Windows::Forms::Label^ int_label;
	private: System::Windows::Forms::Label^ char_label;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LAB_4::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->queueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ASCIIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->char_textBox = (gcnew System::Windows::Forms::TextBox());
			this->int_label = (gcnew System::Windows::Forms::Label());
			this->char_label = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->���������ToolStripMenuItem,
					this->��������ToolStripMenuItem, this->������������ASCIIToolStripMenuItem, this->����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(1268, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->arrayToolStripMenuItem,
					this->vectorToolStripMenuItem, this->stackToolStripMenuItem, this->queueToolStripMenuItem
			});
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(75, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// arrayToolStripMenuItem
			// 
			this->arrayToolStripMenuItem->Name = L"arrayToolStripMenuItem";
			this->arrayToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->arrayToolStripMenuItem->Text = L"Array � ����������� ������";
			this->arrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::arrayToolStripMenuItem_Click);
			// 
			// vectorToolStripMenuItem
			// 
			this->vectorToolStripMenuItem->Name = L"vectorToolStripMenuItem";
			this->vectorToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->vectorToolStripMenuItem->Text = L"Vector � ������������ ������";
			this->vectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::vectorToolStripMenuItem_Click);
			// 
			// stackToolStripMenuItem
			// 
			this->stackToolStripMenuItem->Name = L"stackToolStripMenuItem";
			this->stackToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->stackToolStripMenuItem->Text = L"Stack � ����";
			this->stackToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::stackToolStripMenuItem_Click);
			// 
			// queueToolStripMenuItem
			// 
			this->queueToolStripMenuItem->Name = L"queueToolStripMenuItem";
			this->queueToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->queueToolStripMenuItem->Text = L"Queue � �������";
			this->queueToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::queueToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->��������������ToolStripMenuItem,
					this->���������������ToolStripMenuItem, this->��������������������������ToolStripMenuItem, this->�����������������������ToolStripMenuItem,
					this->����������������������ToolStripMenuItem, this->������������������������ToolStripMenuItem, this->�����������������ToolStripMenuItem,
					this->��������������ToolStripMenuItem
			});
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(75, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->��������������ToolStripMenuItem->Text = L"����� ���������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::��������������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->���������������ToolStripMenuItem->Text = L"�������� �������";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::���������������ToolStripMenuItem_Click);
			// 
			// ��������������������������ToolStripMenuItem
			// 
			this->��������������������������ToolStripMenuItem->Name = L"��������������������������ToolStripMenuItem";
			this->��������������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->��������������������������ToolStripMenuItem->Text = L"�������� ���������� ��������";
			this->��������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::��������������������������ToolStripMenuItem_Click);
			// 
			// �����������������������ToolStripMenuItem
			// 
			this->�����������������������ToolStripMenuItem->Name = L"�����������������������ToolStripMenuItem";
			this->�����������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->�����������������������ToolStripMenuItem->Text = L"������ �������� �� �������";
			this->�����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::�����������������������ToolStripMenuItem_Click);
			// 
			// ����������������������ToolStripMenuItem
			// 
			this->����������������������ToolStripMenuItem->Name = L"����������������������ToolStripMenuItem";
			this->����������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->����������������������ToolStripMenuItem->Text = L"����� ������� �� ��������";
			this->����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::����������������������ToolStripMenuItem_Click);
			// 
			// ������������������������ToolStripMenuItem
			// 
			this->������������������������ToolStripMenuItem->Name = L"������������������������ToolStripMenuItem";
			this->������������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->������������������������ToolStripMenuItem->Text = L"����� ����������� ��������";
			this->������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::������������������������ToolStripMenuItem_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->�����������������ToolStripMenuItem->Text = L"�������� ���������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::�����������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->��������������ToolStripMenuItem->Text = L"��������� ��������� ��������� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::��������������ToolStripMenuItem_Click);
			// 
			// ������������ASCIIToolStripMenuItem
			// 
			this->������������ASCIIToolStripMenuItem->Name = L"������������ASCIIToolStripMenuItem";
			this->������������ASCIIToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->������������ASCIIToolStripMenuItem->Text = L"����������� � �������";
			this->������������ASCIIToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::������������ASCIIToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(42, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::����ToolStripMenuItem_Click);
			// 
			// textBox
			// 
			this->textBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox->Location = System::Drawing::Point(0, 24);
			this->textBox->Margin = System::Windows::Forms::Padding(2);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox->Size = System::Drawing::Size(1268, 642);
			this->textBox->TabIndex = 1;
			// 
			// char_textBox
			// 
			this->char_textBox->Location = System::Drawing::Point(653, 21);
			this->char_textBox->Margin = System::Windows::Forms::Padding(2);
			this->char_textBox->Multiline = true;
			this->char_textBox->Name = L"char_textBox";
			this->char_textBox->ReadOnly = true;
			this->char_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->char_textBox->Size = System::Drawing::Size(614, 646);
			this->char_textBox->TabIndex = 2;
			this->char_textBox->Visible = false;
			// 
			// int_label
			// 
			this->int_label->AutoSize = true;
			this->int_label->Location = System::Drawing::Point(8, 26);
			this->int_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->int_label->Name = L"int_label";
			this->int_label->Size = System::Drawing::Size(167, 13);
			this->int_label->TabIndex = 3;
			this->int_label->Text = L"��������� � �������� �������";
			this->int_label->Visible = false;
			// 
			// char_label
			// 
			this->char_label->AutoSize = true;
			this->char_label->Location = System::Drawing::Point(661, 26);
			this->char_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->char_label->Name = L"char_label";
			this->char_label->Size = System::Drawing::Size(182, 13);
			this->char_label->TabIndex = 4;
			this->char_label->Text = L"��������� � ���������� �������";
			this->char_label->Visible = false;
			// 
			// LAB_4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1268, 666);
			this->Controls->Add(this->char_label);
			this->Controls->Add(this->int_label);
			this->Controls->Add(this->char_textBox);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(400, 200);
			this->Name = L"LAB_4";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LAB_4";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Resize += gcnew System::EventHandler(this, &LAB_4::LAB_4_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/// <summary>
	/// ������� ���������� ��������� �������� ���������� �������� ������� ��������� ������ 
	/// </summary>
	/// <returns>�������� �������� ��������������� ���������� ��������</returns>
	private: int struct_id()
	{
		if (current_struct == "Array") return 1;
		else if (current_struct == "Vector") return 2;
		else if (current_struct == "Stack") return 3;
		else if (current_struct == "Queue") return 4;
		else return -1;
	}
	//
	// ���������, ����������� �������� ��� ������� "����� ���������"
	//
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (current_struct != "")
		{
			switch (struct_id())
			{
			case 1: this->textBox->Text = gcnew String(arr.output().c_str()); break;
			case 2: this->textBox->Text = gcnew String(vector.output().c_str()); break;
			case 3: this->textBox->Text = gcnew String(stack.output().c_str()); break;
			case 4: this->textBox->Text = gcnew String(queue.output().c_str()); break;
			}
			to_char();
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "�������� �������"
	//
	private: System::Void ���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (current_struct != "")
		{
			AddElement^ ae = gcnew AddElement(char_is_enable);
			ae->ShowDialog(this);
			String^ sval = ae->get_value();

			if (!ae->canceled && sval != "")
			{
				int val = Convert::ToInt32(sval);
				switch (struct_id())
				{
				case 1:
				{
					arr.push(val);
					this->textBox->Text = gcnew String(arr.output().c_str());
					break;
				}
				case 2:
				{
					vector.push(val);
					this->textBox->Text = gcnew String(vector.output().c_str());
					break;
				}
				case 3:
				{
					stack.push(val);
					this->textBox->Text = gcnew String(stack.output().c_str());
					break;
				}
				case 4:
				{
					queue.push(val);
					this->textBox->Text = gcnew String(queue.output().c_str());
					break;
				}
				}
			}
			to_char();
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "�������� ���������� ��������"
	//
	private: System::Void ��������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (struct_id() != -1)
		{
			switch (struct_id())
			{
			case 1:
			{
				arr.pop();
				this->textBox->Text = gcnew String(arr.output().c_str());
				break;
			}
			case 2:
			{
				vector.pop();
				this->textBox->Text = gcnew String(vector.output().c_str());
				break;
			}
			case 3:
			{
				stack.pop();
				this->textBox->Text = gcnew String(stack.output().c_str());
				break;
			}
			case 4:
			{
				queue.pop(); 
				this->textBox->Text = gcnew String(queue.output().c_str());
				break;
			}
			}
			to_char();
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "������ �������� �� �������"
	//
	private: System::Void �����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (struct_id() != -1)
		{
			ChangeByIndex^ cbi = gcnew ChangeByIndex(char_is_enable);
			cbi->ShowDialog(this);

			if (cbi->get_val() != "")
			{
				if (!cbi->is_canceled())
				{
					int val = Convert::ToInt32(cbi->get_val());
					switch (struct_id())
					{
					case 1:
					{
						arr.change_by_index(Convert::ToInt32(cbi->get_index()), val);
						this->textBox->Text = gcnew String(arr.output().c_str());
						break;
					}
					case 2:
					{
						vector.change_by_index(Convert::ToInt32(cbi->get_index()), val);
						this->textBox->Text = gcnew String(vector.output().c_str());
						break;
					}
					case 3:
					{
						stack.change_by_index(Convert::ToInt32(cbi->get_index()), val);
						this->textBox->Text = gcnew String(stack.output().c_str());
						break;
					}
					case 4:
					{
						queue.change_by_index(Convert::ToInt32(cbi->get_index()), val); 
						this->textBox->Text = gcnew String(queue.output().c_str());
						break;
					}
					}
				}
				to_char();
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "����� ������� �� ��������"
	//
	private: System::Void ����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (struct_id() != -1)
		{
			int x = this->Left + (this->Width / 2) - 200;
			int y = this->Top + (this->Height / 2) - 100;
				if (!char_is_enable)
				{
					String^ find_value = Interaction::InputBox("������� ��������\r\n\r\n", "����� ������� �� ��������", "", x, y);
					if (find_value != "")
					{
						int value = Convert::ToInt32(find_value);
						int index = -1;
						switch (struct_id())
						{
						case 1: index = arr.find_index(value); break;
						case 2: index = vector.find_index(value); break;
						case 3: index = stack.find_index(value); break;
						case 4: index = queue.find_index(value); break;
						}
						MessageBox::Show("������ ���������� �������� � " + Convert::ToString(index), "����� ������", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
				}
				else
				{
					String^ find_value = Interaction::InputBox("������� ������\r\n\r\n", "����� ������� �� ��������", "", x, y);
					if (find_value != "")
					{
					int value = Convert::ToChar(find_value);
					int index = -1;
					switch (struct_id())
					{
					case 1: index = c_arr.find_index(value); break;
					case 2: index = c_vector.find_index(value); break;
					case 3: index = c_stack.find_index(value); break;
					case 4: index = c_queue.find_index(value); break;
					}
					MessageBox::Show("������ ���������� �������� � " + Convert::ToString(index), "����� ������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "����� ����������� ��������"
	//
	private: System::Void ������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (struct_id() != -1)
		{
			if (!char_is_enable)
			{
				int index = -1;
				switch (struct_id())
				{
				case 1: index = arr.find_max(); break;
				case 2: index = vector.find_max(); break;
				case 3: index = stack.find_max(); break;
				case 4: index = queue.find_max(); break;
				}
				MessageBox::Show("���������� �������� � " + Convert::ToString(index), "���������� ��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				int index = -1;
				switch (struct_id())
				{
				case 1: index = c_arr.find_max(); break;
				case 2: index = c_vector.find_max(); break;
				case 3: index = c_stack.find_max(); break;
				case 4: index = c_queue.find_max(); break;
				}
				MessageBox::Show("���������� �������� � " + Convert::ToString(Convert::ToChar(index)) + " (" + Convert::ToString(index) + ")", "���������� ��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "�������� ���������"
	//
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (struct_id() != -1)
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show("�� ������� ��� ������ �������� ���������?", "��������������", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				switch (struct_id())
				{
				case 1: arr.clear(); this->textBox->Text = gcnew String(arr.output().c_str()); break;
				case 2: vector.clear(); this->textBox->Text = gcnew String(vector.output().c_str()); break;
				case 3: stack.clear(); this->textBox->Text = gcnew String(stack.output().c_str()); break;
				case 4: queue.clear(); this->textBox->Text = gcnew String(queue.output().c_str()); break;
				}
				to_char();
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "�������� ������"
	//
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{	
		if (struct_id() != -1)
		{
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show("�������������� ��������� ����� �������. �� �������, ��� ������ ������ �������� ������?", "��������������", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				switch (struct_id())
				{
				case 1: arr.fill_test(); this->textBox->Text = gcnew String(arr.output().c_str()); break;
				case 2: vector.fill_test(); this->textBox->Text = gcnew String(vector.output().c_str()); break;
				case 3: stack.fill_test(); this->textBox->Text = gcnew String(stack.output().c_str()); break;
				case 4: queue.fill_test(); this->textBox->Text = gcnew String(queue.output().c_str()); break;
				}
				to_char();
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// ���������, ����������� �������� ��� ������� "Array"
	//
	private: System::Void arrayToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Array";
		if (this->Text == "LAB_4") this->Text += " � Array (����������� ������)";
		else this->Text = this->Text->Remove(8) + "Array (����������� ������)";
		this->textBox->Text = gcnew String(arr.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// ���������, ����������� �������� ��� ������� "Vector"
	//
	private: System::Void vectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Vector";
		if (this->Text == "LAB_4") this->Text += " � Vector (������������ ������)";
		else this->Text = this->Text->Remove(8) + "Vector (������������ ������)";
		this->textBox->Text = gcnew String(vector.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// ���������, ����������� �������� ��� ������� "Stack"
	//
	private: System::Void stackToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Stack";
		if (this->Text == "LAB_4") this->Text += " � Stack (����)";
		else this->Text = this->Text->Remove(8) + "Stack (����)";
		this->textBox->Text = gcnew String(stack.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// ���������, ����������� �������� ��� ������� "Queue"
	//
	private: System::Void queueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Queue";
		if (this->Text == "LAB_4") this->Text += " � Queue (�������)";
		else this->Text = this->Text->Remove(8) + "Queue (�������)";
		this->textBox->Text = gcnew String(queue.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// ��������� ����������� �������� ��������� � ���������� ������
	//
	private: void to_char()
	{
		if (char_is_enable)
		{
			this->textBox->Dock = System::Windows::Forms::DockStyle::None;
			this->textBox->Size = System::Drawing::Size(this->Width / 2 - 20, this->Height - 85);
			this->textBox->Location = System::Drawing::Point(10, 40);
			this->char_textBox->Size = System::Drawing::Size(this->Width / 2 - 25, this->Height - 85);
			this->char_textBox->Location = System::Drawing::Point(this->Width / 2, 40);
			this->char_textBox->Visible = true;
			char_is_enable = true;
			this->int_label->Visible = true;
			this->char_label->Location = System::Drawing::Point(this->Width / 2, 27);
			this->char_label->Visible = true;
			switch (struct_id())
			{
			case 1:
			{	
				c_arr.clear();
				c_arr.copy_to_char(arr);
				this->char_textBox->Text = gcnew String(c_arr.output_char().c_str());
			}; break;
			case 2:
			{
				c_vector.clear();
				c_vector.copy_to_char(vector.get_arr(), vector.get_size());
				this->char_textBox->Text = gcnew String(c_vector.output_char().c_str());
			}; break;
			case 3:
			{
				c_stack.clear();
				c_stack.copy_to_char(stack.get_values());
				this->char_textBox->Text = gcnew String(c_stack.output_char().c_str());
			}; break;
			case 4:
			{
				c_queue.clear();
				c_queue.copy_to_char(queue.get_values());
				this->char_textBox->Text = gcnew String(c_queue.output_char().c_str());
			}; break;
			}
		}
		else
		{
			switch (struct_id())
			{
			case 1: c_arr.clear(); break;
			case 2: c_vector.clear(); break;
			case 3: c_stack.clear(); break;
			case 4: c_queue.clear(); break;
			}
			this->char_textBox->Text = "";
			this->textBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox->Size = System::Drawing::Size(this->Width, 991);
			this->char_textBox->Size = System::Drawing::Size(this->Width / 2 - 10, 991);
			this->char_textBox->Location = System::Drawing::Point(this->Width / 2 - 10, 33);
			this->char_textBox->Visible = false;
			char_is_enable = false;
			this->int_label->Visible = false;
			this->char_label->Visible = false;
		}
	}
	//
	// ���������, ����������� �������� ��� ������� "����������� � �������"
	//
	private: System::Void ������������ASCIIToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (char_is_enable) char_is_enable = false;
		else char_is_enable = true;
		to_char();
	}
	/// <summary>
	/// ������� ������������ ����� �������� � ��������� ������ "Array"
	/// </summary>
	/// <returns>��������� ������������</returns>
	private: int test1()
	{
		myArray<int> test;
		test.push(1);
		String^ res = gcnew String(test.output().c_str());
		if (res == "[0] = 1;\r\n")
		{
			test.clear();
			return 0;
		}
		else
		{
			test.clear();
			return 1;
		}
	}
	/// <summary>
	/// ������� ������������ ����� �������� � ��������� ������ "Vector"
	/// </summary>
	/// <returns>��������� ������������</returns>
	private: int test2()
	{
		myVector<int> test;
		test.push(1);
		String^ res = gcnew String(test.output().c_str());
		if (res == "[0] = 1;\r\n")
		{
			test.clear();
			return 0;
		}
		else
		{
			test.clear();
			return 1;
		}
	}
	/// <summary>
	/// ������� ������������ ����� �������� � ��������� ������ "Stack"
	/// </summary>
	/// <returns>��������� ������������</returns>
	private: int test3()
	{
		myStack<int> test;
		test.push(1);
		String^ res = gcnew String(test.output().c_str());
		if (res == "[0] = 1;\r\n")
		{
			test.clear();
			return 0;
		}
		else
		{
			test.clear();
			return 1;
		}
	}
	/// <summary>
	/// ������� ������������ ����� �������� � ��������� ������ "Queue"
	/// </summary>
	/// <returns>��������� ������������</returns>
	private: int test4()
	{
		myQueue<int> test;
		test.push(1);
		String^ res = gcnew String(test.output().c_str());
		if (res == "[0] = 1;\r\n")
		{
			test.clear();
			return 0;
		}
		else
		{
			test.clear();
			return 1;
		}
	}
	/// <summary>
	/// ������� ������������ ����� �������� � ��������� ������
	/// </summary>
	/// <returns>��������� ������������</returns>
	private: int test_cases()
	{
		int result = test1() + test2() + test3() + test4();
		if (result != 0)
		{
			MessageBox::Show("����� �� ��������. �������� ������� �������� �����������. ���������� ����� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
		return result;
	}
	//
	// ���������, ����������� �������� ��� ������� ������ "����"
	//
	private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if(test_cases() == 0) 
			MessageBox::Show("����� ��������. �������� ������� �������� ���������.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//
	//  ���������, ����������� �������� ��� ��������� ������� ����
	//
	private: System::Void LAB_4_Resize(System::Object^ sender, System::EventArgs^ e) 
	{
		if (char_is_enable)
		{
			this->textBox->Size = System::Drawing::Size(this->Width / 2 - 20, this->Height - 85);
			this->textBox->Location = System::Drawing::Point(10, 40);
			this->char_textBox->Size = System::Drawing::Size(this->Width / 2 - 25, this->Height - 85);
			this->char_textBox->Location = System::Drawing::Point(this->Width / 2, 40);
			this->char_label->Location = System::Drawing::Point(this->Width / 2, 27);
		}
	}
};
}
