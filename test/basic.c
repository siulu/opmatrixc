#include <stdio.h>
#include <stdlib.h>

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
double matrix_det(double *initArray,int therow, int thecol);
void matrix_print(double *initArray, int therow, int thecol);
double *matrix_transpose(double *initArray, int therow, int thecol);
double *matrix_identity(int therow, int thecol);
double *matrix_gauss_jordan_elimination(double *initArray, int therow, int thecol);
double *matrix_inverse(double *initArray, int therow, int thecol);
double *matrix_minor(double *initArray, int therow, int thecol, int mi, int mj);


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
    t_C=matrix_minor((double *) &NN[0], 5, 5,0,2);
    matrix_print((double *) &t_C[0],4,4);
    printf("\n\n");
    free(t_B);
    free(t_A);
    free(t_C);
    return EXIT_SUCCESS;
}

/*
* get determinant value of a therow x thecol matrix
*/
double matrix_det(double *initArray, int therow, int thecol) {
    if (thecol == 1) {
        return initArray[therow];
    }

    double det = 0.0;
    double *submatrix = (double *)malloc((thecol - 1) * (thecol - 1) * sizeof(double));

    for (int i = 0; i < thecol; i++) {
        int minor_row = 0, minor_col = 0;
        for (int j = 0; j < thecol; j++) {
            if (j != therow) {
                for (int k = 0; k < thecol; k++) {
                    if (k != i) {
                        submatrix[minor_row * (thecol - 1) + minor_col] = matrix[j * thecol + k];
                        minor_col++;
                    }
                }
                minor_row++;
                minor_col = 0;
            }
        }

        det += initArray[therow * thecol + i] * pow(-1, therow + i) * determinant(submatrix, col - 1, minor_row, minor_col);
    }

    free(submatrix);

    return det;
}
/*
* print 2d matrix
*/
void matrix_print(double *initArray, int therow, int thecol) {
    for (int i=0;i<therow;i++) {
        for (int j=0;j<thecol;j++) {
            printf("%f\t", ( *(initArray + (i*therow)+j)));
        }
        printf("\n");
    }
}
/*
* return transpose of a 2d matrix
*/

double *matrix_transpose(double *initArray, int therow, int thecol ) {
    double* tArray = malloc(therow*thecol*sizeof(double));
    for(int i = 0; i<thecol;i++) {
        for(int j=0;j<therow;j++) {
            *(tArray + (j*therow)+i) = (double) ( *(initArray + (i*therow)+j));
        }
    }
    return tArray;
}
/*
* return matrix identity
*/
double *matrix_identity(int therow, int thecol) {
    double* idArray = (double *)malloc(therow*thecol*sizeof(double));
    for (int i = 0;i<thecol;i++) {
        for(int j = 0;j<therow;j++) {
            if (i==j) {
                *(idArray + (i*therow)+j) = 1.0;
            }
            else {
                *(idArray + (i*therow)+j) = 0.0;
            }
        }
    }
    return idArray;
}
/*
* The inverse of a matrix A is a matrix that, when multiplied by A results in the identity
* this matrix inverse below applied gauss jordan elimination
*/
double *matrix_inverse(double *initArray, int therow, int thecol) {
    double* aArray = malloc(therow*thecol*sizeof(double));
    aArray = initArray;
    
    double m,a1,a2,b1,b2;
    //bArray init with matrix identity.
    double* bArray;
    bArray = matrix_identity(therow, thecol);
    for(int i = 0; i<thecol;i++) {
        for(int j = 0; j<therow;j++) {
            /*elimination except for the diagonal elements*/
            if(i!=j) {
                m = *(aArray + (j*therow)+i) / (*(aArray + (i*therow)+i));
                for(int k = 0;k<thecol;k++) {
                    a1 = *(aArray + (j*therow)+k); 
                    a2 = *(aArray + (i*therow)+k);
                    b1 = *(bArray + (j*therow)+k);
                    b2 = *(bArray + (i*therow)+k);
                    *(aArray + (j*therow)+k)= a1 - m*a2;
                    *(bArray + (j*therow)+k)= b1 - m*b2;

                }
            }
        }
    }
    /*finishing*/
    for(int j=0;j<therow;j++) {
        for(int k=0;k<thecol;k++){
            b1 = *(bArray + (j*therow)+k);
            a1 = *(aArray + (j*therow)+j);
            *(bArray + (j*therow)+k) = b1 / a1;
        }
        *(aArray + (j*therow)+j) = 1.0;
    }
    return bArray;
}
/*
* Minor element of a matrix
* return matrix minor of matrix A against index matrix A[mi][mj]
* will return new matrix M[therow-1][thecol-1]
*/
double *matrix_minor(double *initArray, int therow, int thecol, int mi, int mj) {
    int m,n,mfix,nfix;
    mfix = therow-1; nfix=thecol-1;
    double* mArray = (double *)malloc((mfix)*(nfix)*sizeof(double));
    m=0;n=0;
    for(int i=0;i<thecol;i++) {
        for(int j=0;j<therow;j++) {
            if(j!=mi && i!=mj) {
                *(mArray + (m*mfix)+n) = *(initArray + (j*therow)+i);
                m+=1;
                if(m==nfix) {
                    m=0;
                    n+=1;
                }
            }
        }
    }
    return mArray;
}

