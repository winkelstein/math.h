#include "../s21_math.h"

long double s21_log(double x) {
  long double result = 0.0;

  if (x < 0)
    result = S21_NAN;
  else if (x == S21_POS_INF)
    result = S21_POS_INF;
  else if (x == 1.0)
    result = 0.0;
  else if (x == 0)
    result = S21_NEG_INF;
  else if (x == 2)
    result = S21_M_LN2;
  else if (x == 10.0)
    result = S21_M_LN10;
  else {
    long double term = (x - 1.0) / (x + 1.0);
    long double cur_term = term;

    for (long double n = 1; n <= 1e4; ++n) {
      result += cur_term;
      cur_term *= term * term * (2.0 * n - 1.0) / (2.0 * n + 1.0);

      if (cur_term < 1e-100) {
        break;
      }
    }
    result *= 2.0;
  }

  return result;
}