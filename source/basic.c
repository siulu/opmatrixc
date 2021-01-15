#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

double A[5][5] = {
                        {2,3,4,5,1},
                        {6,7,8,9,2},
                        {1,2,3,4,3},
                        {5,6,7,8,4},
                        {1,2,3,4,3}
                    };
double get_det(double *initArray,int therow, int thecol);

int xx = sizeof(A)/sizeof(A[0]);
int yy = sizeof(A[0])/sizeof(A[0][0]);

int main() {
    double myresult = get_det((double *) &A[0], xx, yy);
    printf("Hasil saya adalah %f\n",myresult);

    return 0;
}
double get_det(double *initArray, int therow, int thecol) {
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
        for(int i=0; i<therow;i++) {
            result = result + pos[i];
        }

    }
    return result;
}
