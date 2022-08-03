#include"s21_math.h"

long double s21_factorial(int x) {
    long double result;
    if (x <= 1) result = 1;
    else
        result = x * s21_factorial(x - 1);
    return result;
}
