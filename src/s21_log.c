#include "s21_math.h"

long double s21_log(double x) {
  int i = 2;
  long double result = x - 1;
  long double result_s = result;
  long double result_a = x;
  if (x < 0) {
    result = s21_NAN;
  } else if (x == 0.0) {
    result = -s21_INF;
  } else if (x < 2.0 + s21_EPS) {
    x = x - 1;
    while (s21_fabs((double)result_s / i) > s21_EPS) {
      result_s *= -1 * x;
      result += result_s / i;
      ++i;
    }
  } else {
    int count = 0;
    while (result_a > 1.0) {
      result_a /= 10;
      count++;
    }
    result = s21_log(result_a) + count * 2.302585092994;
  }
  return result;
}
