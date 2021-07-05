#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

/*
* format matrix
* matrix [row][column]
*/

typedef struct {
	double deteminan;
} Summary;

double A[6][6] = {
                        {2,3,4,5,1,2.4},
                        {6,7,8,9,2,3.5},
                        {1,2,3,4,3,3.2},
                        {5,6,7,8,4,2.2},
                        {1,2,3,4,3,3.3},
                        {3,5,3,2,6,4.5}
                    };
double matrix_det(double *initArray,int therow, int thecol);
void matrix_print(double *initArray, int therow, int thecol);
double *matrix_transpose(double *initArray, int therow, int thecol);
double *matrix_identity(int therow, int thecol);
double *matrix_gauss_jordan_elimination(double *initArray, int therow, int thecol);
int *array_size(double *initArray);


int main() {
    int xx = sizeof(A)/sizeof(A[0]);
    int yy = sizeof(A[0])/sizeof(A[0][0]);
    double *t_A;
    double *t_B;
    int *t_S;
    //double myresult = matrix_det((double *) &A[0], xx, yy);
    //printf("Hasil saya adalah %f\n\n\n",myresult);
    //printf("apalah : %i and %i\n\n\n",xx,yy);
    t_S=array_size((double *)A);
    matrix_print((double *) &A[0],xx,yy);
    printf("%i , %i \n\n",t_S[0],t_S[1]);

    printf("\n\n\n");
    //t_A = matrix_transpose((double *) &A[0], xx, yy);
    //t_A = matrix_identity(xx, yy);

    //matrix_print((double *) &t_A[0],xx,yy);

    //t_B = matrix_gauss_jordan_elimination((double *) &A[0], xx, yy);

    //matrix_print(&t_B[0],xx,yy);

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
int *array_size(double *initArray) {
    int *arraySize;
    //int xx = sizeof(A)/sizeof(A[0]);
    //int yy = sizeof(A[0])/sizeof(A[0][0]);
    //*arraySize=sizeof(initArray)/sizeof(initArray[0]);
    *arraySize=0;
    //*(arraySize+1)=sizeof(initArray[0])/sizeof(initArray[0][0]);
    *(arraySize+1)=0;
    return arraySize;
}
/*
* gaus jordan elimination
*/
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
/*
* return inverse of a matrix
* follows Gauss Jordan elimination metods on calculating matrix inverse
*/
double *matrix_inverse_GJ(double *initArray, int therow, int thecol) {
    double *iArray;
    return iArray;
}

