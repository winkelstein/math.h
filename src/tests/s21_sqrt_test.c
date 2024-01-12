#include "s21_math_tests.h"

START_TEST(s21_sqrt_test) {
  for (double i = 0.0; i < 10; i += 0.01)
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), PRECISION);
}
END_TEST

START_TEST(s21_sqrt_test_pos_inf) {
  ck_assert_ldouble_eq(s21_sqrt(S21_POS_INF), sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test_nan0) { ck_assert_ldouble_nan(s21_sqrt(S21_NAN)); }
END_TEST

START_TEST(s21_sqrt_test_nan1) { ck_assert_ldouble_nan(s21_sqrt(-1.42)); }
END_TEST

START_TEST(s21_sqrt_test_nan2) { ck_assert_ldouble_nan(s21_sqrt(S21_NEG_INF)); }
END_TEST

Suite *s21_sqrt_test_suite() {
  Suite *s = suite_create("s21_sqrt");
  TCase *tc_case = tcase_create("s21_sqrt_case");
  tcase_add_test(tc_case, s21_sqrt_test);
  tcase_add_test(tc_case, s21_sqrt_test_pos_inf);
  tcase_add_test(tc_case, s21_sqrt_test_nan0);
  tcase_add_test(tc_case, s21_sqrt_test_nan1);
  tcase_add_test(tc_case, s21_sqrt_test_nan2);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_sqrt_tests() {
  Suite *s = s21_sqrt_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}