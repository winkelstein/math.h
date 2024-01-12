#include "s21_math_tests.h"

START_TEST(s21_tan_test) {
  for (double i = -1.5; i <= 6.234; i += 0.001)
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), PRECISION);
}
END_TEST

START_TEST(s21_tan_test_nan0) {
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(tan(S21_NAN));
}
END_TEST

START_TEST(s21_tan_test_nan1) {
  ck_assert_ldouble_nan(s21_tan(S21_POS_INF));
  ck_assert_ldouble_nan(tan(INFINITY));
}
END_TEST

START_TEST(s21_tan_test_nan2) {
  ck_assert_ldouble_nan(s21_tan(S21_NEG_INF));
  ck_assert_ldouble_nan(tan(-INFINITY));
}
END_TEST

Suite *s21_tan_test_suite() {
  Suite *s = suite_create("s21_tan");
  TCase *tc_case = tcase_create("s21_tan");
  tcase_add_test(tc_case, s21_tan_test);
  tcase_add_test(tc_case, s21_tan_test_nan0);
  tcase_add_test(tc_case, s21_tan_test_nan1);
  tcase_add_test(tc_case, s21_tan_test_nan2);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_tan_tests() {
  Suite *s = s21_tan_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}