#include"s21_math.h"

long double s21_sin(double x) {
    long double result = 0;
    for (; x < -2 * s21_PI || 2 * s21_PI < x ;) {
        if ( x < -2 * s21_PI) x += 2 * s21_PI;
        else x -= 2 * s21_PI;
    }
    for (int i = 0; i < 500; i++) {
        result += pow(-1, i) * pow(x, (2 * i) + 1)/ s21_factorial((2 * i) + 1);
    }
    return result;
}
