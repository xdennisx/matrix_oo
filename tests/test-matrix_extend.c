#include "matrix_extend.h"
#include <stdio.h>

MatrixAlgo *matrix_providers[] = {
    &MatrixProvider,
};
int main()
{
    MatrixAlgo *algo = matrix_providers[0];

    Matrix dst, m, n, fixed;
    m.col=n.row = 3;
    m.row=n.col = 4;
    fixed.col=fixed.row=4;
    m.priv=getmatrix(4,3);
    n.priv=getmatrix(3,4);
    fixed.priv=getmatrix(4,4);
    float mData[]= {1,2,3,4,5,6,7,8,9,10,11,12};
    float nData[]= {1,2,3,4,5,6,7,8,9,10,11,12};
    float fixData[]= {38,44,50,56,83,98,113,128,128,152,176,200,173,206,239,272};
    algo->assign(&m, mData,4,3);
    algo->assign(&n, nData,3,4);
    algo->assign(&fixed, fixData,4,4);

    algo->mul(&dst, &m, &n);


    if (algo->equal(&dst, &fixed))
        return 0;
    return -1;
}
