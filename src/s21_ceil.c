#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    result = x;
  } else {
    if (x >= 0) {
      long double ceil_x = x - (long long int)x;
      if (ceil_x <= 1E-6) {
        result = x;
      } else {
        result = (long long int)x + 1;
      }
    } else {
      result = (long long int)x;
    }
  }
  return result;
}
