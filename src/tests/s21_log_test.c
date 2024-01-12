#include "s21_math_tests.h"

START_TEST(s21_log_test) {
  for (double i = 1.0; i < 50.0; i++)
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), PRECISION);
}
END_TEST

START_TEST(s21_log_test_pos_inf) {
  ck_assert_ldouble_eq(s21_log(S21_POS_INF), log(INFINITY));
}
END_TEST

START_TEST(s21_log_test_ln2) {
  ck_assert_ldouble_eq_tol(s21_log(2.0), log(2.0), PRECISION);
}
END_TEST

START_TEST(s21_log_test_ln10) {
  ck_assert_ldouble_eq_tol(s21_log(10.0), log(10.0), PRECISION);
}
END_TEST

START_TEST(s21_log_test_nan0) { ck_assert_ldouble_nan(s21_log(S21_NAN)); }
END_TEST

START_TEST(s21_log_test_nan1) { ck_assert_ldouble_nan(s21_log(-10.1)); }
END_TEST

START_TEST(s21_log_test_nan2) { ck_assert_ldouble_nan(s21_log(S21_NEG_INF)); }
END_TEST

Suite *s21_log_test_suite() {
  Suite *s = suite_create("s21_log");
  TCase *tc_case = tcase_create("s21_log_case");
  tcase_add_test(tc_case, s21_log_test);
  tcase_add_test(tc_case, s21_log_test_pos_inf);
  tcase_add_test(tc_case, s21_log_test_ln2);
  tcase_add_test(tc_case, s21_log_test_ln10);
  tcase_add_test(tc_case, s21_log_test_nan0);
  tcase_add_test(tc_case, s21_log_test_nan1);
  tcase_add_test(tc_case, s21_log_test_nan2);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_log_tests() {
  Suite *s = s21_log_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}