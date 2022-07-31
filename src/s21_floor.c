#include "s21_math.h"

long double s21_floor(double x) {
  long double result = s21_fabs(x);

  if ((result == 0) || (result == S21_INF) || (result == S21_MAX_DOUBLE)) {
    result = x;
  } else if (result > 0) {
    result = s21_fabs((long long)x);
    if ((result != s21_fabs(x)) && (((result - s21_fabs(x))) < 1)) {
      if (x < 0) {
        result++;
        result = -result;
      }
    } else {
      result = x;
    }
  } else {
    result = S21_NAN;
  }
  return x == 0 ? 0 : result;
}
