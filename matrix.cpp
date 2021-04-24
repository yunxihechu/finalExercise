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
            _elem[i][j] = d;
        }
    }
}

matrix::matrix(int row, int col, const double *v) {
    _row = row;
    _col = col;
    init();
    for(int i = 0; i < _row; i++){
        for(int j = 0; j < _col; j++){
            _elem[i][j] = *(v + i*_col + j);
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

int matrix::row() const {
    return _row;
}

int matrix::col() const {
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

matrix matrix::inv(const matrix &s) {
    //增广矩阵法
    if(s._col!=s._row){
        cout<<"只有方阵能求逆矩阵"<<endl;
        abort();
    }
    int n = s._col;
    int k = 0;
    double factor=0;
    matrix A = s;
    matrix B = eye(n);
    for(int i = 0; i < n; i++){//row, mainElem col
        if(A._elem[i][i]==0){
            k = A.notZero(i);
            if(k==-1){
                cout<<"Not Full Rank"<<endl;abort();
            }
            factor = 1/(A._elem[k][i]);
            A.rowAdd(i,k,factor);B.rowAdd(i,k,factor);
        }
        else if(A._elem[i][i]!=1){
            factor = A._elem[i][i];
            A.rowDivide(i,factor);B.rowDivide(i,factor);
        }
        //主元已置1
        for(int j = i + 1; j < n; j++){//row
            if(A._elem[j][i]==0) continue;
            factor = -A._elem[j][i];
            A.rowAdd(j,i,factor);B.rowAdd(j,i,factor);
        }
    }
    //现在增广矩阵A|B中, A已经变为上三角矩阵。
    for(int i = n-1; i >=0 ; i--){//col,mainElem row
        for(int j = i-1; j >=0; j--) {//row
            if(A._elem[j][i]==0) continue;
            factor = -A._elem[j][i];
            A.rowAdd(j,i,factor);B.rowAdd(j,i,factor);
        }
    }
    return B;
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

double matrix::det(const matrix &s) {
    if(s._col!=s._row){
        cout<<"非方阵!"<<endl;
        abort();
    }
    int n = s.row();
    int factorial = 1;
    for(int i = n;i > 0;i--){
        factorial = factorial * i;
    }
    int** ar = arrange(n);

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

double func_minus(double x, double y) {
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
    traverse(ans, s, func_minus);
    return ans;
}
matrix matrix::operator-(double r) const {
    matrix ans(_row, _col);
    traverse(ans, r, func_minus);
    return ans;
}
matrix &matrix::operator-=(const matrix &s) {
    traverse(s, func_minus);
    return *this;
}
matrix &matrix::operator-=(double r) {
    traverse(r, func_minus);
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

matrix &matrix::operator/=(const matrix &s) {
    *this = (*this) * inv(s);
    return *this;
}

matrix &matrix::operator/=(double r) {
    traverse(r ,divide);
    return *this;
}

matrix matrix::operator%(const matrix &s) const {
    matrix ans(_row, _col);
    traverse(ans ,s ,divide);
    return ans;
}

matrix &matrix::operator%=(const matrix &s) {
    traverse(s ,divide);
    return *this;
}

matrix matrix::operator&(const matrix &s) const {
    matrix ans(_row, _col);
    traverse(ans ,s ,multi);
    return ans;
}

matrix &matrix::operator&=(const matrix &s) {
    traverse(s ,multi);
    return *this;
}

matrix matrix::operator^(double r) const {
    matrix ans = *this;
    for (int i = 0; i < r; i++){
        ans = ans * ans;
    }
    return ans;
}

matrix &matrix::operator^=(double r) {
    matrix ans = *this;
    for (int i = 0; i < r; i++){
        ans = ans * ans;
    }
    *this = ans;
    return *this;
}

matrix matrix::operator|(double r) const {
    matrix ans(_row, _col);
    traverse(ans ,r ,pow);
    return ans;
}

matrix &matrix::operator|=(double r) {
    traverse(r ,pow);
    return *this;
}

void matrix::rowAdd(int ansRow, int opRow, double factor) {
    for(int i = 0; i < _col; i++){
        _elem[ansRow][i] += factor * _elem[opRow][i];
    }
}

void matrix::rowDivide(int ansRow, double factor){
    for(int i = 0; i < _col; i++){
        _elem[ansRow][i] /= factor;
    }
}

int matrix::notZero(int col) {
    for(int row = col + 1; row < _row; row++){
        if(_elem[row][col]!=0) return row;
    }
    return -1;
}

int** arrange(int r) {
    int n = r;
    int factorial = 1;
    for(int i = n;i > 0;i--){
        factorial = factorial * i;
    }

    int *tmp = new int[n];
    for(int i = 0; i < n; i++){
        tmp[i] = i + 1;
    }
    int** ans = new int*[factorial];
    for(int i = 0; i < factorial; i++){
        ans[i] = new int[n];
    }

    int id = 0;
    do{
        for(int i = 0; i < n ;i++){
            ans[id][i] = tmp[i];
        }
        id++;
    }while(next_permutation(tmp,tmp+n));
    return ans;
}
