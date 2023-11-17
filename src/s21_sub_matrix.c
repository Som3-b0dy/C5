#include "s21_matrix.h"
/* Функция для вычитания матриц, для того, чтобы операция была успешна, матрицы
 * должны быть одного размера, функция возвращает код -> return_code = 0 - все в
 * порядке, return_code = 1 - ошибка, неправильная матрица. return_code = 2 -
 * Ошибка вычисления (несоответствующие размеры матрицы; матрица, для которой
 * вычисления не могут быть выполнены, и т.д.).
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = check_matrix(A);
  if (return_code == 0) check_matrix(B);
  if (A->rows != B->rows || A->columns != B->columns) return_code = 2;
  if (return_code == 0) {
    return_code = s21_create_matrix(A->rows, A->columns, result);
    if (return_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return return_code;
}