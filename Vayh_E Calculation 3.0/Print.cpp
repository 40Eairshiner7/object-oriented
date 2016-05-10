//
//  Print.cpp
//  c++try
//
//  Created by airshiner on 16/2/27.
//  Copyright © 2016年 airshiner. All rights reserved.
//

#include "Print.hpp"

#include <iostream>
#include <queue>
#include <string>
#include <cmath>

void Print::printString(queue<string> charQueue,int mol) {
    
    if (mol==1) {
        while (!charQueue.empty()) {
            cout << charQueue.front() << endl;
            charQueue.pop();
        }
        cout << endl;
    }
    else if (mol==2){
        while (!charQueue.empty()) {
            cout << charQueue.front();
            charQueue.pop();
        }
        cout << " = " ;
    }
    
}
