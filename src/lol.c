#include<math.h>
#include<stdio.h>
#include"s21_math.h"

int main() {
    float k = 0;
    double a = s21_acos(k);
    double b = acos(k);
    printf("k = %lf\n", k);
    printf("s21_acos = %lf\n", a);
    printf("def_acos = %lf\n",  b);
    printf("********\n");
    return 0;
}