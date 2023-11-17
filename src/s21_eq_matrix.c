#include "s21_matrix.h"
/* Функция для сравнения матриц. Использует функцию для проверки каждой матрицы
 * на корректность. Затем в случае, если матрицы верны, идет проверка каждого
 * значения одной матрицы с другой, в случае отличий, цикл прерывается.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_code = 1 - check_matrix(A);
  if (return_code == SUCCESS) return_code = 1 - check_matrix(B);
  if (return_code == SUCCESS) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows && return_code; i++) {
        for (int j = 0; j < A->columns && return_code; j++) {
          if (round(A->matrix[i][j] * 10000000) !=
              round(B->matrix[i][j] * 10000000)) {
            return_code = FAILURE;
          }
        }
      }
    } else
      return_code = 2;
  }
  return return_code;
}