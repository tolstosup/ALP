#pragma once
#include "type.h"

namespace LAB6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AddElement
	/// </summary>
	public ref class AddElement : public System::Windows::Forms::Form
	{
	public:
		AddElement(type t)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			this->type_id = t;
			//if () this->label1->Text = "������� ������:";
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AddElement()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int type_id;
	public: bool canceled;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(187, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(252, 26);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AddElement::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"������� ��������:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(332, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"��������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddElement::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(220, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 35);
			this->button2->TabIndex = 3;
			this->button2->Text = L"������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddElement::button2_Click);
			// 
			// AddElement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 129);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddElement";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������� �������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//
		// ���������, ����������� �������� ��� ������� ������ "��������"
		//
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->textBox1->Text != "")
		{
			if (check())
			{
				this->canceled = false;
				this->Close();
			}
		}
		else MessageBox::Show("�������� ��� ������ �������� �� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // ���������, ����������� �������� ��� ������� ������ "������"
		   //
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->canceled = true;
		this->Close();
	}
		   //
		   // ���������, ����������� �������� ��� ��������� ������ � textBox1
		   //
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		check();
	}
		   //
		   // ������� �������� ������������ �����
		   // ���� void
		   // ����� bool
		   //
	private: bool check()
	{
		if(type_id == char_type)
		{
			if (this->textBox1->Text != "" && (this->textBox1->Text->Length > 1 || !(this->textBox1->Text[0] > 0 && this->textBox1->Text[0] < 255)))
			{
				MessageBox::Show("������� ��������� �������� ��� ������ �����������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			return true;
		}
		else if (type_id == int_type)
		{
			String^ str = this->textBox1->Text;
			int res = 0;
			if (str != "")
			{
				bool check = int::TryParse(str, res);
				if (!check)
				{
					MessageBox::Show("������������ ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->textBox1->Text = this->textBox1->Text->Remove(str->Length - 1, 1);
					return false;
				}
			}
			return true;
		}
		else if (type_id == double_type)
		{
			String^ str = this->textBox1->Text;
			double res = 0.0;
			if (str != "")
			{
				bool check = Double::TryParse(str, res);
				if (!check)
				{
					MessageBox::Show("������������ ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->textBox1->Text = this->textBox1->Text->Remove(str->Length - 1, 1);
					return false;
				}
			}
			return true;
		}
	}
		   //
		   // ������� ��������� �������� �� ���� �����
		   // ���� void
		   // ����� System::String^
		   //
	public: System::String^ get_value()
	{
		if(type_id == int_type)
			return this->textBox1->Text;
		else if (type_id == char_type)
			return Convert::ToString(Convert::ToInt32(Convert::ToChar(this->textBox1->Text)));
		else if(type_id == double_type)
			return this->textBox1->Text;
	}
	};
}