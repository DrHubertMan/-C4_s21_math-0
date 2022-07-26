#include"s21_math.h"

long double sin(double x) {
    long double result = 0;
    for (int i = 0; i < 500; i++) {
        result += pow(-1, i) * pow(x, (2 * i) + 1)/ s21_factorial((2 * i) + 1);
    }
    return result;
}