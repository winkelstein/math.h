#include "../s21_math.h"

long double s21_asin(double x) {
  long double result = 0.0;
  if (x > 1 || x < -1)
    result = S21_NAN;
  else if (x == 1 || x == -1)
    result = S21_M_PI_2 / x;
  else if (x > -1 && x < 1)
    result = S21_M_PI_2 - s21_acos(x);
  return result;
}