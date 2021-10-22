#include <stdio.h>
#include <stdlib.h>
/*
* matrix.c
* common operation in matrix
*/


/*
* get determinant value of a therow x thecol matrix
*/
double matrix_det(double *initArray, int therow, int thecol) {
    double result;
    //double *posarr, *negarr;
    int ro, co;
    double pos[therow], neg[therow];
    double tmp = 0.0;

    for (int i=0;i<therow;i++) {
        pos[i] = 1.0;
        neg[i] = 1.0;
    }

    if (therow != thecol) result = 0;
    else {
        result = 0;
        //positive elements
        for(int idx = 0; idx<therow; idx++ ) {
                tmp = (double) ( *(initArray + (idx*therow)+idx));
                pos[0] = pos[0] * tmp;
        }

        for (int idx = 1; idx<therow; idx++) {
            co = idx;
            tmp = 1.0;
            for(ro=0; ro<therow;ro++) {
                tmp = (double) ( *(initArray + (ro*therow)+co));
                pos[idx] = pos[idx] * tmp;
                co = co + 1;
                if (co>=therow) co = 0;
            }
        }
        //negative elements
        for (int idx = 0; idx<thecol; idx++) {
            co = idx;
            tmp = 1.0;
            for(ro=therow-1; ro>=0;ro--) {
                tmp = (double) ( *(initArray + (ro*therow)+co));
                neg[idx] = neg[idx] * tmp;
                co = co + 1;
                if (co>=thecol) co = 0;
            }
        }
        //result
        for(int i=0; i<therow;i++) {
            result = result + pos[i] - neg[i];
        }

    }
    return result;
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
/*
* special matrix, return matrix containing a certain uniform value, does not have to be square matrix
*/
double *matrix_uniform(int therow, int thecol, double uvalue) {
    double* aArray = malloc(therow*thecol*sizeof(double));
    for (int i=0;i<thecol;i++) {
        for (int j=0;j<therow;j++) {
            *(aArray+(j*therow)+i) = uvalue;
        }
    }
    return aArray;
}
/*
* matrix diagonal extracted from input matrix, return same size matrix with the input, with only diagonal element of the
* input matrix and the rest are zero
* lets call this matrix diagonal right
*/
double *matrix_diagonal_right(double *initArray, int therow, int thecol) {
    double* aArray = malloc(therow*thecol*sizeof(double));
    for(int i=0;i<thecol;i++) {
        for(int j=0;j<thecol;j++) {
            if(i==j) {
                *(aArray+(j*therow)+i) = *(initArray+(j*therow)+i);
            } else {
                *(aArray+(j*therow)+i) = 0.0;
            }
        }
    }
    return aArray;
}
/*
* print 2d matrix with index number
*/
void matrix_print_with_index(double *initArray, int therow, int thecol) {
    for (int i=0;i<therow;i++) {
        for (int j=0;j<thecol;j++) {
            printf("A[%i][%i]=%f;  ",j,i,( *(initArray + (i*therow)+j)));
        }
        printf("\n");
    }
}