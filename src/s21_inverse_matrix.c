#include "s21_matrix.h"
/* Матрица A в степени -1 называется обратной квадратной матрице A, если
 * произведение этих матриц равно единичной матрице. Функция возвращает код ->
 * return_code = 0 - все в порядке, return_code = 1 - ошибка, неправильная
 * матрица. return_code = 2 - Ошибка вычисления (несоответствующие размеры
 * матрицы; матрица, для которой вычисления не могут быть выполнены, и т.д.).
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_code = check_matrix(A);
  if (A->columns != A->rows) return_code = 2;
  if (return_code == 0) {
    double temp;
    return_code = s21_determinant(A, &temp);
    if (return_code == 0) {
      if (temp != 0) {
        matrix_t complements;
        return_code = s21_calc_complements(A, &complements);
        if (return_code == 0) {
          matrix_t trans_matrix;
          return_code = s21_transpose(&complements, &trans_matrix);
          s21_remove_matrix(&complements);
          if (return_code == 0) {
            return_code = s21_mult_number(&trans_matrix, 1 / temp, result);
            s21_remove_matrix(&trans_matrix);
          }
        }
      } else
        return_code = 2;
    }
  }
  return return_code;
}
