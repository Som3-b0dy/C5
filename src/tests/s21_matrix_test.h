#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H
#include <check.h>
Suite *suite_create_matrix(void);
Suite *suite_remove_matrix(void);
Suite *suite_eq_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_sum_matrix(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);
Suite *suite_transpose(void);
Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse_matrix(void);
#endif