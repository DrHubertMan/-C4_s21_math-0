#include"s21_math.h"
#include<math.h>

long double s21_sin(double x) {
    long double result = 0;
    if (S21_IS_INF(x) != 0) {
        result = S21_NAN;
    } else {
        for (; x < -2 * S21_PI || 2 * S21_PI < x ;) {
            if ( x < -2 * S21_PI) x += 2 * S21_PI;
            else
                x -= 2 * S21_PI;
        }
        for (register int i = 0; i < 180; i++) {
            result += pow(-1, i) * pow(x, 2 * i + 1)/ s21_factorial(2 * i + 1);
        }
    }
    return result;
}
