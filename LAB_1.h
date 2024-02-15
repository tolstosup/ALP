#pragma once

namespace LAB_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для LAB_1
	/// </summary>
	public ref class LAB_1 : public System::Windows::Forms::Form
	{
	public:
		LAB_1(void)
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
		~LAB_1()
		{
			if (components)
			{
				delete components;
			}
		}
	// Пользовательсике поля
	private: bool choise;
	private: bool input_blocker = true;
	private: int n;
	private: int n_dop;
	private: bool test_bool = false;
	private: int q = 0;
	private: int index = 0;
	private: bool clear_bool = false;
	private: bool dop_bool = false;
	private: int i = 0;
	private: array<Int32>^ arr = gcnew array<Int32>(100);
	//
	private: System::Windows::Forms::Button^ info_btn;
	private: System::Windows::Forms::Label^ input_label;
	private: System::Windows::Forms::TextBox^ input_textBox;
	private: System::Windows::Forms::Label^ choise_label;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RadioButton^ radio_button_2;
	private: System::Windows::Forms::RadioButton^ radio_button_1;
	private: System::Windows::Forms::Button^ run_btn;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ output_label;
	private: System::Windows::Forms::Label^ label1_output;
	private: System::Windows::Forms::Label^ call_quantity_label;
	private: System::Windows::Forms::Label^ call_quantity_output;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ dop_input;
	private: System::Windows::Forms::TextBox^ dop_output;
	private: System::Windows::Forms::Button^ dop_clear_btn;
	private: System::Windows::Forms::Button^ dop_info_btn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ dop_run_btn;
	private: System::Windows::Forms::Button^ test_btn;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->info_btn = (gcnew System::Windows::Forms::Button());
			this->input_label = (gcnew System::Windows::Forms::Label());
			this->input_textBox = (gcnew System::Windows::Forms::TextBox());
			this->choise_label = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->radio_button_2 = (gcnew System::Windows::Forms::RadioButton());
			this->radio_button_1 = (gcnew System::Windows::Forms::RadioButton());
			this->run_btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->output_label = (gcnew System::Windows::Forms::Label());
			this->label1_output = (gcnew System::Windows::Forms::Label());
			this->call_quantity_label = (gcnew System::Windows::Forms::Label());
			this->call_quantity_output = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dop_input = (gcnew System::Windows::Forms::TextBox());
			this->dop_output = (gcnew System::Windows::Forms::TextBox());
			this->dop_clear_btn = (gcnew System::Windows::Forms::Button());
			this->dop_info_btn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dop_run_btn = (gcnew System::Windows::Forms::Button());
			this->test_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// info_btn
			// 
			this->info_btn->Location = System::Drawing::Point(12, 62);
			this->info_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->info_btn->Name = L"info_btn";
			this->info_btn->Size = System::Drawing::Size(225, 41);
			this->info_btn->TabIndex = 0;
			this->info_btn->Text = L"Информация";
			this->info_btn->UseVisualStyleBackColor = true;
			this->info_btn->Click += gcnew System::EventHandler(this, &LAB_1::info_btn_Click);
			// 
			// input_label
			// 
			this->input_label->AutoSize = true;
			this->input_label->Location = System::Drawing::Point(14, 25);
			this->input_label->Name = L"input_label";
			this->input_label->Size = System::Drawing::Size(104, 20);
			this->input_label->TabIndex = 1;
			this->input_label->Text = L"Поле ввода:";
			// 
			// input_textBox
			// 
			this->input_textBox->Location = System::Drawing::Point(123, 22);
			this->input_textBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->input_textBox->Name = L"input_textBox";
			this->input_textBox->Size = System::Drawing::Size(110, 26);
			this->input_textBox->TabIndex = 2;
			this->input_textBox->TextChanged += gcnew System::EventHandler(this, &LAB_1::input_textBox_TextChanged);
			// 
			// choise_label
			// 
			this->choise_label->AutoSize = true;
			this->choise_label->Location = System::Drawing::Point(248, 24);
			this->choise_label->Name = L"choise_label";
			this->choise_label->Size = System::Drawing::Size(134, 20);
			this->choise_label->TabIndex = 3;
			this->choise_label->Text = L"Выбор рекурсии:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(251, 62);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 41);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Очистить поля";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LAB_1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(18, 118);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(594, 86);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"Здесь будет формула выбранной рекурсивной функции";
			// 
			// radio_button_2
			// 
			this->radio_button_2->AutoSize = true;
			this->radio_button_2->Location = System::Drawing::Point(443, 25);
			this->radio_button_2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radio_button_2->Name = L"radio_button_2";
			this->radio_button_2->Size = System::Drawing::Size(43, 24);
			this->radio_button_2->TabIndex = 9;
			this->radio_button_2->TabStop = true;
			this->radio_button_2->Text = L"2";
			this->radio_button_2->UseVisualStyleBackColor = true;
			this->radio_button_2->CheckedChanged += gcnew System::EventHandler(this, &LAB_1::radioButton2_activity);
			// 
			// radio_button_1
			// 
			this->radio_button_1->AutoSize = true;
			this->radio_button_1->Location = System::Drawing::Point(389, 25);
			this->radio_button_1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radio_button_1->Name = L"radio_button_1";
			this->radio_button_1->Size = System::Drawing::Size(43, 24);
			this->radio_button_1->TabIndex = 8;
			this->radio_button_1->TabStop = true;
			this->radio_button_1->Text = L"1";
			this->radio_button_1->UseVisualStyleBackColor = true;
			this->radio_button_1->CheckedChanged += gcnew System::EventHandler(this, &LAB_1::radioButton1_activity);
			// 
			// run_btn
			// 
			this->run_btn->Location = System::Drawing::Point(503, 22);
			this->run_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->run_btn->Name = L"run_btn";
			this->run_btn->Size = System::Drawing::Size(109, 81);
			this->run_btn->TabIndex = 12;
			this->run_btn->Text = L"Запуск";
			this->run_btn->UseVisualStyleBackColor = true;
			this->run_btn->Click += gcnew System::EventHandler(this, &LAB_1::run_btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(-7, 229);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(636, 46);
			this->label1->TabIndex = 17;
			this->label1->Text = L"____________________________";
			// 
			// output_label
			// 
			this->output_label->AutoSize = true;
			this->output_label->Location = System::Drawing::Point(76, 206);
			this->output_label->Name = L"output_label";
			this->output_label->Size = System::Drawing::Size(0, 20);
			this->output_label->TabIndex = 13;
			// 
			// label1_output
			// 
			this->label1_output->AutoSize = true;
			this->label1_output->Location = System::Drawing::Point(11, 206);
			this->label1_output->Name = L"label1_output";
			this->label1_output->Size = System::Drawing::Size(64, 20);
			this->label1_output->TabIndex = 14;
			this->label1_output->Text = L"Вывод:";
			// 
			// call_quantity_label
			// 
			this->call_quantity_label->AutoSize = true;
			this->call_quantity_label->Location = System::Drawing::Point(11, 238);
			this->call_quantity_label->Name = L"call_quantity_label";
			this->call_quantity_label->Size = System::Drawing::Size(341, 20);
			this->call_quantity_label->TabIndex = 15;
			this->call_quantity_label->Text = L"Количество вызовов рекурсивной функции:";
			// 
			// call_quantity_output
			// 
			this->call_quantity_output->AutoSize = true;
			this->call_quantity_output->Location = System::Drawing::Point(355, 238);
			this->call_quantity_output->Name = L"call_quantity_output";
			this->call_quantity_output->Size = System::Drawing::Size(0, 20);
			this->call_quantity_output->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 294);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(284, 25);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Дополнительная программа";
			// 
			// dop_input
			// 
			this->dop_input->Location = System::Drawing::Point(338, 323);
			this->dop_input->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dop_input->Multiline = true;
			this->dop_input->Name = L"dop_input";
			this->dop_input->ReadOnly = true;
			this->dop_input->Size = System::Drawing::Size(105, 135);
			this->dop_input->TabIndex = 19;
			// 
			// dop_output
			// 
			this->dop_output->Location = System::Drawing::Point(483, 323);
			this->dop_output->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dop_output->Multiline = true;
			this->dop_output->Name = L"dop_output";
			this->dop_output->ReadOnly = true;
			this->dop_output->Size = System::Drawing::Size(105, 135);
			this->dop_output->TabIndex = 20;
			// 
			// dop_clear_btn
			// 
			this->dop_clear_btn->Location = System::Drawing::Point(24, 378);
			this->dop_clear_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dop_clear_btn->Name = L"dop_clear_btn";
			this->dop_clear_btn->Size = System::Drawing::Size(159, 38);
			this->dop_clear_btn->TabIndex = 21;
			this->dop_clear_btn->Text = L"Очистить поля";
			this->dop_clear_btn->UseVisualStyleBackColor = true;
			this->dop_clear_btn->Click += gcnew System::EventHandler(this, &LAB_1::dop_clear_btn_Click);
			// 
			// dop_info_btn
			// 
			this->dop_info_btn->Location = System::Drawing::Point(24, 422);
			this->dop_info_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dop_info_btn->Name = L"dop_info_btn";
			this->dop_info_btn->Size = System::Drawing::Size(159, 36);
			this->dop_info_btn->TabIndex = 22;
			this->dop_info_btn->Text = L"Информация";
			this->dop_info_btn->UseVisualStyleBackColor = true;
			this->dop_info_btn->Click += gcnew System::EventHandler(this, &LAB_1::dop_info_btn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(341, 299);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 20);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Ввод";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(479, 301);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 20);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Вывод";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(23, 338);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(160, 26);
			this->textBox2->TabIndex = 25;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &LAB_1::textBox2_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(189, 338);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 36);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Ввести";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LAB_1::button2_Click);
			// 
			// dop_run_btn
			// 
			this->dop_run_btn->Location = System::Drawing::Point(189, 378);
			this->dop_run_btn->Name = L"dop_run_btn";
			this->dop_run_btn->Size = System::Drawing::Size(114, 80);
			this->dop_run_btn->TabIndex = 27;
			this->dop_run_btn->Text = L"Запуск";
			this->dop_run_btn->UseVisualStyleBackColor = true;
			this->dop_run_btn->Click += gcnew System::EventHandler(this, &LAB_1::dop_run_btn_Click);
			// 
			// test_btn
			// 
			this->test_btn->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->test_btn->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->test_btn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->test_btn->Location = System::Drawing::Point(10, 488);
			this->test_btn->Name = L"test_btn";
			this->test_btn->Size = System::Drawing::Size(602, 48);
			this->test_btn->TabIndex = 28;
			this->test_btn->Text = L"Протестировать программу на наличие ошибок";
			this->test_btn->UseVisualStyleBackColor = false;
			this->test_btn->Click += gcnew System::EventHandler(this, &LAB_1::test_btn_Click);
			// 
			// LAB_1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 548);
			this->Controls->Add(this->test_btn);
			this->Controls->Add(this->dop_run_btn);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dop_info_btn);
			this->Controls->Add(this->dop_clear_btn);
			this->Controls->Add(this->dop_output);
			this->Controls->Add(this->dop_input);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->call_quantity_output);
			this->Controls->Add(this->call_quantity_label);
			this->Controls->Add(this->label1_output);
			this->Controls->Add(this->output_label);
			this->Controls->Add(this->run_btn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radio_button_2);
			this->Controls->Add(this->radio_button_1);
			this->Controls->Add(this->choise_label);
			this->Controls->Add(this->input_textBox);
			this->Controls->Add(this->input_label);
			this->Controls->Add(this->info_btn);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"LAB_1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №1. Рекурсия";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//
	// Очистка полей в области 1 и 2 рекурсии
	//
	private: void clear()
	{
		this->input_textBox->Text = "";
		this->textBox1->Text = "Здесь будет формула выбранной рекурсивной функции.";
		this->output_label->Text = "";
		this->call_quantity_output->Text = "";
		this->radio_button_1->Checked = false;
		this->radio_button_2->Checked = false;
	}
	//
	// Формула первой рекурсивной функции
	//
	private: int recursion_1(int n)
	{
		++q;
		if (n == 1)
		{
			return 1;
		}
		else if (n % 2 == 0)
		{
			return (n + 3 * recursion_1(n - 1));
		}
		else if (n > 1 && n % 2 == 1)
		{
			return (2 + 2 * recursion_1(n - 2));
		}
	}
	//
	// Формула второй рекурсивной функции
	//
	private: int recursion_2(int n)
	{
		++q;
		if (n < 3)
		{
			return 1;
		}
		else if (n > 2 && n % 2 == 1)
		{
			return (recursion_2(n - 1) + recursion_2(n - 2));
		}
		else if (n > 2 && n % 2 == 0)
		{
			int sum = 0;
			for (int i = 1; i <= n - 1; i++)
				sum += recursion_2(i);
			return sum;
		}
	}
	//
	//	Вывод формулы первой рекурсивной функции при нажатии кнопки "1"
	//
	private: System::Void radioButton1_activity(System::Object^ sender, System::EventArgs^ e)
	{
		check_validaty_for_1();
		if (this->radio_button_1->Checked == true)
		{
			this->textBox1->Text = "F(n) = 1, при n = 1;" + "\r\n" + "F(n) = n + 3 * F(n - 1), если n чётно;" + "\r\n" + "F(n) = 2 + 2 * F(n - 2), если n > 1 и при этом n нечётно." + "\r\n";
			choise = true;
		}
		else
		{
			this->textBox1->Text = "Здесь будет формула выбранной рекурсивной функции.";
		}
	}
	//
	//	Вывод формулы первой рекурсивной функции при нажатии кнопки "2"
	//
	private: System::Void radioButton2_activity(System::Object ^ sender, System::EventArgs ^ e)
	{
		check_validaty_for_2();
		if (this->radio_button_2->Checked == true)
		{
			this->textBox1->Text = "F(n) = 1, при n < 3; " + "\r\n" + "F(n) = F(n - 1) + F(n - 2), если n > 2 и при этом n нечётно; " + "\r\n" + "F(n) = summ F(i) 1 <= i <= n - 1, если n > 2 и при этом n чётно." + "\r\n";
			choise = false;
		}
		else
		{
			this->textBox1->Text = "Здесь будет формула выбранной рекурсивной функции.";
		}
	}
	//
	// Проверка входных данных для первой рекурсивной функции
	//
	private: void check_validaty_for_1()
	{

		String^ error_overflow = "При выборе первого варианта рекурсивной функции ввходные данные не могут быть равными 0.";
		try
		{
			if (this->input_textBox->Text != "")
			{
				int data_i = System::Convert::ToInt32(this->input_textBox->Text);
				if (data_i == 0)
				{
					throw error_overflow;
				}
			}
		}
		catch (String^ error_overflow)
		{
			this->input_textBox->ForeColor = Color::Red;
			System::Windows::Forms::DialogResult result = MessageBox::Show(error_overflow, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->input_textBox->Text = "";
				this->input_textBox->ForeColor = Color::Black;
			}
		}
	}
	//
	// Проверка входных данных для второй рекурсивной функции
	//
	private: void check_validaty_for_2()
	{

		String^ error_overflow = "Введено слишком большое число для второго варианта рекурсии. Попробуйте еще раз. Максимальное число для второй рекурсивной функции - 35.";
		try
		{
			if (this->input_textBox->Text != "")
			{
				int data_i = System::Convert::ToInt32(this->input_textBox->Text);
				if (data_i >= 36)
				{
					throw error_overflow;
				}
			}
		}
		catch (String^ error_overflow)
		{
			this->input_textBox->ForeColor = Color::Red;
			System::Windows::Forms::DialogResult result = MessageBox::Show(error_overflow, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->input_textBox->Text = "";
				this->input_textBox->ForeColor = Color::Black;
			}
		}
	}
	//
	//  Проверка входных данных на наличие символов, кроме 0-9, в области 1 и 2 рекурсии
	//
	private: void null_to_nine()
	{
		String^ error = "Введено неверное значение. Попробуйте ещё раз.";
		String^ data = this->input_textBox->Text;
		try
		{
			for (int i = 0; i < this->input_textBox->Text->Length; i++)
			{
				if (!((input_textBox->Text[i] >= '0') && (input_textBox->Text[i] <= '9')) || (input_textBox->Text[i] == ',') || (input_textBox->Text[i] == '.'))
				{
					throw error;
				}
			}

		}
		catch (String^ error)
		{
			this->input_textBox->ForeColor = Color::Red;
			System::Windows::Forms::DialogResult result = MessageBox::Show(error, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->input_textBox->Text = "";
				this->input_textBox->ForeColor = Color::Black;
			}
		}
	}
	//
	// Ограничение входных данных на максимальное значение, в области 1 и 2 рекурсии
	//
	private: void max_value_input()
	{
		String^ error_overflow = "Введено слишком большое число. Попробуйте еще раз. Максимальное число - 64.";
		try
		{
			if (this->input_textBox->Text != "")
			{
				int data_i = System::Convert::ToInt32(this->input_textBox->Text);
				if (data_i >= 65)
				{
					throw error_overflow;
				}
			}
		}
		catch (String^ error_overflow)
		{
			this->input_textBox->ForeColor = Color::Red;
			System::Windows::Forms::DialogResult result = MessageBox::Show(error_overflow, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->input_textBox->Text = "";
				this->input_textBox->ForeColor = Color::Black;
			}
		}
	}
	//
	// Процедура проверки входных данных, в области 1 и 2 рекурсии
	//
	private: void check_validaty_1_2()
	{
		null_to_nine();
		max_value_input();
		if (this->radio_button_1->Checked)
		{
			check_validaty_for_1();
		}
		if (this->radio_button_2->Checked)
		{
			check_validaty_for_2();
		}
	}
	//
	//	Процедура, описывающая действия при нажатии кнопки "Запуск", в области 1 и 2 рекурсии
	//
	private: System::Void run_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		q = 0;
		if (this->input_textBox->Text != "")
		{
			this->n = System::Convert::ToInt32(this->input_textBox->Text);
			if (this->radio_button_1->Checked || this->radio_button_2->Checked)
			{
				if (choise == true)
				{
					this->output_label->Text = System::Convert::ToString(recursion_1(n));
					this->call_quantity_output->Text = System::Convert::ToString(q);
				}
				else
				{
					this->output_label->Text = System::Convert::ToString(recursion_2(n));
					this->call_quantity_output->Text = System::Convert::ToString(q);
				}
			}
		}
	}
	//
	//	Процедура, описывающая действия при нажатии кнопки "Очистить поля", в области 1 и 2 рекурсии
	//
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		clear();
	}
	//
	//	Процедура, описывающая действия при нажатии кнопки "Информация", в области 1 и 2 рекурсии
	//
	private: System::Void info_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Работа с программой\r\n\r\nДля работы с рекурсивными функциями:\r\n\r\n- Введите данные. Для ввода значений введите данные в поле ввода (максимальное значение - 64 для рекурсии #1, 35 для рекурсии #2);\r\n\r\n- Выберите вариант рекурсивной функции. После выбора рекурсии ниже будет выведена формула выбранной функции;\r\n\r\n- Нажмине кнопку \"Запуск\" для запуска рекурсии.\r\n\r\n- После запуска рекурсии будет выведен результат рекурсивных вычислений и количество вызовов рекурсивной функции.\r\n\r\nДля повторного использования программы нажмите кнопку \"Очистить поля\" и повторие вышеперечисленные действия.", "Информация о работе программы", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//
	// 	Процедура описывающая действия при изменении данных в поле ввода, в области 1 и 2 рекурсии
	//
	private: System::Void input_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		check_validaty_1_2();
	};
	//
	// Определение максимального элемента из двух, для дополнительной программы
	//
	private: int max(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	//
	// Основная функция дополнительной программы
	//
	private: int dop()
	{
		int num = 0;
		num = arr[i];
		i++;
		if (num == 0)
		{
			return 0;
		}
		int tmax = dop();
		return max(tmax, num);
	}
	//
	//	Процедура, описывающая действия при нажатии кнопки "Ввести" в области дополнительной программы
	//
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (!(this->textBox2->Text == ""))
		{
			arr[i] = System::Convert::ToInt32(this->textBox2->Text);
			if (this->dop_input->Text == "")
				this->dop_input->Text = this->textBox2->Text;
			else
				this->dop_input->Text += "\r\n" + this->textBox2->Text;
			this->textBox2->Text = "";
			i++;
		}
	}
	//
	//	Процедура, описывающая действия при нажатии кнопки "Очистить поля" в области дополнительной программы
	//
	private: System::Void dop_clear_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->dop_output->Text = "";
		this->dop_input->Text = "";
		this->textBox2->Text = "";
		this->dop_bool = false;
	}
	//
	//	Процедура, описывающая действия при нажатии кнопки "Запуск" в области дополнительной программы
	//
	private: System::Void dop_run_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->dop_bool == true)
		{
			MessageBox::Show("Ответ уже вычислен и выведен в поле \"Вывод\".", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else 
		{
			if (!(this->dop_input->Text == "") && (this->dop_input->Text->EndsWith("0")))
			{
				i = 0;
				this->dop_output->Text = System::Convert::ToString(dop());
				i = 0;
				this->dop_bool = true;
			}
			else if (!(this->dop_input->Text == "") && !(this->dop_input->Text->EndsWith("0")))
			{
				MessageBox::Show("Введите ноль для обозначения конца последовательности.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else if (this->dop_input->Text == "")
			{
				MessageBox::Show("Введите последовательность.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	//
	// Процедура, ограничивающая введение первым элементом последовательности числа "0", в области дополнительной программы
	//
	private: void dop_zero_first()
	{
		String^ zero_first = "Первое элемент в последовательности не может быть нулём.";
		try
		{
			if (this->dop_input->Text == "" && this->textBox2->Text == "0")
			{
				throw zero_first;
			}
		}
		catch (String^ zero_first)
		{
			this->textBox2->ForeColor = Color::Red;
			System::Windows::Forms::DialogResult result = MessageBox::Show(zero_first, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->textBox2->Text = "";
				this->textBox2->ForeColor = Color::Black;
			}
		}
	}
	//
	//	Проверка входных данных на наличие символов, кроме 0-9, в области дополнительной программы
	//
	private: void dop_valid_input()
	{
		String^ error = "Введено неверное значение. Попробуйте ещё раз.";
		String^ data = this->textBox2->Text;
		try
		{
			for (int i = 0; i < this->textBox2->Text->Length; i++)
			{
				if (!((textBox2->Text[i] >= '0') && (textBox2->Text[i] <= '9')) || (textBox2->Text[i] == ',') || (textBox2->Text[i] == '.'))
				{
					throw error;
				}
			}
		}
		catch (String^ error)
		{
			this->textBox2->ForeColor = Color::Red;
			System::Windows::Forms::DialogResult result = MessageBox::Show(error, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->textBox2->Text = "";
				this->textBox2->ForeColor = Color::Black;
			}
		}
	}
	//
	// Процедура проверки входных данных, в области дополнительной программы
	//
	private: void dop_check_validaty()
	{
		dop_zero_first();
		dop_valid_input();
	}
	//
	//	Процедура, описывающая действия при изменении данных в поле ввода, в области дополнительной программы
	//
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		dop_check_validaty();
	}
	//
	//	Процедура описывающая действия при нажатии кнопки "Информация", в области дополнительной программы
	//
	private: System::Void dop_info_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("Данная программа определяет максимальный элемент последовательности и выводит его в поле \"Вывод\", последовательность должна оканчивается нулём и состоять минимум из двух элементов, включая последний.\r\n\r\nДля работы с программой:\r\n\r\n- Введите последовательность в поле ввода по одному элементу;\r\n\r\n- Для добавления элемента в программу нажмите кнопку \"Ввести\", после чего элемент будет добавлен в поле \"Ввод\";\r\n\r\n- Для запуска программы нажмите кнопку \"Запуск\".\r\n\r\nДля повторного использования программы нажмите кнопку \"Очистить поля\" и повторие вышеперечисленные действия.", "Информация о работе программы", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//
	// Тест первой рекурсивной функции, при аргументе = 5
	//
	private: int test_1()
	{
		if (recursion_1(5) == 10)
			return 0;
		else
			return 1;
	}
	//
	// Тест первой рекурсивной функции, при аргументе = 1
	//
	private: int test_2()
	{
		if (recursion_1(1) == 1)
			return 0;
		else
			return 1;
	}
	//
	//  Тест второй рекурсивной функции, при аргументе = 2
	//
	private: int test_3()
	{
		if (recursion_2(2) == 1)
			return 0;
		else
			return 1;
	}
	//
	//  Тест второй рекурсивной функции, при аргументе = 4
	//
	private: int test_4()
	{
		if (recursion_2(4) == 4)
			return 0;
		else
			return 1;
	}
	//
	// Тест функции по определению максимального элемента из двух, при аргументах = 5 и 0
	//
	private: int test_5()
	{
		if (max(5, 0) == 5)
			return 0;
		else
			return 1;
	}
	//
	// Процедула запускающая тестирование трёх функций
	//
	private: void test_cases()
	{
		int test_flag = (test_1() + test_2() + test_3() + test_4() + test_5());
		if (test_flag == 0)
		{
			MessageBox::Show("Все тесты пройдены. Программа работает корректно.", "Пройдено", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show("Тесты не пройдены. Программа работает не корректно. Окно программы будет закрыто.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				this->Close();
			}
		}
	}
	//
	// Процедура, описывающая действия при нажатии кнопки "Протестировать программу на наличие ошибок"
	//
	private: System::Void test_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		test_cases();
	}	
};
}