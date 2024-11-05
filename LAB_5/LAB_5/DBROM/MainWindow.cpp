/*

АЯиП Лабораторная работа #5
Файл исходного кода проекта DBROM
Михайлов Роман, группа 3091, 1 курс
08.04.2024 - 17.04.2024

*/

#include "MainWindow.h"
#include "Windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DBROM::MainWindow form;
	try
	{
		Application::Run(% form);
	}
	catch(System::ObjectDisposedException^) {}
}