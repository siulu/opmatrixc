
#include <stdio.h>
#include <stdlib.h>
#include "../source/matrix.h"

/*
* format matrix
* matrix [row][column]
*/

typedef struct {
	double deteminan;
} Summary;

double A[6][6] = {
                        {2.0,3.0,4.0,5.0,1,2.4},
                        {6.0,7.0,8.0,9.0,2.0,3.5},
                        {1.0,2.0,3.0,4.0,3.0,3.2},
                        {5.0,6.0,7.0,8.0,4.0,2.2},
                        {1.0,2.0,3.0,4.0,3.0,3.3},
                        {3.0,5.0,3.0,2.0,6.0,4.5}
                    };
double MM[3][3] = {{6.0,9.0,8},
                   {10,7,11},
                   {12,5,2}
                  };
double NN[5][5] = {
    {7,5,3,8,6},
    {13,10,9,11,12},
    {4,14,15,16,17},
    {18,19,20,21,22},
    {23,2,24,25,26}
};
int main() {
    //int sizeA = sizeof(A);
    
    int xx = sizeof(A)/sizeof(A[0]);
    int yy = sizeof(A[0])/sizeof(A[0][0]);
    
    double* t_B;
    double myresult = matrix_det((double *) &A[0], xx, yy);
    printf("determinan matrix A adalah %f\n\n\n",myresult);
    t_B = matrix_identity(xx, yy);
    matrix_print((double *) &t_B[0],xx,yy);
    printf("\n\n");
    double* t_A;
    t_A = matrix_transpose((double *) &A[0], xx, yy);
    matrix_print((double *) &t_A[0],xx,yy);
    printf("\n\n");
    matrix_print((double *) &A[0],xx,yy);
    printf("\n\n");
    
    double* t_C;
    t_C=matrix_uniform(5, 5,0.5);
    matrix_print_with_index((double *) &t_C[0],5,5);
    printf("\n\n");
    free(t_B);
    free(t_A);
    free(t_C);
    return EXIT_SUCCESS;
}
