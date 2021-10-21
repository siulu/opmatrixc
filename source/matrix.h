/*
* file heder for libmatrix.a
*/
double matrix_det(double *initArray,int therow, int thecol);
void matrix_print(double *initArray, int therow, int thecol);
double *matrix_transpose(double *initArray, int therow, int thecol);
double *matrix_identity(int therow, int thecol);
double *matrix_gauss_jordan_elimination(double *initArray, int therow, int thecol);
double *matrix_inverse(double *initArray, int therow, int thecol);
double *matrix_minor(double *initArray, int therow, int thecol, int mi, int mj);
