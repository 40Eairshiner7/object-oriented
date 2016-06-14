#ifndef CALCULATION_H
#define CALCULATION_H

#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

class Calculation {

private:
    queue<string> q;
    stack<double> num;
    stack<string> op;
    int oplevel(string op);
    double toDouble(string num);
    double solve(double num1,double num2,string op);

public:
    int idbz;
    double calculating(queue<string> q);

};

#endif // CALCULATION_H
