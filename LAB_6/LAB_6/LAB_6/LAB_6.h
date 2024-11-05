#pragma once
#include <vector>
#include <string>

#include "templateStack.h"
#include "type.h"

#include "ChangeByIndex.h"
#include "AddElement.h"

namespace LAB6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::VisualBasic;

	
	templateStack<int> int_stack(int_type);			
	templateStack<char> char_stack(char_type);
	templateStack<double> double_stack(double_type);

	/// <summary>
	/// ������ ��� LAB_6
	/// </summary>
	public ref class LAB_6 : public System::Windows::Forms::Form
	{
	public:
		LAB_6(void)
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
		~LAB_6()
		{
			int_stack.clear();
			char_stack.clear();
			double_stack.clear();
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: String^ current_type = ""; // ������ � ���� �������� ������� ��������� ������
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ arrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vectorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LAB_6::typeid));
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->arrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->vectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->stackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->��������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->�����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->textBox = (gcnew System::Windows::Forms::TextBox());
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->���������ToolStripMenuItem,
					   this->��������ToolStripMenuItem, this->����������������������ToolStripMenuItem, this->����ToolStripMenuItem
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
			   this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->arrayToolStripMenuItem,
					   this->vectorToolStripMenuItem, this->stackToolStripMenuItem
			   });
			   this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			   this->���������ToolStripMenuItem->Size = System::Drawing::Size(83, 22);
			   this->���������ToolStripMenuItem->Text = L"��� ������";
			   // 
			   // arrayToolStripMenuItem
			   // 
			   this->arrayToolStripMenuItem->Name = L"arrayToolStripMenuItem";
			   this->arrayToolStripMenuItem->Size = System::Drawing::Size(250, 22);
			   this->arrayToolStripMenuItem->Text = L"unsigned int � �������������";
			   this->arrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::arrayToolStripMenuItem_Click);
			   // 
			   // vectorToolStripMenuItem
			   // 
			   this->vectorToolStripMenuItem->Name = L"vectorToolStripMenuItem";
			   this->vectorToolStripMenuItem->Size = System::Drawing::Size(250, 22);
			   this->vectorToolStripMenuItem->Text = L"char � ����������";
			   this->vectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::vectorToolStripMenuItem_Click);
			   // 
			   // stackToolStripMenuItem
			   // 
			   this->stackToolStripMenuItem->Name = L"stackToolStripMenuItem";
			   this->stackToolStripMenuItem->Size = System::Drawing::Size(250, 22);
			   this->stackToolStripMenuItem->Text = L"double � ������������";
			   this->stackToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::stackToolStripMenuItem_Click);
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
			   this->��������ToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			   this->��������ToolStripMenuItem->Text = L"��������������";
			   // 
			   // ��������������ToolStripMenuItem
			   // 
			   this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			   this->��������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->��������������ToolStripMenuItem->Text = L"����� ���������";
			   this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::��������������ToolStripMenuItem_Click);
			   // 
			   // ���������������ToolStripMenuItem
			   // 
			   this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			   this->���������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->���������������ToolStripMenuItem->Text = L"�������� �������";
			   this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::���������������ToolStripMenuItem_Click);
			   // 
			   // ��������������������������ToolStripMenuItem
			   // 
			   this->��������������������������ToolStripMenuItem->Name = L"��������������������������ToolStripMenuItem";
			   this->��������������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->��������������������������ToolStripMenuItem->Text = L"�������� ���������� ��������";
			   this->��������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::��������������������������ToolStripMenuItem_Click);
			   // 
			   // �����������������������ToolStripMenuItem
			   // 
			   this->�����������������������ToolStripMenuItem->Name = L"�����������������������ToolStripMenuItem";
			   this->�����������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->�����������������������ToolStripMenuItem->Text = L"������ �������� �� �������";
			   this->�����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::�����������������������ToolStripMenuItem_Click);
			   // 
			   // ����������������������ToolStripMenuItem
			   // 
			   this->����������������������ToolStripMenuItem->Name = L"����������������������ToolStripMenuItem";
			   this->����������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->����������������������ToolStripMenuItem->Text = L"����� ������� �� ��������";
			   this->����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::����������������������ToolStripMenuItem_Click);
			   // 
			   // ������������������������ToolStripMenuItem
			   // 
			   this->������������������������ToolStripMenuItem->Name = L"������������������������ToolStripMenuItem";
			   this->������������������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->������������������������ToolStripMenuItem->Text = L"����� ����������� ��������";
			   this->������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::������������������������ToolStripMenuItem_Click);
			   // 
			   // �����������������ToolStripMenuItem
			   // 
			   this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			   this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->�����������������ToolStripMenuItem->Text = L"�������� ���������";
			   this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::�����������������ToolStripMenuItem_Click);
			   // 
			   // ��������������ToolStripMenuItem
			   // 
			   this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			   this->��������������ToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->��������������ToolStripMenuItem->Text = L"��������� ��������� ��������� �������";
			   this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::��������������ToolStripMenuItem_Click);
			   // 
			   // ����������������������ToolStripMenuItem
			   // 
			   this->����������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->��������������ToolStripMenuItem,
					   this->�����������������ToolStripMenuItem, this->���������������������ToolStripMenuItem, this->����������������ToolStripMenuItem
			   });
			   this->����������������������ToolStripMenuItem->Name = L"����������������������ToolStripMenuItem";
			   this->����������������������ToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			   this->����������������������ToolStripMenuItem->Text = L"�������������� ��������";
			   // 
			   // ��������������ToolStripMenuItem
			   // 
			   this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			   this->��������������ToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->��������������ToolStripMenuItem->Text = L"����� ���������";
			   this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::��������������ToolStripMenuItem_Click);
			   // 
			   // �����������������ToolStripMenuItem
			   // 
			   this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			   this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->�����������������ToolStripMenuItem->Text = L"�������� ���������";
			   this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::�����������������ToolStripMenuItem_Click);
			   // 
			   // ���������������������ToolStripMenuItem
			   // 
			   this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			   this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->���������������������ToolStripMenuItem->Text = L"������������ ���������";
			   this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::���������������������ToolStripMenuItem_Click);
			   // 
			   // ����������������ToolStripMenuItem
			   // 
			   this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			   this->����������������ToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->����������������ToolStripMenuItem->Text = L"������� ���������";
			   this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::����������������ToolStripMenuItem_Click);
			   // 
			   // ����ToolStripMenuItem
			   // 
			   this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			   this->����ToolStripMenuItem->Size = System::Drawing::Size(42, 22);
			   this->����ToolStripMenuItem->Text = L"����";
			   this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::����ToolStripMenuItem_Click);
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
			   // LAB_6
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->ClientSize = System::Drawing::Size(1268, 666);
			   this->Controls->Add(this->textBox);
			   this->Controls->Add(this->menuStrip1);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MainMenuStrip = this->menuStrip1;
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->MinimumSize = System::Drawing::Size(400, 200);
			   this->Name = L"LAB_6";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"LAB_6";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
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
	private: type type_id()
	{
		if (current_type == "int") return int_type;
		else if (current_type == "char") return char_type;
		else if (current_type == "double") return double_type;
		else return none;
	}
		   //
		   // ���������, ����������� �������� ��� ������� "����� ���������"
		   //
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (current_type != "")
		{
			switch (type_id())
			{
			case 1: this->textBox->Text = gcnew String(int_stack.output().c_str()); break;
			case 2: this->textBox->Text = gcnew String(char_stack.output().c_str()); break;
			case 3: this->textBox->Text = gcnew String(double_stack.output().c_str()); break;
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "�������� �������"
		   //
	private: System::Void ���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (current_type != "")
		{
			AddElement^ ae = gcnew AddElement(type_id());
			ae->ShowDialog(this);
			String^ sval = ae->get_value();

			if (!ae->canceled && sval != "")
			{
				switch (type_id())
				{
				case 1:
				{
					int_stack.push(Convert::ToInt32(sval));
					this->textBox->Text = gcnew String(int_stack.output().c_str());
					break;
				}
				case 2:
				{
					char_stack.push(Convert::ToChar(sval));
					this->textBox->Text = gcnew String(char_stack.output().c_str());
					break;
				}
				case 3:
				{
					double_stack.push(Convert::ToDouble(sval));
					this->textBox->Text = gcnew String(double_stack.output().c_str());
					break;
				}
				}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "�������� ���������� ��������"
		   //
	private: System::Void ��������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				int_stack.pop();
				this->textBox->Text = gcnew String(int_stack.output().c_str());
				break;
			}
			case 2:
			{
				char_stack.pop();
				this->textBox->Text = gcnew String(char_stack.output().c_str());
				break;
			}
			case 3:
			{
				double_stack.pop();
				this->textBox->Text = gcnew String(double_stack.output().c_str());
				break;
			}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "������ �������� �� �������"
		   //
	private: System::Void �����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (type_id() != none)
		{
			ChangeByIndex^ cbi = gcnew ChangeByIndex(type_id());
			cbi->ShowDialog(this);

			if (cbi->get_value() != "")
			{
				if (!cbi->is_canceled())
				{
					switch (type_id())
					{
					case 1:
					{
						int_stack.change_by_index(Convert::ToInt32(cbi->get_index()), Convert::ToInt32(cbi->get_value()));
						this->textBox->Text = gcnew String(int_stack.output().c_str());
						break;
					}
					case 2:
					{
						char_stack.change_by_index(Convert::ToInt32(cbi->get_index()), Convert::ToChar(cbi->get_value()));
						this->textBox->Text = gcnew String(char_stack.output().c_str());
						break;
					}
					case 3:
					{
						double_stack.change_by_index(Convert::ToInt32(cbi->get_index()), Convert::ToDouble(cbi->get_value()));
						this->textBox->Text = gcnew String(double_stack.output().c_str());
						break;
					}
					}
				}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "����� ������� �� ��������"
		   //
	private: System::Void ����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (type_id() != none)
		{
			int x = this->Left + (this->Width / 2) - 200;
			int y = this->Top + (this->Height / 2) - 100;
			String^ find_value = Interaction::InputBox("������� ��������\r\n\r\n", "����� ������� �� ��������", "", x, y);
			if (find_value != "")
			{
				int index = none;
				switch (type_id())
				{
				case 1: index = int_stack.find_index(Convert::ToInt32(find_value)); break;
				case 2: index = char_stack.find_index(Convert::ToChar(find_value)); break;
				case 3: index = double_stack.find_index(Convert::ToDouble(find_value)); break;
				}
				MessageBox::Show("������ ���������� �������� � " + Convert::ToString(index), "����� ������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "����� ����������� ��������"
		   //
	private: System::Void ������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				int maxi = 0;
				maxi = int_stack.find_max();
				MessageBox::Show("���������� �������� � " + Convert::ToString(maxi), "���������� ��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				char maxc = char_stack.find_max();
				MessageBox::Show("���������� �������� � " + Convert::ToString(maxc) + " (" + Convert::ToChar(maxc) + ")", "���������� ��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				double maxd = double_stack.find_max();
				MessageBox::Show("���������� �������� � " + Convert::ToString(maxd), "���������� ��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
			}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//
		// ���������, ����������� �������� ��� ������� "�������� ���������"
		//
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (type_id() != none)
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show("�� ������� ��� ������ �������� ���������?", "��������������", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				switch (type_id())
				{
				case 1: int_stack.clear(); this->textBox->Text = gcnew String(int_stack.output().c_str()); break;
				case 2: char_stack.clear(); this->textBox->Text = gcnew String(char_stack.output().c_str()); break;
				case 3: double_stack.clear(); this->textBox->Text = gcnew String(double_stack.output().c_str()); break;
				}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "�������� ������"
		   //
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (type_id() != none)
		{
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show("�������������� ��������� ����� �������. �� �������, ��� ������ ������ �������� ������?", "��������������", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				switch (type_id())
				{
				case 1: int_stack.fill_test(); this->textBox->Text = gcnew String(int_stack.output().c_str()); break;
				case 2: char_stack.fill_test(); this->textBox->Text = gcnew String(char_stack.output().c_str()); break;
				case 3: double_stack.fill_test(); this->textBox->Text = gcnew String(double_stack.output().c_str()); break;
				}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void ��������������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("����� ��������� �������������� ����� � " + Convert::ToString(int_stack.sum()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				String^ str = gcnew String(char_stack.sum_of_char().c_str());
				MessageBox::Show("����� ��������� ����������� ����� � " + str, "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("����� ��������� ������������� ����� � " + Convert::ToString(double_stack.sum()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void �����������������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{

		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("�������� ��������� �������������� ����� � " + Convert::ToString(int_stack.difference()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				MessageBox::Show("�������� ��������� ����������� ����� � \"\"", "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("�������� ��������� ������������� ����� � " + Convert::ToString(double_stack.difference()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void ���������������������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{

		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("������������ ��������� �������������� ����� � " + Convert::ToString(int_stack.product()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				MessageBox::Show("������������ ��������� ����������� ����� � \"\"", "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("������������ ��������� ������������� ����� � " + Convert::ToString(double_stack.product()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void ����������������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{

		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("������� ��������� �������������� ����� � " + Convert::ToString(int_stack.quotient()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				MessageBox::Show("������� ��������� ����������� ����� � ", "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("������� ��������� ������������� ����� � " + Convert::ToString(double_stack.quotient()), "����� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("��������� ������ �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� "int"
		   //
	private: System::Void arrayToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->current_type = "int";
		if (this->Text == "LAB_6") this->Text += " � int (�������������)";
		else this->Text = this->Text->Remove(8) + "int (�������������)";
		this->textBox->Text = gcnew String(int_stack.output().c_str());
	}
		   //
		   // ���������, ����������� �������� ��� ������� "char"
		   //
	private: System::Void vectorToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->current_type = "char";
		if (this->Text == "LAB_6") this->Text += " � char (����������)";
		else this->Text = this->Text->Remove(8) + "char (����������)";
		this->textBox->Text = gcnew String(char_stack.output().c_str());
	}
		   //
		   // ���������, ����������� �������� ��� ������� "double"
		   //
	private: System::Void stackToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->current_type = "double";
		if (this->Text == "LAB_6") this->Text += " � double (������������)";
		else this->Text = this->Text->Remove(8) + "double (������������)";
		this->textBox->Text = gcnew String(double_stack.output().c_str());
	}
		   /// <summary>
		   /// ������� ������������ ����� �������� � ��������� ������ "Array"
		   /// </summary>
		   /// <returns>��������� ������������</returns>
	private: int test1()
	{
		templateStack<int> test(int_type);
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
		templateStack<char> test(char_type);
		test.push(1);
		String^ res = gcnew String(test.output().c_str());
		if (res == "[0] = \u0001;\r\n")
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
		templateStack<double> test(double_type);
		test.push(1);
		String^ res = gcnew String(test.output().c_str());
		if (res == "[0] = 1.000000;\r\n")
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
		int result = test1() + test2() + test3();
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
	private: System::Void ����ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (test_cases() == 0)
			MessageBox::Show("����� ��������. �������� ������� �������� ���������.", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
	};
