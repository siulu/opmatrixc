#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

/*
* format matrix
* matrix [row][column]
*/

double A[5][5] = {
                        {2,3,4,5,1},
                        {6,7,8,9,2},
                        {1,2,3,4,3},
                        {5,6,7,8,4},
                        {1,2,3,4,3}
                    };
double matrix_det(double *initArray,int therow, int thecol);
void matrix_print(double *initArray, int therow, int thecol);
double *matrix_transpose(double *initArray, int therow, int thecol);

int xx = sizeof(A)/sizeof(A[0]);
int yy = sizeof(A[0])/sizeof(A[0][0]);

int main() {
    double *t_A;
    double myresult = matrix_det((double *) &A[0], xx, yy);
    printf("Hasil saya adalah %f\n\n\n",myresult);
    matrix_print(&A[0],xx,yy);

    printf("\n\n\n");
    t_A = matrix_transpose((double *) &A[0], xx, yy);

    matrix_print(&t_A[0],xx,yy);

    return 0;
}
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
