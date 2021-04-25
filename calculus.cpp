#include "calculus.h"

calculus::calculus() {
    classMap = {
            {"e",cons},
            {"pi",cons},

            {"+",binoOp},
            {"-",binoOp},
            {"*",binoOp},
            {"/",binoOp},
            {"^",binoOp},
            {"!",func},// "!"是特殊的单目运算符，可以视为函数factorial(double)

            {"x",xOp},

            {"^",func},
            {"sin",func},
            {"cos",func},
            {"tan",func},
            {"asin",func},
            {"acos",func},
            {"atan",func},
            {"atan2",func},
            {"sinh",func},
            {"cosh",func},
            {"tanh",func},
            {"log",func},
            {"log10",func},
            {"exp",func},
            {"sqrt",func},
            {"ceil",func},
            {"floor",func},
            {"fabs",func},
    };
    funcMap = {
            {"!",factorial},
            //这些其实都是单目运算
            {"sin",sin},
            {"cos",cos},
            {"tan",tan},
            {"asin",asin},
            {"acos",acos},
            {"atan",atan},
            {"sinh",sinh},
            {"cosh",cosh},
            {"tanh",tanh},
            {"log",log},
            {"log10",log10},
            {"exp",exp},
            {"sqrt",sqrt},
            {"ceil",ceil},
            {"floor",floor},
            {"fabs",fabs}
    };
    valueMap = {
            {"e",exp(1)},
            {"pi",4*atan(1)}
    };
}

void calculus::getInfo() {
    cout << "input Exp: "<<endl;
    cin >> inputExp;
    cout << "input interval: "<<endl;
    cin >> _lo >> _hi;

    int i = 0,j = 0;
    unsigned int l = inputExp.length();
    for(j = 0; j < l; j++){
        if(inputExp[j]==';'){
            suffixExp.push_back(inputExp.substr(i,j-i));
            i = j + 1;
        }
    }
    if(i != l + 1 ) suffixExp.push_back(inputExp.substr(i,j-i));
    return;
}

double calculus::integral() {
    double h = 0.000001;
    double ans = 0;
    double x = _lo;
    while (x < _hi){
        ans += h * expFunc(x);
        x += h;
    }
    return ans;
}

double calculus::expFunc(double x) {
    double numOpA,numOpB;
    stack<double> nStack;

    for(const auto& item:suffixExp){
        if(containNum(item)){
            numOpA = stod(item);
            nStack.push(numOpA);
            continue;
        }
        switch (classMap.find(item)->second) {
            case cons:
                numOpA = valueMap.find(item)->second;
                nStack.push(numOpA);
                break;
            case xOp:
                nStack.push(x);
                break;
            case binoOp:
                numOpA = nStack.top(); nStack.pop();
                numOpB = nStack.top(); nStack.pop();
                switch (item[0])
                {
                    case '+':
                        nStack.push(numOpA + numOpB);
                        break;
                    case '-':
                        nStack.push(numOpA - numOpB);
                        break;
                    case '*':
                        nStack.push(numOpA * numOpB);
                        break;
                    case '/':
                        nStack.push(numOpA / numOpB);
                        break;
                    case '^':
                        nStack.push(pow(numOpA,numOpB));
                        break;
                    default:
                        break;
                }
                break;
            case func:
                numOpA = nStack.top(); nStack.pop();
                funcPointer pf;
                pf = funcMap.find(item)->second;
                numOpB = pf(numOpA);
                nStack.push(numOpB);
                break;
            default:
                cout<<"Warning! Unexpected characters!"<<endl;
                abort();
                break;
        }
    }
    numOpA = nStack.top();nStack.pop();
    if(!nStack.empty()){
        cout<<"There is an error in the expression, the result may be wrong"<<endl;
    }
    return numOpA;
}

double factorial(double x) {
    int ans = 1;
    for(int i = 1;i <= x;i++){
        ans = ans * i;
    }
    return ans;
}

bool containNum(string str) {
    char c = str[0];
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'){
        return true;
    }
    return false;
}