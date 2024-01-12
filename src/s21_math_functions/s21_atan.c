#include "../s21_math.h"

long double s21_powi(double base, int exp);

long double s21_atan(double x) {
  long double result = 0.0;
  if (S21_IS_NAN(x)) {
    result = S21_NAN;
  } else if (x == S21_POS_INF) {
    result = S21_M_PI_2;
  } else if (x == S21_NEG_INF) {
    result = -S21_M_PI_2;
  } else if (x == 1) {
    result = S21_M_PI_4;
  } else if (x == -1) {
    result = -S21_M_PI_4;
  } else {
    short int inRange = -1;
    if (x > -1 && x < 1) {
      inRange = 1;
      result = x;
    } else {
      result = 1.0 / x;
    }
    for (int i = 1; i < 1000; i++) {
      result +=
          s21_powi(-1, i) * s21_powi(x, (1 + 2 * i) * inRange) / (1 + 2 * i);
    }
    if (inRange == -1) result = (S21_M_PI * s21_fabs(x) / (2 * x)) - result;
  }
  return result;
}

long double s21_powi(double base, int exp) {
  long double result = 1.0;
  short int sign = 0;
  if (exp > 0) {
    sign = 1;
    exp *= 1;
  } else {
    exp *= -1;
  }
  for (int i = 0; i < exp; i++) {
    if (sign) {
      result *= base;
    } else {
      result /= base;
    }
  }
  return result;
}