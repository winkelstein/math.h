#include "s21_math_tests.h"

START_TEST(s21_fmod_test0) {
  for (double i = -0.1; i < 5.0; i += 0.01)
    for (double j = 0.1; j < 5.0; j += 0.01)
      ck_assert_ldouble_eq_tol(s21_fmod(i, j), fmod(i, j), PRECISION);
}
END_TEST

START_TEST(s21_fmod_test_nan0) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan1) {
  ck_assert_ldouble_nan(s21_fmod(S21_POS_INF, S21_POS_INF));
}
END_TEST

START_TEST(s21_fmod_test_nan2) {
  ck_assert_ldouble_nan(s21_fmod(S21_NEG_INF, S21_NEG_INF));
}
END_TEST

START_TEST(s21_fmod_test_nan3) {
  ck_assert_ldouble_nan(s21_fmod(S21_POS_INF, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan4) {
  ck_assert_ldouble_nan(s21_fmod(S21_NEG_INF, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan5) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_POS_INF));
}
END_TEST

START_TEST(s21_fmod_test_nan6) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NEG_INF));
}
END_TEST

START_TEST(s21_fmod_test_nan7) {
  ck_assert_ldouble_nan(s21_fmod(S21_NEG_INF, S21_POS_INF));
}
END_TEST

START_TEST(s21_fmod_test_nan8) {
  ck_assert_ldouble_nan(s21_fmod(S21_POS_INF, S21_NEG_INF));
}
END_TEST

START_TEST(s21_fmod_test_nan9) { ck_assert_ldouble_nan(s21_fmod(24.9, 0)); }
END_TEST

START_TEST(s21_fmod_test1) {
  ck_assert_ldouble_eq_tol(s21_fmod(15.7, S21_POS_INF), fmod(15.7, INFINITY),
                           PRECISION);
}
END_TEST

START_TEST(s21_fmod_test2) {
  ck_assert_ldouble_eq_tol(s21_fmod(15.7, S21_NEG_INF), fmod(15.7, INFINITY),
                           PRECISION);
}
END_TEST

Suite *s21_fmod_test_suite() {
  Suite *s = suite_create("s21_fmod");
  TCase *tc_case = tcase_create("s21_fmod_case");
  tcase_add_test(tc_case, s21_fmod_test0);
  tcase_add_test(tc_case, s21_fmod_test1);
  tcase_add_test(tc_case, s21_fmod_test2);
  tcase_add_test(tc_case, s21_fmod_test_nan0);
  tcase_add_test(tc_case, s21_fmod_test_nan1);
  tcase_add_test(tc_case, s21_fmod_test_nan2);
  tcase_add_test(tc_case, s21_fmod_test_nan3);
  tcase_add_test(tc_case, s21_fmod_test_nan4);
  tcase_add_test(tc_case, s21_fmod_test_nan5);
  tcase_add_test(tc_case, s21_fmod_test_nan6);
  tcase_add_test(tc_case, s21_fmod_test_nan7);
  tcase_add_test(tc_case, s21_fmod_test_nan8);
  tcase_add_test(tc_case, s21_fmod_test_nan9);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_fmod_tests() {
  Suite *s = s21_fmod_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}