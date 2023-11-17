#include "s21_matrix.h"
/* Функция для транспонирования матрицы, для того, колонны матрицы становятся
 * рядами и наоборт, функция возвращает код -> return_code = 0 - все в порядке,
 * return_code = 1 - ошибка, неправильная матрица. return_code = 2 - Ошибка
 * вычисления (несоответствующие размеры матрицы; матрица, для которой
 * вычисления не могут быть выполнены, и т.д.).
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_code = check_matrix(A);
  if (return_code == 0) {
    return_code = s21_create_matrix(A->columns, A->rows, result);
    if (return_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return return_code;
}