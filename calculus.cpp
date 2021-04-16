#include "calculus.h"

void calculus::getInfo() {
    cout << "请输入表达式: ";
    cin >> inputExp;
    cout << "请输入积分区间: ";
    cin >> _lo >> _hi;
}

void calculus::translate() {

}

double calculus::intergral() {
    double h = 0.00001;
    double ans = 0;
    double x = _lo;
    while (x < _hi){
        //TODO
    }
    return ans;
}

double calculus::intergral(double lo, double hi, double (*func)(double )) {
    double h = 0.00001;
    double ans = 0;
    double x = lo;
    while (x < hi){
        ans += h*func(x);
        x += h;
    }
    return ans;
}

double calculus::interByString(double lo, double hi, string s) {
    //
    return 0;
}
