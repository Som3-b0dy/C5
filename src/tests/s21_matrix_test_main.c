#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix_test.h"

int main(void) {
  int failed = 0;
  int num_of_tests = 0;
  Suite *s_1, *s_2, *s_3, *s_4, *s_5, *s_6, *s_7, *s_8, *s_9, *s_10, *s_11;
  SRunner *runner_1, *runner_2, *runner_3, *runner_4, *runner_5, *runner_6,
      *runner_7, *runner_8, *runner_9, *runner_10, *runner_11;

  s_1 = suite_create_matrix();
  s_2 = suite_remove_matrix();
  s_3 = suite_eq_matrix();
  s_4 = suite_sub_matrix();
  s_5 = suite_sum_matrix();
  s_6 = suite_mult_number();
  s_7 = suite_mult_matrix();
  s_8 = suite_transpose();
  s_9 = suite_calc_complements();
  s_10 = suite_determinant();
  s_11 = suite_inverse_matrix();

  runner_1 = srunner_create(s_1);
  srunner_set_fork_status(runner_1, CK_NOFORK);
  printf("\033[1;32mRUNNING CREATE_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_1, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_1);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_2 = srunner_create(s_2);
  srunner_set_fork_status(runner_2, CK_NOFORK);
  printf("\033[1;32mRUNNING REMOVE_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_2, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_2);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_3 = srunner_create(s_3);
  srunner_set_fork_status(runner_3, CK_NOFORK);
  printf("\033[1;32mRUNNING EQ_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_3, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_3);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_4 = srunner_create(s_4);
  srunner_set_fork_status(runner_4, CK_NOFORK);
  printf("\033[1;32mRUNNING SUB_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_4, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_4);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_5 = srunner_create(s_5);
  srunner_set_fork_status(runner_5, CK_NOFORK);
  printf("\033[1;32mRUNNING SUM_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_5, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_5);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_6 = srunner_create(s_6);
  srunner_set_fork_status(runner_6, CK_NOFORK);
  printf("\033[1;32mRUNNING MULT_NUMBER TESTS\033[1;0m\n");
  srunner_run_all(runner_6, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_6);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_7 = srunner_create(s_7);
  srunner_set_fork_status(runner_7, CK_NOFORK);
  printf("\033[1;32mRUNNING MULT_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_7, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_7);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_8 = srunner_create(s_8);
  srunner_set_fork_status(runner_8, CK_NOFORK);
  printf("\033[1;32mRUNNING TRANSPOSE TESTS\033[1;0m\n");
  srunner_run_all(runner_8, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_8);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_9 = srunner_create(s_9);
  srunner_set_fork_status(runner_9, CK_NOFORK);
  printf("\033[1;32mRUNNING CALC_COMPLEMENTS TESTS\033[1;0m\n");
  srunner_run_all(runner_9, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_9);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_10 = srunner_create(s_10);
  srunner_set_fork_status(runner_10, CK_NOFORK);
  printf("\033[1;32mRUNNING DETERMINANT TESTS\033[1;0m\n");
  srunner_run_all(runner_10, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_10);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);
  printf("\n");

  runner_11 = srunner_create(s_11);
  srunner_set_fork_status(runner_11, CK_NOFORK);
  printf("\033[1;32mRUNNING INVERSE_MATRIX TESTS\033[1;0m\n");
  srunner_run_all(runner_11, CK_VERBOSE);
  num_of_tests += srunner_ntests_run(runner_11);
  printf("\033[1;33m[+] Total number of tests run -> %d\033[1;0m\n",
         num_of_tests);

  failed = srunner_ntests_failed(runner_1) + srunner_ntests_failed(runner_2) +
           srunner_ntests_failed(runner_3) + srunner_ntests_failed(runner_4) +
           srunner_ntests_failed(runner_5) + srunner_ntests_failed(runner_6) +
           srunner_ntests_failed(runner_7) + srunner_ntests_failed(runner_8) +
           srunner_ntests_failed(runner_9) + srunner_ntests_failed(runner_10) +
           srunner_ntests_failed(runner_11);

  srunner_free(runner_1);
  srunner_free(runner_2);
  srunner_free(runner_3);
  srunner_free(runner_4);
  srunner_free(runner_5);
  srunner_free(runner_6);
  srunner_free(runner_7);
  srunner_free(runner_8);
  srunner_free(runner_9);
  srunner_free(runner_10);
  srunner_free(runner_11);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}