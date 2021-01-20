#include <stdio.h>
/*
* matrix.c
* common operation in matrix
*/


/*
* get determinant value of a therow x thecol matrix
*/
double matrix_det(double *initArray, int therow, int thecol) {
    double result;
    double *posarr, *negarr;
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
    double *tArray;
    for(int i = 0; i<thecol;i++) {
        for(int j=0;j<therow;j++) {
            *(tArray + (j*therow)+i) = (double) ( *(initArray + (i*therow)+j));
        }
    }
    return tArray;
}
/*
*
*/
double *matrix_identity(int therow, int thecol) {
    double *idArray;
    *(idArray) = 1.0; // i tried to include this a[0][0]=1.0 into the for loop but does not work
    for (int i = 0;i<thecol;i++) {
        for(int j = 1;j<therow;j++) {
            if (i=j) {
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
* return inverse of a matrix
* follows Gauss Jordan elimination metods on calculating matrix inverse
*/
double *matrix_inverse_GJ(double *initArray, int therow, int thecol) {
    double *iArray;
    return iArray;
}

