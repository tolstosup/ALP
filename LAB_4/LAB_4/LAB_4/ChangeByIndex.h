#pragma once

namespace LAB4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChangeByIndex
	/// </summary>
	public ref class ChangeByIndex : public System::Windows::Forms::Form
	{
	public:
		ChangeByIndex(bool char_is_enable)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->char_is_enable = char_is_enable;
			if (char_is_enable) this->label2->Text = "Введите новый символ:";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChangeByIndex()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ index_textBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ ok_button;
	private: System::Windows::Forms::Button^ cancel_button;
	protected:
	private: bool canceled;
	private: bool char_is_enable;
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
			this->index_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ok_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// index_textBox
			// 
			this->index_textBox->Location = System::Drawing::Point(231, 33);
			this->index_textBox->Name = L"index_textBox";
			this->index_textBox->Size = System::Drawing::Size(225, 26);
			this->index_textBox->TabIndex = 0;
			this->index_textBox->TextChanged += gcnew System::EventHandler(this, &ChangeByIndex::index_textBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(217, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите индекс элемента:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите новое значение:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(231, 84);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(225, 26);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ChangeByIndex::textBox1_TextChanged);
			// 
			// ok_button
			// 
			this->ok_button->Location = System::Drawing::Point(381, 140);
			this->ok_button->Name = L"ok_button";
			this->ok_button->Size = System::Drawing::Size(75, 39);
			this->ok_button->TabIndex = 4;
			this->ok_button->Text = L"OK";
			this->ok_button->UseVisualStyleBackColor = true;
			this->ok_button->Click += gcnew System::EventHandler(this, &ChangeByIndex::ok_button_Click);
			// 
			// cancel_button
			// 
			this->cancel_button->Location = System::Drawing::Point(275, 140);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(85, 39);
			this->cancel_button->TabIndex = 5;
			this->cancel_button->Text = L"Отмена";
			this->cancel_button->UseVisualStyleBackColor = true;
			this->cancel_button->Click += gcnew System::EventHandler(this, &ChangeByIndex::cancel_button_Click);
			// 
			// ChangeByIndex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 201);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->ok_button);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->index_textBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ChangeByIndex";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Замена значения по индексу";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	// Процедура, запускающая действия при нажатии кнопки "Отмена"
	//
	private: System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
		canceled = true;
	}
	//
	// Процедура, запускающая действия при нажатии кнопки "OK"
	//
	private: System::Void ok_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (this->textBox1->Text != "" || this->index_textBox->Text != "")
		{
			check_index();
			if (check())
			{
				this->Close();
				canceled = false;
			}
		}
		else MessageBox::Show("Значение для нового элемента не введено", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Функция получения значения из поля ввода индекса
	// Вход void
	// Выход System::String^
	//
	public: String^ get_index()
	{
		return this->index_textBox->Text;
	}
	//
	// Функция получения значения глобальной переменной canceled
	// Вход void
	// Выход bool
	//
	public: bool is_canceled()
	{
		return canceled;
	}
	//
	// Процедура проверки корректонсти ввода индекса
	//
	private: void check_index()
	{
		String^ str = index_textBox->Text;
		for (int i = 0; i < str->Length; i++)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				if (str->Length > 1)
					this->index_textBox->Text = this->index_textBox->Text->Remove(this->index_textBox->TextLength - 1);
				else
					this->index_textBox->Text = "";
			}
		}
	}
	//
	// Процедура, запускающая действия при изменении текста в index_textBox
	//
	private: System::Void index_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		check_index();
	}
	//
	// Процедура, запускающая действия при изменении текста в textBox1
	//
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		check();
	}
	//
	// Функция проверки корректности ввода в поле нового значения
	// Вход void
	// Выход bool
	//
	private: bool check()
	{
		if (char_is_enable)
		{
			if (this->textBox1->Text->Length > 1)
			{
				MessageBox::Show("Введено несколько символов", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			else if (this->textBox1->Text->Length != 0 && !(this->textBox1->Text[0] > 0 && this->textBox1->Text[0] < 255))
			{
				MessageBox::Show("Введенный символ некорректен", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			return true;
		}
		else
		{
			String^ str = this->textBox1->Text;
			for (int i = 0; i < str->Length; i++)
			{
				if (!(str[i] >= '0' && str[i] <= '9'))
				{
					this->textBox1->Text = this->textBox1->Text->Remove(this->textBox1->TextLength - 1);
				}
			}
			if (Convert::ToInt32(this->textBox1->Text) > 200000000)
			{
				this->textBox1->Text = this->textBox1->Text->Remove(this->textBox1->TextLength - 1);
			}
			return true;
		}
	}
	//
	// Функция получения нового значения
	// Вход void
	// Выход System::String^
	//
	public: System::String^ get_val()
	{
		if (char_is_enable)
			return Convert::ToString(Convert::ToInt32(Convert::ToChar(this->textBox1->Text)));
		else
			return Convert::ToString(Convert::ToInt32(this->textBox1->Text));
	}
};
}
