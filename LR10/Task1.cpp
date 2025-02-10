#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale.h>

using namespace std;

double ctg(double x);
double Func(double x, double y, double const a);

void main()
{
    setlocale(LC_CTYPE, "");
    system("color f0");

    double const a = 0.5;
    double x, y, s;

    cout << "\n Таблица вычисления функции \ns=ctg(xy)-sin(ax+y)+sqrt(xy)\n";
    cout << "\n" << "|  x  |  y  |  a  |    s    |\n";
    cout << "-----------------------------\n";
    
    for (x = -1; x <= 2; x += 0.2) {
        for (y = 5; y <= 7; y += 0.3) {
            //Избавляемся от погрешностей округления вещественных чисел
            x = round(x*1000)/1000;
            y = round(y*1000)/1000;

            double xy = x * y;

            // Проверяем, чтобы x * y не было отрицательным для корня
            if (xy < 0) {
                cout << "|" << setw(4) << x << " |" << setw(4) << y << " | " << setw(3) << a << " | " << " ошибка |\n";
                continue;
            }
            
            // Проверяем тангенс, чтобы избежать деления на ноль
            if (tan(x * y) == 0) {
                cout << "|" << setw(4) << x << " |" << setw(4) << y << " | " << setw(3) << a << " | " << " ошибка |\n";
                continue;
            }
            
            s = Func(x, y, a);

            cout << "|" << fixed << setprecision(1) << setw(4) << x << " |";
            cout << fixed << setprecision(1) << setw(4) << y << " | ";
            cout << fixed << setw(3) << a << " | ";
            cout << fixed << setprecision(4) << setw(7) << s << " |" << "\n";
        }
    }
    cout << "-----------------------------\n";
}

double ctg(double x)
{
    return 1.0 / tan(x);
}

double Func(double x, double y, double const a)
{
    return ctg(x * y) - sin(a * x + y) + sqrt(x * y);
}
