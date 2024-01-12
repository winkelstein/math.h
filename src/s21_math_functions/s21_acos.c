#include "../s21_math.h"

long double s21_acos(double x) {
  long double result = 0.0;
  if (x > 1 || x < -1) result = S21_NAN;
  if (x == 1) result = 0;
  if (x == -1)
    result = S21_M_PI;
  else if (x < 1 && x >= 0)
    result = s21_atan(s21_sqrt(1.0 - x * x) / x);
  else if (x < 0 && x > -1)
    result = S21_M_PI + s21_atan(s21_sqrt(1.0 - x * x) / x);
  return result;
}