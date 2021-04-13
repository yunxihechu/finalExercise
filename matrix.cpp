//
// Created by 95247 on 2021-04-13.
//

#include "matrix.h"

matrix::matrix(int row, int col, double d=0) {
    _row = row;
    _col = col;
    init();
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            _elem[i][j]=d;
        }
    }
}
