#include "s21_math_tests.h"

START_TEST(s21_ceil_test) {
  for (double i = -10.0; i < 10; i += 0.01)
    ck_assert_ldouble_eq(s21_ceil(i), ceil(i));
}
END_TEST

START_TEST(s21_ceil_test_nan) { ck_assert_ldouble_nan(s21_ceil(S21_NAN)); }
END_TEST

START_TEST(s21_ceil_test_pos_inf) {
  ck_assert_ldouble_eq(s21_ceil(S21_POS_INF), ceil(INFINITY));
}
END_TEST

START_TEST(s21_ceil_test_neg_inf) {
  ck_assert_ldouble_eq(s21_ceil(S21_NEG_INF), ceil(-INFINITY));
}
END_TEST

Suite *s21_ceil_test_suite() {
  Suite *s = suite_create("s21_ceil");
  TCase *tc_case = tcase_create("s21_ceil_case");
  tcase_add_test(tc_case, s21_ceil_test);
  tcase_add_test(tc_case, s21_ceil_test_nan);
  tcase_add_test(tc_case, s21_ceil_test_pos_inf);
  tcase_add_test(tc_case, s21_ceil_test_neg_inf);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_ceil_tests() {
  Suite *s = s21_ceil_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}