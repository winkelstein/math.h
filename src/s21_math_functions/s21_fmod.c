#include "../s21_math.h"
int is_nan_answer(double x, double y);

long double s21_fmod(double x, double y) {
  long double res = 0.0;
  if (y == 0)
    res = S21_NAN;
  else if (x == S21_POS_INF || x == S21_NEG_INF)
    res = S21_NAN;
  else if (y == S21_POS_INF || y == S21_NEG_INF)
    res = (long double)x;
  else {
    res = x - (int)(x / y) * y;
  }
  return (long double)res;
}