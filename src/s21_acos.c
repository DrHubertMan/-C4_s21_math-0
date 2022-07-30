#include"s21_math.h"

long double s21_acos(double x) {
    long double result = 0;
    if (x <= 1 && x > 0) {
        result = s21_atan(s21_sqrt(1 - (x * x)) / x);
    } else if (x >= -1 && x < 0) {
        result = s21_PI + s21_atan(s21_sqrt(1 - (x * x)) / x);
    } else if (s21_IS_INF(x) != 0) {
        result = s21_NAN;
    } else if (x < s21_EPS && x >= 0) {
        result = s21_05PI;
    }  else {
        result = s21_NAN;
    }
    return result;
}
