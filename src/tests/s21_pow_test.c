#include "s21_math_tests.h"

START_TEST(s21_pow_test1) {
  ck_assert_ldouble_eq_tol(s21_pow(20, 0.4), powl(20, 0.4), PRECISION);
}
END_TEST

START_TEST(s21_pow_test2) {
  ck_assert_ldouble_nan(s21_pow(-20, 0.4));
  ck_assert_ldouble_nan(powl(-20, 0.4));
}
END_TEST

START_TEST(s21_pow_test3) {
  ck_assert_ldouble_eq(s21_pow(INFINITY, INFINITY), powl(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test4) {
  ck_assert_ldouble_eq(s21_pow(-INFINITY, -INFINITY),
                       powl(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test5) {
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
  ck_assert_ldouble_nan(powl(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_test6) {
  ck_assert_ldouble_nan(s21_pow(INFINITY, NAN));
  ck_assert_ldouble_nan(powl(INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test7) {
  ck_assert_ldouble_nan(s21_pow(NAN, INFINITY));
  ck_assert_ldouble_nan(powl(NAN, INFINITY));
}
END_TEST

START_TEST(s21_pow_test8) {
  ck_assert_ldouble_nan(s21_pow(-INFINITY, NAN));
  ck_assert_ldouble_nan(powl(-INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test9) {
  ck_assert_ldouble_nan(s21_pow(NAN, -INFINITY));
  ck_assert_ldouble_nan(powl(NAN, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test10) {
  ck_assert_ldouble_eq(s21_pow(-INFINITY, INFINITY), powl(-INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test11) {
  ck_assert_ldouble_eq(s21_pow(INFINITY, -INFINITY), powl(INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test12) {
  ck_assert_ldouble_eq_tol(s21_pow(12.69, 0), powl(12.69, 0), PRECISION);
}
END_TEST

START_TEST(s21_pow_test13) {
  ck_assert_ldouble_eq_tol(s21_pow(-20.63, 3), powl(-20.63, 3), PRECISION);
}
END_TEST

START_TEST(s21_pow_test14) {
  ck_assert_ldouble_eq_tol(s21_pow(-20.63, 6), powl(-20.63, 6), PRECISION);
}
END_TEST

START_TEST(s21_pow_test15) {
  ck_assert_ldouble_eq_tol(s21_pow(-INFINITY, 0), powl(-INFINITY, 0),
                           PRECISION);
}
END_TEST

START_TEST(s21_pow_test16) {
  ck_assert_ldouble_eq_tol(s21_pow(INFINITY, 0), powl(INFINITY, 0), PRECISION);
}
END_TEST

START_TEST(s21_pow_test17) {
  ck_assert_ldouble_eq_tol(s21_pow(NAN, 0), powl(NAN, 0), PRECISION);
}
END_TEST

START_TEST(s21_pow_test18) {
  ck_assert_ldouble_eq(s21_pow(0, -INFINITY), powl(0, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test19) {
  ck_assert_ldouble_eq_tol(s21_pow(0, INFINITY), powl(0, INFINITY), PRECISION);
}
END_TEST

START_TEST(s21_pow_test20) {
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
  ck_assert_ldouble_nan(powl(0, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test21) { ck_assert_double_eq(s21_pow(0, 0), powl(0, 0)); }
END_TEST

START_TEST(s21_pow_test22) {
  ck_assert_double_eq(s21_pow(16894.2629, 1545), powl(16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test23) {
  ck_assert_double_eq(s21_pow(16894.2629, -1545), powl(16894.2629, -1545));
}
END_TEST

START_TEST(s21_pow_test25) {
  ck_assert_double_eq(s21_pow(-16894.2629, -1545), powl(-16894.2629, -1545));
}
END_TEST

START_TEST(s21_pow_test26) { ck_assert_double_eq(s21_pow(0, 15), powl(0, 15)); }
END_TEST

START_TEST(s21_pow_test27) { ck_assert_double_eq(s21_pow(0, 15), powl(0, 15)); }
END_TEST

Suite *s21_pow_test_suite() {
  Suite *s = suite_create("s21_pow");
  TCase *tc_case = tcase_create("s21_pow_case");
  tcase_add_test(tc_case, s21_pow_test1);
  tcase_add_test(tc_case, s21_pow_test2);
  tcase_add_test(tc_case, s21_pow_test3);
  tcase_add_test(tc_case, s21_pow_test4);
  tcase_add_test(tc_case, s21_pow_test5);
  tcase_add_test(tc_case, s21_pow_test6);
  tcase_add_test(tc_case, s21_pow_test7);
  tcase_add_test(tc_case, s21_pow_test8);
  tcase_add_test(tc_case, s21_pow_test9);
  tcase_add_test(tc_case, s21_pow_test10);
  tcase_add_test(tc_case, s21_pow_test11);
  tcase_add_test(tc_case, s21_pow_test12);
  tcase_add_test(tc_case, s21_pow_test13);
  tcase_add_test(tc_case, s21_pow_test14);
  tcase_add_test(tc_case, s21_pow_test15);
  tcase_add_test(tc_case, s21_pow_test16);
  tcase_add_test(tc_case, s21_pow_test17);
  tcase_add_test(tc_case, s21_pow_test18);
  tcase_add_test(tc_case, s21_pow_test19);
  tcase_add_test(tc_case, s21_pow_test20);
  tcase_add_test(tc_case, s21_pow_test21);
  tcase_add_test(tc_case, s21_pow_test22);
  tcase_add_test(tc_case, s21_pow_test23);
  tcase_add_test(tc_case, s21_pow_test25);
  tcase_add_test(tc_case, s21_pow_test26);
  tcase_add_test(tc_case, s21_pow_test27);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_pow_tests() {
  Suite *s = s21_pow_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}