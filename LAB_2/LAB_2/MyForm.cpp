/*

���� ������������ ������ #2
���� ��������� ���� ������� LAB_2
�������� �����, ������ 3091, 1 ����
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
