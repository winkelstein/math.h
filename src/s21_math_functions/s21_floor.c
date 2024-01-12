#include "../s21_math.h"

long double s21_floor(double x) {
  long double res = x;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (x == S21_POS_INF || x == S21_NEG_INF)
    res = (long double)res;
  else if (x < 0 && (x != (int)x)) {
    res = (int)x - 1;
  } else {
    res = (int)x;
  }
  return (long double)res;
}