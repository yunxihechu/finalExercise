#ifndef FINALEXERCISE_CALCULUS_H
#define FINALEXERCISE_CALCULUS_H
#include "pch.h"

//基本函数
/* given by math.h
 * double sin(double);正弦
 * double cos(double);余弦
 * double tan(double);正切
 * double asin (double); 结果介于[-PI/2,PI/2]
 * double acos (double); 结果介于[0,PI]
 * double atan (double); 反正切（主值），结果介于[-PI/2,PI/2]
 * double sinh (double);双曲三角函数
 * double cosh (double);
 * double tanh (double);
 * double log (double); 以e为底的对数
 * double log10 (double);以10为底的对数
 * double exp (double);求取自然数e的幂
 * double sqrt (double);开平方
 * double ceil (double); 取上整，返回不比x小的最小整数
 * double floor (double); 取下整，返回不比x大的最大整数，即高斯函数[x]
 * double fabs (double);求实型的绝对值
 *
 * double pow(double x,double y);计算x的y次幂不支持，使用 ^ 实现
 * */

enum token{
    cons,
    xOp,
    binoOp,
    func
};

using funcPointer=double(*)(double );//pf是该函数指针类型的一个别名
class calculus{
public:
    int _lo = 0, _hi = 0;
    map<string,token> classMap;
    map<string,funcPointer> funcMap;
    map<string,double> valueMap;
    string inputExp;//用户输入的函数表达式,要求后缀表达式
    vector<string> suffixExp;//计算时方便用的
public:
    calculus();
    void getInfo();//输入
    double expFunc(double x);
    double integral();

};
extern double factorial(double );
extern bool containNum(string);
#endif //FINALEXERCISE_CALCULUS_H