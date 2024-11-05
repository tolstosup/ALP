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
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Сводка для DeleteRecord
	/// </summary>
	public ref class DeleteRecord : public System::Windows::Forms::Form
	{
	public:
		DeleteRecord(String^ ds, String^ ic, String^ tn)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->ds = ds;
			this->ic = ic;
			this->tn = tn;
			get_id();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DeleteRecord()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
	private: SqlConnection^ connection;	// Строка подключения
	private: String^ ds = "";			// Название сервера
	private: String^ ic = "";			// Название базы данных
	private: String^ tn = "";			// Имя таблицы

	private: System::Windows::Forms::ComboBox^ id_comboBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Button^ delete_button;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->id_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// id_comboBox
			// 
			this->id_comboBox->FormattingEnabled = true;
			this->id_comboBox->Location = System::Drawing::Point(313, 13);
			this->id_comboBox->Name = L"id_comboBox";
			this->id_comboBox->Size = System::Drawing::Size(138, 28);
			this->id_comboBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(295, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Выбирите ID записи для её удаления";
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(149, 65);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(145, 40);
			this->exit_button->TabIndex = 12;
			this->exit_button->Text = L"Отмена";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &DeleteRecord::exit_button_Click);
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(306, 65);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(145, 40);
			this->delete_button->TabIndex = 11;
			this->delete_button->Text = L"Удалить";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &DeleteRecord::delete_button_Click);
			// 
			// DeleteRecord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 117);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->delete_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->id_comboBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"DeleteRecord";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Удаление записи";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	//	Процедура подключения к БД
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
	//	Процедура получения ID записей
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
	//	Процедура удаления выбранной записи
	//
	private: void delete_rec()
	{
		String^ col_name = "";
		String^ id = Convert::ToString(id_comboBox->Items[id_comboBox->SelectedIndex]);
		String^ command_text = "DELETE FROM " + tn + " WHERE ID = " + id;
		connect_to_DB();
		SqlCommand^ cmd = gcnew SqlCommand(command_text, connection);
		connection->Open();
		cmd->ExecuteNonQuery();
		connection->Close();
	}
	//
	//	Процедура запускающая действия при нажатии кнопки "Отмена"
	//
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	//
	//	Процедура запускающая действия при нажатии кнопки "Удалить"
	//
	private: System::Void delete_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (id_comboBox->SelectedIndex != -1)
		{
			System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить эту запись?", "Уведомление", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				delete_rec();
			}
			this->Close();
		}
	}
};
}