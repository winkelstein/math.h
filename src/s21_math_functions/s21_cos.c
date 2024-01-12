#include "../s21_math.h"

long double s21_cos(double x) {
  long double result = 1.0;
  if (S21_IS_NAN(x) || x == S21_POS_INF || x == S21_NEG_INF)
    result = S21_NAN;
  else {
    int forSign = x / S21_M_PI;
    x -= forSign * S21_M_PI;
    short int sign = 1;
    if (forSign % 2 != 0) sign = -1;
    long double term = 1.0;
    for (int i = 1; i <= 10; i++) {
      long double termCoefficient = 2.0 * i;
      long double denominator = termCoefficient * (termCoefficient - 1.0);
      term *= x * x / denominator;
      if (i % 2 == 0) {
        result += term;
      } else {
        result -= term;
      }
    }
    result *= sign;
  }
  return result;
}