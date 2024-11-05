/*

АЯиП Лабораторная работа #5
Заголовочный файл проекта DBROM
Михайлов Роман, группа 3091, 1 курс
01.04.2024 - 17.04.2024

*/

#pragma once
namespace DBROM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NewRecord
	/// </summary>
	public ref class NewRecord : public System::Windows::Forms::Form
	{
	public:
		NewRecord(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewRecord()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(153, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(301, 26);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &NewRecord::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(310, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewRecord::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(153, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(301, 26);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(153, 108);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(301, 26);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(153, 148);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(301, 26);
			this->textBox4->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(143, 240);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 40);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NewRecord::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Название";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Описание";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Статус";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 148);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(130, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Ответственный";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(18, 188);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 20);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Срок сдачи";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(154, 188);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(301, 26);
			this->dateTimePicker1->TabIndex = 12;
			// 
			// NewRecord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(467, 299);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"NewRecord";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Добавить новую запись";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	// Процедура проверки корректности введённой даты
	//
	//private: bool check_date()
	//{
	//	if (this->textBox5->Text->Length > 9)
	//	{
	//		DateTime date;
	//		if (DateTime::TryParse(this->textBox5->Text, date)) 
	//		{
	//			if (Convert::ToInt32(this->textBox5->Text->Substring(6)) > 2023 && Convert::ToInt32(this->textBox5->Text->Substring(6)) < 10000) { return true; }
	//			else
	//			{
	//				MessageBox::Show("Заполните поле срока сдачи корректно. Ограничение ввода года - от 2024 до 9999 ", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	//				return false;
	//			}
	//		}
	//		else
	//		{
	//			MessageBox::Show("Заполните поле срока сдачи корректно", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	//			return false;
	//		}
	//	}
	//	return true;
	//}
	//
	// Процедура запускающая действия при нажатии "Добавить"
	//
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (get_label() != "" || get_description() != "" || get_status() != "" || get_admin() != "") { this->Close(); }
		else MessageBox::Show("Заполните все поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Функция получения данных из поля "Название"
	//
	public: String^ get_label()
	{
		return this->textBox1->Text;
	}
	//
	// Функция получения данных из поля "Описание"
	//
	public: String^ get_description()
	{
		return this->textBox2->Text;
	}
	//
	// Функция получения данных из поля "Статус"
	//
	public: String^ get_status()
	{
		return this->textBox3->Text;
	}
	//
	// Функция получения данных из поля "Ответственный"
	//
	public: String^ get_admin()
	{
		return this->textBox4->Text;
	}
	//
	// Функция получения данных из поля "Срок сдачи"
	//
	public: DateTime^ get_deadline()
	{
		return this->dateTimePicker1->Value;
	}
	//
	// Процедура запускающая действия при нажатии "Отмена"
	//
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	//
	// Процедура проверки поля "Название"
	//
	private: void check_lenght1()
	{
		if (this->textBox1->Text->Length > 200)
		{
			MessageBox::Show("Слишком длинный текст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = this->textBox1->Text->Remove(200);
		}
	}
	//
	// Процедура проверки поля "Описание"
	//
	private: void check_lenght2()
	{
		if (this->textBox2->Text->Length > 200)
		{
			MessageBox::Show("Слишком длинный текст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox2->Text = this->textBox2->Text->Remove(200);
		}
	}
	//
	// Процедура проверки поля "Статус"
	//
	private: void check_lenght3()
	{
		if (this->textBox3->Text->Length > 200)
		{
			MessageBox::Show("Слишком длинный текст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox3->Text = this->textBox3->Text->Remove(200);
		}
	}
	//
	// Процедура проверки поля "Ответственный"
	//
	private: void check_lenght4()
	{
		if (this->textBox4->Text->Length > 200)
		{
			MessageBox::Show("Слишком длинный текст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox4->Text = this->textBox4->Text->Remove(200);
		}
	}
	//
	// Процедура запускающая действия при изменении данных в поле "Название"
	//
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		check_lenght1();
	}
	//
	// Процедура запускающая действия при изменении данных в поле "Описание"
	//
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		check_lenght2();
	}
	//
	// Процедура запускающая действия при изменении данных в поле "Статус"
	//
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		check_lenght3();
	}
	//
	// Процедура запускающая действия при изменении данных в поле "Ответственный"
	//
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		check_lenght4();
	}
};
}