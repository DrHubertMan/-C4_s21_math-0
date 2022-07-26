#include"s21_math.h"

long double cos(double x) {
    long double result = 0;
    for (int i = 0; i < 500; i++) {
        result += pow(-1, i) * pow(x, 2 * i)/ s21_factorial(2 * i);
    }
    return result;
}