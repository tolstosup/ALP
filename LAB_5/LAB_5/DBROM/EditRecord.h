/*

���� ������������ ������ #5
������������ ���� ������� DBROM
�������� �����, ������ 3091, 1 ����
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
	using namespace System::Data::SqlClient;

	/// <summary>
	/// ������ ��� EditRecord
	/// </summary>
	public ref class EditRecord : public System::Windows::Forms::Form
	{
	public:
		EditRecord(String^ ds, String^ ic, String^ tn)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			this->ds = ds;
			this->ic = ic;
			this->tn = tn;
			get_id();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~EditRecord()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
	private: SqlConnection^ connection; // ������ �����������
	private: String^ ds = "";			// �������� �������
	private: String^ ic = "";			// �������� ���� ������
	private: String^ tn = "";			// ��� �������

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ id_comboBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ col_comboBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ current_data;
	private: System::Windows::Forms::TextBox^ new_data;
	private: System::Windows::Forms::Button^ rename_button;
	private: System::Windows::Forms::Button^ exit_button;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->id_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->col_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->current_data = (gcnew System::Windows::Forms::TextBox());
			this->new_data = (gcnew System::Windows::Forms::TextBox());
			this->rename_button = (gcnew System::Windows::Forms::Button());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(392, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�������� ID ������, ������� �� ������ ��������";
			// 
			// id_comboBox
			// 
			this->id_comboBox->FormattingEnabled = true;
			this->id_comboBox->Location = System::Drawing::Point(410, 15);
			this->id_comboBox->Name = L"id_comboBox";
			this->id_comboBox->Size = System::Drawing::Size(116, 28);
			this->id_comboBox->TabIndex = 1;
			this->id_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EditRecord::id_comboBox_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(269, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"�������� ������� ��� ���������";
			// 
			// col_comboBox
			// 
			this->col_comboBox->FormattingEnabled = true;
			this->col_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"��������", L"��������", L"������", L"������������",
					L"���� �����"
			});
			this->col_comboBox->Location = System::Drawing::Point(287, 58);
			this->col_comboBox->Name = L"col_comboBox";
			this->col_comboBox->Size = System::Drawing::Size(239, 28);
			this->col_comboBox->TabIndex = 3;
			this->col_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EditRecord::col_comboBox_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(148, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"������� ��������";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(200, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"������� ����� ��������";
			// 
			// current_data
			// 
			this->current_data->Location = System::Drawing::Point(166, 104);
			this->current_data->Name = L"current_data";
			this->current_data->ReadOnly = true;
			this->current_data->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->current_data->Size = System::Drawing::Size(361, 26);
			this->current_data->TabIndex = 6;
			// 
			// new_data
			// 
			this->new_data->Location = System::Drawing::Point(218, 147);
			this->new_data->Name = L"new_data";
			this->new_data->Size = System::Drawing::Size(309, 26);
			this->new_data->TabIndex = 7;
			this->new_data->TextChanged += gcnew System::EventHandler(this, &EditRecord::new_data_TextChanged);
			// 
			// rename_button
			// 
			this->rename_button->Location = System::Drawing::Point(382, 203);
			this->rename_button->Name = L"rename_button";
			this->rename_button->Size = System::Drawing::Size(145, 40);
			this->rename_button->TabIndex = 9;
			this->rename_button->Text = L"��������";
			this->rename_button->UseVisualStyleBackColor = true;
			this->rename_button->Click += gcnew System::EventHandler(this, &EditRecord::rename_button_Click);
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(225, 203);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(145, 40);
			this->exit_button->TabIndex = 10;
			this->exit_button->Text = L"������";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &EditRecord::exit_button_Click);
			// 
			// EditRecord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 262);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->rename_button);
			this->Controls->Add(this->new_data);
			this->Controls->Add(this->current_data);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->col_comboBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->id_comboBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"EditRecord";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������������� ������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	// ��������� �������� ������������ ������ � ���� "���� �����"
	//
	private: void check_date()
	{
		if (this->new_data->Text->Length > 10) this->new_data->Text = this->new_data->Text->Remove(10);
		int j = 0;
		for (int i = 0; i < this->new_data->Text->Length; i++) if (this->new_data->Text[i] == '.') j++;
		if(j > 2) this->new_data->Text = this->new_data->Text->Remove(this->new_data->Text->LastIndexOf("."));
		if (this->new_data->Text->Length > 9)
		{
			DateTime date;
			if (DateTime::TryParse(this->new_data->Text, date)) {}
			else MessageBox::Show("��������� ���� ����� ����� ���������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	//
	// ��������� ����������� � ��
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
	// ��������� ��������� ��������� ������
	//
	private: void edit()
	{
		String^ col_name = "";
		switch (col_comboBox->SelectedIndex)
		{
		case 0: col_name = "label"; break;
		case 1: col_name = "description"; break;
		case 2: col_name = "status"; break;
		case 3: col_name = "admin"; break;
		case 4: col_name = "deadline"; break;
		}
		String^ id = Convert::ToString(id_comboBox->Items[id_comboBox->SelectedIndex]);
		String^ comamnd_text = "UPDATE " + tn + " SET " + col_name + " = '" + new_data->Text + "' WHERE ID = " + id;
		connect_to_DB();
		SqlCommand^ cmd = gcnew SqlCommand(comamnd_text, connection);
		connection->Open();
		cmd->ExecuteNonQuery();
		connection->Close();
	}
	//
	// ��������� ��������� ID �������
	//
	private: void get_id()
	{
		connect_to_DB();
		String^ query = "SELECT ID FROM " + tn;
		connection->Open();
		SqlCommand^ cmd = gcnew SqlCommand(query, connection);
		SqlDataReader^ reader = cmd->ExecuteReader();

		String^ id_temp = "";
		while (reader->Read())
		{
			id_temp = reader["ID"]->ToString();
			id_comboBox->Items->Add(String::Format("{0}", id_temp));
		}
		connection->Close();
	}
	//
	// ��������� ��������� ������ ��������� ������ 
	//
	private: void get_curr_data()
	{
		String^ col_name = "";
		switch (col_comboBox->SelectedIndex)
		{
		case 0: col_name = "label"; break;
		case 1: col_name = "description"; break;
		case 2: col_name = "status"; break;
		case 3: col_name = "admin"; break;
		case 4: col_name = "deadline"; break;
		}
		String^ id = Convert::ToString(id_comboBox->Items[id_comboBox->SelectedIndex]);
		String^ query = "SELECT " + col_name + " FROM " + tn + " WHERE ID = " + id;
		connect_to_DB();
		connection->Open();
		SqlCommand^ cmd = gcnew SqlCommand(query, connection);
		SqlDataReader^ reader = cmd->ExecuteReader();
		if(col_comboBox->SelectedIndex != 4) while(reader->Read()) current_data->Text = reader[col_name]->ToString();
		else while (reader->Read()) current_data->Text = (reader[col_name]->ToString())->Remove(10);
		connection->Close();
	}
	//
	// �������� ����������� �������� ��� ������� ������ "��������"
	//
	private: System::Void rename_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		edit();
		this->Close();
	}
	//
	// ��������� ����������� �������� ��� ������� ������ "������"
	//
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	//
	// ��������� ����������� �������� ��� ������ ����������� �������
	//
	private: System::Void col_comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if(id_comboBox->SelectedIndex != -1 && col_comboBox->SelectedIndex != -1) get_curr_data();
	}
	//
	// ��������� ����������� �������� ��� ������ ���������� ������
	//
	private: System::Void id_comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (id_comboBox->SelectedIndex != -1 && col_comboBox->SelectedIndex != -1) get_curr_data();
	}
	//
	// ��������� ����������� �������� ��� ��������� ������ � ���� "������� ����� ��������"
	//
	private: System::Void new_data_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (col_comboBox->SelectedIndex == 4) check_date();
		else
		{
			if (this->new_data->Text->Length > 200)
			{
				MessageBox::Show("������� ������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->new_data->Text = this->new_data->Text->Remove(200);
			}
		}
	}
};
}