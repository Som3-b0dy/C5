#include "s21_matrix.h"
/* Функция для умножения матрицы на число. Функция возвращает код -> return_code
 * = 0 - все в порядке, return_code = 1 - ошибка, неправильная матрица.
 * return_code = 2 - Ошибка вычисления (несоответствующие размеры матрицы;
 * матрица, для которой вычисления не могут быть выполнены, и т.д.).
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_code = check_matrix(A);
  if (return_code == 0) {
    return_code = s21_create_matrix(A->rows, A->columns, result);
    if (return_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return return_code;
}