/*

���� ������������ ������ #3
���� ������������� ������� LAB_3
�������� �����, ������ 3091, 1 ����
14.03.2024 - 21.03.2024

*/
#pragma once

namespace LAB3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace Microsoft::VisualBasic;

	/// <summary>
	/// ������ ��� LAB_3
	/// </summary>
	public ref class LAB_3 : public System::Windows::Forms::Form
	{
	public:
		LAB_3(void)
		{
			InitializeComponent();
			SaveFileDialog->Filter = "��������� ���� (*.txt)|*.txt|�������� ���� (*.bin)|*.bin";
			OpenFileDialog->Filter = "��������� ���� (*.txt)|*.txt|�������� ���� (*.bin)|*.bin";
			constructor_test();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~LAB_3()
		{
			if (components)
			{
				delete components;
			}
		}
		// ���������������� ���������
	private: String^ open_file_name = "";
	protected:
	private: System::Windows::Forms::OpenFileDialog^ OpenFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ SaveFileDialog;
	private: System::Windows::Forms::TextBox^ text;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ txt�binToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ name_of_file;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ extension;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LAB_3::typeid));
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->text = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txt�binToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->name_of_file = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->extension = (gcnew System::Windows::Forms::Label());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// text
			// 
			this->text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text->Location = System::Drawing::Point(12, 31);
			this->text->Multiline = true;
			this->text->Name = L"text";
			this->text->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text->Size = System::Drawing::Size(717, 558);
			this->text->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->����ToolStripMenuItem,
					this->�������������������������ToolStripMenuItem, this->txt�binToolStripMenuItem, this->����������ToolStripMenuItem, this->����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(741, 32);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->�������ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->���������ToolStripMenuItem, this->��������������ToolStripMenuItem, this->�������������ToolStripMenuItem,
					this->������������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(68, 28);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(230, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::�������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(230, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(230, 34);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::���������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(230, 34);
			this->��������������ToolStripMenuItem->Text = L"��������� �";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::��������������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(230, 34);
			this->�������������ToolStripMenuItem->Text = L"�������������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::�������������ToolStripMenuItem_Click);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(230, 34);
			this->������������ToolStripMenuItem->Text = L"������� ����";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::������������ToolStripMenuItem_Click);
			// 
			// �������������������������ToolStripMenuItem
			// 
			this->�������������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem2,
					this->�����������������ToolStripMenuItem
			});
			this->�������������������������ToolStripMenuItem->Name = L"�������������������������ToolStripMenuItem";
			this->�������������������������ToolStripMenuItem->Size = System::Drawing::Size(153, 28);
			this->�������������������������ToolStripMenuItem->Text = L"��������������";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(284, 34);
			this->toolStripMenuItem2->Text = L"\"%\" ����� \"\?\"";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &LAB_3::toolStripMenuItem2_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(284, 34);
			this->�����������������ToolStripMenuItem->Text = L"������ ���� ��� ����";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::�����������������ToolStripMenuItem_Click);
			// 
			// txt�binToolStripMenuItem
			// 
			this->txt�binToolStripMenuItem->Name = L"txt�binToolStripMenuItem";
			this->txt�binToolStripMenuItem->Size = System::Drawing::Size(98, 28);
			this->txt�binToolStripMenuItem->Text = L"txt <=> bin";
			this->txt�binToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::txt�binToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(124, 28);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::����������ToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 592);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"��� �����:";
			// 
			// name_of_file
			// 
			this->name_of_file->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->name_of_file->AutoSize = true;
			this->name_of_file->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->name_of_file->Location = System::Drawing::Point(77, 593);
			this->name_of_file->Name = L"name_of_file";
			this->name_of_file->Size = System::Drawing::Size(0, 20);
			this->name_of_file->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(544, 593);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"����������:";
			// 
			// extension
			// 
			this->extension->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->extension->AutoSize = true;
			this->extension->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->extension->Location = System::Drawing::Point(613, 593);
			this->extension->Name = L"extension";
			this->extension->Size = System::Drawing::Size(0, 20);
			this->extension->TabIndex = 12;
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(60, 28);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &LAB_3::����ToolStripMenuItem_Click);
			// 
			// LAB_3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 619);
			this->Controls->Add(this->extension);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->name_of_file);
			this->Controls->Add(this->text);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(763, 675);
			this->Name = L"LAB_3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������������ ������ �3. ������ � ������ � �������";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// �����������, ���� ������ � ������, ���� ��� ����
	//
	private: void count()
	{
		int int_q = 0, char_q = 0;

		if (this->text->Text->StartsWith("�����\r\n"))
		{
			this->text->Text = this->text->Text->Replace("�����\r\n", "");
		}
		else if (this->text->Text->StartsWith("�����\r\n"))
		{
			this->text->Text = this->text->Text->Replace("�����\r\n", "");
		}
		String^ str = this->text->Text;
		for (int i = 0; i < str->Length; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				int_q++;
			}
			else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 1040 && str[i] <= 1103))
			{
				char_q++;
			}
		}

		if (char_q > int_q)
		{
			this->text->Text = "�����\r\n" + text->Text;
		}
		else if (char_q < int_q)
		{
			this->text->Text = "�����\r\n" + text->Text;
		}
	}
	//
	// ������� ������� �������� ����� ������� ��������� ��������������� �����
	//
	private: void insert_percent(String^ str)
	{
		if (str == "?")	str += "%";
		else
		{
			for (int i = 0; i < str->Length - 1; i++)
			{
				if (str->Length > 1 && str[i] == '?' && str[i + 1] != '%')
				{
					str = str->Insert(i + 1, "%");
				}
			}
		}
		if (str->EndsWith("?")) str += "%";
		this->text->Text = str;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// ����� ��� ����� � ��� ����������
	//
	private: void file_info(String^ info)
	{
		this->extension->Text = info->Remove(0, info->Length - (info->Length - info->LastIndexOf(".")));
		String^ temp = info->Remove(0, info->LastIndexOf("\\") + 1);
		this->name_of_file->Text = temp->Remove(temp->Length - (temp->Length - temp->LastIndexOf(".")), 4);
	}
	//
	// ������ �� �����
	//
	private: void read_from_file(String^ filename)
	{
		if (filename->Contains(".txt"))
		{
			StreamReader^ reader = gcnew StreamReader(filename);
			this->text->Text = reader->ReadToEnd();
			reader->Close();
		}
		else if (filename->Contains(".bin"))
		{
			BinaryReader^ reader = gcnew BinaryReader(File::Open(filename, FileMode::OpenOrCreate));
			this->text->Text = reader->ReadString();
			reader->Close();
		}
	}
	//
	// ������ � ����
	//
	private: void write_to_file(String^ filename)
	{
		if (filename->Contains(".txt"))
		{
			StreamWriter^ writer = gcnew StreamWriter(filename, false);
			writer->Write(text->Text);
			writer->Close();
		}
		else if (filename->Contains(".bin"))
		{
			BinaryWriter^ writer = gcnew BinaryWriter(File::Open(filename, FileMode::OpenOrCreate));
			writer->Write(this->text->Text);
			writer->Close();
		}
	}
	//
	// �������� �����
	//
	private: void create_file(String^ filename)
	{
		if (filename->Contains(".txt"))
		{
			StreamWriter^ writer = gcnew StreamWriter(filename, false);
			writer->Close();
		}
		else if (filename->Contains(".bin"))
		{
			BinaryWriter^ writer = gcnew BinaryWriter(File::Open(filename, FileMode::OpenOrCreate));
			writer->Close();
		}
	}
	//
	// �������� �����
	//
	private: void delete_file(String^ filename)
	{
		FileInfo^ file = gcnew FileInfo(filename);
		if (file->Exists)
		{
			file->Delete();
		}
	}
	//
	// ������������� ����
	//
	private: void rename(String^ new_name)
	{
		if (open_file_name != "")
		{
			int sl_index = 0, dot_index = 0;
			sl_index = open_file_name->LastIndexOf("\\");
			dot_index = open_file_name->IndexOf(".");

			delete_file(open_file_name);
			String^ way = (open_file_name->Remove(sl_index + 1, dot_index - sl_index - 1))->Insert(sl_index + 1, new_name);
			write_to_file(way);

			open_file_name = way;
			file_info(way);
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// �������� ��� ������ �������� �����
	//
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->text->Text = "";
			create_file(SaveFileDialog->FileName);
			open_file_name = SaveFileDialog->FileName;
			file_info(SaveFileDialog->FileName);
		}
	}
	//
	// �������� ��� ������ �������� �����
	//
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->text->Text = "";
			open_file_name = OpenFileDialog->FileName;
			this->text->Clear();
			read_from_file(OpenFileDialog->FileName);
			file_info(open_file_name);
		}
	}
	//
	// �������� ��� ������ ���������� �����
	//
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (open_file_name != "")
		{
			write_to_file(open_file_name);
		}
		else
		{
			if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				write_to_file(SaveFileDialog->FileName);
				open_file_name = SaveFileDialog->FileName;
				file_info(SaveFileDialog->FileName);
			}
		}
	}
	//
	// �������� ��� ������ �������������� (% ����� ?)
	//
	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->text->Text != "") insert_percent(this->text->Text);
		else
		{
			MessageBox::Show("���� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	//
	// �������� ��� ������ �������������� (������ ���� ��� ����)
	//
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->text->Text != "") count();
		else
		{
			MessageBox::Show("���� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	//
	// �������� ��� ������ ����������� .txt � .bin
	//
	private: System::Void txt�binToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (open_file_name != "" && open_file_name->Contains(".txt"))
		{
			BinaryWriter^ writer = gcnew BinaryWriter(File::Open(open_file_name->Replace(".txt", ".bin"), FileMode::OpenOrCreate));
			writer->Write(this->text->Text);
			writer->Close();
			delete_file(open_file_name);
			open_file_name = open_file_name->Replace(".txt", ".bin");
			file_info(open_file_name);
		}
		else if (open_file_name != "" && open_file_name->Contains(".bin"))
		{
			String^ temp;
			BinaryReader^ reader = gcnew BinaryReader(File::Open(open_file_name, FileMode::Open));
			temp = reader->ReadString();
			reader->Close();
			write_to_file(open_file_name->Replace(".bin", ".txt"));
			delete_file(open_file_name);
			open_file_name = open_file_name->Replace(".bin", ".txt");
			file_info(open_file_name);
		}
		else
		{
			MessageBox::Show("���� �� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	//
	// �������� ��� ������ ������� �����
	//
	private: System::Void ������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->text->Text = "";
		this->open_file_name = "";
		this->name_of_file->Text = "";
		this->extension->Text = "";
	}
	//
	// �������� ��� ������ ��������������
	//
	private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (open_file_name != "")
		{
			int sl_index = open_file_name->LastIndexOf("\\");
			String^ name = open_file_name->Remove(0, sl_index + 1);
			int dot_index = name->IndexOf(".");
			name = name->Remove(dot_index, name->Length - dot_index);


			int x = this->Left + (this->Width / 2) - 200;
			int y = this->Top + (this->Height / 2) - 100;
			String^ new_name = ";";
			int flag = 1;
			while (max_quantity(new_name) || valid_input(new_name))
			{
				if ((max_quantity(new_name) || valid_input(new_name)) && flag == 2)
				{
					MessageBox::Show("������������� ����\r\n\r\n�� ����������� ������� , . \\ / | : ; * ? \" < > = + [ ] { } & � ��� ����, ��������� ������ �� ��������\r\n������������ ����� ����� - 250 ��������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				if (flag) flag = 2;
				new_name = Interaction::InputBox("������� ����� ��� �����\r\n\r\n������� ��� �����: " + name, "�������������", "", x, y);
			}
			if (new_name != "") rename(new_name);
		}
		else
		{
			MessageBox::Show("���� ��� �������������� �� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	//
	// �������� ���������� �������� � ��������
	//
	private: bool max_quantity(String^ str)
	{
		if (str->Length > 250)
			return true;
		return false;
	}
	//
	// �������� ������������ ��������� ��������
	//
	private: bool valid_input(String^ str)
	{
		if (str != "")
		{
			int j = 0;
			for (int i = 0; i < str->Length; i++)
			{
				if (str[i] == ' ') j++;
			}
			if (j == str->Length)
				return true;
			else if ((str->Contains(",")) || (str->Contains(".")) || (str->Contains("\\")) || (str->Contains("/")) || (str->Contains(":")) || (str->Contains("*")) || (str->Contains("?")) || (str->Contains("|")) || (str->Contains("\"")) || (str->Contains("<")) || (str->Contains(">")) || (str->Contains(";")) || (str->Contains("=")) || (str->Contains("+")) || (str->Contains("[")) || (str->Contains("]")) || (str->Contains("{")) || (str->Contains("}")) || (str->Contains("&")))
				return true;
		}
		return false;
	}
	//
	// �������� ��� ������ ���������� �
	// 
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (SaveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ name = SaveFileDialog->FileName;
			write_to_file(name);
		}
	}
	//
	// �������� ��� ������ � ���������
	// 
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("��������� ��� ������ � ���������� ������� � ��������� �� �����������.\r\n\r\n� ��������� ������������� �����������:\r\n1.  ������ ������������� �����;\r\n2.  �������������� ����������� �����;\r\n3.  ���������� ����������������� ���������� � ����;\r\n4.  �������� ������ �����;\r\n5.  ������ ������ ��� �������������;\r\n6.  ����������� �� ������� txt � bin, � �������;\r\n7.  �������������� ��������� �����.\r\n\r\n��������������� �������� �������������� �����������:\r\n1.  ����� ������� ����� ������� ��������� ��� �������� ������ �%�;\r\n2.  ���������� ���������� ���� � ������ � �������� ��� � ����������� ���� � ������, �������� � ������ ������ �������, ���� ���� ������, ������� � ���� ������.", "� ���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// ������� ������������ ��������� count(), �� ����� void, �� ������ int
	//
	private: int count_test()
	{
		this->text->Text = "abc11";
		count();
		if (this->text->Text->StartsWith("�����"))
		{
			this->text->Text = "";
			return 0;
		}
		else
		{
			this->text->Text = "";
			return 1;
		}
	}
	//
	// ������� ������������ ��������� insetr_percent(), �� ����� void, �� ������ int
	//
	private: int insert_test()
	{
		String^ temp = "a?b?c";
		insert_percent(temp);
		if(this->text->Text == "a?%b?%c")
		{
			this->text->Text = "";
			return 0;
		}
		else
		{
			this->text->Text = "";
			return 1;
		}
	}
	//
	// ������� ������������ ��������� file_info(), �� ����� void, �� ������ int
	//
	private: int file_info_test()
	{
		String^ file_name = "C:\\Users\\name.txt";
		file_info(file_name);
		if(this->name_of_file->Text == "name" && this->extension->Text == ".txt")
		{
			this->name_of_file->Text = "";
			this->extension->Text = "";
			return 0;
		}
		else
		{
			this->name_of_file->Text = "";
			this->extension->Text = "";
			return 1;
		}
	}
	//
	// �������� ��� ������ ����
	//
	private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ temp_text = this->text->Text;
		String^ temp_file_name = this->name_of_file->Text;
		String ^ temp_extension = this->extension->Text;
		int result = count_test() + insert_test() + file_info_test();
		if (result == 0)
		{
			this->text->Text = temp_text;
			this->name_of_file->Text = temp_file_name;
			this->extension->Text = temp_extension;
			MessageBox::Show("����� ��������, ���������� �������� ���������", "������������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("����� �� ��������. ���������� ����� �������", "������������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
	}
	//
	// ��������� ������������ ��������� ��� ������ ������������
	//
	private: void constructor_test()
	{
		int result = count_test() + insert_test() + file_info_test();
		if (result != 0)
		{
			MessageBox::Show("����� �� ��������. ���������� ����� �������", "������������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
	}
};
}