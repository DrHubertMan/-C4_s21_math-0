#include "s21_math.h"

long double s21_sqrt(double x) {
    long double left_point = 0;
    long double right_point = 1;
    if (x > right_point) right_point = x;
    long double midle_point = (right_point + left_point) / 2;
    if (x == -S21_INF) {
        midle_point = S21_NAN;
    } else if (S21_IS_INF(x) != 0) {
        midle_point = S21_INF;
    } else if (S21_IS_NAN(x) != 0) {
        midle_point = S21_NAN;
    } else if (x == 0) {
        midle_point = 0;
    } else if (x > 0) {
        while ((midle_point - left_point) > S21_EPS) {
            if ((midle_point  * midle_point) > x) {
                right_point = midle_point;
            } else {
                left_point = midle_point;
            }
            midle_point = (right_point + left_point) / 2;
        }
    }  else if (x < 0) {
        midle_point = S21_NAN;
    }
    return midle_point;
}
