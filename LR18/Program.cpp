#include "ExampleForm.h" //���������� �����, ������� ����� ����������� � ������ �������
#include "Task1.h"
#include "Task2.h"
#include "Task1_Part2.h"

namespace LR18 //�������� ������������ ���� ���������� ���������� � ����� ��������� ����� � ������ �����
{
    [STAThreadAttribute] //������� ��� ������ ������� ��������� ������ (����������)

    int Main(array<System::String^>^ args) //������� �����, �������� ����������� � ���������
    {
        System::Windows::Forms::Application::EnableVisualStyles(); //�������� ���������� ����� ��� ����������.                   
        System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);//��� ��������� ������
        System::Windows::Forms::Application::Run(gcnew Task2()); //������ �����

        return 0;
    }
}
