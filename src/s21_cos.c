#include"s21_math.h"

long double s21_cos(double x) {
    long double result = 0;
    while (x < -2 * s21_PI || 2 * s21_PI < x) {
        if ( x < -2 * s21_PI) {
            x += 2 * s21_PI;
        } else {
            x -= 2 * s21_PI;
        }
    }
    for (register int i = 0; i < 180; i++) {
        result += pow(-1, i) * pow(x, 2 * i)/ s21_factorial(2 * i);
    }
    return result;
}