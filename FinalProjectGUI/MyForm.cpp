#include "MyForm.h"
#include "roomsCommands.h"
#include "PatientsCommands.h"
#include "EmployeesCommands.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FinalProjectGUI::MyForm form;
    Application::Run(% form);

	/**/

	

}

