#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  long double add_result_tmp = 1;
  long double count = 1;

  int flag = 0;

  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(add_result_tmp) > S21_EPS) {
    add_result_tmp *= x / count;
    count++;
    result += add_result_tmp;
    if (result > S21_MAX_DOUBLE) {
      result = S21_INF;
      break;
    }
  }
  if (flag == 1) {
    if (result > S21_MAX_DOUBLE)
      result = 0;
    else
      result = 1. / result;
  }
  if (result > S21_MAX_DOUBLE) result = S21_INF;
  return result;
}
