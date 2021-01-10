#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double get_det(double *initArray);

int main() {
    double A[4][4] = {
                        {2,3,4,5},
                        {6,7,8,9},
                        {1,2,3,4},
                        {5,6,7,8}
                    };
    double myresult = get_det(*A);
    printf("Hasil saya adalah %f\n",myresult);

    return 0;
}
double get_det(double *initArray) {
    double result;
    double *posarr, *negarr;
    int ro, co;
    int row = sizeof(initArray) / sizeof(initArray[0]);
    int column = sizeof(initArray)/row;
    double pos[column], neg[column];
    double tmp = 0.0;

    if (row != column) result = 0;
    else {
        result = 0;
        for(int idx = 0; idx<column; idx++ ) {
                /* pos[0] = pos[0] * initArray[idx][idx]; */
                tmp = *( *(initArray + idx) + idx);
                pos[0] = pos[0] * tmp;
        }
        for (int idx = 1; idx<column; idx++) {
            co = idx;
            for(ro=0; ro<column;ro++)
                pos[idx] = pos[idx]*initArray[ro][co];
                co = co + 1;
                if (co>=column) co = 0;
        }
        for(int i=0; i<column;i++) {
            result = result + pos[i];
        }
    }
    return result;
}
