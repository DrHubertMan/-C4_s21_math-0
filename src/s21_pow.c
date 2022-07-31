#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result;
  long double exp_fractional = exp - (long long int)exp;

  if ((!S21_IS_NAN(exp)) && (!S21_IS_NAN(base)) && (exp_fractional <= 1E-6) &&
      (exp_fractional >= -1E-6)) {
    result = 1;
    if (exp > 0) {
      result = base;
      for (long int i = 0; i < (long int)exp - 1; i++) {
        result *= base;
      }
    } else if (exp < 0) {
      result = 1 / base;
      for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
        result /= base;
      }
    }
  } else {
    if ((exp == 0) || (base == 1) || (base == -1 && S21_IS_INF(exp))) {
      result = 1;
    } else if (S21_IS_NAN(base)) {
      result = S21_NAN;
    } else if ((base == 0) && (!S21_IS_NAN(exp))) {
      result = exp < 0 ? S21_INF : 0;
    } else if (exp == S21_INF) {
      result = s21_fabs(base) > 1 ? S21_INF : 0;
    } else if (exp == -S21_INF) {
      result = s21_fabs(base) < 1 ? S21_INF : 0;
    } else if ((base == -S21_INF) && (!S21_IS_NAN(exp))) {
      result = exp > 0 ? S21_INF : 0;
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}
