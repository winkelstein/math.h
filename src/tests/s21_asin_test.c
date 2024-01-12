#include "s21_math_tests.h"

START_TEST(s21_asin_test) {
  for (double i = -1; i <= 1; i += 0.01)
    ck_assert_double_eq_tol(s21_asin(i), asin(i), PRECISION);
}
END_TEST

START_TEST(s21_asin_test_nan) {
  ck_assert_double_nan(s21_asin(-12.4));
  ck_assert_double_nan(s21_asin(1.00001));
}
END_TEST

Suite *s21_asin_test_suite() {
  Suite *s = suite_create("s21_asin");
  TCase *tc_case = tcase_create("s21_asin");
  tcase_add_test(tc_case, s21_asin_test);
  tcase_add_test(tc_case, s21_asin_test_nan);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_asin_tests() {
  Suite *s = s21_asin_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}