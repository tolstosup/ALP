/*

���� ������������ ������ #3
���� ��������� ���� ������� LAB_3
�������� �����, ������ 3091, 1 ����
14.03.2024

*/

#include "LAB_3.h"
#include "Windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LAB3::LAB_3 form;
	Application::Run(% form);
}