//
//  Calculation.hpp
//  Calculator
//
//  Created by airshiner on 4/9/16.
//  Copyright © 2016 airshiner. All rights reserved.
//

#ifndef Calculation_hpp
#define Calculation_hpp

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
    
public:
    int idbz;
    int oplevel(string op);
    int check(string cur);
    double toDouble(string num);
    double calculating(queue<string> q);
    double solve(double num1,double num2,string op);
    
};

#endif
