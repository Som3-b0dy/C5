#include "s21_matrix.h"
/* Функция для проверки матрицы, идет проверка на нули рядов и колонн, а так же
 * существует ли матрица. return_code = 0 - все в порядке, return_code = 1 -
 * ошибка, неправильная матрица.
 */
int check_matrix(matrix_t *A) {
  int return_code = 1;
  if (A && A->matrix && A->rows > 0 && A->columns > 0) return_code = 0;
  return return_code;
}