#include"s21_math.h"

int main() {
    double x = 1;
    printf("x:%f\n", x);
    printf("fact(x):%Lf\n", s21_factorial(x));
    printf("s21_sin(x):%Lf\n", s21_sin(x));
    printf("def_sin(x):%f\n", sin(x));
    printf("s21_cos(x):%Lf\n", s21_cos(x));
    printf("def_cos(x):%f\n", cos(x));
    printf("s21_tan(x):%Lf\n", s21_tan(x));
    printf("def_tan(x):%f\n", tan(x));
    printf("s21_atan(x):%Lf\n", s21_atan(x));
    printf("def_atan(x):%f\n", atan(x));
}