#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = s21_fabs(x);

  y = s21_fabs(y);
  if (y == 0) x = S21_NAN;
  int i = 1;
  while (result >= y) {
    result = s21_fabs(x) - y * i;
    i++;
  }
  return (x < 0) ? -result : result;
}
