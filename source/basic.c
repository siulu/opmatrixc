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
double matrix_det(double *initArray,int therow, int thecol);
void matrix_print(double *initArray, int therow, int thecol);
double *matrix_transpose(double *initArray, int therow, int thecol);
double *matrix_identity(int therow, int thecol);
double *matrix_gauss_jordan_elimination(double *initArray, int therow, int thecol);


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
    matrix_print((double *) &t_A[0],yy,yy);
    printf("\n\n");
    matrix_print((double *) &A[0],xx,yy);
    printf("\n\n");
    free(t_B);
    free(t_A);
    return EXIT_SUCCESS;
}

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
* gaus jordan elimination
*/
/*
double *matrix_gauss_jordan_elimination(double *initArray, int therow, int thecol) {
    double *gjArray;
    double *iArray;
    double m;

    iArray = matrix_identity(therow, thecol);
    
    for(int i=0;i<thecol;i++) {
        for(int j=0;j<therow;j++) {
            //elimination process take place except for the diagonal
            if(i != j) {
                m = - (*(initArray + (i*therow)+j)) / (*(initArray + (i*thecol)+i));
                for (int k=j;k<thecol;k++) {
                    *(initArray+(j*therow)+k) = *(initArray+(j*therow)+k) + m*(*(initArray+(i*therow)+k));
                    *(iArray+(j*therow)+k) = *(iArray+(j*therow)+k) + m*(*(iArray+(i*therow)+k));
                }
            }
        }
    }
    
    return iArray;
}
*/


