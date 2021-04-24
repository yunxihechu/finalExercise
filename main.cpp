#include <iostream>
#include "matrix.h"
#include "calculus.h"

int main() {
    /*calculus cal;
    cal.getInfo();
    cal.translate();
    cal.showinfixExp();*/
    /*double v[25] = {1,2,1,-1,1,0,2,1,3,2,5,7,8,9,1,5,4,2,3,6,5,4,2,4,1};
    double v1[3] = {3,0,3};
    matrix A(3,3);
    A = v;
    A.showMatrix();
    cout<<"------"<<endl;
    matrix tmp = A;
    matrix B = matrix::inv(tmp);
    matrix b(3,1);
    b = v1;
    matrix x = B*b;
    cout<<"------"<<endl;
    B.showMatrix();
    cout<<"------"<<endl;
    b.showMatrix();
    cout<<"------"<<endl;
    x.showMatrix();*/
    arrange ar(5);
    ar.showAr();
    return 0;
}