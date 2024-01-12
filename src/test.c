#include <math.h>
#include <stdio.h>

#include "tests/s21_math_tests.h"

int main() {
  int result = 0;

  result += s21_abs_tests();
  result += s21_fabs_tests();
  result += s21_ceil_tests();
  result += s21_floor_tests();
  result += s21_fmod_tests();
  result += s21_sqrt_tests();
  result += s21_log_tests();
  result += s21_exp_tests();
  result += s21_pow_tests();
  result += s21_cos_tests();
  result += s21_sin_tests();
  result += s21_tan_tests();
  result += s21_acos_tests();
  result += s21_asin_tests();
  result += s21_atan_tests();

  return (result == 0) ? 0 : 1;
}