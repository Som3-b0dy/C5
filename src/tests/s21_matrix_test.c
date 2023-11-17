#include "../s21_matrix.h"

#include <check.h>
#include <math.h>
#include <stdio.h>

#include "s21_matrix_test.h"

START_TEST(test_create_matrix) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(0, 0, &B);
  int code = check_matrix(&B);
  A.matrix[0][0] = 10;
  ck_assert_float_eq(A.matrix[0][0], 10.0);
  ck_assert_int_eq(3, A.rows);
  ck_assert_int_eq(3, A.columns);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_remove_matrix) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5;
  s21_remove_matrix(&A);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
  _ck_assert_ptr_null(A.matrix, ==);
}
END_TEST

START_TEST(test_eq_matrix) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  B.matrix[1][1] = 3;
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  A.matrix[1][1] = 0.0000007;
  B.matrix[1][1] = 0.0000008;
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 0);
  A.matrix[1][1] = 0.0000008;
  B.matrix[1][1] = 0.0000008;
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 4;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 4;
  s21_sub_matrix(&A, &B, &result);
  ck_assert_float_eq(result.matrix[0][0], 1);
  ck_assert_float_eq(result.matrix[0][1], 2);
  ck_assert_float_eq(result.matrix[1][0], 3);
  ck_assert_float_eq(result.matrix[1][1], 4);
  s21_remove_matrix(&result);
  s21_sub_matrix(&B, &A, &result);
  ck_assert_float_eq(result.matrix[0][0], -1);
  ck_assert_float_eq(result.matrix[0][1], -2);
  ck_assert_float_eq(result.matrix[1][0], -3);
  ck_assert_float_eq(result.matrix[1][1], -4);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 4;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 4;
  s21_sum_matrix(&A, &B, &result);
  ck_assert_float_eq(result.matrix[0][0], 9);
  ck_assert_float_eq(result.matrix[0][1], 10);
  ck_assert_float_eq(result.matrix[1][0], 11);
  ck_assert_float_eq(result.matrix[1][1], 12);
  s21_remove_matrix(&result);
  s21_sum_matrix(&B, &A, &result);
  ck_assert_float_eq(result.matrix[0][0], 9);
  ck_assert_float_eq(result.matrix[0][1], 10);
  ck_assert_float_eq(result.matrix[1][0], 11);
  ck_assert_float_eq(result.matrix[1][1], 12);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  s21_mult_number(&A, 2, &result);
  ck_assert_float_eq(result.matrix[0][0], 10);
  ck_assert_float_eq(result.matrix[0][1], 12);
  ck_assert_float_eq(result.matrix[1][0], 14);
  ck_assert_float_eq(result.matrix[1][1], 16);
  s21_remove_matrix(&result);
  s21_mult_number(&A, 100, &result);
  ck_assert_float_eq(result.matrix[0][0], 500);
  ck_assert_float_eq(result.matrix[0][1], 600);
  ck_assert_float_eq(result.matrix[1][0], 700);
  ck_assert_float_eq(result.matrix[1][1], 800);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[2][0] = 3;
  A.matrix[0][1] = 4;
  A.matrix[1][1] = 5;
  A.matrix[2][1] = 6;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  s21_mult_matrix(&A, &B, &result);
  ck_assert_float_eq(result.matrix[0][0], 17);
  ck_assert_float_eq(result.matrix[0][1], 22);
  ck_assert_float_eq(result.matrix[0][2], 27);
  ck_assert_float_eq(result.matrix[1][0], 22);
  ck_assert_float_eq(result.matrix[1][1], 29);
  ck_assert_float_eq(result.matrix[1][2], 36);
  ck_assert_float_eq(result.matrix[2][0], 27);
  ck_assert_float_eq(result.matrix[2][1], 36);
  ck_assert_float_eq(result.matrix[2][2], 45);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_transpose(&A, &result);
  ck_assert_float_eq(result.matrix[0][0], 1);
  ck_assert_float_eq(result.matrix[0][1], 2);
  ck_assert_float_eq(result.matrix[0][2], 3);
  ck_assert_float_eq(result.matrix[1][0], 4);
  ck_assert_float_eq(result.matrix[1][1], 5);
  ck_assert_float_eq(result.matrix[1][2], 6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  s21_calc_complements(&A, &result);
  ck_assert_float_eq(result.matrix[0][0], 0);
  ck_assert_float_eq(result.matrix[0][1], 10);
  ck_assert_float_eq(result.matrix[0][2], -20);
  ck_assert_float_eq(result.matrix[1][0], 4);
  ck_assert_float_eq(result.matrix[1][1], -14);
  ck_assert_float_eq(result.matrix[1][2], 8);
  ck_assert_float_eq(result.matrix[2][0], -8);
  ck_assert_float_eq(result.matrix[2][1], -2);
  ck_assert_float_eq(result.matrix[2][2], 4);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_determinant) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  s21_determinant(&A, &result);
  ck_assert_float_eq(result, 0);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  s21_determinant(&A, &result);
  ck_assert_float_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_inverse_matrix(&A, &result);
  ck_assert_float_eq(result.matrix[0][0], 1);
  ck_assert_float_eq(result.matrix[0][1], -1);
  ck_assert_float_eq(result.matrix[0][2], 1);
  ck_assert_float_eq(result.matrix[1][0], -38);
  ck_assert_float_eq(result.matrix[1][1], 41);
  ck_assert_float_eq(result.matrix[1][2], -34);
  ck_assert_float_eq(result.matrix[2][0], 27);
  ck_assert_float_eq(result.matrix[2][1], -29);
  ck_assert_float_eq(result.matrix[2][2], 24);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s;
  TCase *tc_create_matrix;

  s = suite_create("s21_create_matrix");
  tc_create_matrix = tcase_create("s21_create_matrix tcase");

  tcase_add_test(tc_create_matrix, test_create_matrix);
  suite_add_tcase(s, tc_create_matrix);
  tcase_set_timeout(tc_create_matrix, 100);

  return s;
}

