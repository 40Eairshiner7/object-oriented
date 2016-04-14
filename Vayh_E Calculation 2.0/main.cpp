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
#include <cmath>

#include "Print.hpp"
#include "Calculation.hpp"
#include "Scan.hpp"

using namespace std;
int main(int argc,char *argv[]) {
    
    string input;
    Scan m_scan;
    Print m_pr;
    Calculation m_cal;
//    getline(cin,input);
    
    if (argc>1) {
    
        if (argc==2) {
            
            input=*(argv+1);
            m_scan.ToStringQueue(input, 2);
            if (m_scan.tooBig==true) {
                cout << "ERROR:Number Not Conform To The Requirement." << endl;
            }
            else {
                m_cal.calculating(m_scan.ToStringQueue(input,2));
                if (m_cal.idbz==1) {
                    cout << "ERROR:Divided By Zero." << endl;
                }else if (m_cal.idbz==0){
                    cout << m_cal.calculating(m_scan.ToStringQueue(input,2)) << endl;
                }
            }
    
        }else if (argc==3) {
            
            input=*(argv+1);
            if (input=="-a") {
            	input=*(argv+2);

                m_pr.printString(m_scan.ToStringQueue(input,1),2);
            }
            
            input=*(argv+2);
            m_scan.ToStringQueue(input, 2);
            if (m_scan.tooBig==true) {
                cout << "ERROR:Number Not Conform To The Requirement." << endl;
            }
            else {
                m_cal.calculating(m_scan.ToStringQueue(input,2));
                if (m_cal.idbz==1) {
                    cout << "ERROR:Divided By Zero." << endl;
                }else if (m_cal.idbz==0){
                    cout << m_cal.calculating(m_scan.ToStringQueue(input,2)) << endl;
                }
            }
            
       }
    }
    
    return 0;
}
//数字太大报错
//除以零报错
//9(2+3)在括号前填充乘号
//2*-3负数不需要括号
//左右括号数不一样多，自动补充括号
