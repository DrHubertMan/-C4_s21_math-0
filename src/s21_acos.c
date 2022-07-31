#include"s21_math.h"
#include<math.h>

long double s21_acos(double x) {
    long double result = 0;
    if (x <= 1 && x > 0) {
        result = s21_atan(sqrt(1 - (x * x)) / x);
    } else if (x >= -1 && x < 0) {
        result = S21_PI + s21_atan(sqrt(1 - (x * x)) / x);
    } else if (S21_IS_INF(x) != 0) {
        result = S21_NAN;
    } else if (x < S21_EPS && x >= 0) {
        result = S21_05PI;
    }  else {
        result = S21_NAN;
    }
    return result;
}
