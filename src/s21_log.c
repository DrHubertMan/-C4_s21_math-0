#include "s21_math.h"

long double s21_log(double x) {
    int exp = 0;
    long double result = 0;
    double compare = 0;
    if (x != x) {
        result = -S21_NAN;
    } else if (x == S21_INF) {
        result = x;
    } else if (x == -S21_INF || x < 0) {
        result = S21_NAN;
    } else if (x == 0) {
        result = -S21_INF;
    } else {
        for (; x >= S21_EXP; x /= S21_EXP, exp++) continue;
        for (int i = 0; i < 100; i++) {
            compare = result;
            result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
        }
    }
    return result + exp;
}
