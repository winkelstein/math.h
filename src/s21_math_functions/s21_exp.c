#include "../s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0;

  if (S21_IS_NAN(x)) {
    result = S21_NAN;
  } else if (x == S21_POS_INF) {
    result = S21_POS_INF;
  } else if (x == S21_NEG_INF || x < -14.5) {
    result = 0.0;
  } else {
    int max = 0;
    long double i = 1;
    long double step = x / i;
    while (s21_fabs(step) > 1e-7 && max == 0) {
      result += step;

      if (result > 1e100) {
        max = 1;
        result = S21_POS_INF;
      } else {
        i++;
        step *= x / i;
      }
    }
  }
  return result;
}
