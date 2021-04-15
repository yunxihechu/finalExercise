//
// Created by 95247 on 2021-04-13.
//

#include "matrix.h"

void matrix::init() {
    _elem = new double*[_row];
    for (int i = 0; i < _row; i++){
        _elem[i] = new double[_col];
    }
}

void matrix::remove() {
    for (int i = 0; i < _row; ++i) {
        delete[] _elem[i];
    }
    delete[] _elem;
}

matrix::matrix(int row, int col, double d) {
    _row = row;
    _col = col;
    init();
    for(int i = 0; i < _row; i++){
        for(int j = 0; j < _col; j++){
            _elem[i][j] = 0;
        }
    }
}

matrix::~matrix() {
    remove();
}

void matrix::traverse(const matrix &s, double (*func)(double, double)) {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            _elem[i][j] = func(_elem[i][j], s._elem[i][j]);
        }
    }
}
void matrix::traverse(double r, double (*func)(double, double)) {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            _elem[i][j] = func(_elem[i][j], r);
        }
    }
}

void matrix::traverse(matrix &ans, const matrix &s, double (*func)(double, double)) const{
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            ans._elem[i][j] = func(_elem[i][j], s._elem[i][j]);
        }
    }
}

void matrix::traverse(matrix &ans, double r, double (*func)(double, double)) const{
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            ans._elem[i][j] = func(_elem[i][j], r);
        }
    }
}
matrix& matrix::operator=(const matrix &s) {
    if(this == &s){
        return *this;
    }
    if (_row != s._row || _col != s._col) {
        remove();
        _row = s._row;
        _col = s._col;
        init();
    }
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            _elem[i][j] = s._elem[i][j];
        }
    }
    return *this;
}

matrix &matrix::operator=(const double *v) {
    for(int i = 0; i < _row; i++){
        for(int j = 0; j < _col; j++){
            _elem[i][j] = *(v + i*_col + j);
        }
    }
    return *this;
}

std::istream &operator>>(std::istream& is, matrix& s) {
    for (int i = 0; i < s._row; i++) {
        for (int j = 0; j < s._col; j++) {
            is >> s._elem[i][j];
        }
    }
    return is;
}

int matrix::queryRow() const {
    return _row;
}

int matrix::queryCol() const {
    return _col;
}

void matrix::showMatrix() const {
    for(int i = 0; i < _row; i++){
        for(int j = 0; j < _col; j++){
            std::cout << _elem[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double matrix::cell(int i, int j) const {
    return _elem[i][j];
}

matrix matrix::Solve(const matrix &A, const matrix &b) {
    return inv(A)*b;
}

matrix matrix::inv(const matrix &s) {//TODO
    return matrix(0, 0);
}

matrix matrix::eye(int row) {
    matrix ans(row,row);
    for (int i = 0; i < ans._row; i++) {
        for (int j = 0; j < ans._col; j++) {
            ans._elem[i][j] = (i==j)?1:0;
        }
    }
    return ans;
}

double matrix::det(const matrix &s) {//TODO
    return 0;
}

matrix matrix::T(const matrix &s) {
    matrix ans(s._col, s._row);
    for(int i = 0; i < s._row; i++){
        for(int j = 0; j < s._col; j++){
            ans._elem[j][i] = s._elem[i][j];
        }
    }
    return ans;
}

double add(double x, double y) {
    return (x+y);
}

double minus(double x, double y) {
    return (x-y);
}

double multi(double x, double y) {
    return (x*y);
}

double divide(double x, double y) {
    if(y==0) return NAN;
    return (x/y);
}

matrix matrix::operator+(const matrix &s) const{
    matrix ans(_row, _col);
    traverse(ans ,s ,add);
    return ans;
}
matrix matrix::operator+(double r) const {
    matrix ans(_row, _col);
    traverse(ans ,r ,add);
    return ans;
}
matrix &matrix::operator+=(const matrix &s) {
    traverse(s ,add);
    return *this;
}
matrix &matrix::operator+=(double r) {
    traverse(r ,add);
    return *this;
}

matrix matrix::operator-(const matrix &s) const {
    matrix ans(_row, _col);
    traverse(ans ,s ,minus);
    return ans;
}
matrix matrix::operator-(double r) const {
    matrix ans(_row, _col);
    traverse(ans ,r ,minus);
    return ans;
}
matrix &matrix::operator-=(const matrix &s) {
    traverse(s ,minus);
    return *this;
}
matrix &matrix::operator-=(double r) {
    traverse(r ,minus);
    return *this;
}

matrix matrix::operator*(const matrix &s) const {
    //因为是 this * s ,需要this的列==s的行
    if(_col != s._row) {
        abort();
    }
    matrix ans(_row, s._col, 0.0);
    for(int i = 0; i < _row; i++){
        for(int j = 0;j < s._col; j++){
            for(int k = 0; k < _col; k++){
                ans._elem[i][j] += (_elem[i][k] * s._elem[k][j]);
            }
        }
    }
    return ans;
}
matrix matrix::operator*(double r) const {
    matrix ans(_row, _col);
    traverse(ans ,r ,multi);
    return ans;
}
matrix &matrix::operator*=(const matrix &s) {
    //因为是 this * s ,需要this的列==s的行
    if(_col != s._row) {
        abort();
    }
    matrix ans(_row, s._col, 0.0);
    for(int i = 0; i < _row; i++){
        for(int j = 0;j < s._col; j++){
            for(int k = 0; k < _col; k++){
                ans._elem[i][j] += (_elem[i][k] * s._elem[k][j]);
            }
        }
    }
    *this = ans;
    return *this;
}
matrix &matrix::operator*=(double r) {
    traverse(r ,multi);
    return *this;
}

matrix matrix::operator/(const matrix &s) const {
    return (*this) * inv(s);
}

matrix matrix::operator/(double r) const {
    matrix ans(_row, _col);
    traverse(ans ,r ,divide);
    return ans;
}

matrix &matrix::operator/=(const matrix &s) {//TODO
    return *this;
}
