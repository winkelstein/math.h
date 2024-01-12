#include "s21_math_tests.h"

START_TEST(s21_abs_test) {
  for (int i = -1000; i < 1000; i++) ck_assert_int_eq(s21_abs(i), abs(i));
}
END_TEST

Suite *s21_abs_test_suite() {
  Suite *s = suite_create("s21_abs");
  TCase *tc_case = tcase_create("s21_abs_case");
  tcase_add_test(tc_case, s21_abs_test);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_abs_tests() {
  Suite *s = s21_abs_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}