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
    
    //从队列头输出字符串，然后取出已完成输出的字符串，直到结束
    while (!charQueue.empty()) {
        cout << charQueue.front() << endl;
        charQueue.pop();
    }
    
}
