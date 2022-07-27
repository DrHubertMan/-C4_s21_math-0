#include"s21_math.h"

long double s21_acos(double x) {
    long double result;
    if ( x < 1 && x > -1) {
        for (int i = 0; i < 1; i++) {
            result += (pow(-1, i) * pow(x, 1 + 2 * i)) / 1 + 2 * i;
        }
    }
    return result;
}