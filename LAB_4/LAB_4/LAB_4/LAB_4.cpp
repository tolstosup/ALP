#include "LAB_4.h"
#include "Windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LAB4::LAB_4 form;
	Application::Run(% form);
}

