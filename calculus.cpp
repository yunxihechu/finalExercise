#include "calculus.h"

calculus::calculus() {
    strHash['+']=1;
    strHash['-']=1;
    strHash['*']=1;
    strHash['/']=1;
    strHash['^']=1;
    strHash['(']=1;
    strHash[')']=1;
    strHash['!']=1;
}
bool calculus::matchOp(char c) {
    if(strHash[c]==1) return true;
    return false;
}

void calculus::getInfo() {
    cout << "input Exp: ";
    cin >> inputExp;
    cout << "input qujian: ";
    cin >> _lo >> _hi;
}

void calculus::translate() {
    int i = 0,j = 0;
    int count = 0;//括号匹配
    unsigned int l = inputExp.length();
    if(matchOp(inputExp[0])) abort();
    for(j = 0; j < l; j++){
        if(matchOp(inputExp[j])){
            if(inputExp[j]=='(') count++;
            if(inputExp[j]==')') count--;
            if(i!=j) infixExp.push_back(inputExp.substr(i,j-i));
            infixExp.push_back(inputExp.substr(j,1));
            i = j + 1;
        }
    }
    if(count!= 0){
        cout<<"Parenthesis does not match!"<<endl;
        abort();
    }
    if(i!= l+1 ) infixExp.push_back(inputExp.substr(i,j-i+1));
    else if(inputExp[j]!='(' && inputExp[j]!=')'){
        cout << "end with operator" << endl;
    }
    //中缀输入完毕
    //中缀转后缀
    i = 0; j = 0;
    l = infixExp.size();
    stack<string> st;
    for(i = 0; i < l; i++){
        string tmp = infixExp[i];
        if(infixExp[i].length()!=1){//非单目运算符

        }
        else{
            char ch = infixExp[i][0];
            switch (ch) {
                case '+':
                case '-':
                    while (!st.empty()) {
                        char opTop = st.top()[0];
                        if (opTop == '(') {
                            break;
                        }
                        else {
                            suffixExp.push_back(to_string(opTop));
                        }
                    }
                    st.push(to_string(ch));
                    break;
                case '*':
                case '/':
                    while (!st.empty()) {
                        char opTop = st.top()[0];
                        if (opTop == '(') {
                            break;
                        }
                        else {
                            if(opTop=='+'||opTop=='-')
                            suffixExp.push_back(to_string(opTop));
                        }
                    }
                    st.push(to_string(ch));
            }
        }
    }
    return;
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

void calculus::showinfixExp() {
    cout<<"heihei"<<endl;
    int n = infixExp.size();
    cout<<"---------------------------------------------------"<<endl;
    for(int i = 0; i < n; i++){
        cout<< i <<"\t";
    }
    cout<<endl;
    for(int i = 0; i < n; i++){
        cout << infixExp[i] <<"\t";
    }
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl;
    return;
}
