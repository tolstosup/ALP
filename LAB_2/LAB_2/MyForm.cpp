/*

АЯиП Лабораторная работа #2
Файл исходного кода проекта LAB_2
Михайлов Роман, группа 3091, 1 курс
28.02.2024

*/

#include "LAB_2.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LAB_2::LAB_2 form;
	Application::Run(% form);
}
