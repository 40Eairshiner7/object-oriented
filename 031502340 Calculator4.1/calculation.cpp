#include "Calculation.h"

#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>

int Calculation::oplevel(string op) {

    idbz=0;
    int level;
    if (op[0]=='+' || op[0]=='-') {
        level=2;
    }else if (op[0]=='*' || op[0]=='/') {
        level=3;
    }else if (op[0]=='^') {
        level=4;
    }else if (op[0]==')' || op[0]=='(') {
        level=1;
    }else if (op[0]=='|') {
        level=0;
    }

    return level;
}

double Calculation::toDouble(string num) {

    stringstream s;
    double number=0;
    s << num;
    s >> number;
    return number;

}

double Calculation::solve(double num1, double num2, string op) {
    if (op[0]=='+') {
        num1=num1+num2;
    }
    if (op[0]=='-') {
        num1=num1-num2;
    }
    if (op[0]=='*') {
        num1=num1*num2;
    }
    if (op[0]=='/') {
        if (num2!=0) {
            num1=num1/num2;
        }
        else {
            idbz=1;
            return 0;
        }
    }
    if (op[0]=='^') {
        num1=pow(num1, num2);
    }

    return num1;
}

double Calculation::calculating(queue<string> q) {

    double result=0,num1,num2;
    string cur,curop;

    while (!q.empty()) {

        cur=q.front();

        if (cur[0]=='(') {
            op.push(cur);
            q.pop();
            if (q.front()[0]!='(') {
                num.push(toDouble(q.front()));
                q.pop();
            }
        }

        else {

            if (num.empty()) {
                num.push(toDouble(cur));
                q.pop();
                cur=q.front();
            }

            while (!op.empty()) {
                if (oplevel(cur)>oplevel(op.top()) || op.top()[0]=='(') break;
                num2=num.top();num.pop();
                num1=num.top();num.pop();
                curop=op.top();op.pop();
                num1=solve(num1, num2, curop);
                if (num1==0 && idbz==1) {
                    return 0;
                }
                num.push(num1);
            }

            if (cur[0]==')' && op.top()[0]=='(') {
                op.pop();
                q.pop();
            }else if (cur[0]=='|') {
                break;
            }else {
                op.push(cur);
                q.pop();
                if (q.front()[0]!='(') {
                    num.push(toDouble(q.front()));
                    q.pop();
                }
            }

        }
    }

    result=num.top();num.pop();
    return result;
}
