/*

���� ������������ ������ #5
������������ ���� ������� DBROM
�������� �����, ������ 3091, 1 ����
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
	/// ������ ��� Visual
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			SaveFileDialog->Filter = "��������� ���� (*.txt)|*.txt"/*|PDF - ���� (*.pdf)|*.pdf"*/;
			this->Show();
			connection_to_constr();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
						System::Windows::Forms::DialogResult result = MessageBox::Show("���������� ������ ���������� SQL-�������?", "�����������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
						q = 1;
						if (result == System::Windows::Forms::DialogResult::Yes)
						{
							service->Stop();
							service->WaitForStatus(ServiceControllerStatus::Stopped, TimeSpan::FromMinutes(1));
							if (service->Status == ServiceControllerStatus::Stopped)
							{
								System::Windows::Forms::DialogResult result = MessageBox::Show("������ ���������� SQL-������� �����������", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	private: SqlConnection^ connection;								// ������ �����������
	private: String^ data_source = "";								// �������� �������
	private: String^ initial_catalog = "";							// �������� ���� ������
	private: String^ t_name = "";									// ��� �������
	private: ConnectionWindow^ cw = gcnew ConnectionWindow(true);	// ���� �����������
	private: String^ prev_query = "";
	private: String^ serviceName = "";

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������SQL������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem1;
	private: System::Windows::Forms::SaveFileDialog^ SaveFileDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������SQL������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->�����������ToolStripMenuItem,
					this->��������������ToolStripMenuItem, this->������ToolStripMenuItem, this->����������ToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1898, 36);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����������ToolStripMenuItem,
					this->��������������ToolStripMenuItem, this->����������������ToolStripMenuItem
			});
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(143, 30);
			this->�����������ToolStripMenuItem->Text = L"�����������";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(281, 34);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::����������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(281, 34);
			this->��������������ToolStripMenuItem->Text = L"����������� � ��";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(281, 34);
			this->����������������ToolStripMenuItem->Text = L"������� ���������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::����������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->�����������ToolStripMenuItem,
					this->�������������ToolStripMenuItem, this->����������������ToolStripMenuItem, this->��������������������ToolStripMenuItem, this->��������������ToolStripMenuItem
			});
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(162, 30);
			this->��������������ToolStripMenuItem->Text = L"��������������";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->�����������ToolStripMenuItem->Text = L"����� ������";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::�����������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->�������������ToolStripMenuItem->Text = L"������� ������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::�������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->����������������ToolStripMenuItem->Text = L"������� ��� ������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::����������������ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->��������������������ToolStripMenuItem->Text = L"�������������� ������";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��������������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(308, 34);
			this->��������������ToolStripMenuItem->Text = L"������� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��������������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->��������ToolStripMenuItem,
					this->���������������������ToolStripMenuItem, this->������������������������ToolStripMenuItem, this->����������������������������ToolStripMenuItem,
					this->����������������SQL������ToolStripMenuItem
			});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(87, 30);
			this->������ToolStripMenuItem->Text = L"������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->��������ToolStripMenuItem->Text = L"����� �������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��������ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->���������������������ToolStripMenuItem->Text = L"����� ������� �� �������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::���������������������ToolStripMenuItem_Click);
			// 
			// ������������������������ToolStripMenuItem
			// 
			this->������������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem
			});
			this->������������������������ToolStripMenuItem->Name = L"������������������������ToolStripMenuItem";
			this->������������������������ToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->������������������������ToolStripMenuItem->Text = L"����� ������� �� ����� �����";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(285, 34);
			this->��������������ToolStripMenuItem->Text = L"� ������ �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(285, 34);
			this->����������������ToolStripMenuItem->Text = L"� �������� �������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::����������������ToolStripMenuItem_Click);
			// 
			// ����������������������������ToolStripMenuItem
			// 
			this->����������������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��ToolStripMenuItem,
					this->��ToolStripMenuItem
			});
			this->����������������������������ToolStripMenuItem->Name = L"����������������������������ToolStripMenuItem";
			this->����������������������������ToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->����������������������������ToolStripMenuItem->Text = L"����� ������� �� ��������������";
			// 
			// ��ToolStripMenuItem
			// 
			this->��ToolStripMenuItem->Name = L"��ToolStripMenuItem";
			this->��ToolStripMenuItem->Size = System::Drawing::Size(154, 34);
			this->��ToolStripMenuItem->Text = L"� - �";
			this->��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��ToolStripMenuItem_Click);
			// 
			// ��ToolStripMenuItem
			// 
			this->��ToolStripMenuItem->Name = L"��ToolStripMenuItem";
			this->��ToolStripMenuItem->Size = System::Drawing::Size(154, 34);
			this->��ToolStripMenuItem->Text = L"� - �";
			this->��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::��ToolStripMenuItem_Click);
			// 
			// ����������������SQL������ToolStripMenuItem
			// 
			this->����������������SQL������ToolStripMenuItem->Name = L"����������������SQL������ToolStripMenuItem";
			this->����������������SQL������ToolStripMenuItem->Size = System::Drawing::Size(404, 34);
			this->����������������SQL������ToolStripMenuItem->Text = L"���������������� SQL-������";
			this->����������������SQL������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::����������������SQL������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem1
			// 
			this->����������ToolStripMenuItem1->Name = L"����������ToolStripMenuItem1";
			this->����������ToolStripMenuItem1->Size = System::Drawing::Size(142, 30);
			this->����������ToolStripMenuItem1->Text = L"����� � ����";
			this->����������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::����������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(32, 19);
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
			this->Column2->HeaderText = L"��������";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"��������";
			this->Column3->MinimumWidth = 8;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"������";
			this->Column4->MinimumWidth = 8;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"�������������";
			this->Column5->MinimumWidth = 8;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"���� �����";
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
	// ����������� � ��
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
	// ��������� �������� ����� ������
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
	// ��������� ������ ������ ���� �� ������� �������
	//
	private: void read_single_row(DataGridView^ dgw, IDataRecord^ record)
	{
		dgw->Rows->Add(record->GetInt32(0), record->GetString(1), record->GetString(2), record->GetString(3), record->GetString(4), Convert::ToString(record->GetDateTime(5))->Remove(10));
	}
	//
	// ��������� ������ ���������� �������
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
	// ��������� ����������� �������� ��� ������� "����� ������"
	//
	private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		NewRecord^ nr = gcnew NewRecord();
		nr->ShowDialog(this);
		if (nr->get_label() != "" && nr->get_description() != "" && nr->get_status() != "" && nr->get_admin() != "" && Convert::ToString(nr->get_deadline()) != "")
		{
			insert_data(nr->get_label(), nr->get_description(), nr->get_status(), nr->get_admin(), Convert::ToString(nr->get_deadline()));
		}
	}
	//
	// ��������� ����������� �������� ��� ������� "������� ��� ������"
	//
	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ ������� ��� ������?", "�����������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
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
	// ��������� ����������� �������� ��� ������� "����� �������"
	//
	private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// ��������� ����������� �������� ��� ������� "����� ������� �� �������"
	//
	private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY status");
	}
	//
	// ��������� ����������� �������� ��� ������� "� - �"
	//
	private: System::Void ��ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY admin ASC");	/*id, admin, label, description, status, deadline FROM*/
	}
	//
	// ��������� ����������� �������� ��� ������� "� - �"
	//	   
	private: System::Void ��ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY admin DESC"); /*id, admin, label, description, status, deadline FROM*/
	}
	//
	// ��������� ����������� �������� ��� ������� "� ������ �������"
	//
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY deadline ASC");
	}
	//
	// ��������� ����������� �������� ��� ������� "� �������� �������"
	//
	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		output_table(dataGridView1, "SELECT * FROM " + t_name + " ORDER BY deadline DESC");
	}
	//
	// ��������� ����������� �������� ��� ������� "������� ������"
	//
	private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		DeleteRecord^ dr = gcnew DeleteRecord(data_source, initial_catalog, t_name);
		dr->ShowDialog(this);
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// ��������� ����������� �������� ��� ������� "�������������� ������"
	//
	private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		EditRecord^ er = gcnew EditRecord(data_source, initial_catalog, t_name);
		er->ShowDialog(this);
		output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// ��������� ����������� �������� ��� ������� "����������"
	//
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("��� ������ ��������� ���������� ������������ � SQL �������. �� ������� ���������� ������� ���� ������ � ������� � ������������� ����������.\r\n\r\n��� ���������� ������ ��������� ������� ���� ������ ������ ������������� ��������� ��������:\r\n1. � ������� ������ ���� ��������� ��������, ������� ���� ��� �������, � ������� ��� ������: ID (int), label (varchar(200)), description (varchar(200)), status (varchar(200)), admin (varchar(200)), deadline (date)\r\n2. � ������� ID ������ ���� ������� �������� \"Identity Specification\"\r\n3. � ���� ������� ������ ���� �������� �������� \"Allow Nulls\"\r\n\r\n��� ����������� � ��������� �� �������� \"����������� � ��\", � ����������� ���� ������� �������� ������� � ���� ������", "���������� � ����������� � ���������� SQL �������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//
	// ��������� ����������� � �� ��� ������ ������������
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
						if (this->Text != "DBROM") this->Text = this->Text->Remove(5) + " � " + t_name;
						else this->Text = this->Text + " � " + t_name;
					}
				}
			}
			delete cwc;
		}
		catch (System::ObjectDisposedException^) { this->Close(); }
	}
	//
	// ��������� ����������� � ��
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
			if (this->Text != "DBROM") this->Text = this->Text->Remove(5) + " � " + t_name;
			else this->Text = this->Text + " � " + t_name;
		}
	}
	//
	// ��������� ����������� �������� ��� ������� "����������� � ��"
	//
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		connection_to();
		if(t_name != "")
			output_table(dataGridView1, "SELECT * FROM " + t_name);
	}
	//
	// ��������� ����������� �������� ��� ������� "������� �������"
	//
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ ������� ��� �������?", "�����������", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
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
			��������������ToolStripMenuItem_Click(sender, e);
		}
	}
	//
	//
	//
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
			data += "ID ������:\t" + reader->GetInt32(0) + "\r\n��������:\t" + reader->GetString(1) + "\r\n��������:\t" + reader->GetString(2) + "\r\n������:\t\t" + reader->GetString(3) + "\r\n������������:\t" + reader->GetString(4) + "\r\n���� �����:\t" + Convert::ToString(reader->GetDateTime(5))->Remove(10) + "\r\n\r\n";
		}
		reader->Close();
		connection->Close();

			StreamWriter^ writer = gcnew StreamWriter(path);
			writer->Write(data);
			writer->Close();
			MessageBox::Show("������ ��������� � ���� �� ������: " + path, "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	//
	// ��������� ����������� �������� ��� ������� "���������������� SQL-������"
	//
	private: System::Void ����������������SQL������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
		query = Interaction::InputBox("������� ����� SQL-������, �� ����������� ������� �� ������� (� ���� ������� ������ �� ��������� �� �����)", "SQL-������", query, x, y);
		try
		{
			//output_table(dataGridView1, query);
			connect_to_DB();
			SqlCommand^ cmd = gcnew SqlCommand(query, connection);
			connection->Open();
			cmd->ExecuteNonQuery();
			connection->Close();
			MessageBox::Show("SQL-������ ��������", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^)
		{
			MessageBox::Show("����� ������������ SQL-������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			prev_query = pr_q;
		}
		output_table(dataGridView1, "SELECT TOP(1000)[ID], [label], [description], [status], [admin], [deadline] FROM[" + t_name + "]");
	}

	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};
}