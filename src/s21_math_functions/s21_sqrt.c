#include "../s21_math.h"

long double s21_sqrt(double x) {  // методом ньютона
  const double epsilon = 0.0000001;
  long double guess = 1.0;
  if (x < 0.0 || x == S21_NEG_INF || S21_IS_NAN(x))
    guess = S21_NAN;
  else if (x == S21_POS_INF)
    guess = S21_POS_INF;
  else if (x == 0)
    return 0.0;
  else {
    while ((guess * guess - x) > epsilon || (guess * guess - x) < -epsilon) {
      guess = (guess + x / guess) / 2.0;
    }
  }
  return guess;
}