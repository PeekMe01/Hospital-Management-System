#pragma once

#include "EmployeesCommands.h"
#include "PatientsCommands.h"
#include "roomsCommands.h"
#include <msclr\marshal_cppstd.h>
#include <ctype.h>

LISTFloors floorsList;
LISTRooms roomsListF1, roomsListF2, roomsListF3, roomsListF4;
LISTPatient patientsList;
LISTEmployee employeesList;
Rooms* roomWeLookingFor;
Patient* patientWeLookingFor;
Employee* employeeWeLookingFor;

namespace FinalProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			InitializeListFloors(floorsList);
			InitializeListRooms(roomsListF1);
			InitializeListRooms(roomsListF2);
			InitializeListRooms(roomsListF3);
			InitializeListRooms(roomsListF4);

			for (int i = 1; i <= MAXROOMSPERFLOOR; i++) {
				InsertInfoToRoomsList(roomsListF1, i, 1);
				InsertInfoToRoomsList(roomsListF2, i, 2);
				InsertInfoToRoomsList(roomsListF3, i, 3);
				InsertInfoToRoomsList(roomsListF4, i, 4);
			}
			InsertRoomsListToFloors(floorsList, roomsListF1, roomsListF2, roomsListF3, roomsListF4); // to insert the room lists into all the floors

			InitializeListPatient(patientsList);
			InitializeListEmployee(employeesList);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ outputPanel;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ roomsFloorsTab;
	private: System::Windows::Forms::TabPage^ patientsTab;

	private: System::Windows::Forms::TabPage^ employeesTab;



	public: System::Windows::Forms::RichTextBox^ outputBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ Rooms;

	private: System::Windows::Forms::GroupBox^ Floors;
	private: System::Windows::Forms::Button^ printFloorsH2R_btn;
	private: System::Windows::Forms::Button^ printFloorsR2H_btn;


	private: System::Windows::Forms::Button^ printRoomsR2H_btn;
	private: System::Windows::Forms::Button^ printRoomsH2R_btn;
	private: System::Windows::Forms::Button^ clear_btn;
	private: System::Windows::Forms::CheckBox^ floor4Rooms_chkBox;

	private: System::Windows::Forms::CheckBox^ floor3Rooms_chkBox;

	private: System::Windows::Forms::CheckBox^ floor2Rooms_chkBox;

	private: System::Windows::Forms::CheckBox^ floor1Rooms_chkBox;
	private: System::Windows::Forms::Button^ printPatientInfoInRoom_btn;
	private: System::Windows::Forms::TextBox^ roomID_txtField;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ age_txtField;

	private: System::Windows::Forms::TextBox^ reasonOfStay_txtField;

	private: System::Windows::Forms::TextBox^ lName_txtField;

	private: System::Windows::Forms::TextBox^ fName_txtField;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ address_txtField;

	private: System::Windows::Forms::TextBox^ guardian_txtField;
	private: System::Windows::Forms::Button^ createPatient_btn;


	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ printPateintsR2H_btn;
	private: System::Windows::Forms::Button^ printPatientsH2R_btn;
	private: System::Windows::Forms::Button^ printPatient_btn;
	private: System::Windows::Forms::TextBox^ patientPrintID_txtField;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ deletePatient_btn;

	private: System::Windows::Forms::TextBox^ insertPatientToRoom_txtField;
	private: System::Windows::Forms::Button^ insertPatientToRoom_btn;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ removePatientFromRoom_btn;
	private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::ComboBox^ sortingType_ComboBox;
private: System::Windows::Forms::ComboBox^ order_ComboBox;







private: System::Windows::Forms::Button^ reinitializePatientsID_bnt;
private: System::Windows::Forms::Button^ s;




private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::TextBox^ newValueToUpdate_txtField;
private: System::Windows::Forms::ComboBox^ newValueType_ComboBox;
private: System::Windows::Forms::Button^ update_btn;
private: System::Windows::Forms::GroupBox^ groupBox5;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ emp_Salary_txtField;


private: System::Windows::Forms::TextBox^ emp_Age_txtField;

private: System::Windows::Forms::TextBox^ emp_Address_txtField;

private: System::Windows::Forms::TextBox^ emp_LastName_txtField;

private: System::Windows::Forms::TextBox^ emp_FirstName_txtField;
private: System::Windows::Forms::ComboBox^ emp_Position_ComboBox;
private: System::Windows::Forms::Button^ createEmployee_btn;
private: System::Windows::Forms::GroupBox^ groupBox6;
private: System::Windows::Forms::GroupBox^ groupBox7;
private: System::Windows::Forms::Button^ goSortEmployee_btn;

private: System::Windows::Forms::Button^ reInitializeIDemp_btn;
private: System::Windows::Forms::ComboBox^ sortingTypeEmp_ComboBox;
private: System::Windows::Forms::ComboBox^ orderEmp_ComboBox;





private: System::Windows::Forms::GroupBox^ groupBox8;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Button^ printEmployee_btn;





private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Button^ deleteEmployee_btn;
private: System::Windows::Forms::TextBox^ employeeID_txtField;


