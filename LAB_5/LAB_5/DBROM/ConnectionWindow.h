/*

АЯиП Лабораторная работа #5
Заголовочный файл проекта DBROM
Михайлов Роман, группа 3091, 1 курс
01.04.2024 - 17.04.2024

*/

#include "CloseBar.h"

#pragma once

namespace DBROM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SqlClient;
	using namespace System::Text;
	using namespace System::IO;
	using namespace System::ServiceProcess;

	/// <summary>
	/// Сводка для ConnectionWindow
	/// </summary>
	public ref class ConnectionWindow : public System::Windows::Forms::Form
	{
	public:
		ConnectionWindow(bool not_constr)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			get_from_file();
			this->not_constr = not_constr;
			if (this->service_textBox->Text != "" && not_constr == false)
			{
				try
				{
					ServiceController^ service = gcnew ServiceController(this->service_textBox->Text);
					if (service->Status == ServiceControllerStatus::Running)
					{
						is_enable = true;
					}
					else
					{
						is_enable = false;
					}
				}
				catch (System::ArgumentException^) { is_enable = false; }
				catch (System::InvalidOperationException^) { is_enable = false; }
			}
			start_check();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ConnectionWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: String^ ds = "";			// Строка настройки подключения к БД DataSource
	private: String^ ic = "";			// Строка настройки подключения к БД InitialCatalog
	private: String^ tn = "";			// Имя таблицы к которой происходит подключение
	private: String^ serv = "";			// Имя службы локального SQL сервера
	public: String^ ex = "";			// Передаваемая переменная, обозначающая закрытие окна присоединения
	private: bool not_constr;			// Переменная, обозначающая открытие окна не через конструктор
	public: bool  is_enable = false;	// 

	private: System::Windows::Forms::TextBox^ DS_textBox;
	private: System::Windows::Forms::TextBox^ IC_textBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Button^ rename_button;
	private: SqlConnection^ connection;
	private: System::Windows::Forms::TextBox^ table_name_textBox;
	private: System::Windows::Forms::ComboBox^ tables_comboBox;
	private: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::TextBox^ service_textBox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ exist_checkBox;
	private: System::Windows::Forms::Label^ create_label;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConnectionWindow::typeid));
			this->DS_textBox = (gcnew System::Windows::Forms::TextBox());
			this->IC_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->rename_button = (gcnew System::Windows::Forms::Button());
			this->table_name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->tables_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->service_textBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->exist_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->create_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DS_textBox
			// 
			this->DS_textBox->Location = System::Drawing::Point(176, 77);
			this->DS_textBox->Name = L"DS_textBox";
			this->DS_textBox->Size = System::Drawing::Size(363, 26);
			this->DS_textBox->TabIndex = 0;
			this->DS_textBox->TextChanged += gcnew System::EventHandler(this, &ConnectionWindow::DS_textBox_TextChanged);
			// 
			// IC_textBox
			// 
			this->IC_textBox->Location = System::Drawing::Point(176, 127);
			this->IC_textBox->Name = L"IC_textBox";
			this->IC_textBox->Size = System::Drawing::Size(363, 26);
			this->IC_textBox->TabIndex = 1;
			this->IC_textBox->TextChanged += gcnew System::EventHandler(this, &ConnectionWindow::IC_textBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Сервер:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"База данных:";
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(237, 297);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(145, 40);
			this->exit_button->TabIndex = 12;
			this->exit_button->Text = L"Отмена";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &ConnectionWindow::exit_button_Click);
			// 
			// rename_button
			// 
			this->rename_button->Location = System::Drawing::Point(394, 297);
			this->rename_button->Name = L"rename_button";
			this->rename_button->Size = System::Drawing::Size(145, 40);
			this->rename_button->TabIndex = 11;
			this->rename_button->Text = L"Подключиться";
			this->rename_button->UseVisualStyleBackColor = true;
			this->rename_button->Click += gcnew System::EventHandler(this, &ConnectionWindow::connect_button_Click);
			// 
			// table_name_textBox
			// 
			this->table_name_textBox->Enabled = false;
			this->table_name_textBox->Location = System::Drawing::Point(219, 227);
			this->table_name_textBox->Name = L"table_name_textBox";
			this->table_name_textBox->Size = System::Drawing::Size(320, 26);
			this->table_name_textBox->TabIndex = 18;
			// 
			// tables_comboBox
			// 
			this->tables_comboBox->Enabled = false;
			this->tables_comboBox->Location = System::Drawing::Point(375, 177);
			this->tables_comboBox->Name = L"tables_comboBox";
			this->tables_comboBox->Size = System::Drawing::Size(164, 28);
			this->tables_comboBox->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(147, 20);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Название службы:";
			// 
			// service_textBox
			// 
			this->service_textBox->Location = System::Drawing::Point(176, 27);
			this->service_textBox->Name = L"service_textBox";
			this->service_textBox->Size = System::Drawing::Size(228, 26);
			this->service_textBox->TabIndex = 21;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(410, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 33);
			this->button1->TabIndex = 22;
			this->button1->Text = L"Запуск";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ConnectionWindow::button1_Click);
			// 
			// exist_checkBox
			// 
			this->exist_checkBox->AutoSize = true;
			this->exist_checkBox->Location = System::Drawing::Point(22, 177);
			this->exist_checkBox->Name = L"exist_checkBox";
			this->exist_checkBox->Size = System::Drawing::Size(351, 24);
			this->exist_checkBox->TabIndex = 23;
			this->exist_checkBox->Text = L"Подключиться к существующей таблице:";
			this->exist_checkBox->UseVisualStyleBackColor = true;
			this->exist_checkBox->CheckedChanged += gcnew System::EventHandler(this, &ConnectionWindow::exist_checkBox_CheckedChanged);
			// 
			// create_label
			// 
			this->create_label->AutoSize = true;
			this->create_label->Enabled = false;
			this->create_label->Location = System::Drawing::Point(18, 227);
			this->create_label->Name = L"create_label";
			this->create_label->Size = System::Drawing::Size(195, 20);
			this->create_label->TabIndex = 24;
			this->create_label->Text = L"Создать новую таблицу:";
			// 
			// ConnectionWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(551, 362);
			this->Controls->Add(this->create_label);
			this->Controls->Add(this->exist_checkBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->service_textBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tables_comboBox);
			this->Controls->Add(this->table_name_textBox);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->rename_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->IC_textBox);
			this->Controls->Add(this->DS_textBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ConnectionWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Подключение";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	//	Процедура запуска службы SQL-сервера
	//
	private: void start_service(String^ serviceName)
	{
		ServiceController^ service = gcnew ServiceController(serviceName);
		try
		{
			if (service->Status != ServiceControllerStatus::Running)
			{
				service->Start();
				is_enable = true;
			}
			else if (service->Status == ServiceControllerStatus::Running)
			{
				is_enable = true;
			}
		}
		catch (System::Exception^)
		{
			MessageBox::Show("Такой службы нет", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->service_textBox->Text = "";
		}
		serv = this->service_textBox->Text;
	}

	public: String^ get_serv_name()
	{
		return this->service_textBox->Text;
	}
	//
	//	Функция получения значений из поля "Сервер"
	//
	public: String^ get_DS()
	{
		return this->DS_textBox->Text;
	}
	//
	// Функция получения значений из поля "База данных"
	//
	public: String^ get_IC()
	{
		return this->IC_textBox->Text;
	}
	//
	// Функция получения значений переменной tn
	//
	public: String^ get_table_name()
	{
		return tn;
	}
	//
	//	Процедура сохранения параметров текущего подключения
	//
	private: void save_curr_to_file()
	{
		StreamWriter^ writer = gcnew StreamWriter("ConnectionProperties.dbrom");
		writer->Write(this->service_textBox->Text + "\r\n" + this->DS_textBox->Text + "\r\n" + this->IC_textBox->Text);
		writer->Close();
	}
	//
	//	Процедура чтения параметров предыдущего подключения
	//
	private: void get_from_file()
	{
		if (File::Exists("ConnectionProperties.dbrom"))
		{
			StreamReader^ reader = gcnew StreamReader("ConnectionProperties.dbrom");
			String^ serv = reader->ReadLine();
			String^ ds = reader->ReadLine();
			String^ ic = reader->ReadLine();
			reader->Close();
			this->service_textBox->Text = serv;
			this->DS_textBox->Text = ds;
			this->IC_textBox->Text = ic;
		}
	}
	//
	//	Процедура запуска действий при нажатии кнопки "Подключиться"
	//
	private: System::Void connect_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ServiceController^ service = gcnew ServiceController(this->service_textBox->Text);
		if (service->Status == ServiceControllerStatus::Running)
		{
			if (!db_exist())
				MessageBox::Show("Некорректные данные подключения (неверно указан сервер или база данных)", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			else
			{
				try
				{
					if (this->tables_comboBox->SelectedIndex != -1 || this->table_name_textBox->Text != "")
					{
						save_curr_to_file();
						if (exist_checkBox->Checked == true)
						{
							tn = Convert::ToString(tables_comboBox->Items[tables_comboBox->SelectedIndex]);
							this->Close();
						}
						else if (exist_checkBox->Checked == false)
						{
							tn = this->table_name_textBox->Text;
							if (check_table())
								create_table(table_name_textBox->Text);
						}
					}
					else MessageBox::Show("Таблицы не выбрана", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				catch (System::Exception^) {}
			}
		}
		else MessageBox::Show("SQL служба не запущена", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//
	// Процедура запуска действий при нажатии кнопки "Отмена"
	//
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->ex = "1";
		this->tables_comboBox->Items->Add("");
		this->tables_comboBox->SelectedIndex = 0;
		this->Close();
	}
	//
	// Процедура подключения к БД
	//
	private: void connect_to_DB()
	{
		SqlConnectionStringBuilder^ strbild = gcnew SqlConnectionStringBuilder();
		strbild->DataSource = ds;
		strbild->InitialCatalog = ic;
		strbild->IntegratedSecurity = true;

		connection = gcnew SqlConnection(Convert::ToString(strbild));
	}
	//
	//	Процедура создания таблицы в БД
	//
	private: void create_table(String^ t_name)
	{
		connect_to_DB();
		String^ command_text = "CREATE TABLE " + t_name + " (ID INT IDENTITY(1, 1) PRIMARY KEY NOT NULL, label varchar(200) NOT NULL, description varchar(200) NOT NULL, status varchar(200) NOT NULL, admin varchar(200) NOT NULL, deadline date NOT NULL)";
		connection->Open();
		SqlCommand^ cmd = gcnew SqlCommand(command_text, connection);
		SqlDataReader^ reader = cmd->ExecuteReader();
		connection->Close();
		this->Close();
	}
	//
	//	Процедура проверки существования таблицы с введённым названием
	//
	private: bool check_table() 
	{
		if (DS_textBox->Text != "" && IC_textBox->Text != "")
		{
			String^ query = "IF EXISTS (SELECT 1 FROM sys.tables WHERE name = '" + this->table_name_textBox->Text + "') SELECT '1' as prove ELSE SELECT '0' as prove";
			connect_to_DB();
			SqlCommand^ cmd = gcnew SqlCommand(query, connection);
			connection->Open();
			SqlDataReader^ reader = cmd->ExecuteReader();
			String^ check = "";
			while (reader->Read()) check = reader["prove"]->ToString();
			connection->Close();
			if (check == "1")
			{
				MessageBox::Show("Таблица с таким именем уже существует", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
			else if (check == "0") return true;
		}
	}
	//
	// Процедура присваивания глобальной переменной ds значений в поле "Сервер"
	//
	private: System::Void DS_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ds = this->DS_textBox->Text;
	}
	//
	// Процедура присваивания глобальной переменной ic значений в поле "База данных" и включение скрытых полей
	//
	private: System::Void IC_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ic = this->IC_textBox->Text;
		if (this->service_textBox->Text != "" && is_enable)
		{
			ServiceController^ service = gcnew ServiceController(this->service_textBox->Text);
			if (service->Status == ServiceControllerStatus::Running)
			{
				if (this->IC_textBox->Text != "" && this->DS_textBox->Text != "")
				{
					this->exist_checkBox->Visible = true;
					this->tables_comboBox->Enabled = true;
					this->table_name_textBox->Enabled = false;
					this->create_label->Enabled = false;
				}
				else
				{
					this->exist_checkBox->Visible = false;
					this->tables_comboBox->Enabled = false;
					this->table_name_textBox->Enabled = true;
					this->create_label->Enabled = true;
				}
			}
		}
	}
	//
	// Процедура проверки активности comboBox "Подключиться к существующей таблице"
	//
	private: void enable_check()
	{
		if (exist_checkBox->Checked == true)
		{
			this->create_label->Enabled = false;
			this->table_name_textBox->Enabled = false;
			this->tables_comboBox->Enabled = true;
		}
		else
		{
			this->create_label->Enabled = true;
			this->table_name_textBox->Enabled = true;
			this->tables_comboBox->Enabled = false;
		}
	}
	//
	// Процедура отслеживания активности comboBox "Подключиться к существующей таблице"
	//
	private: System::Void exist_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (db_exist())
		{
			if (is_enable)
			{
				enable_check();
				this->tables_comboBox->Items->Clear();
				table_names();
			}
			else
			{
				if (this->exist_checkBox->Checked == true) MessageBox::Show("Запустите службу локального SQL-сервера", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->exist_checkBox->Checked = false;
			}
		}
		else
		{
			this->tables_comboBox->Enabled = false;
			if(this->exist_checkBox->Checked == true)
				MessageBox::Show("Некорректные данные подключения (неверно указан сервер или база данных) или служба локального SQL-сервера не запущена", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->exist_checkBox->Checked = false;
		}
	}
	//
	//	Процедура ввода в список названий таблицы значения из текущей базы данных по специальным параметрам
	//
	private: void table_names()
	{
		try
		{
			String^ query = "select distinct table_name from information_schema.columns where column_name in ('label','description','status','admin','deadline')";
			connect_to_DB();
			connection->Open();

			SqlCommand^ cmd = gcnew SqlCommand(query, connection);
			SqlDataReader^ reader = cmd->ExecuteReader();

			String^ name_temp = "";
			while (reader->Read())
			{
				name_temp = reader["table_name"]->ToString();
				tables_comboBox->Items->Add(String::Format("{0}", name_temp));
			}
			connection->Close();
		}
		catch (System::InvalidOperationException^) {}
		catch (System::IO::IOException^) {}
		catch (System::ObjectDisposedException^) {}
	}
	//
	//	Процедура запускающая действия при нажатии кнопки "Запуск"
	//
	private: void start()
	{
		if (this->service_textBox->Text != "")
		{
			start_service(this->service_textBox->Text);
			System::Threading::Thread::Sleep(1000);
			if (this->service_textBox->Text != "" && serv == this->service_textBox->Text)
			{
				ServiceController^ service = gcnew ServiceController(this->service_textBox->Text);
				if (service->Status == ServiceControllerStatus::Running)
				{
					this->DS_textBox->Enabled = true;
					this->IC_textBox->Enabled = true;
					if (DS_textBox->Text != "" && IC_textBox->Text != "") this->create_label->Enabled = true;
					save_curr_to_file();
				}
				else
				{
					this->DS_textBox->Enabled = false;
					this->IC_textBox->Enabled = false;
				}
			}
			if (this->DS_textBox->Text != "" && this->IC_textBox->Text != "" && this->service_textBox->Text != "")
			{
				this->exist_checkBox->Visible = true;
				this->create_label->Enabled = true;
				this->table_name_textBox->Enabled = true;
			}
			else
			{
				this->tables_comboBox->Enabled = false;
				this->exist_checkBox->Visible = false;
				this->create_label->Enabled = false;
				this->table_name_textBox->Enabled = false;
			}
		}
	}

	private: void start_check()
	{
		if (this->service_textBox->Text != "")
		{
			if (this->service_textBox->Text != "" && serv == this->service_textBox->Text)
			{
				ServiceController^ service = gcnew ServiceController(this->service_textBox->Text);
				if (service->Status == ServiceControllerStatus::Running)
				{
					this->DS_textBox->Enabled = true;
					this->IC_textBox->Enabled = true;
					if (DS_textBox->Text != "" && IC_textBox->Text != "") this->create_label->Enabled = true;
					save_curr_to_file();
				}
				else
				{
					this->DS_textBox->Enabled = false;
					this->IC_textBox->Enabled = false;
				}
			}
			if (this->DS_textBox->Text != "" && this->IC_textBox->Text != "" && this->service_textBox->Text != "")
			{
				this->exist_checkBox->Visible = true;
				this->create_label->Enabled = true;
				this->table_name_textBox->Enabled = true;
			}
			else
			{
				this->tables_comboBox->Enabled = false;
				this->exist_checkBox->Visible = false;
				this->create_label->Enabled = false;
				this->table_name_textBox->Enabled = false;
			}
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		start();
	}

	private: bool db_exist()
	{
		if (this->exist_checkBox->Checked == true)
		{
			connect_to_DB();
			SqlCommand^ query = gcnew SqlCommand("IF DB_ID('" + this->ds + "') IS NOT NULL SELECT '1' as prove ELSE SELECT '0' as prove", connection);
			try
			{
				/*CloseBar^ cb = gcnew CloseBar();
				cb->Show();*/
				connection->Open();
			}
			catch (System::Exception^) 
			{
				return false;
			}
		/*	catch (System::InvalidOperationException^)
			{
				return false;
			}
			catch (System::Data::SqlClient::SqlException^)
			{
				return false;
			}
			catch (System::Configuration::ConfigurationException^)
			{
				return false;
			}
			catch (Win32Exception^)
			{
				return false;
			}*/
		}
		return true;
	}
};
}