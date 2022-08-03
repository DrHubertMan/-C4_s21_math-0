#include"s21_math.h"

long double s21_cos(double x) {
    long double result = 0;
    if (S21_IS_INF(x) != 0) {
        result = S21_NAN;
    } else {
        while (x < -2 * S21_PI || 2 * S21_PI < x) {
            if (x < -2 * S21_PI) {
                x += 2 * S21_PI;
            } else {
                x -= 2 * S21_PI;
            }
        }
        for (register int i = 0; i < 180; i++) {
            result += s21_pow(-1, i) * s21_pow(x, 2 * i)/ s21_factorial(2 * i);
        }
    }
    return result;
}
