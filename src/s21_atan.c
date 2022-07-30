#include"s21_math.h"

long double s21_atan(double x) {
    long double result = 0;
    if (s21_IS_INF(x) != 0) {
            result = s21_05PI;
    } else {
        if (x < 1. && x > -1.) {
            for (register int i = 0; i < 500; i++) {
                result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
            }
        } else if (x >= 1. || x <= -1.) {
            for (register int i = 0; i < 500; i++) {
                result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
            }
            result = s21_PI * s21_sqrt(x * x) / (2 * x) - result;
        } else {
            result = s21_NAN;
        }
    }
    return result;
}
