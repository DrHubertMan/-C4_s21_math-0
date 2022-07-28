#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include<stdio.h>
#include<math.h>

#define s21_NAN (0.0 / 0.0)
#define s21_INF 1 / 0.0 // 
#define s21_PI 3.14159265358979323846264338327950288
/*
  return 1 if NaN and 0 if not
*/
#define s21_IS_NAN(x) __builtin_isnan(x)  // this (!(x >= 0) && !(x < 0)) 
/*
  return 1 if inf and -1 if -inf and 0 if finite
*/
#define s21_IS_INF(x) __built_isinf(x)  // ((x == S21_INF) || (x == -S21_INF)) 

long double s21_sin(double x);
long double s21_factorial(int x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);

#endif  // SRC_S21_MATH_H_
