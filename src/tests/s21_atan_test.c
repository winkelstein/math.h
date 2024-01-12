#include "s21_math_tests.h"

START_TEST(s21_atan_test1) {
  for (double i = -1; i <= 1; i += 0.01)
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), PRECISION);
}
END_TEST

START_TEST(s21_atan_test2) {
  ck_assert_ldouble_eq(s21_atan(INFINITY), atan(INFINITY));
}
END_TEST

START_TEST(s21_atan_test3) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(s21_atan_test4) { ck_assert_ldouble_eq(s21_atan(1), S21_M_PI_4); }
END_TEST

START_TEST(s21_atan_test5) {
  ck_assert_ldouble_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

START_TEST(s21_atan_test_nan) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atan(S21_NAN));
}
END_TEST

Suite *s21_atan_test_suite() {
  Suite *s = suite_create("s21_atan");
  TCase *tc_case = tcase_create("s21_atan");
  tcase_add_test(tc_case, s21_atan_test1);
  tcase_add_test(tc_case, s21_atan_test2);
  tcase_add_test(tc_case, s21_atan_test3);
  tcase_add_test(tc_case, s21_atan_test4);
  tcase_add_test(tc_case, s21_atan_test5);
  tcase_add_test(tc_case, s21_atan_test_nan);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_atan_tests() {
  Suite *s = s21_atan_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}