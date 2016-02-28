//
//  Scan.cpp
//  c++try
//
//  Created by airshiner on 16/2/27.
//  Copyright © 2016年 airshiner. All rights reserved.
//

#include "Scan.hpp"

#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string> Scan::ToStringQueue(string input){
    
    tooBig = false;
    int count=0;
    string item = "";
    std::queue<string> charQueue;
    
    for (int i=0; i<input.length(); i++)
    {
        
        if(input[i]=='+' || input[i]=='-'|| input[i]=='*' || input[i]=='/' || input[i]=='(' || input[i]==')' )
        {
            if(!item.empty()){
                charQueue.push(item);
            }
            item.clear();
            count = 0;
            
            item = input[i];
            charQueue.push(item);
            item.clear();
        }
        
        else if((input[i] >= 48 && input[i] <=57) || input[i] == '.' )
        {
            item += input[i];
            if(input[i] != '.'){
                count++;
            }
            if (count >= 10) {
                tooBig = true;
            }
            
        }
    }
    
    if(!item.empty())
    {
        charQueue.push(item);
    }
    
    return charQueue;
}