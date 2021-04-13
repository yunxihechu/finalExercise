#ifndef FINALWORK_MATRIX_H
#define FINALWORK_MATRIX_H
#include "pch.h"
class matrix
{
public:
    double **_elem;
    int _row;
    int _col;
    //初始化
    void init();
public:
    //构造函数
    matrix(int row, int col, double d = 0);//声明一个初始值为v的矩阵

    //析构函数
    ~matrix();//析构函数应当是虚函数，

    //可写接口
    matrix& operator=(const matrix& s);//矩阵整体复制
    matrix& operator=(double const* v);//从数组开始复制
    friend std::istream& operator>>(std::istream&, matrix&);//实现矩阵的输入

    //只读访问接口 ~ 求解相关 matrix gaussianEliminate();//高斯消元法
    int queryRow() const;//查询列数
    int queryCol() const;//查询行数
    void showMatrix() const;//矩阵显示
    double cell(int i, int j) const;//取出i行j列
    double det();//求矩阵的行列式

    //静态函数
    static matrix Solve(const matrix& A, const matrix& b);//求解线性方程组Ax=b
    static matrix inv(const matrix& s);//求矩阵的逆矩阵
    static matrix eye(int row);//制造一个单位矩阵
    static double det(const matrix& s);//求矩阵的行列式
    static matrix T(const matrix & s);//矩阵转置的实现,且不改变矩阵

    //运算

    matrix operator+(const matrix& s) const;// A = this + s, 矩阵对应元素相加
    matrix operator+(const double r) const; // A = this + r, 矩阵每个元素加上标量
    matrix& operator+=(const matrix& s);    // this += s   , 矩阵对应元素相加
    matrix& operator+=(const double r);     // this += r   , 矩阵每个元素加上标量

    matrix operator-(const matrix& s) const;// A = this - s, 矩阵对应元素相减
    matrix operator-(const double r) const; // A = this - r, 矩阵每个元素减去标量
    matrix& operator-=(const matrix& s);    // this -= s   , 矩阵对应元素相减
    matrix& operator-=(const double r);     // this -= r   , 矩阵每个元素减去标量

    matrix operator*(const matrix& s) const;// A = this * s, 矩阵乘法
    matrix operator*(const double r) const; // A = this * r, 矩阵每个元素乘以标量
    matrix& operator*=(const matrix& s);    // this *= s   , 矩阵对应元素相减
    matrix& operator*=(const double r);     // this *= r   , 矩阵每个元素减去标量

    matrix operator/(const matrix& s) const;// A = this / s, 矩阵对应元素相减
    matrix operator/(const double r) const; // A = this / r, 矩阵对应元素相减
    matrix& operator/=(const matrix& s);    // this /= s   , 矩阵对应元素相减
    matrix& operator/=(const double r);     // this /= r   , 矩阵每个元素减去标量

    matrix operator%(const matrix& s) const;// A = this % s, 矩阵对应元素相减
    matrix operator%(const double r) const; // A = this % r, 矩阵对应元素相减
    matrix& operator%=(const matrix& s);    // this %= s   , 矩阵对应元素相减
    matrix& operator%=(const double r);     // this %= r   , 矩阵对应元素相减

    matrix operator^(const double r) const; // A = this ^ s, 矩阵对应元素相减
    matrix& operator^=(const double r);     // this ^= r   , 矩阵对应元素相减

};

extern matrix* ones(int row, int col);
extern matrix* zeros(int row, int col);
#endif //FINALWORK_MATRIX_H