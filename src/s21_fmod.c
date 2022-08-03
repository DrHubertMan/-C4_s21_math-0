#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = s21_fabs(x);

  y = s21_fabs(y);
  if (x == S21_NAN) {
    result = S21_NAN;
  } else if (x == -S21_NAN) {
    result = -S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else if (x == -1 && y == -S21_INF) {
    x = -1;
  } else if (x == 0 && y == S21_INF) {
    x = 0;
  } else if (y > 0 || y < 0) {
    int i = 1;
    while (result >= y) {
      result = s21_fabs(x) - y * i;
      i++;
    }
  } else {
    result = -S21_NAN;
  }
  return (x < 0) ? -result : result;
}
