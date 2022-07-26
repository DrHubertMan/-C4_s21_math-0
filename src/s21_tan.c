#include"math.h"

long double tan(double x) {
    long double result;
    result = s21_sin(x)/s21_cos(x);
    return result;
}