#include "ui.h"

void systemUI::showMenu() {
    cout<<"---------------------------------"<<endl;
    cout<<"|[^_^] Welcome!   @j3.ninja\t|"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"|[1]:Interval calculator   \t|"<<endl;
    cout<<"|[2]:Solve linear equations\t|"<<endl;
    cout<<"|[3]:Inverse of the matrix \t|"<<endl;
    cout<<"|[4]:Determinant of matrix \t|"<<endl;
    cout<<"|[5]:Matrix operate(+-*/&%)\t|"<<endl;
    cout<<"|[6]:Quit                  \t|"<<endl;
    cout<<"---------------------------------"<<endl;
}

void systemUI::run() {
    calculus cal;
    char d;
    menuShow:showMenu();
    menuINPUT:cout<<"Input:";
    cin >> d; cin.clear();
    switch (d) {
        //Interval calculator
        case '1': {
            cal.getInfo();
            cout << "interval answer is:" << cal.integral() << endl;
            goto menuShow;
        }
        //Solve linear equations
        case '2': {
            cout<<"To solve Ax=b, answer is x"<<endl;
            int n = 0;
            cout << "Enter the number of equations:";
            cin >> n;
            //使用 cin >> matrix 需要先保证matrix已经确定行和列
            matrix A(n,n);
            matrix b(n,1);
            matrix x(n,1);
            cout << "Input A, separated by spaces or line breaks:"<<endl;
            cin >> A;
            cout << "Input b:"<<endl;
            cin >> b;
            x = matrix::Solve(A,b);
            x.showMatrix();
            goto menuShow;
        }
        //Inverse of the matrix
        case '3':{
            int n = 0;
            cout << "Enter the order of the matrix:";
            cin >> n; cin.clear();
            //使用 cin >> matrix 需要先保证matrix已经确定行和列
            matrix A(n,n);
            matrix x(n,n);
            cout << "Input A, separated by spaces or line breaks:"<<endl;
            cin >> A; cin.clear();
            x = matrix::inv(A);
            x.showMatrix();
            goto menuShow;
        }
        //Determinant of matrix
        case '4':{
            /*int n = 0;
            cout << "Enter the order of the matrix:";
            cin >> n;
            //使用 cin >> matrix 需要先保证matrix已经确定行和列
            matrix A(n,n);
            double ans;
            cout << "Input matrix, separated by spaces or line breaks:"<<endl;
            cin >> A;
            ans = A.det();
            cout << "Det of matrix is:"<<ans<<endl;*/
            goto menuShow;
        }
        //Matrix operate
        case '5':{
            matrix A;
            matrix B;
            char op;
            OPInput: cout << "Choose which operation(+-*/&%):" << endl;
            cin >> op; cin.clear();
            switch (op) {
                case '+': {
                    matrix x = A + B;
                    cout << "A+B = ";
                    x.showMatrix();
                    break;
                }
                case '-': {
                    matrix x = A - B;
                    cout << "A-B = ";
                    x.showMatrix();
                    break;
                }
                case '*': {
                    matrix x = A * B;
                    cout << "A*B = ";
                    x.showMatrix();
                    break;
                }
                case '/': {
                    matrix x = A / B;
                    cout << "A/B = ";
                    x.showMatrix();
                    break;
                }
                case '&': {
                    matrix x = A & B;
                    cout << "A.*B = ";
                    x.showMatrix();
                    break;
                }
                case '%': {
                    matrix x = A % B;
                    cout << "A./B = ";
                    x.showMatrix();
                    break;
                }
                default:{
                    cout<<"The operator is wrong!"<<endl;
                    goto OPInput;
                }
            }
            goto menuShow;
        }
        case '6':{
            cout<<"Thanks for using! ^_^"<<endl;
            return;
        }
        default:{
            cout<<"Wrong order!"<<endl;
            goto menuINPUT;
        }
    }
}
