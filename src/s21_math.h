#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_PI 3.14159265358979323846264338327950288
#define S21_05PI 1.570796326794896619231
#define S21_EXP 2.7182818284590452353602874713526624

#define S21_EPS 1e-14
#define S21_MAX_DOUBLE 1.7976931348623157E308

#define S21_NAN 0.0 / 0.0
#define S21_INF 1 / 0.0

// #define s21_IS_NAN(x) (!(x >= 0) && !(x < 0))
// #define s21_IS_INF(x) ((x == S21_INF) || (x == -S21_INF))

/*
  return 1 if NaN and 0 if not
*/
#define S21_IS_NAN(x) __builtin_isnan(x)  // this (!(x >= 0) && !(x < 0))
/*
  return 1 if inf and -1 if -inf and 0 if finite
*/
#define S21_IS_INF(x) __builtin_isinf(x)  // ((x == S21_INF) || (x == -S21_INF))

// betacind
int s21_abs(int x);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

    // betacind

    // mammiemi
long double s21_sin(double x);
long double s21_factorial(int x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
// mammiemi

#endif  // SRC_S21_MATH_H_
