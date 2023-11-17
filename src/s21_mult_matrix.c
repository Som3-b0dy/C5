#include "s21_matrix.h"
/* Функция для умножения матрицы на матрицу. Функция возвращает код ->
 * return_code = 0 - все в порядке, return_code = 1 - ошибка, неправильная
 * матрица. return_code = 2 - Ошибка вычисления (несоответствующие размеры
 * матрицы; матрица, для которой вычисления не могут быть выполнены, и т.д.).
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = check_matrix(A);
  if (return_code == 0) return_code = check_matrix(B);
  if (A->columns != B->rows) return_code = 2;
  if (return_code == 0) {
    return_code = s21_create_matrix(A->rows, B->columns, result);
    if (return_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return return_code;
}