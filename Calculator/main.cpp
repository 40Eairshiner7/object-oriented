//
//  main.cpp
//  c++queue
//
//  Created by airshiner on 16/2/27.
//  Copyright © 2016年 airshiner. All rights reserved.
//
#include <iostream>
#include <queue>
#include <string>

#include "Print.hpp"
#include "Scan.hpp"

using namespace std;
int main() {
    
    string input;
    Scan m_scan;
    getline(cin,input);
    m_scan.ToStringQueue(input);
    
    if(m_scan.tooBig)
    {
        cout << "Error!Number not conform to the requirement.";
    }
    else
    {
        class Print pr;
        pr.printString(m_scan.ToStringQueue(input));
        cout << m_scan.tooBig;
    }
    
    return 0;
}