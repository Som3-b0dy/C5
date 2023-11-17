#include "s21_matrix.h"
/* Функция для вычисления определителя. Определитель матрицы равен сумме
 * произведений элементов строки (столбца) и соответствующих алгебраических
 * дополнений. Функция возвращает код -> return_code = 0 - все в порядке,
 * return_code = 1 - ошибка, неправильная матрица. return_code = 2 - Ошибка
 * вычисления (несоответствующие размеры матрицы; матрица, для которой
 * вычисления не могут быть выполнены, и т.д.).
 */

int s21_determinant(matrix_t *A, double *result) {
  int return_code = check_matrix(A);
  if (A->columns != A->rows) return_code = 2;
  if (return_code == 0) {
    if (A->rows != 1) {
      *result = 0;
      matrix_t temp_matrix;
      for (int i = 0; i < A->columns && !return_code; i++) {
        s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix);
        double result_copy;
        matrix_minor(A, 0, i, &temp_matrix);
        return_code = s21_determinant(&temp_matrix, &result_copy);
        *result += A->matrix[0][i] * result_copy * pow(-1, i);
        s21_remove_matrix(&temp_matrix);
      }
    } else
      *result = A->matrix[0][0];
  }
  return return_code;
}