Suite *suite_remove_matrix(void) {
  Suite *s;
  TCase *tc_remove_matrix;

  s = suite_create("s21_remove_matrix");
  tc_remove_matrix = tcase_create("s21_remove_matrix tcase");

  tcase_add_test(tc_remove_matrix, test_remove_matrix);
  suite_add_tcase(s, tc_remove_matrix);
  tcase_set_timeout(tc_remove_matrix, 100);

  return s;
}

Suite *suite_eq_matrix(void) {
  Suite *s;
  TCase *tc_eq_matrix;

  s = suite_create("s21_eq_matrix");
  tc_eq_matrix = tcase_create("s21_eq_matrix tcase");

  tcase_add_test(tc_eq_matrix, test_eq_matrix);
  suite_add_tcase(s, tc_eq_matrix);
  tcase_set_timeout(tc_eq_matrix, 100);

  return s;
}

Suite *suite_sub_matrix(void) {
  Suite *s;
  TCase *tc_sub_matrix;

  s = suite_create("s21_sub_matrix");
  tc_sub_matrix = tcase_create("s21_sub_matrix tcase");

  tcase_add_test(tc_sub_matrix, test_sub_matrix);
  suite_add_tcase(s, tc_sub_matrix);
  tcase_set_timeout(tc_sub_matrix, 100);

  return s;
}

Suite *suite_sum_matrix(void) {
  Suite *s;
  TCase *tc_sum_matrix;

  s = suite_create("s21_sum_matrix");
  tc_sum_matrix = tcase_create("s21_sum_matrix tcase");

  tcase_add_test(tc_sum_matrix, test_sum_matrix);
  suite_add_tcase(s, tc_sum_matrix);
  tcase_set_timeout(tc_sum_matrix, 100);

  return s;
}

Suite *suite_mult_number(void) {
  Suite *s;
  TCase *tc_mult_number;

  s = suite_create("s21_mult_number");
  tc_mult_number = tcase_create("s21_mult_number tcase");

  tcase_add_test(tc_mult_number, test_mult_number);
  suite_add_tcase(s, tc_mult_number);
  tcase_set_timeout(tc_mult_number, 100);

  return s;
}

Suite *suite_mult_matrix(void) {
  Suite *s;
  TCase *tc_mult_matrix;

  s = suite_create("s21_mult_matrix");
  tc_mult_matrix = tcase_create("s21_mult_matrix tcase");

  tcase_add_test(tc_mult_matrix, test_mult_matrix);
  suite_add_tcase(s, tc_mult_matrix);
  tcase_set_timeout(tc_mult_matrix, 100);

  return s;
}

Suite *suite_transpose(void) {
  Suite *s;
  TCase *tc_transpose;

  s = suite_create("s21_transpose");
  tc_transpose = tcase_create("s21_transpose tcase");

  tcase_add_test(tc_transpose, test_transpose);
  suite_add_tcase(s, tc_transpose);
  tcase_set_timeout(tc_transpose, 100);

  return s;
}

Suite *suite_calc_complements(void) {
  Suite *s;
  TCase *tc_calc_complements;

  s = suite_create("s21_calc_complements");
  tc_calc_complements = tcase_create("s21_calc_complements tcase");

  tcase_add_test(tc_calc_complements, test_calc_complements);
  suite_add_tcase(s, tc_calc_complements);
  tcase_set_timeout(tc_calc_complements, 100);

  return s;
}

Suite *suite_determinant(void) {
  Suite *s;
  TCase *tc_determinant;

  s = suite_create("s21_determinant");
  tc_determinant = tcase_create("s21_determinant tcase");

  tcase_add_test(tc_determinant, test_determinant);
  suite_add_tcase(s, tc_determinant);
  tcase_set_timeout(tc_determinant, 100);

  return s;
}

Suite *suite_inverse_matrix(void) {
  Suite *s;
  TCase *tc_inverse_matrix;

  s = suite_create("s21_inverse_matrix");
  tc_inverse_matrix = tcase_create("s21_inverse_matrix tcase");

  tcase_add_test(tc_inverse_matrix, test_inverse_matrix);
  suite_add_tcase(s, tc_inverse_matrix);
  tcase_set_timeout(tc_inverse_matrix, 100);

  return s;
}