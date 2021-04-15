#include <iostream>
#include "matrix.h"
int main() {
    matrix a(4,3,1);
    matrix b(3,1);
    double x = 1.2;
    matrix c = a * x;
    matrix d = a / b;
    a.showMatrix();
    c.showMatrix();
    d.showMatrix();
    return 0;
}