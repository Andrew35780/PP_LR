#include <stdio.h>
#include <locale.h>
#include <cmath>

using namespace std;

void main() {
    setlocale(LC_CTYPE, "");

    system("color f0");

    float r, A, R;

    printf("¬ведите радиус вписанной в квадрат окружности, r=");
    scanf_s("%f", &r);

    A = 2 * r;
    R = A / sqrt(2);

    printf("\nA=%f\nR=%f\n", A, R);
}
