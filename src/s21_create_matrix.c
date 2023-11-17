#include "s21_matrix.h"
/* Функция для создания матрицы, получает указатель на структуру, заполняет
 * ряды, столбцы и выделяет память для матрицы. В случае ошибки или если не
 * выделится память для одного ряда, матрица чистится функцией очистки.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_code = 0;
  int stop = 1;
  if (rows <= 0 || columns <= 0) return_code = 1;
  if (return_code == 0) {
    double **tmp_matrix = (double **)calloc(rows, sizeof(double *));
    if (tmp_matrix != NULL) {
      for (int i = 0; i < rows && stop; i++) {
        tmp_matrix[i] = (double *)calloc(columns, sizeof(double));
        if (tmp_matrix[i] == NULL) {
          stop = 0;
          for (int j = 0; j < i; j++) free(tmp_matrix[i]);
          free(tmp_matrix);
        }
      }
    }
    if (stop) {
      result->rows = rows;
      result->columns = columns;
      result->matrix = tmp_matrix;
    }
  }
  return return_code;
}