private: System::Windows::Forms::Button^ printEmployeesR2H_btn;
private: System::Windows::Forms::Button^ printEmployeesH2R_btn;












	private: System::ComponentModel::IContainer^ components;














	protected:

	protected:

	protected:



	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->outputPanel = (gcnew System::Windows::Forms::Panel());
			this->clear_btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->outputBox = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->roomsFloorsTab = (gcnew System::Windows::Forms::TabPage());
			this->Rooms = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->roomID_txtField = (gcnew System::Windows::Forms::TextBox());
			this->printPatientInfoInRoom_btn = (gcnew System::Windows::Forms::Button());
			this->floor4Rooms_chkBox = (gcnew System::Windows::Forms::CheckBox());
			this->floor3Rooms_chkBox = (gcnew System::Windows::Forms::CheckBox());
			this->floor2Rooms_chkBox = (gcnew System::Windows::Forms::CheckBox());
			this->floor1Rooms_chkBox = (gcnew System::Windows::Forms::CheckBox());
			this->printRoomsR2H_btn = (gcnew System::Windows::Forms::Button());
			this->printRoomsH2R_btn = (gcnew System::Windows::Forms::Button());
			this->Floors = (gcnew System::Windows::Forms::GroupBox());
			this->printFloorsR2H_btn = (gcnew System::Windows::Forms::Button());
			this->printFloorsH2R_btn = (gcnew System::Windows::Forms::Button());
			this->patientsTab = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->s = (gcnew System::Windows::Forms::Button());
			this->reinitializePatientsID_bnt = (gcnew System::Windows::Forms::Button());
			this->sortingType_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->order_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->newValueToUpdate_txtField = (gcnew System::Windows::Forms::TextBox());
			this->newValueType_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->update_btn = (gcnew System::Windows::Forms::Button());
			this->removePatientFromRoom_btn = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->insertPatientToRoom_txtField = (gcnew System::Windows::Forms::TextBox());
			this->insertPatientToRoom_btn = (gcnew System::Windows::Forms::Button());
			this->printPatient_btn = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->deletePatient_btn = (gcnew System::Windows::Forms::Button());
			this->patientPrintID_txtField = (gcnew System::Windows::Forms::TextBox());
			this->printPateintsR2H_btn = (gcnew System::Windows::Forms::Button());
			this->printPatientsH2R_btn = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->createPatient_btn = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->address_txtField = (gcnew System::Windows::Forms::TextBox());
			this->guardian_txtField = (gcnew System::Windows::Forms::TextBox());
			this->age_txtField = (gcnew System::Windows::Forms::TextBox());
			this->reasonOfStay_txtField = (gcnew System::Windows::Forms::TextBox());
			this->lName_txtField = (gcnew System::Windows::Forms::TextBox());
			this->fName_txtField = (gcnew System::Windows::Forms::TextBox());
			this->employeesTab = (gcnew System::Windows::Forms::TabPage());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->goSortEmployee_btn = (gcnew System::Windows::Forms::Button());
			this->reInitializeIDemp_btn = (gcnew System::Windows::Forms::Button());
			this->sortingTypeEmp_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->orderEmp_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->printEmployee_btn = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->deleteEmployee_btn = (gcnew System::Windows::Forms::Button());
			this->employeeID_txtField = (gcnew System::Windows::Forms::TextBox());
			this->printEmployeesR2H_btn = (gcnew System::Windows::Forms::Button());
			this->printEmployeesH2R_btn = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->createEmployee_btn = (gcnew System::Windows::Forms::Button());
			this->emp_Position_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->emp_Salary_txtField = (gcnew System::Windows::Forms::TextBox());
			this->emp_Age_txtField = (gcnew System::Windows::Forms::TextBox());
			this->emp_Address_txtField = (gcnew System::Windows::Forms::TextBox());
			this->emp_LastName_txtField = (gcnew System::Windows::Forms::TextBox());
			this->emp_FirstName_txtField = (gcnew System::Windows::Forms::TextBox());
			this->outputPanel->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->roomsFloorsTab->SuspendLayout();
			this->Rooms->SuspendLayout();
			this->Floors->SuspendLayout();
			this->patientsTab->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->employeesTab->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// outputPanel
			// 
			this->outputPanel->BackColor = System::Drawing::Color::IndianRed;
			this->outputPanel->Controls->Add(this->clear_btn);
			this->outputPanel->Controls->Add(this->label1);
			this->outputPanel->Controls->Add(this->outputBox);
			this->outputPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->outputPanel->Location = System::Drawing::Point(1356, 0);
			this->outputPanel->Margin = System::Windows::Forms::Padding(4);
			this->outputPanel->Name = L"outputPanel";
			this->outputPanel->Size = System::Drawing::Size(568, 961);
			this->outputPanel->TabIndex = 0;
			// 
			// clear_btn
			// 
			this->clear_btn->Location = System::Drawing::Point(28, 909);
			this->clear_btn->Name = L"clear_btn";
			this->clear_btn->Size = System::Drawing::Size(511, 48);
			this->clear_btn->TabIndex = 2;
			this->clear_btn->Text = L"Clear Output";
			this->clear_btn->UseVisualStyleBackColor = true;
			this->clear_btn->Click += gcnew System::EventHandler(this, &MyForm::clear_btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(20, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(182, 42);
			this->label1->TabIndex = 1;
			this->label1->Text = L"OUTPUT:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// outputBox
			// 
			this->outputBox->BackColor = System::Drawing::SystemColors::InfoText;
			this->outputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputBox->ForeColor = System::Drawing::Color::Lime;
			this->outputBox->Location = System::Drawing::Point(28, 41);
			this->outputBox->Margin = System::Windows::Forms::Padding(4);
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->Size = System::Drawing::Size(511, 861);
			this->outputBox->TabIndex = 0;
			this->outputBox->Text = L"";
			this->outputBox->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->roomsFloorsTab);
			this->tabControl1->Controls->Add(this->patientsTab);
			this->tabControl1->Controls->Add(this->employeesTab);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(10, 3);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1356, 961);
			this->tabControl1->TabIndex = 1;
			// 
			// roomsFloorsTab
			// 
			this->roomsFloorsTab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->roomsFloorsTab->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->roomsFloorsTab->Controls->Add(this->Rooms);
			this->roomsFloorsTab->Controls->Add(this->Floors);
			this->roomsFloorsTab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->roomsFloorsTab->Location = System::Drawing::Point(4, 38);
			this->roomsFloorsTab->Margin = System::Windows::Forms::Padding(4);
			this->roomsFloorsTab->Name = L"roomsFloorsTab";
			this->roomsFloorsTab->Padding = System::Windows::Forms::Padding(4);
			this->roomsFloorsTab->Size = System::Drawing::Size(1348, 919);
			this->roomsFloorsTab->TabIndex = 0;
			this->roomsFloorsTab->Text = L"Rooms / Floors";
			// 
			// Rooms
			// 
			this->Rooms->Controls->Add(this->label2);
			this->Rooms->Controls->Add(this->roomID_txtField);
			this->Rooms->Controls->Add(this->printPatientInfoInRoom_btn);
			this->Rooms->Controls->Add(this->floor4Rooms_chkBox);
			this->Rooms->Controls->Add(this->floor3Rooms_chkBox);
			this->Rooms->Controls->Add(this->floor2Rooms_chkBox);
			this->Rooms->Controls->Add(this->floor1Rooms_chkBox);
			this->Rooms->Controls->Add(this->printRoomsR2H_btn);
			this->Rooms->Controls->Add(this->printRoomsH2R_btn);
			this->Rooms->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Rooms->Location = System::Drawing::Point(4, 446);
			this->Rooms->Margin = System::Windows::Forms::Padding(4);
			this->Rooms->Name = L"Rooms";
			this->Rooms->Padding = System::Windows::Forms::Padding(4);
			this->Rooms->Size = System::Drawing::Size(1336, 465);
			this->Rooms->TabIndex = 1;
			this->Rooms->TabStop = false;
			this->Rooms->Text = L"Rooms";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(340, 293);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(190, 29);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Enter Room ID:";
			// 
			// roomID_txtField
			// 
			this->roomID_txtField->Location = System::Drawing::Point(344, 327);
			this->roomID_txtField->MaxLength = 4;
			this->roomID_txtField->Name = L"roomID_txtField";
			this->roomID_txtField->Size = System::Drawing::Size(259, 34);
			this->roomID_txtField->TabIndex = 7;
			this->roomID_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// printPatientInfoInRoom_btn
			// 
			this->printPatientInfoInRoom_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->printPatientInfoInRoom_btn->Location = System::Drawing::Point(9, 293);
			this->printPatientInfoInRoom_btn->Name = L"printPatientInfoInRoom_btn";
			this->printPatientInfoInRoom_btn->Size = System::Drawing::Size(259, 102);
			this->printPatientInfoInRoom_btn->TabIndex = 6;
			this->printPatientInfoInRoom_btn->Text = L"Patient in room";
			this->printPatientInfoInRoom_btn->UseVisualStyleBackColor = true;
			this->printPatientInfoInRoom_btn->Click += gcnew System::EventHandler(this, &MyForm::printPatientInfoInRoom_btn_Click);
			// 
			// floor4Rooms_chkBox
			// 
			this->floor4Rooms_chkBox->AutoSize = true;
			this->floor4Rooms_chkBox->Location = System::Drawing::Point(9, 180);
			this->floor4Rooms_chkBox->Name = L"floor4Rooms_chkBox";
			this->floor4Rooms_chkBox->Size = System::Drawing::Size(226, 33);
			this->floor4Rooms_chkBox->TabIndex = 5;
			this->floor4Rooms_chkBox->Text = L"Rooms in floor 4";
			this->floor4Rooms_chkBox->UseVisualStyleBackColor = true;
			// 
			// floor3Rooms_chkBox
			// 
			this->floor3Rooms_chkBox->AutoSize = true;
			this->floor3Rooms_chkBox->Location = System::Drawing::Point(9, 141);
			this->floor3Rooms_chkBox->Name = L"floor3Rooms_chkBox";
			this->floor3Rooms_chkBox->Size = System::Drawing::Size(226, 33);
			this->floor3Rooms_chkBox->TabIndex = 4;
			this->floor3Rooms_chkBox->Text = L"Rooms in floor 3";
			this->floor3Rooms_chkBox->UseVisualStyleBackColor = true;
			// 
			// floor2Rooms_chkBox
			// 
			this->floor2Rooms_chkBox->AutoSize = true;
			this->floor2Rooms_chkBox->Location = System::Drawing::Point(9, 102);
			this->floor2Rooms_chkBox->Name = L"floor2Rooms_chkBox";
			this->floor2Rooms_chkBox->Size = System::Drawing::Size(226, 33);
			this->floor2Rooms_chkBox->TabIndex = 3;
			this->floor2Rooms_chkBox->Text = L"Rooms in floor 2";
			this->floor2Rooms_chkBox->UseVisualStyleBackColor = true;
			// 
			// floor1Rooms_chkBox
			// 
			this->floor1Rooms_chkBox->AutoSize = true;
			this->floor1Rooms_chkBox->Location = System::Drawing::Point(9, 70);
			this->floor1Rooms_chkBox->Name = L"floor1Rooms_chkBox";
			this->floor1Rooms_chkBox->Size = System::Drawing::Size(226, 33);
			this->floor1Rooms_chkBox->TabIndex = 2;
			this->floor1Rooms_chkBox->Text = L"Rooms in floor 1";
			this->floor1Rooms_chkBox->UseVisualStyleBackColor = true;
			// 
			// printRoomsR2H_btn
			// 
			this->printRoomsR2H_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printRoomsR2H_btn->Location = System::Drawing::Point(344, 144);
			this->printRoomsR2H_btn->Margin = System::Windows::Forms::Padding(4);
			this->printRoomsR2H_btn->Name = L"printRoomsR2H_btn";
			this->printRoomsR2H_btn->Size = System::Drawing::Size(260, 102);
			this->printRoomsR2H_btn->TabIndex = 1;
			this->printRoomsR2H_btn->Text = L"Print Rooms R2H";
			this->printRoomsR2H_btn->UseVisualStyleBackColor = true;
			this->printRoomsR2H_btn->Click += gcnew System::EventHandler(this, &MyForm::printRoomsR2H_btn_Click);
			// 
			// printRoomsH2R_btn
			// 
			this->printRoomsH2R_btn->Location = System::Drawing::Point(345, 34);
			this->printRoomsH2R_btn->Margin = System::Windows::Forms::Padding(4);
			this->printRoomsH2R_btn->Name = L"printRoomsH2R_btn";
			this->printRoomsH2R_btn->Size = System::Drawing::Size(259, 102);
			this->printRoomsH2R_btn->TabIndex = 0;
			this->printRoomsH2R_btn->Text = L"Print Rooms H2R";
			this->printRoomsH2R_btn->UseVisualStyleBackColor = true;
			this->printRoomsH2R_btn->Click += gcnew System::EventHandler(this, &MyForm::printRoomsH2R_btn_Click);
			// 
			// Floors
			// 
			this->Floors->Controls->Add(this->printFloorsR2H_btn);
			this->Floors->Controls->Add(this->printFloorsH2R_btn);
			this->Floors->Dock = System::Windows::Forms::DockStyle::Top;
			this->Floors->Location = System::Drawing::Point(4, 4);
			this->Floors->Margin = System::Windows::Forms::Padding(4);
			this->Floors->Name = L"Floors";
			this->Floors->Padding = System::Windows::Forms::Padding(4);
			this->Floors->Size = System::Drawing::Size(1336, 431);
			this->Floors->TabIndex = 0;
			this->Floors->TabStop = false;
			this->Floors->Text = L"Floors";
			// 
			// printFloorsR2H_btn
			// 
			this->printFloorsR2H_btn->Location = System::Drawing::Point(9, 158);
			this->printFloorsR2H_btn->Margin = System::Windows::Forms::Padding(4);
			this->printFloorsR2H_btn->Name = L"printFloorsR2H_btn";
			this->printFloorsR2H_btn->Size = System::Drawing::Size(259, 102);
			this->printFloorsR2H_btn->TabIndex = 1;
			this->printFloorsR2H_btn->Text = L"Print Floors R2H";
			this->printFloorsR2H_btn->UseVisualStyleBackColor = true;
			this->printFloorsR2H_btn->Click += gcnew System::EventHandler(this, &MyForm::printFloorsR2H_btn_Click);
			// 
			// printFloorsH2R_btn
			// 
			this->printFloorsH2R_btn->Location = System::Drawing::Point(8, 48);
			this->printFloorsH2R_btn->Margin = System::Windows::Forms::Padding(4);
			this->printFloorsH2R_btn->Name = L"printFloorsH2R_btn";
			this->printFloorsH2R_btn->Size = System::Drawing::Size(260, 102);
			this->printFloorsH2R_btn->TabIndex = 0;
			this->printFloorsH2R_btn->Text = L"Print Floors H2R";
			this->printFloorsH2R_btn->UseVisualStyleBackColor = true;
			this->printFloorsH2R_btn->Click += gcnew System::EventHandler(this, &MyForm::printFloorsH2R_btn_Click);
			// 
			// patientsTab
			// 
			this->patientsTab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->patientsTab->Controls->Add(this->groupBox2);
			this->patientsTab->Controls->Add(this->groupBox1);
			this->patientsTab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->patientsTab->Location = System::Drawing::Point(4, 38);
			this->patientsTab->Margin = System::Windows::Forms::Padding(4);
			this->patientsTab->Name = L"patientsTab";
			this->patientsTab->Padding = System::Windows::Forms::Padding(4);
			this->patientsTab->Size = System::Drawing::Size(1348, 919);
			this->patientsTab->TabIndex = 1;
			this->patientsTab->Text = L"Patients";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->groupBox4);
			this->groupBox2->Controls->Add(this->groupBox3);
			this->groupBox2->Controls->Add(this->printPateintsR2H_btn);
			this->groupBox2->Controls->Add(this->printPatientsH2R_btn);
			this->groupBox2->Location = System::Drawing::Point(3, 288);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1338, 624);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Patient List Options";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->s);
			this->groupBox4->Controls->Add(this->reinitializePatientsID_bnt);
			this->groupBox4->Controls->Add(this->sortingType_ComboBox);
			this->groupBox4->Controls->Add(this->order_ComboBox);
			this->groupBox4->Location = System::Drawing::Point(5, 390);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(1319, 228);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Patient List Sorting";
			// 
			// s
			// 
			this->s->Location = System::Drawing::Point(673, 149);
			this->s->Name = L"s";
			this->s->Size = System::Drawing::Size(244, 37);
			this->s->TabIndex = 3;
			this->s->Text = L"Go";
			this->s->UseVisualStyleBackColor = true;
			this->s->Click += gcnew System::EventHandler(this, &MyForm::goSort_btn_Click);
			// 
			// reinitializePatientsID_bnt
			// 
			this->reinitializePatientsID_bnt->Location = System::Drawing::Point(7, 48);
			this->reinitializePatientsID_bnt->Name = L"reinitializePatientsID_bnt";
			this->reinitializePatientsID_bnt->Size = System::Drawing::Size(244, 74);
			this->reinitializePatientsID_bnt->TabIndex = 2;
			this->reinitializePatientsID_bnt->Text = L"Reinitialize IDs";
			this->reinitializePatientsID_bnt->UseVisualStyleBackColor = true;
			this->reinitializePatientsID_bnt->Click += gcnew System::EventHandler(this, &MyForm::reinitializePatientsID_bnt_Click);
			// 
			// sortingType_ComboBox
			// 
			this->sortingType_ComboBox->FormattingEnabled = true;
			this->sortingType_ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"ID", L"First Name", L"Last Name",
					L"Age", L"Reason Of Stay", L"Guardian", L"Address"
			});
			this->sortingType_ComboBox->Location = System::Drawing::Point(7, 149);
			this->sortingType_ComboBox->Name = L"sortingType_ComboBox";
			this->sortingType_ComboBox->Size = System::Drawing::Size(244, 37);
			this->sortingType_ComboBox->TabIndex = 1;
			this->sortingType_ComboBox->Text = L"Sorting Type";
			// 
			// order_ComboBox
			// 
			this->order_ComboBox->FormattingEnabled = true;
			this->order_ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ascending", L"Descencing" });
			this->order_ComboBox->Location = System::Drawing::Point(340, 149);
			this->order_ComboBox->Name = L"order_ComboBox";
			this->order_ComboBox->Size = System::Drawing::Size(244, 37);
			this->order_ComboBox->TabIndex = 0;
			this->order_ComboBox->Text = L"Order";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->newValueToUpdate_txtField);
			this->groupBox3->Controls->Add(this->newValueType_ComboBox);
			this->groupBox3->Controls->Add(this->update_btn);
			this->groupBox3->Controls->Add(this->removePatientFromRoom_btn);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->insertPatientToRoom_txtField);
			this->groupBox3->Controls->Add(this->insertPatientToRoom_btn);
			this->groupBox3->Controls->Add(this->printPatient_btn);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->deletePatient_btn);
			this->groupBox3->Controls->Add(this->patientPrintID_txtField);
			this->groupBox3->Location = System::Drawing::Point(6, 112);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(1318, 272);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Patient Controls";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(672, 40);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(146, 29);
			this->label11->TabIndex = 13;
			this->label11->Text = L"New Value:";
			// 
			// newValueToUpdate_txtField
			// 
			this->newValueToUpdate_txtField->Location = System::Drawing::Point(672, 72);
			this->newValueToUpdate_txtField->Name = L"newValueToUpdate_txtField";
			this->newValueToUpdate_txtField->Size = System::Drawing::Size(244, 34);
			this->newValueToUpdate_txtField->TabIndex = 12;
			// 
			// newValueType_ComboBox
			// 
			this->newValueType_ComboBox->FormattingEnabled = true;
			this->newValueType_ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"First Name", L"Last Name", L"Reason Of Stay",
					L"Age", L"Guardian", L"Address"
			});
			this->newValueType_ComboBox->Location = System::Drawing::Point(672, 132);
			this->newValueType_ComboBox->Name = L"newValueType_ComboBox";
			this->newValueType_ComboBox->Size = System::Drawing::Size(244, 37);
			this->newValueType_ComboBox->TabIndex = 11;
			this->newValueType_ComboBox->Text = L"Value Type";
			// 
			// update_btn
			// 
			this->update_btn->Location = System::Drawing::Point(672, 192);
			this->update_btn->Name = L"update_btn";
			this->update_btn->Size = System::Drawing::Size(244, 74);
			this->update_btn->TabIndex = 10;
			this->update_btn->Text = L"Update";
			this->update_btn->UseVisualStyleBackColor = true;
			this->update_btn->Click += gcnew System::EventHandler(this, &MyForm::update_btn_Click);
			// 
			// removePatientFromRoom_btn
			// 
			this->removePatientFromRoom_btn->Location = System::Drawing::Point(339, 192);
			this->removePatientFromRoom_btn->Name = L"removePatientFromRoom_btn";
			this->removePatientFromRoom_btn->Size = System::Drawing::Size(244, 74);
			this->removePatientFromRoom_btn->TabIndex = 9;
			this->removePatientFromRoom_btn->Text = L"Remove Patient From Room";
			this->removePatientFromRoom_btn->UseVisualStyleBackColor = true;
			this->removePatientFromRoom_btn->Click += gcnew System::EventHandler(this, &MyForm::removePatientFromRoom_btn_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(334, 40);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(121, 29);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Room ID:";
			// 
			// insertPatientToRoom_txtField
			// 
			this->insertPatientToRoom_txtField->Location = System::Drawing::Point(339, 72);
			this->insertPatientToRoom_txtField->MaxLength = 4;
			this->insertPatientToRoom_txtField->Name = L"insertPatientToRoom_txtField";
			this->insertPatientToRoom_txtField->Size = System::Drawing::Size(244, 34);
			this->insertPatientToRoom_txtField->TabIndex = 7;
			this->insertPatientToRoom_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// insertPatientToRoom_btn
			// 
			this->insertPatientToRoom_btn->Location = System::Drawing::Point(339, 112);
			this->insertPatientToRoom_btn->Name = L"insertPatientToRoom_btn";
			this->insertPatientToRoom_btn->Size = System::Drawing::Size(244, 74);
			this->insertPatientToRoom_btn->TabIndex = 6;
			this->insertPatientToRoom_btn->Text = L"Insert Patient To Room";
			this->insertPatientToRoom_btn->UseVisualStyleBackColor = true;
			this->insertPatientToRoom_btn->Click += gcnew System::EventHandler(this, &MyForm::insertPatientToRoom_btn_Click);
			// 
			// printPatient_btn
			// 
			this->printPatient_btn->Location = System::Drawing::Point(6, 112);
			this->printPatient_btn->Name = L"printPatient_btn";
			this->printPatient_btn->Size = System::Drawing::Size(244, 74);
			this->printPatient_btn->TabIndex = 2;
			this->printPatient_btn->Text = L"Print Patient";
			this->printPatient_btn->UseVisualStyleBackColor = true;
			this->printPatient_btn->Click += gcnew System::EventHandler(this, &MyForm::printPatient_btn_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1, 40);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(133, 29);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Patient ID:";
			// 
			// deletePatient_btn
			// 
			this->deletePatient_btn->Location = System::Drawing::Point(6, 192);
			this->deletePatient_btn->Name = L"deletePatient_btn";
			this->deletePatient_btn->Size = System::Drawing::Size(244, 74);
			this->deletePatient_btn->TabIndex = 5;
			this->deletePatient_btn->Text = L"Delete Patient";
			this->deletePatient_btn->UseVisualStyleBackColor = true;
			this->deletePatient_btn->Click += gcnew System::EventHandler(this, &MyForm::deletePatient_btn_Click);
			// 
			// patientPrintID_txtField
			// 
			this->patientPrintID_txtField->Location = System::Drawing::Point(6, 72);
			this->patientPrintID_txtField->Name = L"patientPrintID_txtField";
			this->patientPrintID_txtField->Size = System::Drawing::Size(244, 34);
			this->patientPrintID_txtField->TabIndex = 3;
			this->patientPrintID_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->patientPrintID_txtField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::patientPrintID_txtField_KeyPress);
			// 
			// printPateintsR2H_btn
			// 
			this->printPateintsR2H_btn->Location = System::Drawing::Point(256, 33);
			this->printPateintsR2H_btn->Name = L"printPateintsR2H_btn";
			this->printPateintsR2H_btn->Size = System::Drawing::Size(244, 73);
			this->printPateintsR2H_btn->TabIndex = 1;
			this->printPateintsR2H_btn->Text = L"Print Patients R2H";
			this->printPateintsR2H_btn->UseVisualStyleBackColor = true;
			this->printPateintsR2H_btn->Click += gcnew System::EventHandler(this, &MyForm::printPateintsR2H_btn_Click);
			// 
			// printPatientsH2R_btn
			// 
			this->printPatientsH2R_btn->Location = System::Drawing::Point(6, 33);
			this->printPatientsH2R_btn->Name = L"printPatientsH2R_btn";
			this->printPatientsH2R_btn->Size = System::Drawing::Size(244, 74);
			this->printPatientsH2R_btn->TabIndex = 0;
			this->printPatientsH2R_btn->Text = L"Print Patients H2R";
			this->printPatientsH2R_btn->UseVisualStyleBackColor = true;
			this->printPatientsH2R_btn->Click += gcnew System::EventHandler(this, &MyForm::printPatientsH2R_btn_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->createPatient_btn);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->address_txtField);
			this->groupBox1->Controls->Add(this->guardian_txtField);
			this->groupBox1->Controls->Add(this->age_txtField);
			this->groupBox1->Controls->Add(this->reasonOfStay_txtField);
			this->groupBox1->Controls->Add(this->lName_txtField);
			this->groupBox1->Controls->Add(this->fName_txtField);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1332, 279);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Create Patient";
			// 
			// createPatient_btn
			// 
			this->createPatient_btn->Location = System::Drawing::Point(628, 113);
			this->createPatient_btn->Name = L"createPatient_btn";
			this->createPatient_btn->Size = System::Drawing::Size(173, 74);
			this->createPatient_btn->TabIndex = 12;
			this->createPatient_btn->Text = L"Create Patient";
			this->createPatient_btn->UseVisualStyleBackColor = true;
			this->createPatient_btn->Click += gcnew System::EventHandler(this, &MyForm::insertPatient_btn_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(7, 235);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 29);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Address";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 194);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 29);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Guardian";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 153);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 29);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Age";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 113);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(184, 29);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Reason of stay";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(137, 29);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Last Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 29);
			this->label3->TabIndex = 6;
			this->label3->Text = L"First Name";
			// 
			// address_txtField
			// 
			this->address_txtField->Location = System::Drawing::Point(214, 235);
			this->address_txtField->MaxLength = 200;
			this->address_txtField->Name = L"address_txtField";
			this->address_txtField->Size = System::Drawing::Size(286, 34);
			this->address_txtField->TabIndex = 5;
			this->address_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// guardian_txtField
			// 
			this->guardian_txtField->Location = System::Drawing::Point(214, 194);
			this->guardian_txtField->MaxLength = 25;
			this->guardian_txtField->Name = L"guardian_txtField";
			this->guardian_txtField->Size = System::Drawing::Size(286, 34);
			this->guardian_txtField->TabIndex = 4;
			this->guardian_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// age_txtField
			// 
			this->age_txtField->Location = System::Drawing::Point(214, 153);
			this->age_txtField->MaxLength = 3;
			this->age_txtField->Name = L"age_txtField";
			this->age_txtField->Size = System::Drawing::Size(286, 34);
			this->age_txtField->TabIndex = 3;
			this->age_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->age_txtField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::age_txtField_KeyPress);
			// 
			// reasonOfStay_txtField
			// 
			this->reasonOfStay_txtField->Location = System::Drawing::Point(214, 113);
			this->reasonOfStay_txtField->MaxLength = 100;
			this->reasonOfStay_txtField->Name = L"reasonOfStay_txtField";
			this->reasonOfStay_txtField->Size = System::Drawing::Size(286, 34);
			this->reasonOfStay_txtField->TabIndex = 2;
			this->reasonOfStay_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lName_txtField
			// 
			this->lName_txtField->Location = System::Drawing::Point(214, 73);
			this->lName_txtField->MaxLength = 25;
			this->lName_txtField->Name = L"lName_txtField";
			this->lName_txtField->Size = System::Drawing::Size(286, 34);
			this->lName_txtField->TabIndex = 1;
			this->lName_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// fName_txtField
			// 
			this->fName_txtField->Location = System::Drawing::Point(214, 33);
			this->fName_txtField->MaxLength = 25;
			this->fName_txtField->Name = L"fName_txtField";
			this->fName_txtField->Size = System::Drawing::Size(286, 34);
			this->fName_txtField->TabIndex = 0;
			this->fName_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// employeesTab
			// 
			this->employeesTab->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->employeesTab->Controls->Add(this->groupBox6);
			this->employeesTab->Controls->Add(this->groupBox5);
			this->employeesTab->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->employeesTab->Location = System::Drawing::Point(4, 38);
			this->employeesTab->Margin = System::Windows::Forms::Padding(4);
			this->employeesTab->Name = L"employeesTab";
			this->employeesTab->Padding = System::Windows::Forms::Padding(4);
			this->employeesTab->Size = System::Drawing::Size(1348, 919);
			this->employeesTab->TabIndex = 2;
			this->employeesTab->Text = L"Employees";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->groupBox7);
			this->groupBox6->Controls->Add(this->groupBox8);
			this->groupBox6->Controls->Add(this->printEmployeesR2H_btn);
			this->groupBox6->Controls->Add(this->printEmployeesH2R_btn);
			this->groupBox6->Location = System::Drawing::Point(4, 292);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(1338, 624);
			this->groupBox6->TabIndex = 2;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Patient List Options";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->goSortEmployee_btn);
			this->groupBox7->Controls->Add(this->reInitializeIDemp_btn);
			this->groupBox7->Controls->Add(this->sortingTypeEmp_ComboBox);
			this->groupBox7->Controls->Add(this->orderEmp_ComboBox);
			this->groupBox7->Location = System::Drawing::Point(5, 390);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(1319, 228);
			this->groupBox7->TabIndex = 7;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Employee List Sorting";
			// 
			// goSortEmployee_btn
			// 
			this->goSortEmployee_btn->Location = System::Drawing::Point(673, 149);
			this->goSortEmployee_btn->Name = L"goSortEmployee_btn";
			this->goSortEmployee_btn->Size = System::Drawing::Size(244, 37);
			this->goSortEmployee_btn->TabIndex = 3;
			this->goSortEmployee_btn->Text = L"Go";
			this->goSortEmployee_btn->UseVisualStyleBackColor = true;
			this->goSortEmployee_btn->Click += gcnew System::EventHandler(this, &MyForm::goSortEmployee_btn_Click);
			// 
			// reInitializeIDemp_btn
			// 
			this->reInitializeIDemp_btn->Location = System::Drawing::Point(7, 48);
			this->reInitializeIDemp_btn->Name = L"reInitializeIDemp_btn";
			this->reInitializeIDemp_btn->Size = System::Drawing::Size(244, 74);
			this->reInitializeIDemp_btn->TabIndex = 2;
			this->reInitializeIDemp_btn->Text = L"Reinitialize IDs";
			this->reInitializeIDemp_btn->UseVisualStyleBackColor = true;
			this->reInitializeIDemp_btn->Click += gcnew System::EventHandler(this, &MyForm::reInitializeIDemp_btn_Click);
			// 
			// sortingTypeEmp_ComboBox
			// 
			this->sortingTypeEmp_ComboBox->FormattingEnabled = true;
			this->sortingTypeEmp_ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"ID", L"First Name", L"Last Name",
					L"Address", L"Age", L"Position", L"Salary"
			});
			this->sortingTypeEmp_ComboBox->Location = System::Drawing::Point(7, 149);
			this->sortingTypeEmp_ComboBox->Name = L"sortingTypeEmp_ComboBox";
			this->sortingTypeEmp_ComboBox->Size = System::Drawing::Size(244, 37);
			this->sortingTypeEmp_ComboBox->TabIndex = 1;
			this->sortingTypeEmp_ComboBox->Text = L"Sorting Type";
			// 
			// orderEmp_ComboBox
			// 
			this->orderEmp_ComboBox->FormattingEnabled = true;
			this->orderEmp_ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ascending", L"Descencing" });
			this->orderEmp_ComboBox->Location = System::Drawing::Point(340, 149);
			this->orderEmp_ComboBox->Name = L"orderEmp_ComboBox";
			this->orderEmp_ComboBox->Size = System::Drawing::Size(244, 37);
			this->orderEmp_ComboBox->TabIndex = 0;
			this->orderEmp_ComboBox->Text = L"Order";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label18);
			this->groupBox8->Controls->Add(this->textBox1);
			this->groupBox8->Controls->Add(this->comboBox3);
			this->groupBox8->Controls->Add(this->button3);
			this->groupBox8->Controls->Add(this->printEmployee_btn);
			this->groupBox8->Controls->Add(this->label20);
			this->groupBox8->Controls->Add(this->deleteEmployee_btn);
			this->groupBox8->Controls->Add(this->employeeID_txtField);
			this->groupBox8->Location = System::Drawing::Point(6, 112);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(1318, 272);
			this->groupBox8->TabIndex = 6;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Employee Controls";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(339, 40);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(146, 29);
			this->label18->TabIndex = 13;
			this->label18->Text = L"New Value:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(339, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(244, 34);
			this->textBox1->TabIndex = 12;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"First Name", L"Last Name", L"Reason Of Stay",
					L"Age", L"Guardian", L"Address"
			});
			this->comboBox3->Location = System::Drawing::Point(339, 132);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(244, 37);
			this->comboBox3->TabIndex = 11;
			this->comboBox3->Text = L"Value Type";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(339, 192);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 74);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Update";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// printEmployee_btn
			// 
			this->printEmployee_btn->Location = System::Drawing::Point(6, 112);
			this->printEmployee_btn->Name = L"printEmployee_btn";
			this->printEmployee_btn->Size = System::Drawing::Size(244, 74);
			this->printEmployee_btn->TabIndex = 2;
			this->printEmployee_btn->Text = L"Print Employee";
			this->printEmployee_btn->UseVisualStyleBackColor = true;
			this->printEmployee_btn->Click += gcnew System::EventHandler(this, &MyForm::printEmployee_btn_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1, 40);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(169, 29);
			this->label20->TabIndex = 4;
			this->label20->Text = L"Employee ID:";
			// 
			// deleteEmployee_btn
			// 
			this->deleteEmployee_btn->Location = System::Drawing::Point(6, 192);
			this->deleteEmployee_btn->Name = L"deleteEmployee_btn";
			this->deleteEmployee_btn->Size = System::Drawing::Size(244, 74);
			this->deleteEmployee_btn->TabIndex = 5;
			this->deleteEmployee_btn->Text = L"Delete Employee";
			this->deleteEmployee_btn->UseVisualStyleBackColor = true;
			this->deleteEmployee_btn->Click += gcnew System::EventHandler(this, &MyForm::deleteEmployee_btn_Click);
			// 
			// employeeID_txtField
			// 
			this->employeeID_txtField->Location = System::Drawing::Point(6, 72);
			this->employeeID_txtField->Name = L"employeeID_txtField";
			this->employeeID_txtField->Size = System::Drawing::Size(244, 34);
			this->employeeID_txtField->TabIndex = 3;
			this->employeeID_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->employeeID_txtField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::employeeID_txtField_KeyPress);
			// 
			// printEmployeesR2H_btn
			// 
			this->printEmployeesR2H_btn->Location = System::Drawing::Point(256, 33);
			this->printEmployeesR2H_btn->Name = L"printEmployeesR2H_btn";
			this->printEmployeesR2H_btn->Size = System::Drawing::Size(244, 73);
			this->printEmployeesR2H_btn->TabIndex = 1;
			this->printEmployeesR2H_btn->Text = L"Print Employees R2H";
			this->printEmployeesR2H_btn->UseVisualStyleBackColor = true;
			this->printEmployeesR2H_btn->Click += gcnew System::EventHandler(this, &MyForm::printEmployeesR2H_btn_Click);
			// 
			// printEmployeesH2R_btn
			// 
			this->printEmployeesH2R_btn->Location = System::Drawing::Point(6, 33);
			this->printEmployeesH2R_btn->Name = L"printEmployeesH2R_btn";
			this->printEmployeesH2R_btn->Size = System::Drawing::Size(244, 74);
			this->printEmployeesH2R_btn->TabIndex = 0;
			this->printEmployeesH2R_btn->Text = L"Print Employees H2R";
			this->printEmployeesH2R_btn->UseVisualStyleBackColor = true;
			this->printEmployeesH2R_btn->Click += gcnew System::EventHandler(this, &MyForm::printEmployeesH2R_btn_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->createEmployee_btn);
			this->groupBox5->Controls->Add(this->emp_Position_ComboBox);
			this->groupBox5->Controls->Add(this->label12);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Controls->Add(this->label14);
			this->groupBox5->Controls->Add(this->label15);
			this->groupBox5->Controls->Add(this->label16);
			this->groupBox5->Controls->Add(this->label17);
			this->groupBox5->Controls->Add(this->emp_Salary_txtField);
			this->groupBox5->Controls->Add(this->emp_Age_txtField);
			this->groupBox5->Controls->Add(this->emp_Address_txtField);
			this->groupBox5->Controls->Add(this->emp_LastName_txtField);
			this->groupBox5->Controls->Add(this->emp_FirstName_txtField);
			this->groupBox5->Location = System::Drawing::Point(4, 0);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(1337, 288);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Create Employee";
			// 
			// createEmployee_btn
			// 
			this->createEmployee_btn->Location = System::Drawing::Point(625, 119);
			this->createEmployee_btn->Name = L"createEmployee_btn";
			this->createEmployee_btn->Size = System::Drawing::Size(173, 74);
			this->createEmployee_btn->TabIndex = 25;
			this->createEmployee_btn->Text = L"Create Employee";
			this->createEmployee_btn->UseVisualStyleBackColor = true;
			this->createEmployee_btn->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// emp_Position_ComboBox
			// 
			this->emp_Position_ComboBox->FormattingEnabled = true;
			this->emp_Position_ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"intern", L"nurse", L"doctor" });
			this->emp_Position_ComboBox->Location = System::Drawing::Point(213, 200);
			this->emp_Position_ComboBox->Name = L"emp_Position_ComboBox";
			this->emp_Position_ComboBox->Size = System::Drawing::Size(286, 37);
			this->emp_Position_ComboBox->TabIndex = 24;
			this->emp_Position_ComboBox->Text = L"Position";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 241);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(86, 29);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Salary";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 200);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(108, 29);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Position";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(6, 159);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(59, 29);
			this->label14->TabIndex = 21;
			this->label14->Text = L"Age";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 119);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(109, 29);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Address";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 79);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(137, 29);
			this->label16->TabIndex = 19;
			this->label16->Text = L"Last Name";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 39);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(141, 29);
			this->label17->TabIndex = 18;
			this->label17->Text = L"First Name";
			// 
			// emp_Salary_txtField
			// 
			this->emp_Salary_txtField->Location = System::Drawing::Point(213, 243);
			this->emp_Salary_txtField->MaxLength = 7;
			this->emp_Salary_txtField->Name = L"emp_Salary_txtField";
			this->emp_Salary_txtField->Size = System::Drawing::Size(286, 34);
			this->emp_Salary_txtField->TabIndex = 17;
			this->emp_Salary_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->emp_Salary_txtField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::emp_Salary_txtField_KeyPress);
			// 
			// emp_Age_txtField
			// 
			this->emp_Age_txtField->Location = System::Drawing::Point(213, 159);
			this->emp_Age_txtField->MaxLength = 3;
			this->emp_Age_txtField->Name = L"emp_Age_txtField";
			this->emp_Age_txtField->Size = System::Drawing::Size(286, 34);
			this->emp_Age_txtField->TabIndex = 15;
			this->emp_Age_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->emp_Age_txtField->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::emp_Age_txtField_KeyPress);
			// 
			// emp_Address_txtField
			// 
			this->emp_Address_txtField->Location = System::Drawing::Point(213, 119);
			this->emp_Address_txtField->MaxLength = 100;
			this->emp_Address_txtField->Name = L"emp_Address_txtField";
			this->emp_Address_txtField->Size = System::Drawing::Size(286, 34);
			this->emp_Address_txtField->TabIndex = 14;
			this->emp_Address_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// emp_LastName_txtField
			// 
			this->emp_LastName_txtField->Location = System::Drawing::Point(213, 79);
			this->emp_LastName_txtField->MaxLength = 25;
			this->emp_LastName_txtField->Name = L"emp_LastName_txtField";
			this->emp_LastName_txtField->Size = System::Drawing::Size(286, 34);
			this->emp_LastName_txtField->TabIndex = 13;
			this->emp_LastName_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// emp_FirstName_txtField
			// 
			this->emp_FirstName_txtField->Location = System::Drawing::Point(213, 39);
			this->emp_FirstName_txtField->MaxLength = 25;
			this->emp_FirstName_txtField->Name = L"emp_FirstName_txtField";
			this->emp_FirstName_txtField->Size = System::Drawing::Size(286, 34);
			this->emp_FirstName_txtField->TabIndex = 12;
			this->emp_FirstName_txtField->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 961);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->outputPanel);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->outputPanel->ResumeLayout(false);
			this->outputPanel->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->roomsFloorsTab->ResumeLayout(false);
			this->Rooms->ResumeLayout(false);
			this->Rooms->PerformLayout();
			this->Floors->ResumeLayout(false);
			this->patientsTab->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->employeesTab->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	// go from System::String^ to std::string
		static std::string toStandardString(System::String^ string)
		{
			using System::Runtime::InteropServices::Marshal;
			System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
			char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
			std::string returnString(charPointer, string->Length);
			Marshal::FreeHGlobal(pointer);

			return returnString;
		}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}

	//Print floors from head to rear.
	private: System::Void printFloorsH2R_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = PrintListH2RFloors(floorsList);
		outputBox->Text += output;
	}
	//Print floors from rear to head.   
	private: System::Void printFloorsR2H_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = PrintListR2HFloors(floorsList);
		outputBox->Text += output;
	}
	//Print rooms from head to rear.
	private: System::Void printRoomsH2R_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!(floor1Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListH2RRooms(roomsListF1);
			outputBox->Text += output;
		}
		if (!(floor2Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListH2RRooms(roomsListF2);
			outputBox->Text += output;
		}
		if (!(floor3Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListH2RRooms(roomsListF3);
			outputBox->Text += output;
		}
		if (!(floor4Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListH2RRooms(roomsListF4);
			outputBox->Text += output;
		}
		if ((floor1Rooms_chkBox->CheckState == CheckState::Unchecked)	// if all not selected tell user to selected a checkbox
			&& (floor2Rooms_chkBox->CheckState == CheckState::Unchecked)
			&& (floor3Rooms_chkBox->CheckState == CheckState::Unchecked)
			&& (floor4Rooms_chkBox->CheckState == CheckState::Unchecked)) {
			outputBox->Text += "PLEASE SELECT THE CHECKBOX FOR THE ROOMS YOU WANT TO DISPLAY!!!\n==========\n";
		}
	}
	// print room from rear to head
	private: System::Void printRoomsR2H_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!(floor1Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListR2HRooms(roomsListF1);
			outputBox->Text += output;
		}
		if (!(floor2Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListR2HRooms(roomsListF2);
			outputBox->Text += output;
		}
		if (!(floor3Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListR2HRooms(roomsListF3);
			outputBox->Text += output;
		}
		if (!(floor4Rooms_chkBox->CheckState == CheckState::Unchecked)) { // if not unchecked then do this
			System::String^ output = PrintListR2HRooms(roomsListF4);
			outputBox->Text += output;
		}
		if ((floor1Rooms_chkBox->CheckState == CheckState::Unchecked)
			&& (floor2Rooms_chkBox->CheckState == CheckState::Unchecked)
			&& (floor3Rooms_chkBox->CheckState == CheckState::Unchecked)
			&& (floor4Rooms_chkBox->CheckState == CheckState::Unchecked)) {
			outputBox->Text += "PLEASE SELECT THE CHECKBOX FOR THE ROOMS YOU WANT TO DISPLAY!!!\n==========\n";
		}
	}
	// print info of patients inside a specific room
	private: System::Void printPatientInfoInRoom_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GetRoom(floorsList, toStandardString(roomID_txtField->Text)) == NULL) {
			outputBox->Text += "The room ID you entered is invalid...\n";
		}
		else {
			roomWeLookingFor = GetRoom(floorsList, toStandardString(roomID_txtField->Text));
			outputBox->Text += PrintPatientsInfoInRoom(roomWeLookingFor);
			roomWeLookingFor = nullptr; // get it back to NULL ( not necessary tho )
		}
	}
	// insert patients to patientslist
	private: System::Void insertPatient_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (fName_txtField->Text == ""
			|| lName_txtField->Text == ""
			|| reasonOfStay_txtField->Text == ""
			|| age_txtField->Text == ""
			|| guardian_txtField->Text == ""
			|| address_txtField->Text == "") {
			outputBox->Text += "Please fill in the following field(s):\n";
			if (fName_txtField->Text == "") outputBox->Text += "First name\n";
			if (lName_txtField->Text == "") outputBox->Text += "Last name\n";
			if (reasonOfStay_txtField->Text == "") outputBox->Text += "Reason of stay\n";
			if (age_txtField->Text == "") outputBox->Text += "Age\n";
			if (guardian_txtField->Text == "") outputBox->Text += "Guardian\n";
			if (address_txtField->Text == "") outputBox->Text += "Address\n\n";
			}
			else {
				InsertElementPatient(patientsList,
				GetNumberOfElementsPatient(patientsList)==0?1:patientsList.rear->patientID+1, // nb of patient = 0? if yes then insert id as 1 otherwise get last patients and add +1 to his id
				toStandardString(fName_txtField->Text),
				toStandardString(lName_txtField->Text),
				toStandardString(reasonOfStay_txtField->Text),
				stoi(toStandardString(age_txtField->Text)), // convert to string first then to int
				toStandardString(guardian_txtField->Text),
				toStandardString(address_txtField->Text));
				outputBox->Text += "The patient was succesfully added\n";
				fName_txtField->Text = "";
				lName_txtField->Text = "";
				reasonOfStay_txtField->Text = "";
				age_txtField->Text = "";
				guardian_txtField->Text = "";
				address_txtField->Text = "";
			}
	}
	// to prevent insertion of digits in the age text field
	private: System::Void age_txtField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!std::isdigit(ch)) {
			e->Handled = true;
		}
	}
	private: System::Void printPatientsH2R_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = PrintListH2RPatient(patientsList);
		outputBox->Text += output;
	}
	private: System::Void printPateintsR2H_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = PrintListR2HPatient(patientsList);
		outputBox->Text += output;
	}
	private: System::Void printPatient_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (patientPrintID_txtField->Text == "") {
			outputBox->Text += "Please enter the patient ID...\n";
		}
		else {
			patientWeLookingFor = GetPatient(patientsList, System::Convert::ToInt64(patientPrintID_txtField->Text));
			System::String^ output = printPatient(patientWeLookingFor);
			outputBox->Text += output;
			patientWeLookingFor = nullptr;
		}
	}
	private: System::Void insertPatientToRoom_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (patientPrintID_txtField->Text == "") {
			outputBox->Text += "Please enter the patient ID...\n";
		}
		else {
			if (insertPatientToRoom_txtField->Text == "") {
				outputBox->Text += "Please enter the room ID...\n";
			}
			else {
				std::string patientID = toStandardString(patientPrintID_txtField->Text);
				std::string roomID = toStandardString(insertPatientToRoom_txtField->Text);
				int patientIDstr = stoi(patientID);
				roomWeLookingFor = GetRoom(floorsList, roomID);
				patientWeLookingFor = GetPatient(patientsList, patientIDstr);
				if (roomWeLookingFor == NULL) {
					outputBox->Text += "We can't find the room\n";
					roomWeLookingFor == nullptr;
					patientWeLookingFor == nullptr;
					return;
				}
				if (patientWeLookingFor == NULL) {
					outputBox->Text += "We can't find the patient\n";
					roomWeLookingFor == nullptr;
					patientWeLookingFor == nullptr;
					return;
				}
				outputBox->Text += InsertPatientToRoom(*roomWeLookingFor, *patientWeLookingFor);
				patientPrintID_txtField->Text = "";
				insertPatientToRoom_txtField->Text = "";
			}
		}
		roomWeLookingFor == nullptr;
		patientWeLookingFor == nullptr;
	}
	private: System::Void removePatientFromRoom_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (insertPatientToRoom_txtField->Text == "") {
				outputBox->Text += "Please enter the room ID...\n";
			}
			else {
				if (patientPrintID_txtField->Text == "") {
					outputBox->Text += "Please enter the patient ID...\n";
				}
				else {
					std::string patientIndex = toStandardString(patientPrintID_txtField->Text);
					std::string roomID = toStandardString(insertPatientToRoom_txtField->Text);
					int patientIDstr = stoi(patientIndex);
					roomWeLookingFor = GetRoom(floorsList, roomID);
					if (roomWeLookingFor == NULL) {
						outputBox->Text += "We can't find the room\n";
						return;
					}
					outputBox->Text += RemovePatientFromRoom(*roomWeLookingFor, patientIDstr);
					//outputBox->Text += "Patient have been remove from the room...\n";
				}
			}
			roomWeLookingFor == NULL;
	}
	private: System::Void deletePatient_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (patientPrintID_txtField->Text == "") {
			outputBox->Text += "Please enter the patient ID...\n";
		}else{
				outputBox->Text += deleteElementPatient(patientsList, System::Convert::ToInt64(patientPrintID_txtField->Text));
			}
	}
	private: System::Void reinitializePatientsID_bnt_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = ReInitializeIDPatients(patientsList);
		outputBox->Text += output;
	}
	private: System::Void goSort_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (sortingType_ComboBox->Text == "Sorting Type") {
			outputBox->Text += "Please select a sorting type...\n";
		}
		else {
			if (order_ComboBox->Text == "Order") {
				outputBox->Text += "Please select an order for your sort...\n";
				return;
			}
			else {
				std::string type = toStandardString(sortingType_ComboBox->Text);
				std::string order = toStandardString(order_ComboBox->Text);
				if (type == "ID") {
					if (order == "Ascending") {
						outputBox->Text += SortByID_ASC(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByID_DES(patientsList);
						return;
					}
				}
				else if (type == "First Name") {
					if (order == "Ascending") {
						outputBox->Text += SortByFirstNameA2Z(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByFirstNameZ2A(patientsList);
						return;
					}
				}
				else if (type == "Last Name") {
					if (order == "Ascending") {
						outputBox->Text += SortByLastNameA2Z(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByLastNameZ2A(patientsList);
						return;
					}
				}
				else if (type == "Age") {
					if (order == "Ascending") {
						outputBox->Text += SortByAgeY2O(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByAgeO2Y(patientsList);
						return;
					}
				}
				else if (type == "Reason Of Stay") {
					if (order == "Ascending") {
						outputBox->Text += SortByReasonOfStayLengthS2L(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByReasonOfStayLengthL2S(patientsList);
						return;
					}
				}
				else if (type == "Guardian") {
					if (order == "Ascending") {
						outputBox->Text += SortByGuardianA2Z(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByGuardianZ2A(patientsList);
						return;
					}
				}
				else if (type == "Address") {
					if (order == "Ascending") {
						outputBox->Text += SortByAddressLengthS2L(patientsList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByAddressLengthL2S(patientsList);
						return;
					}
				}
			}
		}
	}
	private: System::Void update_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (patientPrintID_txtField->Text == "") {
			outputBox->Text += "Please enter the patient ID...\n";
			return;
			   }
		else {
			if (newValueToUpdate_txtField->Text == "") {
				outputBox->Text += "Please insert a new value...\n";
				return;
			}
			else {
				if (newValueType_ComboBox->Text == "Value Type") {
					outputBox->Text += "Please select a value type...\n";
					return;
				}
				else {
					std::string patientID = toStandardString(patientPrintID_txtField->Text);
					std::string newValue = toStandardString(newValueToUpdate_txtField->Text);
					int patientIDstr = stoi(patientID);
					patientWeLookingFor = GetPatient(patientsList, patientIDstr);
					if (newValueType_ComboBox->Text == "First Name") outputBox->Text+=changeFirstName(patientWeLookingFor, newValue);
					if (newValueType_ComboBox->Text == "Last Name") outputBox->Text += changeLastName(patientWeLookingFor, newValue);
					if (newValueType_ComboBox->Text == "Reason Of Stay") outputBox->Text += changeReasonOfStay(patientWeLookingFor, newValue);
					if (newValueType_ComboBox->Text == "Age") outputBox->Text += changeAge(patientWeLookingFor, stoi(newValue));
					if (newValueType_ComboBox->Text == "Guardian") outputBox->Text += changeGuardian(patientWeLookingFor, newValue);
					if (newValueType_ComboBox->Text == "Address") outputBox->Text += changeAddress(patientWeLookingFor, newValue);
				}
			}
		}
	}
	private: System::Void patientPrintID_txtField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!std::isdigit(ch)) {
			e->Handled = true;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (emp_FirstName_txtField->Text == ""
			|| emp_LastName_txtField->Text == ""
			|| emp_Address_txtField->Text == ""
			|| emp_Age_txtField->Text == ""
			|| emp_Position_ComboBox->Text == "Position"
			|| emp_Salary_txtField->Text == "") {
			outputBox->Text += "Please fill in the following field(s):\n";
			if (emp_FirstName_txtField->Text == "") outputBox->Text += "First name\n";
			if (emp_LastName_txtField->Text == "") outputBox->Text += "Last name\n";
			if (emp_Address_txtField->Text == "") outputBox->Text += "Address\n";
			if (emp_Age_txtField->Text == "") outputBox->Text += "Age\n";
			if (emp_Position_ComboBox->Text == "Position") outputBox->Text += "Position\n";
			if (emp_Salary_txtField->Text == "") outputBox->Text += "Salary\n\n";
		}
		else {
			InsertElementEmployee(employeesList,
				GetNumberOfElementsEmployee(employeesList) == 0 ? 1 : employeesList.rear->employeeID + 1, // nb of patient = 0? if yes then insert id as 1 otherwise get last patients and add +1 to his id
				toStandardString(emp_FirstName_txtField->Text),
				toStandardString(emp_LastName_txtField->Text),
				toStandardString(emp_Address_txtField->Text),
				stoi(toStandardString(emp_Age_txtField->Text)), // convert to string first then to int
				toStandardString(emp_Position_ComboBox->Text),
				stoi(toStandardString(emp_Salary_txtField->Text)));
			outputBox->Text += "The employee was succesfully added\n";
			emp_FirstName_txtField->Text = "";
			emp_LastName_txtField->Text = "";
			emp_Address_txtField->Text = "";
			emp_Age_txtField->Text = "";
			emp_Position_ComboBox->Text = "";
			emp_Salary_txtField->Text = "";
		}
	}
	private: System::Void printEmployeesH2R_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = PrintListH2REmployee(employeesList);
		outputBox->Text += output;
	}

	private: System::Void printEmployeesR2H_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = PrintListR2HEmployee(employeesList);
		outputBox->Text += output;
	}

	private: System::Void printEmployee_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (employeeID_txtField->Text == "") {
			outputBox->Text += "Please enter the employee ID...\n";
		}
		else {
			employeeWeLookingFor = GetEmployee(employeesList, System::Convert::ToInt64(employeeID_txtField->Text));
			System::String^ output = printEmployee(employeeWeLookingFor);
			outputBox->Text += output;
			employeeWeLookingFor = nullptr;
		}
	}

	private: System::Void reInitializeIDemp_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ output = ReInitializeIDEmployees(employeesList);
		outputBox->Text += output;
	}

	private: System::Void deleteEmployee_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (employeeID_txtField->Text == "") {
			outputBox->Text += "Please enter the employees ID...\n";
		}
		else {
			outputBox->Text += deleteElementEmployee(employeesList, System::Convert::ToInt64(employeeID_txtField->Text));
		}
	}

	private: System::Void goSortEmployee_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (sortingTypeEmp_ComboBox->Text == "Sorting Type") {
			outputBox->Text += "Please select a sorting typedfghjhgf...\n";
		}
		else {
			if (orderEmp_ComboBox->Text == "Order") {
				outputBox->Text += "Please select an order for your sort...\n";
				return;
			}
			else {
				std::string type = toStandardString(sortingTypeEmp_ComboBox->Text);
				std::string order = toStandardString(orderEmp_ComboBox->Text);
				if (type == "Position") {
					if (order == "Ascending") {
						outputBox->Text += SortByPosition_ASC(employeesList);
						return;
					}
					if (order == "Descencing") {
						outputBox->Text += SortByPosition_DEC(employeesList);
						return;
					}
				}
			}
		}
	}

	private: System::Void clear_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		outputBox->Text = "";
	}
	private: System::Void emp_Age_txtField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!std::isdigit(ch)) {
			e->Handled = true;
		}
	}
	private: System::Void employeeID_txtField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!std::isdigit(ch)) {
			e->Handled = true;
		}
	}
	private: System::Void emp_Salary_txtField_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!std::isdigit(ch)) {
			e->Handled = true;
		}
	}
};
}

