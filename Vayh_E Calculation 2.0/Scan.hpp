//
//  Scan.hpp
//  c++try
//
//  Created by airshiner on 16/2/27.
//  Copyright © 2016年 airshiner. All rights reserved.
//

#ifndef Scan_hpp
#define Scan_hpp

#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

class Scan {
    
private:
    string input;
    string charString;
    
public:
    bool tooBig;
    queue<string> ToStringQueue(string input,int mol);
    
};

#endif
