#include "s21_matrix.h"
/* Фунция для очистки матрицы, получает указатель на структуру и полностью
 * очищает выделенную память.
 */
void s21_remove_matrix(matrix_t *a) {
  for (int i = 0; i < a->rows; i++) {
    free(a->matrix[i]);
  }
  free(a->matrix);
  a->matrix = NULL;
  a->rows = 0;
  a->columns = 0;
  a = NULL;
}