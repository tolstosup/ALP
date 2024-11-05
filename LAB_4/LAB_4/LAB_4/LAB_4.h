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

	myArray<int> arr;			// Экземпляр шаблонного класса myArray структуры данных Array, данных типа int
	myVector<int> vector;		// Экземпляр шаблонного класса myVector структуры данных Vector, данных типа int 
	myStack<int> stack;			// Экземпляр шаблонного класса myStack структуры данных Stack, данных типа int
	myQueue<int> queue;			// Экземпляр шаблонного класса myQueue структуры данных Queue, данных типа int

	myArray<char> c_arr;		// Экземпляр шаблонного класса myArray структуры данных Array, данных типа char
	myVector<char> c_vector;	// Экземпляр шаблонного класса myVector структуры данных Vector, данных типа char
	myStack<char> c_stack;		// Экземпляр шаблонного класса myStack структуры данных Stack, данных типа char
	myQueue<char> c_queue;		// Экземпляр шаблонного класса myQueue структуры данных Queue, данных типа char

	/// <summary>
	/// Сводка для LAB_4
	/// </summary>
	public ref class LAB_4 : public System::Windows::Forms::Form
	{
	public:
		LAB_4(void)
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
	private: String^ current_struct = ""; // Хранит в себе название текущей структуры данных
	private: bool char_is_enable = false; // Хранит информацию в текущем режиме приложения
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ структураToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ arrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vectorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ queueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ операцииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавитьЭлементToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалениеПоследнегоЭлементаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ заменаЗначенияПоИндексуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ поискИндексаПоЗначениюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ поискНаибольшегоЭлементаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ конвертацияВASCIIToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ очиститьСтруктураToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::ToolStripMenuItem^ выводСтруктурыToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ char_textBox;
	private: System::Windows::Forms::Label^ int_label;
	private: System::Windows::Forms::Label^ char_label;
	private: System::Windows::Forms::ToolStripMenuItem^ тестовыеДанныеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ тестToolStripMenuItem;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LAB_4::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->структураToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->queueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->операцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводСтруктурыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавитьЭлементToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалениеПоследнегоЭлементаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->заменаЗначенияПоИндексуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->поискИндексаПоЗначениюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->поискНаибольшегоЭлементаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститьСтруктураToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->тестовыеДанныеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->конвертацияВASCIIToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->тестToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->структураToolStripMenuItem,
					this->операцииToolStripMenuItem, this->конвертацияВASCIIToolStripMenuItem, this->тестToolStripMenuItem
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
			this->структураToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->arrayToolStripMenuItem,
					this->vectorToolStripMenuItem, this->stackToolStripMenuItem, this->queueToolStripMenuItem
			});
			this->структураToolStripMenuItem->Name = L"структураToolStripMenuItem";
			this->структураToolStripMenuItem->Size = System::Drawing::Size(75, 22);
			this->структураToolStripMenuItem->Text = L"Структура";
			// 
			// arrayToolStripMenuItem
			// 
			this->arrayToolStripMenuItem->Name = L"arrayToolStripMenuItem";
			this->arrayToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->arrayToolStripMenuItem->Text = L"Array — Статический массив";
			this->arrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::arrayToolStripMenuItem_Click);
			// 
			// vectorToolStripMenuItem
			// 
			this->vectorToolStripMenuItem->Name = L"vectorToolStripMenuItem";
			this->vectorToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->vectorToolStripMenuItem->Text = L"Vector — Динамический массив";
			this->vectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::vectorToolStripMenuItem_Click);
			// 
			// stackToolStripMenuItem
			// 
			this->stackToolStripMenuItem->Name = L"stackToolStripMenuItem";
			this->stackToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->stackToolStripMenuItem->Text = L"Stack — Стек";
			this->stackToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::stackToolStripMenuItem_Click);
			// 
			// queueToolStripMenuItem
			// 
			this->queueToolStripMenuItem->Name = L"queueToolStripMenuItem";
			this->queueToolStripMenuItem->Size = System::Drawing::Size(251, 22);
			this->queueToolStripMenuItem->Text = L"Queue — Очередь";
			this->queueToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::queueToolStripMenuItem_Click);
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
			this->операцииToolStripMenuItem->Size = System::Drawing::Size(75, 22);
			this->операцииToolStripMenuItem->Text = L"Операции";
			// 
			// выводСтруктурыToolStripMenuItem
			// 
			this->выводСтруктурыToolStripMenuItem->Name = L"выводСтруктурыToolStripMenuItem";
			this->выводСтруктурыToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->выводСтруктурыToolStripMenuItem->Text = L"Вывод структуры";
			this->выводСтруктурыToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::выводСтруктурыToolStripMenuItem_Click);
			// 
			// добавитьЭлементToolStripMenuItem
			// 
			this->добавитьЭлементToolStripMenuItem->Name = L"добавитьЭлементToolStripMenuItem";
			this->добавитьЭлементToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->добавитьЭлементToolStripMenuItem->Text = L"Добавить элемент";
			this->добавитьЭлементToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::добавитьЭлементToolStripMenuItem_Click);
			// 
			// удалениеПоследнегоЭлементаToolStripMenuItem
			// 
			this->удалениеПоследнегоЭлементаToolStripMenuItem->Name = L"удалениеПоследнегоЭлементаToolStripMenuItem";
			this->удалениеПоследнегоЭлементаToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->удалениеПоследнегоЭлементаToolStripMenuItem->Text = L"Удаление последнего элемента";
			this->удалениеПоследнегоЭлементаToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::удалениеПоследнегоЭлементаToolStripMenuItem_Click);
			// 
			// заменаЗначенияПоИндексуToolStripMenuItem
			// 
			this->заменаЗначенияПоИндексуToolStripMenuItem->Name = L"заменаЗначенияПоИндексуToolStripMenuItem";
			this->заменаЗначенияПоИндексуToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->заменаЗначенияПоИндексуToolStripMenuItem->Text = L"Замена значения по индексу";
			this->заменаЗначенияПоИндексуToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::заменаЗначенияПоИндексуToolStripMenuItem_Click);
			// 
			// поискИндексаПоЗначениюToolStripMenuItem
			// 
			this->поискИндексаПоЗначениюToolStripMenuItem->Name = L"поискИндексаПоЗначениюToolStripMenuItem";
			this->поискИндексаПоЗначениюToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->поискИндексаПоЗначениюToolStripMenuItem->Text = L"Поиск индекса по значению";
			this->поискИндексаПоЗначениюToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::поискИндексаПоЗначениюToolStripMenuItem_Click);
			// 
			// поискНаибольшегоЭлементаToolStripMenuItem
			// 
			this->поискНаибольшегоЭлементаToolStripMenuItem->Name = L"поискНаибольшегоЭлементаToolStripMenuItem";
			this->поискНаибольшегоЭлементаToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->поискНаибольшегоЭлементаToolStripMenuItem->Text = L"Поиск наибольшего элемента";
			this->поискНаибольшегоЭлементаToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::поискНаибольшегоЭлементаToolStripMenuItem_Click);
			// 
			// очиститьСтруктураToolStripMenuItem
			// 
			this->очиститьСтруктураToolStripMenuItem->Name = L"очиститьСтруктураToolStripMenuItem";
			this->очиститьСтруктураToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->очиститьСтруктураToolStripMenuItem->Text = L"Очистить структуру";
			this->очиститьСтруктураToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::очиститьСтруктураToolStripMenuItem_Click);
			// 
			// тестовыеДанныеToolStripMenuItem
			// 
			this->тестовыеДанныеToolStripMenuItem->Name = L"тестовыеДанныеToolStripMenuItem";
			this->тестовыеДанныеToolStripMenuItem->Size = System::Drawing::Size(307, 22);
			this->тестовыеДанныеToolStripMenuItem->Text = L"Заполнить структуру тестовыми данными";
			this->тестовыеДанныеToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::тестовыеДанныеToolStripMenuItem_Click);
			// 
			// конвертацияВASCIIToolStripMenuItem
			// 
			this->конвертацияВASCIIToolStripMenuItem->Name = L"конвертацияВASCIIToolStripMenuItem";
			this->конвертацияВASCIIToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->конвертацияВASCIIToolStripMenuItem->Text = L"Конвертация в символы";
			this->конвертацияВASCIIToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::конвертацияВASCIIToolStripMenuItem_Click);
			// 
			// тестToolStripMenuItem
			// 
			this->тестToolStripMenuItem->Name = L"тестToolStripMenuItem";
			this->тестToolStripMenuItem->Size = System::Drawing::Size(42, 22);
			this->тестToolStripMenuItem->Text = L"Тест";
			this->тестToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_4::тестToolStripMenuItem_Click);
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
			this->int_label->Text = L"Структура в числовом формате";
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
			this->char_label->Text = L"Структура в символьном формате";
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
	/// Функция присвоения числового значения строковому значению текущей структуры данных 
	/// </summary>
	/// <returns>Числовое значение соответствующее строковому названию</returns>
	private: int struct_id()
	{
		if (current_struct == "Array") return 1;
		else if (current_struct == "Vector") return 2;
		else if (current_struct == "Stack") return 3;
		else if (current_struct == "Queue") return 4;
		else return -1;
	}
	//
	// Процедура, запускающая действия при нажатии "Вывод структуры"
	//
	private: System::Void выводСтруктурыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Добавить элемент"
	//
	private: System::Void добавитьЭлементToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Удаление последнего элемента"
	//
	private: System::Void удалениеПоследнегоЭлементаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Замена значения по индексу"
	//
	private: System::Void заменаЗначенияПоИндексуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Поиск индекса по значению"
	//
	private: System::Void поискИндексаПоЗначениюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (struct_id() != -1)
		{
			int x = this->Left + (this->Width / 2) - 200;
			int y = this->Top + (this->Height / 2) - 100;
				if (!char_is_enable)
				{
					String^ find_value = Interaction::InputBox("Введите значение\r\n\r\n", "Поиск индекса по значению", "", x, y);
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
						MessageBox::Show("Индекс введенного значения — " + Convert::ToString(index), "Найти индекс", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
				}
				else
				{
					String^ find_value = Interaction::InputBox("Введите символ\r\n\r\n", "Поиск индекса по значению", "", x, y);
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
					MessageBox::Show("Индекс введенного значения — " + Convert::ToString(index), "Найти индекс", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Поиск наибольшего элемента"
	//
	private: System::Void поискНаибольшегоЭлементаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
				MessageBox::Show("Наибольшее значение — " + Convert::ToString(index), "Наибольшее значение", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
				MessageBox::Show("Наибольшее значение — " + Convert::ToString(Convert::ToChar(index)) + " (" + Convert::ToString(index) + ")", "Наибольшее значение", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Очистить структуру"
	//
	private: System::Void очиститьСтруктураToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (struct_id() != -1)
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены что хотите очистить структуру?", "Предупреждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Тестовые данных"
	//
	private: System::Void тестовыеДанныеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{	
		if (struct_id() != -1)
		{
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show("Предварительно структура будет очищена. Вы уверены, что хотите ввести тестовые данные?", "Предупреждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
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
		else MessageBox::Show("Структура данных не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура, запускающая действия при нажатии "Array"
	//
	private: System::Void arrayToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Array";
		if (this->Text == "LAB_4") this->Text += " — Array (Статический массив)";
		else this->Text = this->Text->Remove(8) + "Array (Статический массив)";
		this->textBox->Text = gcnew String(arr.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// Процедура, запускающая действия при нажатии "Vector"
	//
	private: System::Void vectorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Vector";
		if (this->Text == "LAB_4") this->Text += " — Vector (Динамический массив)";
		else this->Text = this->Text->Remove(8) + "Vector (Динамический массив)";
		this->textBox->Text = gcnew String(vector.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// Процедура, запускающая действия при нажатии "Stack"
	//
	private: System::Void stackToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Stack";
		if (this->Text == "LAB_4") this->Text += " — Stack (Стек)";
		else this->Text = this->Text->Remove(8) + "Stack (Стек)";
		this->textBox->Text = gcnew String(stack.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// Процедура, запускающая действия при нажатии "Queue"
	//
	private: System::Void queueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->current_struct = "Queue";
		if (this->Text == "LAB_4") this->Text += " — Queue (Очередь)";
		else this->Text = this->Text->Remove(8) + "Queue (Очередь)";
		this->textBox->Text = gcnew String(queue.output().c_str());
		if (char_is_enable) to_char();
	}
	//
	// Процедура конвертацию числовой структуры в символьный формат
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
	// Процедура, запускающая действия при нажатии "Конвертация в символы"
	//
	private: System::Void конвертацияВASCIIToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (char_is_enable) char_is_enable = false;
		else char_is_enable = true;
		to_char();
	}
	/// <summary>
	/// Функция тестирования ввода значений в структуру данных "Array"
	/// </summary>
	/// <returns>Результат тестирования</returns>
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
	/// Функция тестирования ввода значений в структуру данных "Vector"
	/// </summary>
	/// <returns>Результат тестирования</returns>
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
	/// Функция тестирования ввода значений в структуру данных "Stack"
	/// </summary>
	/// <returns>Результат тестирования</returns>
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
	/// Функция тестирования ввода значений в структуру данных "Queue"
	/// </summary>
	/// <returns>Результат тестирования</returns>
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
	/// Функция тестирования ввода значений в структуры данных
	/// </summary>
	/// <returns>Результат тестирования</returns>
	private: int test_cases()
	{
		int result = test1() + test2() + test3() + test4();
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
	private: System::Void тестToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if(test_cases() == 0) 
			MessageBox::Show("Тесты пройдены. Ключевые функции работают корректно.", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//
	//  Процедура, запускающая действия при изменении размера окна
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
