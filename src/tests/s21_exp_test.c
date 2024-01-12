#include "s21_math_tests.h"

START_TEST(s21_exp_test) {
  for (double i = 0.0; i < 5.0; i += 0.1)
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), PRECISION);
}
END_TEST

START_TEST(s21_exp_test_pos_inf) {
  ck_assert_ldouble_eq(s21_exp(S21_POS_INF), exp(INFINITY));
}
END_TEST

START_TEST(s21_exp_test_neg_inf) {
  ck_assert_ldouble_eq(s21_exp(S21_NEG_INF), exp(-INFINITY));
}
END_TEST

START_TEST(s21_exp_test_zero) {
  ck_assert_ldouble_eq(s21_exp(S21_NEG_INF), exp(S21_NEG_INF));
}
END_TEST

START_TEST(s21_exp_test_nan) { ck_assert_ldouble_nan(s21_exp(S21_NAN)); }
END_TEST

Suite *s21_exp_test_suite() {
  Suite *s = suite_create("s21_exp");
  TCase *tc_case = tcase_create("s21_exp_case");
  tcase_add_test(tc_case, s21_exp_test);
  tcase_add_test(tc_case, s21_exp_test_pos_inf);
  tcase_add_test(tc_case, s21_exp_test_neg_inf);
  tcase_add_test(tc_case, s21_exp_test_zero);
  tcase_add_test(tc_case, s21_exp_test_nan);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_exp_tests() {
  Suite *s = s21_exp_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}