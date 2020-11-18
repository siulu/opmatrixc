#include <stdio.h>
#include <stdlib.h>
#include <math.h>



double get_det(double *initArray[]) {
    double result, pos, neg;
    double *posarr, *negarr;
    int row = sizeof(initArray) / sizeof(initArray[0]);
    int column = sizeof(initArray)/row;
    int tmp = 0;
    
    if (row != column) result = 0.0;
    else {
        for(int i = 0; i<row;i++) {
            pos = 1.0;
            neg = 1.0;
            for(int j=0; j<column;j++) {
                
                pos = pos * initArray[tmp][tmp];
            }
            posarr[i] = pos;
            negarr[i] = neg;
        }
    }
    return result;
}