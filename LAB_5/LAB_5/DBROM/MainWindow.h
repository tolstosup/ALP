/*

АЯиП Лабораторная работа #5
Заголовочный файл проекта DBROM
Михайлов Роман, группа 3091, 1 курс
01.04.2024 - 17.04.2024

*/

#pragma once
#include "ConnectionWindow.h"
#include "NewRecord.h"
#include "EditRecord.h"
#include "DeleteRecord.h"
#include "ConnectionWindow.h"
#include "CloseBar.h"

namespace DBROM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace Microsoft::VisualBasic;
	using namespace System::IO;
	using namespace Microsoft::VisualBasic;
	using namespace System::ServiceProcess;

	/// <summary>
	/// Сводка для Visual
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			SaveFileDialog->Filter = "Текстовый файл (*.txt)|*.txt"/*|PDF - файл (*.pdf)|*.pdf"*/;
			this->Show();
			connection_to_constr();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			try
			{
				int q = 0;
				CloseBar^ cb = gcnew CloseBar();
				cb->ShowDialog(this);
				ServiceController^ service = gcnew ServiceController(serviceName);
				if (service->Status != ServiceControllerStatus::Stopped)
				{
					if (q == 0)
					{
						System::Windows::Forms::DialogResult result = MessageBox::Show("Остановить службу локального SQL-сервера?", "Уведомление", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
						q = 1;
						if (result == System::Windows::Forms::DialogResult::Yes)
						{
							service->Stop();
							service->WaitForStatus(ServiceControllerStatus::Stopped, TimeSpan::FromMinutes(1));
							if (service->Status == ServiceControllerStatus::Stopped)
							{
								System::Windows::Forms::DialogResult result = MessageBox::Show("Служба локального SQL-сервера остановлена", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
								if (result == System::Windows::Forms::DialogResult::Yes) {}
							}
						}
					}
				}
			}
			catch (System::Exception^) {}
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: SqlConnection^ connection;								// Строка подключения
	private: String^ data_source = "";								// Название сервера
	private: String^ initial_catalog = "";							// Название базы данных
	private: String^ t_name = "";									// Имя таблицы
	private: ConnectionWindow^ cw = gcnew ConnectionWindow(true);	// Окно подключения
	private: String^ prev_query = "";
	private: String^ serviceName = "";

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ редактированиеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ запросToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выводВФайлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ новаяЗаписьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьЗаписьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьВсеЗаписиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выводТаблицыПоОтветственномуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выводТаблицыПоСтатусуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выводТаблицыПоСрокуСдачиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выводТабToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вПрямомПорядкеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вОбратномПорядкеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ аЯToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ яАToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^ редактированиеЗаписиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ подключениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ подключениеВБДToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ удалитьТаблицуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ пользовательскийSQLзапросToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::ToolStripMenuItem^ выводВФайлToolStripMenuItem1;
	private: System::Windows::Forms::SaveFileDialog^ SaveFileDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ закрытьПрограммуToolStripMenuItem;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->подключениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->подключениеВБДToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->закрытьПрограммуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->редактированиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новаяЗаписьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьЗаписьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьВсеЗаписиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->редактированиеЗаписиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьТаблицуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->запросToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводТабToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводТаблицыПоСтатусуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводТаблицыПоСрокуСдачиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вПрямомПорядкеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вОбратномПорядкеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводТаблицыПоОтветственномуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->аЯToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->яАToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->пользовательскийSQLзапросToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводВФайлToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выводВФайлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->подключениеToolStripMenuItem,
					this->редактированиеToolStripMenuItem, this->запросToolStripMenuItem, this->выводВФайлToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1898, 36);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// подключениеToolStripMenuItem
			// 
			this->подключениеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->информацияToolStripMenuItem,
					this->подключениеВБДToolStripMenuItem, this->закрытьПрограммуToolStripMenuItem
			});
			this->подключениеToolStripMenuItem->Name = L"подключениеToolStripMenuItem";
			this->подключениеToolStripMenuItem->Size = System::Drawing::Size(143, 30);
			this->подключениеToolStripMenuItem->Text = L"Подключение";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(281, 34);
			this->информацияToolStripMenuItem->Text = L"Информация";
			this->информацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::информацияToolStripMenuItem_Click);
			// 
			// подключениеВБДToolStripMenuItem
			// 
			this->подключениеВБДToolStripMenuItem->Name = L"подключениеВБДToolStripMenuItem";
			this->подключениеВБДToolStripMenuItem->Size = System::Drawing::Size(281, 34);
			this->подключениеВБДToolStripMenuItem->Text = L"Подключение в БД";
			this->подключениеВБДToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::подключениеВБДToolStripMenuItem_Click);
			// 
			// закрытьПрограммуToolStripMenuItem
			// 
			this->закрытьПрограммуToolStripMenuItem->Name = L"закрытьПрограммуToolStripMenuItem";
			this->закрытьПрограммуToolStripMenuItem->Size = System::Drawing::Size(281, 34);
			this->закрытьПрограммуToolStripMenuItem->Text = L"Закрыть программу";
			this->закрытьПрограммуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::закрытьПрограммуToolStripMenuItem_Click);
			// 
			// редактированиеToolStripMenuItem
			// 
			this->редактированиеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->новаяЗаписьToolStripMenuItem,
					this->удалитьЗаписьToolStripMenuItem, this->удалитьВсеЗаписиToolStripMenuItem, this->редактированиеЗаписиToolStripMenuItem, this->удалитьТаблицуToolStripMenuItem
			});
			this->редактированиеToolStripMenuItem->Name = L"редактированиеToolStripMenuItem";
			this->редактированиеToolStripMenuItem->Size = System::Drawing::Size(162, 30);
			this->редактированиеToolStripMenuItem->Text = L"Редактирование";
			// 
			// новаяЗаписьToolStripMenuItem
			// 
			this->новаяЗаписьToolStripMenuItem->Name = L"новаяЗаписьToolStripMenuItem";
			this->новаяЗаписьToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->новаяЗаписьToolStripMenuItem->Text = L"Новая запись";
			this->новаяЗаписьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::новаяЗаписьToolStripMenuItem_Click);
			// 
			// удалитьЗаписьToolStripMenuItem
			// 
			this->удалитьЗаписьToolStripMenuItem->Name = L"удалитьЗаписьToolStripMenuItem";
			this->удалитьЗаписьToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->удалитьЗаписьToolStripMenuItem->Text = L"Удалить запись";
			this->удалитьЗаписьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::удалитьЗаписьToolStripMenuItem_Click);
			// 
			// удалитьВсеЗаписиToolStripMenuItem
			// 
			this->удалитьВсеЗаписиToolStripMenuItem->Name = L"удалитьВсеЗаписиToolStripMenuItem";
			this->удалитьВсеЗаписиToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->удалитьВсеЗаписиToolStripMenuItem->Text = L"Удалить все записи";
			this->удалитьВсеЗаписиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::удалитьВсеЗаписиToolStripMenuItem_Click);
			// 
			// редактированиеЗаписиToolStripMenuItem
			// 
			this->редактированиеЗаписиToolStripMenuItem->Name = L"редактированиеЗаписиToolStripMenuItem";
			this->редактированиеЗаписиToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->редактированиеЗаписиToolStripMenuItem->Text = L"Редактирование записи";
			this->редактированиеЗаписиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::редактированиеЗаписиToolStripMenuItem_Click);
			// 
			// удалитьТаблицуToolStripMenuItem
			// 
			this->удалитьТаблицуToolStripMenuItem->Name = L"удалитьТаблицуToolStripMenuItem";
			this->удалитьТаблицуToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->удалитьТаблицуToolStripMenuItem->Text = L"Удалить таблицу";
			this->удалитьТаблицуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::удалитьТаблицуToolStripMenuItem_Click);
			// 
			// запросToolStripMenuItem
			// 
			this->запросToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->выводТабToolStripMenuItem,
					this->выводТаблицыПоСтатусуToolStripMenuItem, this->выводТаблицыПоСрокуСдачиToolStripMenuItem, this->выводТаблицыПоОтветственномуToolStripMenuItem,
					this->пользовательскийSQLзапросToolStripMenuItem
			});
			this->запросToolStripMenuItem->Name = L"запросToolStripMenuItem";
			this->запросToolStripMenuItem->Size = System::Drawing::Size(87, 30);
			this->запросToolStripMenuItem->Text = L"Запрос";
			// 
			// выводТабToolStripMenuItem
			// 
			this->выводТабToolStripMenuItem->Name = L"выводТабToolStripMenuItem";
			this->выводТабToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->выводТабToolStripMenuItem->Text = L"Вывод таблицы";
			this->выводТабToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::выводТабToolStripMenuItem_Click);
			// 
			// выводТаблицыПоСтатусуToolStripMenuItem
			// 
			this->выводТаблицыПоСтатусуToolStripMenuItem->Name = L"выводТаблицыПоСтатусуToolStripMenuItem";
			this->выводТаблицыПоСтатусуToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->выводТаблицыПоСтатусуToolStripMenuItem->Text = L"Вывод таблицы по статусу";
			this->выводТаблицыПоСтатусуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::выводТаблицыПоСтатусуToolStripMenuItem_Click);
			// 
			// выводТаблицыПоСрокуСдачиToolStripMenuItem
			// 
			this->выводТаблицыПоСрокуСдачиToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->вПрямомПорядкеToolStripMenuItem,
					this->вОбратномПорядкеToolStripMenuItem
			});
			this->выводТаблицыПоСрокуСдачиToolStripMenuItem->Name = L"выводТаблицыПоСрокуСдачиToolStripMenuItem";
			this->выводТаблицыПоСрокуСдачиToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->выводТаблицыПоСрокуСдачиToolStripMenuItem->Text = L"Вывод таблицы по сроку сдачи";
			// 
			// вПрямомПорядкеToolStripMenuItem
			// 
			this->вПрямомПорядкеToolStripMenuItem->Name = L"вПрямомПорядкеToolStripMenuItem";
			this->вПрямомПорядкеToolStripMenuItem->Size = System::Drawing::Size(285, 34);
			this->вПрямомПорядкеToolStripMenuItem->Text = L"В прямом порядке";
			this->вПрямомПорядкеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::вПрямомПорядкеToolStripMenuItem_Click);
			// 
			// вОбратномПорядкеToolStripMenuItem
			// 
			this->вОбратномПорядкеToolStripMenuItem->Name = L"вОбратномПорядкеToolStripMenuItem";
			this->вОбратномПорядкеToolStripMenuItem->Size = System::Drawing::Size(285, 34);
			this->вОбратномПорядкеToolStripMenuItem->Text = L"В обратном порядке";
			this->вОбратномПорядкеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::вОбратномПорядкеToolStripMenuItem_Click);
			// 
			// выводТаблицыПоОтветственномуToolStripMenuItem
			// 
			this->выводТаблицыПоОтветственномуToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->аЯToolStripMenuItem,
					this->яАToolStripMenuItem
			});
			this->выводТаблицыПоОтветственномуToolStripMenuItem->Name = L"выводТаблицыПоОтветственномуToolStripMenuItem";
			this->выводТаблицыПоОтветственномуToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->выводТаблицыПоОтветственномуToolStripMenuItem->Text = L"Вывод таблицы по ответственному";
			// 
			// аЯToolStripMenuItem
			// 
			this->аЯToolStripMenuItem->Name = L"аЯToolStripMenuItem";
			this->аЯToolStripMenuItem->Size = System::Drawing::Size(154, 34);
			this->аЯToolStripMenuItem->Text = L"А - Я";
			this->аЯToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::аЯToolStripMenuItem_Click);
			// 
			// яАToolStripMenuItem
			// 
			this->яАToolStripMenuItem->Name = L"яАToolStripMenuItem";
			this->яАToolStripMenuItem->Size = System::Drawing::Size(154, 34);
			this->яАToolStripMenuItem->Text = L"Я - А";
			this->яАToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::яАToolStripMenuItem_Click);
			// 
			// пользовательскийSQLзапросToolStripMenuItem
			// 
			this->пользовательскийSQLзапросToolStripMenuItem->Name = L"пользовательскийSQLзапросToolStripMenuItem";
			this->пользовательскийSQLзапросToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->пользовательскийSQLзапросToolStripMenuItem->Text = L"Пользовательский SQL-запрос";
			this->пользовательскийSQLзапросToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::пользовательскийSQLзапросToolStripMenuItem_Click);
			// 
			// выводВФайлToolStripMenuItem1
			// 
			this->выводВФайлToolStripMenuItem1->Name = L"выводВФайлToolStripMenuItem1";
			this->выводВФайлToolStripMenuItem1->Size = System::Drawing::Size(142, 30);
			this->выводВФайлToolStripMenuItem1->Text = L"Вывод в файл";
			this->выводВФайлToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::выводВФайлToolStripMenuItem_Click);
			// 
			// выводВФайлToolStripMenuItem
			// 
			this->выводВФайлToolStripMenuItem->Name = L"выводВФайлToolStripMenuItem";
			this->выводВФайлToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 40;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1898, 988);
			this->dataGridView1->TabIndex = 16;
			// 
			// Column1
			// 
			this->Column1->FillWeight = 20;
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 8;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Название";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Описание";
			this->Column3->MinimumWidth = 8;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Статус";
			this->Column4->MinimumWidth = 8;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Ответственный";
			this->Column5->MinimumWidth = 8;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Срок сдачи";
			this->Column6->MinimumWidth = 8;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1898, 1024);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(640, 360);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DBROM";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	// Подключение к БД
	//
	private: void connect_to_DB()
	{
		SqlConnectionStringBuilder^ strbild = gcnew SqlConnectionStringBuilder();
		strbild->DataSource = data_source;
		strbild->InitialCatalog = initial_catalog;
		strbild->IntegratedSecurity = true;

		connection = gcnew SqlConnection(Convert::ToString(strbild));
	}
	//
	// Процедура создания новой записи
	//
	private: void insert_data(String^ label, String^ description, String^ status, String^ admin, String^ deadline)
	{
		connect_to_DB();
		String^ command_text = "INSERT INTO " + t_name +"(label, description, status, admin, deadline) VALUES(@Label, @Description, @Status, @Admin, @Deadline)";
		SqlCommand^ cmd = gcnew SqlCommand(command_text, connection);
		cmd->Parameters->AddWithValue("@Label", label);
		cmd->Parameters->AddWithValue("@Description", description);
		cmd->Parameters->AddWithValue("@Status", status);
		cmd->Parameters->AddWithValue("@Admin", admin);
		cmd->Parameters->AddWithValue("@Deadline", Convert::ToDateTime(deadline));
		connection->Open();
		cmd->ExecuteNonQuery();
		connection->Close();
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// Процедура чтения одного ряда из таблицы запроса
	//
	private: void read_single_row(DataGridView^ dgw, IDataRecord^ record)
	{
		dgw->Rows->Add(record->GetInt32(0), record->GetString(1), record->GetString(2), record->GetString(3), record->GetString(4), Convert::ToString(record->GetDateTime(5))->Remove(10));
	}
	//
	// Процедура вывода полученной таблицы
	//
	private: void output_table(DataGridView^ dgw, String^ query)
	{
		prev_query = query;
		dgw->Rows->Clear();
		connect_to_DB();
		SqlCommand^ cmd = gcnew SqlCommand(query, connection);
		connection->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();
		while (reader->Read())
		{
			read_single_row(dgw, reader);
		}
		reader->Close();
		connection->Close();
	}
	//
	// Процедура запускающая действия при нажатии "Новая запись"
	//
	private: System::Void новаяЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		NewRecord^ nr = gcnew NewRecord();
		nr->ShowDialog(this);
		if (nr->get_label() != "" && nr->get_description() != "" && nr->get_status() != "" && nr->get_admin() != "" && Convert::ToString(nr->get_deadline()) != "")
		{
			insert_data(nr->get_label(), nr->get_description(), nr->get_status(), nr->get_admin(), Convert::ToString(nr->get_deadline()));
		}
	}
	//
	// Процедура запускающая действия при нажатии "Удалить все записи"
	//
	private: System::Void удалитьВсеЗаписиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить все записи?", "Уведомление", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			connect_to_DB();
			String^ command_text = "DELETE " + t_name;
			SqlCommand^ cmd = gcnew SqlCommand(command_text, connection);
			connection->Open();
			cmd->ExecuteNonQuery();
			connection->Close();
		}
	}
	//
	// Процедура запускающая действия при нажатии "Вывод таблицы"
	//
	private: System::Void выводТабToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// Процедура запускающая действия при нажатии "Вывод таблицы по статусу"
	//
	private: System::Void выводТаблицыПоСтатусуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY status");
	}
	//
	// Процедура запускающая действия при нажатии "А - Я"
	//
	private: System::Void аЯToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY admin ASC");	/*id, admin, label, description, status, deadline FROM*/
	}
	//
	// Процедура запускающая действия при нажатии "Я - А"
	//	   
	private: System::Void яАToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY admin DESC"); /*id, admin, label, description, status, deadline FROM*/
	}
	//
	// Процедура запускающая действия при нажатии "В прямом порядке"
	//
	private: System::Void вПрямомПорядкеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY deadline ASC");
	}
	//
	// Процедура запускающая действия при нажатии "В обратном порядке"
	//
	private: System::Void вОбратномПорядкеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY deadline DESC");
	}
	//
	// Процедура запускающая действия при нажатии "Удалить запись"
	//
	private: System::Void удалитьЗаписьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		DeleteRecord^ dr = gcnew DeleteRecord(data_source, initial_catalog, t_name);
		dr->ShowDialog(this);
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// Процедура запускающая действия при нажатии "Редактирование записи"
	//
	private: System::Void редактированиеЗаписиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		EditRecord^ er = gcnew EditRecord(data_source, initial_catalog, t_name);
		er->ShowDialog(this);
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// Процедура запускающая действия при нажатии "Информация"
	//
	private: System::Void информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("Для работы программы необходимо подключиться к SQL серверу. На сервере необходимо создать базу дынных и таблицу с произвольными названиями.\r\n\r\nДля корректной работы программы таблица базы данных должна удовлетворять следующим условиям:\r\n1. У колонок должны быть следующие названия, сначала идет имя колонки, в скобках тип данных: ID (int), label (varchar(200)), description (varchar(200)), status (varchar(200)), admin (varchar(200)), deadline (date)\r\n2. У колонки ID должен быть включён параметр \"Identity Specification\"\r\n3. У всех колонок должен быть отключён параметр \"Allow Nulls\"\r\n\r\nДля подключения к созданной БД выберите \"Подключение к БД\", в открывшемся окне введите название сервера и базы данных", "Информация о подключении к локальному SQL серверу", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//
	// Процедура подключения к БД при вызове конструктора
	//
	private: void connection_to_constr()
	{
		try
		{
			ConnectionWindow^ cwc = gcnew ConnectionWindow(false);
			cwc->ShowDialog(this);
			data_source = cwc->get_DS();
			initial_catalog = cwc->get_IC();
			t_name = cwc->get_table_name();
			serviceName = cw->get_serv_name();
			if (cwc->ex == "1")
			{
				this->Close();
			}
			else
			{
				if (data_source == "" && initial_catalog == "" && this->t_name == "") this->Close();
				else
				{
					output_table(dataGridView1, "SELECT * FROM " + t_name);

					if (data_source != "" && initial_catalog != "" && t_name != "")
					{
						if (this->Text != "DBROM") this->Text = this->Text->Remove(5) + " — " + t_name;
						else this->Text = this->Text + " — " + t_name;
					}
				}
			}
			delete cwc;
		}
		catch (System::ObjectDisposedException^) { this->Close(); }
	}
	//
	// Процедура подключения в БД
	//
	private: void connection_to()
	{
		ConnectionWindow^ cw = gcnew ConnectionWindow(true);
		cw->ShowDialog(this);
		data_source = cw->get_DS();
		initial_catalog = cw->get_IC();
		t_name = cw->get_table_name();
		serviceName = cw->get_serv_name();
		if(cw->ex != "1")
		{
			if (this->Text != "DBROM") this->Text = this->Text->Remove(5) + " — " + t_name;
			else this->Text = this->Text + " — " + t_name;
		}
	}
	//
	// Процедура запускающая действия при нажатии "Подключение к БД"
	//
	private: System::Void подключениеВБДToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		connection_to();
		if(t_name != "")
			output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// Процедура запускающая действия при нажатии "Удалить таблицу"
	//
	private: System::Void удалитьТаблицуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить эту таблицу?", "Уведомление", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			dataGridView1->Rows->Clear();
			connect_to_DB();
			String^ query = "DROP TABLE " + t_name;
			SqlCommand^ cmd = gcnew SqlCommand(query, connection);
			connection->Open();
			cmd->ExecuteNonQuery();
			connection->Close();
			this->Text = "DBROM";
			подключениеВБДToolStripMenuItem_Click(sender, e);
		}
	}
	//
	//
	//
	private: System::Void выводВФайлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ path;
		if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			path = SaveFileDialog->FileName;
			if (path != "")
			{
				StreamWriter^ writer = gcnew StreamWriter(path, false);
				writer->Close();
			}
		}
		if (path != nullptr)
		{

		String^ data = "";
		connect_to_DB();
		SqlCommand^ cmd = gcnew SqlCommand(prev_query, connection);
		connection->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();
		while (reader->Read())
		{
			data += "ID записи:\t" + reader->GetInt32(0) + "\r\nНазвание:\t" + reader->GetString(1) + "\r\nОписание:\t" + reader->GetString(2) + "\r\nСтатус:\t\t" + reader->GetString(3) + "\r\nОтветсвенный:\t" + reader->GetString(4) + "\r\nСрок сдачи:\t" + Convert::ToString(reader->GetDateTime(5))->Remove(10) + "\r\n\r\n";
		}
		reader->Close();
		connection->Close();

			StreamWriter^ writer = gcnew StreamWriter(path);
			writer->Write(data);
			writer->Close();
			MessageBox::Show("Данных сохранены в файл по адресу: " + path, "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	//
	// Процедура запускающая действия при нажатии "Пользовательский SQL-запрос"
	//
	private: System::Void пользовательскийSQLзапросToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		{
			connect_to_DB();
			String^ query = "SELECT TOP(1000)[ID], [label], [description], [status], [admin], [deadline] FROM[" + t_name + "]";
			SqlCommand^ cmd = gcnew SqlCommand(query, connection);
			connection->Open();
			cmd->ExecuteNonQuery();
			connection->Close();
		}

		int x = this->Left + (this->Width / 2) - 200;
		int y = this->Top + (this->Height / 2) - 100;
		int check = 0;
		String^ pr_q = prev_query;
		String^ query = "";
		query = Interaction::InputBox("Введите любой SQL-запрос, за исключением запроса на выборку (в этой функции данные не выводятся на экран)", "SQL-запрос", query, x, y);
		try
		{
			//output_table(dataGridView1, query);
			connect_to_DB();
			SqlCommand^ cmd = gcnew SqlCommand(query, connection);
			connection->Open();
			cmd->ExecuteNonQuery();
			connection->Close();
			MessageBox::Show("SQL-запрос выполнен", "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^)
		{
			MessageBox::Show("Введён некорректный SQL-запрос", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			prev_query = pr_q;
		}
		output_table(dataGridView1, "SELECT TOP(1000)[ID], [label], [description], [status], [admin], [deadline] FROM[" + t_name + "]");
	}

	private: System::Void закрытьПрограммуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};
}