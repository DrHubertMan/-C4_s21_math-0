#include "s21_math.h"

long double s21_floor(double x) {
  long int result = (long int)x;
  if (x < 0) {
    if (result > x) {
      result--;
    }
  }
  return x == 0 ? 0 : result;
}
