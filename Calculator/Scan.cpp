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
    //计算数字位数的字符串
    int count=0;
    //用于组合数字或符号的字符串  
    string item = "";
    std::queue<string> charQueue;
    
    for (int i=0; i<input.length(); i++)
    {
        
        //是符号则先将组合好的数字压入队列然后才压入符号     
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
        
        //组合数字的过程里计算位数，注意：小数点不要计入位数中！
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
    
    //如果最后一个字符是数字则要记住将其压入
    if(!item.empty())
    {
        charQueue.push(item);
    }
    
    return charQueue;
}
