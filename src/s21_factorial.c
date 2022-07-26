#include"s21_math.h"

int s21_factorial(int x) {
    return (x < 2) ? 1 : s21_factorial(x - 1);
}