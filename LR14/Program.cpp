#include "MyForm.h" //���������� �����, ������� ����� ����������� � ������ �������
#include "FormTask.h"

namespace LR14 //�������� ������������ ���� ���������� ���������� � ����� ��������� ����� � ������ �����
{
    [STAThreadAttribute] //������� ��� ������ ������� ��������� ������ (����������)

    int Main(array<System::String^>^ args) //������� �����, �������� ����������� � ���������
    {
        System::Windows::Forms::Application::EnableVisualStyles(); //�������� ���������� ����� ��� ����������.                   
        System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);//��� ��������� ������
        System::Windows::Forms::Application::Run(gcnew FormTask()); //������ �����

        return 0;
    }
}
