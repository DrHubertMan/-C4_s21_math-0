#include"s21_math.h"

long double s21_atan(double x) {
    long double result = 0;
    if ( (x < 1. && x > -1.) || x == 1) {
        for (register int i = 0; i < 500; i++) {
            result += pow(-1, i) * pow(x, 1 + (2 * i)) / (1 + (2 * i));
        }
    } else if (x > 1. || x < -1.) {
        for (register int i = 0; i < 500; i++) {
            result += pow(-1, i) * pow(x, -1 - (2 * i)) / (1 + (2 * i));
        }
        result = ((s21_PI * sqrt(pow(x, 2))) / 2 * x) - result;
    }
    return result;
}