#include "../s21_math.h"

long double s21_ceil(double x) {
  long double result = 0.0;
  if (S21_IS_NAN(x))
    result = S21_NAN;
  else if (x == S21_POS_INF)
    result = S21_POS_INF;
  else if (x == S21_NEG_INF)
    result = S21_NEG_INF;
  else if (x == (int)x)
    result = x;
  else if (x < 0.0 || x == 0)
    result = (int)x;
  else
    result = (int)x + 1;
  return (long double)result;
}