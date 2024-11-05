/*

АЯиП Лабораторная работа #1
Исходный файл проекта LAB_1 (main.cpp)
Михайлов Роман, группа 3091, 1 курс
07.02.2024 - 17.02.2024

*/

#include "LAB_1.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LAB_1::LAB_1 form;
	Application::Run(% form);
}