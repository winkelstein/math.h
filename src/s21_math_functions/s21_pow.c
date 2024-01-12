#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1.0;
  long double copy = base;
  long long int copy_exp_int = (long long int)exp;
  if (S21_IS_NAN(base) && exp != 0)
    result = S21_NAN;
  else if (base == S21_NEG_INF && exp == S21_POS_INF) {
    result = S21_POS_INF;
  } else if (base == 0 && exp == S21_NEG_INF) {
    result = S21_POS_INF;
  } else if (exp == S21_NEG_INF) {
    result = 0;
  } else if (exp == 0) {
    result = 1;
  } else if (copy < 0 && exp != copy_exp_int) {
    result = S21_NAN;
  } else if (S21_IS_NAN(exp) || (copy == 0 && exp < 0))
    result = S21_NAN;
  else if (copy < 0) {
    copy = -copy;
    result = s21_exp(exp * s21_log(copy));
    if (s21_fmod(exp, 2) != 0) {
      result = -result;
    }
  } else {
    result = s21_exp(exp * s21_log(base));
  }
  return result;
}