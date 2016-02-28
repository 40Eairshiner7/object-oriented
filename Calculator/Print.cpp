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

void Print::printString(queue<string> charQueue)
{
    while (!charQueue.empty()) {
        cout << charQueue.front() << endl;
        charQueue.pop();
    }
}