/*

АЯиП Лабораторная работа #2
Файл заголовочного проекта LAB_2
Михайлов Роман, группа 3091, 1 курс
15.03.2024

*/
#pragma once

namespace LAB3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RenameWindow
	/// </summary>
	public ref class RenameWindow : public System::Windows::Forms::Form
	{
	public:
		RenameWindow(void)
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
		~RenameWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	public: String^ new_name = "";
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ Cancel;
	private: System::Windows::Forms::Button^ Apply;
	public: System::Windows::Forms::TextBox^ textBox2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->Apply = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(200, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Старое название файла:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 144);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Новое название файла:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(243, 141);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(253, 26);
			this->textBox1->TabIndex = 2;
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(221, 210);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(143, 45);
			this->Cancel->TabIndex = 3;
			this->Cancel->Text = L"Отмена";
			this->Cancel->UseVisualStyleBackColor = true;
			this->Cancel->Click += gcnew System::EventHandler(this, &RenameWindow::Cancel_Click);
			// 
			// Apply
			// 
			this->Apply->Location = System::Drawing::Point(380, 210);
			this->Apply->Name = L"Apply";
			this->Apply->Size = System::Drawing::Size(143, 45);
			this->Apply->TabIndex = 4;
			this->Apply->Text = L"Применить";
			this->Apply->UseVisualStyleBackColor = true;
			this->Apply->Click += gcnew System::EventHandler(this, &RenameWindow::Apply_Click);
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(243, 35);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox2->Size = System::Drawing::Size(253, 19);
			this->textBox2->TabIndex = 5;
			// 
			// RenameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 267);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->Apply);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"RenameWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Переименование файла";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void Apply_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		new_name = this->textBox1->Text;
		this->Close();
	}
	
	private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};
}
