#include "ExampleForm.h" //���������� �����, ������� ����� ����������� � ������ �������
#include "TaskForm.h"

namespace LR20 //�������� ������������ ���� ���������� ���������� � ����� ��������� ����� � ������ �����
{
    [STAThreadAttribute] //������� ��� ������ ������� ��������� ������ (����������)

    int Main(array<System::String^>^ args) //������� �����, �������� ����������� � ���������
    {
        System::Windows::Forms::Application::EnableVisualStyles(); //�������� ���������� ����� ��� ����������.                   
        System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);//��� ��������� ������
        System::Windows::Forms::Application::Run(gcnew TaskForm()); //������ �����

        return 0;
    }
}
