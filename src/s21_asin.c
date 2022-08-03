#include"s21_math.h"

long double s21_asin(double x) {
    long double result = 0;
    if (x < 1 && x > -1) {
        result = s21_atan(x / s21_sqrt(1 - (x * x)));
    } else if (x == 1) {
        result = S21_05PI;
    } else if (x == -1) {
        result = -S21_05PI;
    } else {
        result = S21_NAN;
    }
    return result;
}
