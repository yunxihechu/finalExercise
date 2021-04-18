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
 * double atan2 (double,double); 反正切（整圆值），结果介于[-PI,PI]
 * double sinh (double);双曲三角函数
 * double cosh (double);
 * double tanh (double);
 * double log (double); 以e为底的对数
 * double log10 (double);以10为底的对数
 * double pow(double x,double y);计算x的y次幂
 * double exp (double);求取自然数e的幂
 * double sqrt (double);开平方
 * double ceil (double); 取上整，返回不比x小的最小整数
 * double floor (double); 取下整，返回不比x大的最大整数，即高斯函数[x]
 * double fabs (double);求实型的绝对值
 * */

class calculus{
public:
    int _lo = 0, _hi = 0;
    string inputExp;//用户输入的函数表达式
    char strHash[256]={0};
    /*string op[25]={"+","-","*","/","^","!","sin","cos","tan","asin","acos","atan","atan2","sinh","cosh","tanh","log","log10","pow",
                    "exp","sqrt","ceil","floor","fabs"};*/
    //vector<string> infixExp;//先翻译成中缀表达式...直接要求输入后缀表达式吧
    vector<string> suffixExp;//再翻译成后缀表达式，也即"function"
public:
    calculus();
    void showinfixExp();
    bool matchOp(char c);
    void getInfo();//输入
    void translate();//翻译
    double intergral();

    //计算接口
    static double intergral(double lo,double hi,double (*func)(double ));
    static double interByString(double lo, double hi, string s);

};
#endif //FINALEXERCISE_CALCULUS_H