#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  long double added_value = 1;
  long double count = 1;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = x;
  } else if (x == -S21_INF) {
    result = 0;
  } else if (x == 0) {
    result = 1;
  } else {
    while (s21_fabs(added_value) > S21_EPS) {
      added_value *= x / count;
      result += added_value;
      if (result > S21_MAX_DOUBLE) {
        result = S21_INF;
        break;
      }
      if (result < -7.083964E+002) {
        result = 0;
        break;
      }
      count++;
    }
  }

  if (result > S21_MAX_DOUBLE) result = S21_INF;

  return result;
}
