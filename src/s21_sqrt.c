#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result_tmp = 0;
  long double result = result_tmp = 0;
  
  if (x > 0) {
    for (int j = 0; j < 20; j++) {
      double reduction = 1;
      double count = 0;
      for (; (result_tmp + count) * (result_tmp + count) < x;
           count += reduction) {
      }
      count -= reduction;
      result_tmp += count;
      reduction /= 10;
    }
  } else if (x < 0) {
    result_tmp = S21_NAN;
  }
  result = result_tmp;

  return result;
}
