#include "ExampleForm.h" //Подключаем форму, которая будет запускаться в первую очередь
#include "TaskForm.h"

namespace LR20 //Название пространства имен необходимо посмотреть в ранее созданной форме в начале файла
{
    [STAThreadAttribute] //атрибут для явного задания потоковой модели (обязателен)

    int Main(array<System::String^>^ args) //Входная точка, название указывалось в свойствах
    {
        System::Windows::Forms::Application::EnableVisualStyles(); //Включает визуальные стили для приложения.                   
        System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);//Тип отрисовки текста
        System::Windows::Forms::Application::Run(gcnew TaskForm()); //Запуск формы

        return 0;
    }
}
