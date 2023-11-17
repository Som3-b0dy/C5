#include "s21_matrix.h"
/* Функция для поиска младшего элемента матрицы. Он относится к
 * определителю меньшей квадратной матрицы, полученной путем удаления
 * установленных строк и столбцов из исходной матрицы. Матрица алгебраических
 * дополнений, также известная как матрица кофакторов, представляет собой
 * матрицу, полученную путем транспонирования матрицы миноров и умножения
 * каждого элемента на знак в соответствии с его положением. Функция возвращает
 * код -> return_code = 0 - все в порядке, return_code = 1 - ошибка,
 * неправильная матрица. return_code = 2 - Ошибка вычисления (несоответствующие
 * размеры матрицы; матрица, для которой вычисления не могут быть выполнены, и
 * т.д.).
 */

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  double result_copy;
  int return_code = 0;
  matrix_t temp_matrix;
  s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix);
  return_code = check_matrix(A);
  if (A->columns != A->rows) return_code = 2;
  if (return_code == 0) {
    return_code = s21_create_matrix(A->rows, A->columns, result);
    if (return_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_minor(A, i, j, &temp_matrix);
          s21_determinant(&temp_matrix, &result_copy);
          result->matrix[i][j] = result_copy * pow(-1, i + j);
        }
      }
    }
  }
  s21_remove_matrix(&temp_matrix);
  return return_code;
}

void matrix_minor(matrix_t *A, int rows, int columns, matrix_t *temp_matrix) {
  int rows_count = 0;
  int col_count = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != rows) {
      for (int j = 0; j < A->columns; j++) {
        if (j != columns) {
          temp_matrix->matrix[rows_count][col_count] = A->matrix[i][j];
          col_count++;
        }
      }
      rows_count++;
    }
    col_count = 0;
  }
}