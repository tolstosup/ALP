#include "LAB_6.h"
#include "Windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LAB6::LAB_6 form;
	try
	{
		Application::Run(% form);
	}
	catch (System::ObjectDisposedException^) {}
}

