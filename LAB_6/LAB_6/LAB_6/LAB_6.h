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
	/// Сводка для LAB_6
	/// </summary>
	public ref class LAB_6 : public System::Windows::Forms::Form
	{
	public:
		LAB_6(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			test_cases();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: String^ current_type = ""; // Хранит в себе название текущей структуры данных
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ структураToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ arrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vectorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ операцииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавитьЭлементToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалениеПоследнегоЭлементаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ заменаЗначенияПоИндексуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ поискИндексаПоЗначениюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ поискНаибольшегоЭлементаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ очиститьСтруктураToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::ToolStripMenuItem^ выводСтруктурыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ тестовыеДанныеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ тестToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ математическиеОперацииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ суммаЭлементовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ разностьЭлементовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ произведениеЭлементовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ частноеЭлементовToolStripMenuItem;
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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LAB_6::typeid));
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->структураToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->arrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->vectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->stackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->операцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->выводСтруктурыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->добавитьЭлементToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->удалениеПоследнегоЭлементаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->заменаЗначенияПоИндексуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->поискИндексаПоЗначениюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->поискНаибольшегоЭлементаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->очиститьСтруктураToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->тестовыеДанныеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->математическиеОперацииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->суммаЭлементовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->разностьЭлементовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->произведениеЭлементовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->частноеЭлементовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->тестToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->textBox = (gcnew System::Windows::Forms::TextBox());
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->структураToolStripMenuItem,
					   this->операцииToolStripMenuItem, this->математическиеОперацииToolStripMenuItem, this->тестToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			   this->menuStrip1->Size = System::Drawing::Size(1268, 24);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // структураToolStripMenuItem
			   // 
			   this->структураToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->arrayToolStripMenuItem,
					   this->vectorToolStripMenuItem, this->stackToolStripMenuItem
			   });
			   this->структураToolStripMenuItem->Name = L"структураToolStripMenuItem";
			   this->структураToolStripMenuItem->Size = System::Drawing::Size(83, 22);
			   this->структураToolStripMenuItem->Text = L"Тип данных";
			   // 
			   // arrayToolStripMenuItem
			   // 
			   this->arrayToolStripMenuItem->Name = L"arrayToolStripMenuItem";
			   this->arrayToolStripMenuItem->Size = System::Drawing::Size(250, 22);
			   this->arrayToolStripMenuItem->Text = L"unsigned int — Целочисленный";
			   this->arrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::arrayToolStripMenuItem_Click);
			   // 
			   // vectorToolStripMenuItem
			   // 
			   this->vectorToolStripMenuItem->Name = L"vectorToolStripMenuItem";
			   this->vectorToolStripMenuItem->Size = System::Drawing::Size(250, 22);
			   this->vectorToolStripMenuItem->Text = L"char — Символьный";
			   this->vectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::vectorToolStripMenuItem_Click);
			   // 
			   // stackToolStripMenuItem
			   // 
			   this->stackToolStripMenuItem->Name = L"stackToolStripMenuItem";
			   this->stackToolStripMenuItem->Size = System::Drawing::Size(250, 22);
			   this->stackToolStripMenuItem->Text = L"double — Вещественный";
			   this->stackToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::stackToolStripMenuItem_Click);
			   // 
			   // операцииToolStripMenuItem
			   // 
			   this->операцииToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				   this->выводСтруктурыToolStripMenuItem,
					   this->добавитьЭлементToolStripMenuItem, this->удалениеПоследнегоЭлементаToolStripMenuItem, this->заменаЗначенияПоИндексуToolStripMenuItem,
					   this->поискИндексаПоЗначениюToolStripMenuItem, this->поискНаибольшегоЭлементаToolStripMenuItem, this->очиститьСтруктураToolStripMenuItem,
					   this->тестовыеДанныеToolStripMenuItem
			   });
			   this->операцииToolStripMenuItem->Name = L"операцииToolStripMenuItem";
			   this->операцииToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			   this->операцииToolStripMenuItem->Text = L"Редактирование";
			   // 
			   // выводСтруктурыToolStripMenuItem
			   // 
			   this->выводСтруктурыToolStripMenuItem->Name = L"выводСтруктурыToolStripMenuItem";
			   this->выводСтруктурыToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->выводСтруктурыToolStripMenuItem->Text = L"Вывод структуры";
			   this->выводСтруктурыToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::выводСтруктурыToolStripMenuItem_Click);
			   // 
			   // добавитьЭлементToolStripMenuItem
			   // 
			   this->добавитьЭлементToolStripMenuItem->Name = L"добавитьЭлементToolStripMenuItem";
			   this->добавитьЭлементToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->добавитьЭлементToolStripMenuItem->Text = L"Добавить элемент";
			   this->добавитьЭлементToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::добавитьЭлементToolStripMenuItem_Click);
			   // 
			   // удалениеПоследнегоЭлементаToolStripMenuItem
			   // 
			   this->удалениеПоследнегоЭлементаToolStripMenuItem->Name = L"удалениеПоследнегоЭлементаToolStripMenuItem";
			   this->удалениеПоследнегоЭлементаToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->удалениеПоследнегоЭлементаToolStripMenuItem->Text = L"Удаление последнего элемента";
			   this->удалениеПоследнегоЭлементаToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::удалениеПоследнегоЭлементаToolStripMenuItem_Click);
			   // 
			   // заменаЗначенияПоИндексуToolStripMenuItem
			   // 
			   this->заменаЗначенияПоИндексуToolStripMenuItem->Name = L"заменаЗначенияПоИндексуToolStripMenuItem";
			   this->заменаЗначенияПоИндексуToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->заменаЗначенияПоИндексуToolStripMenuItem->Text = L"Замена значения по индексу";
			   this->заменаЗначенияПоИндексуToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::заменаЗначенияПоИндексуToolStripMenuItem_Click);
			   // 
			   // поискИндексаПоЗначениюToolStripMenuItem
			   // 
			   this->поискИндексаПоЗначениюToolStripMenuItem->Name = L"поискИндексаПоЗначениюToolStripMenuItem";
			   this->поискИндексаПоЗначениюToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->поискИндексаПоЗначениюToolStripMenuItem->Text = L"Поиск индекса по значению";
			   this->поискИндексаПоЗначениюToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::поискИндексаПоЗначениюToolStripMenuItem_Click);
			   // 
			   // поискНаибольшегоЭлементаToolStripMenuItem
			   // 
			   this->поискНаибольшегоЭлементаToolStripMenuItem->Name = L"поискНаибольшегоЭлементаToolStripMenuItem";
			   this->поискНаибольшегоЭлементаToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->поискНаибольшегоЭлементаToolStripMenuItem->Text = L"Поиск наибольшего элемента";
			   this->поискНаибольшегоЭлементаToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::поискНаибольшегоЭлементаToolStripMenuItem_Click);
			   // 
			   // очиститьСтруктураToolStripMenuItem
			   // 
			   this->очиститьСтруктураToolStripMenuItem->Name = L"очиститьСтруктураToolStripMenuItem";
			   this->очиститьСтруктураToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->очиститьСтруктураToolStripMenuItem->Text = L"Очистить структуру";
			   this->очиститьСтруктураToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::очиститьСтруктураToolStripMenuItem_Click);
			   // 
			   // тестовыеДанныеToolStripMenuItem
			   // 
			   this->тестовыеДанныеToolStripMenuItem->Name = L"тестовыеДанныеToolStripMenuItem";
			   this->тестовыеДанныеToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			   this->тестовыеДанныеToolStripMenuItem->Text = L"Заполнить структуру тестовыми данными";
			   this->тестовыеДанныеToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::тестовыеДанныеToolStripMenuItem_Click);
			   // 
			   // математическиеОперацииToolStripMenuItem
			   // 
			   this->математическиеОперацииToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				   this->суммаЭлементовToolStripMenuItem,
					   this->разностьЭлементовToolStripMenuItem, this->произведениеЭлементовToolStripMenuItem, this->частноеЭлементовToolStripMenuItem
			   });
			   this->математическиеОперацииToolStripMenuItem->Name = L"математическиеОперацииToolStripMenuItem";
			   this->математическиеОперацииToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			   this->математическиеОперацииToolStripMenuItem->Text = L"Математические операции";
			   // 
			   // суммаЭлементовToolStripMenuItem
			   // 
			   this->суммаЭлементовToolStripMenuItem->Name = L"суммаЭлементовToolStripMenuItem";
			   this->суммаЭлементовToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->суммаЭлементовToolStripMenuItem->Text = L"Сумма элементов";
			   this->суммаЭлементовToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::суммаЭлементовToolStripMenuItem_Click);
			   // 
			   // разностьЭлементовToolStripMenuItem
			   // 
			   this->разностьЭлементовToolStripMenuItem->Name = L"разностьЭлементовToolStripMenuItem";
			   this->разностьЭлементовToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->разностьЭлементовToolStripMenuItem->Text = L"Разность элементов";
			   this->разностьЭлементовToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::разностьЭлементовToolStripMenuItem_Click);
			   // 
			   // произведениеЭлементовToolStripMenuItem
			   // 
			   this->произведениеЭлементовToolStripMenuItem->Name = L"произведениеЭлементовToolStripMenuItem";
			   this->произведениеЭлементовToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->произведениеЭлементовToolStripMenuItem->Text = L"Произведение элементов";
			   this->произведениеЭлементовToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::произведениеЭлементовToolStripMenuItem_Click);
			   // 
			   // частноеЭлементовToolStripMenuItem
			   // 
			   this->частноеЭлементовToolStripMenuItem->Name = L"частноеЭлементовToolStripMenuItem";
			   this->частноеЭлементовToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			   this->частноеЭлементовToolStripMenuItem->Text = L"Частное элементов";
			   this->частноеЭлементовToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::частноеЭлементовToolStripMenuItem_Click);
			   // 
			   // тестToolStripMenuItem
			   // 
			   this->тестToolStripMenuItem->Name = L"тестToolStripMenuItem";
			   this->тестToolStripMenuItem->Size = System::Drawing::Size(42, 22);
			   this->тестToolStripMenuItem->Text = L"Тест";
			   this->тестToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_6::тестToolStripMenuItem_Click);
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
		   /// Функция присвоения числового значения строковому значению текущей структуры данных 
		   /// </summary>
		   /// <returns>Числовое значение соответствующее строковому названию</returns>
	private: type type_id()
	{
		if (current_type == "int") return int_type;
		else if (current_type == "char") return char_type;
		else if (current_type == "double") return double_type;
		else return none;
	}
		   //
		   // Процедура, запускающая действия при нажатии "Вывод структуры"
		   //
	private: System::Void выводСтруктурыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "Добавить элемент"
		   //
	private: System::Void добавитьЭлементToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "Удаление последнего элемента"
		   //
	private: System::Void удалениеПоследнегоЭлементаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "Замена значения по индексу"
		   //
	private: System::Void заменаЗначенияПоИндексуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "Поиск индекса по значению"
		   //
	private: System::Void поискИндексаПоЗначениюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (type_id() != none)
		{
			int x = this->Left + (this->Width / 2) - 200;
			int y = this->Top + (this->Height / 2) - 100;
			String^ find_value = Interaction::InputBox("Введите значение\r\n\r\n", "Поиск индекса по значению", "", x, y);
			if (find_value != "")
			{
				int index = none;
				switch (type_id())
				{
				case 1: index = int_stack.find_index(Convert::ToInt32(find_value)); break;
				case 2: index = char_stack.find_index(Convert::ToChar(find_value)); break;
				case 3: index = double_stack.find_index(Convert::ToDouble(find_value)); break;
				}
				MessageBox::Show("Индекс введенного значения — " + Convert::ToString(index), "Найти индекс", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "Поиск наибольшего элемента"
		   //
	private: System::Void поискНаибольшегоЭлементаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				int maxi = 0;
				maxi = int_stack.find_max();
				MessageBox::Show("Наибольшее значение — " + Convert::ToString(maxi), "Наибольшее значение", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				char maxc = char_stack.find_max();
				MessageBox::Show("Наибольшее значение — " + Convert::ToString(maxc) + " (" + Convert::ToChar(maxc) + ")", "Наибольшее значение", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				double maxd = double_stack.find_max();
				MessageBox::Show("Наибольшее значение — " + Convert::ToString(maxd), "Наибольшее значение", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
			}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//
		// Процедура, запускающая действия при нажатии "Очистить структуру"
		//
	private: System::Void очиститьСтруктураToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (type_id() != none)
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены что хотите очистить структуру?", "Предупреждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "Тестовые данных"
		   //
	private: System::Void тестовыеДанныеToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (type_id() != none)
		{
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show("Предварительно структура будет очищена. Вы уверены, что хотите ввести тестовые данные?", "Предупреждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void суммаЭлементовToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("Сумма элементов целочисленного стека — " + Convert::ToString(int_stack.sum()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				String^ str = gcnew String(char_stack.sum_of_char().c_str());
				MessageBox::Show("Сумма элементов символьного стека — " + str, "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("Сумма элементов вещественного стека — " + Convert::ToString(double_stack.sum()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void разностьЭлементовToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{

		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("Разность элементов целочисленного стека — " + Convert::ToString(int_stack.difference()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				MessageBox::Show("Разность элементов символьного стека — \"\"", "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("Разность элементов вещественного стека — " + Convert::ToString(double_stack.difference()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void произведениеЭлементовToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{

		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("Произведение элементов целочисленного стека — " + Convert::ToString(int_stack.product()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				MessageBox::Show("Произведение элементов символьного стека — \"\"", "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("Произведение элементов вещественного стека — " + Convert::ToString(double_stack.product()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	private: System::Void частноеЭлементовToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{

		if (type_id() != none)
		{
			switch (type_id())
			{
			case 1:
			{
				MessageBox::Show("Частное элементов целочисленного стека — " + Convert::ToString(int_stack.quotient()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 2:
			{
				MessageBox::Show("Частное элементов символьного стека — ", "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			case 3:
			{
				MessageBox::Show("Частное элементов вещественного стека — " + Convert::ToString(double_stack.quotient()), "Сумма элементов", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //
		   // Процедура, запускающая действия при нажатии "int"
		   //
	private: System::Void arrayToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->current_type = "int";
		if (this->Text == "LAB_6") this->Text += " — int (Целочисленный)";
		else this->Text = this->Text->Remove(8) + "int (Целочисленный)";
		this->textBox->Text = gcnew String(int_stack.output().c_str());
	}
		   //
		   // Процедура, запускающая действия при нажатии "char"
		   //
	private: System::Void vectorToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->current_type = "char";
		if (this->Text == "LAB_6") this->Text += " — char (Символьный)";
		else this->Text = this->Text->Remove(8) + "char (Символьный)";
		this->textBox->Text = gcnew String(char_stack.output().c_str());
	}
		   //
		   // Процедура, запускающая действия при нажатии "double"
		   //
	private: System::Void stackToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->current_type = "double";
		if (this->Text == "LAB_6") this->Text += " — double (Вещественный)";
		else this->Text = this->Text->Remove(8) + "double (Вещественный)";
		this->textBox->Text = gcnew String(double_stack.output().c_str());
	}
		   /// <summary>
		   /// Функция тестирования ввода значений в структуру данных "Array"
		   /// </summary>
		   /// <returns>Результат тестирования</returns>
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
		   /// Функция тестирования ввода значений в структуру данных "Vector"
		   /// </summary>
		   /// <returns>Результат тестирования</returns>
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
		   /// Функция тестирования ввода значений в структуру данных "Stack"
		   /// </summary>
		   /// <returns>Результат тестирования</returns>
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
		   /// Функция тестирования ввода значений в структуры данных
		   /// </summary>
		   /// <returns>Результат тестирования</returns>
	private: int test_cases()
	{
		int result = test1() + test2() + test3();
		if (result != 0)
		{
			MessageBox::Show("Тесты не пройдены. Ключевые функции работают некорректно. Приложение будет закрыто", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
		return result;
	}
		   //
		   // Процедура, запускающая действия при нажатии кнопки "Тест"
		   //
	private: System::Void тестToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (test_cases() == 0)
			MessageBox::Show("Тесты пройдены. Ключевые функции работают корректно.", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
	};
