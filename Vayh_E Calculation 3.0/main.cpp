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
#include <fstream>

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
            
        }else if (argc==4) {
            
            input=*(argv+1);
            if (input=="-f") {
                ifstream in(*(argv+2), ios::in);
				ofstream out(*(argv+3), ios::out);
				if (in.is_open()) {
					while(getline(in,input)) {
						m_scan.ToStringQueue(input, 2);   
						if (out.is_open()) {
		                    if (m_scan.tooBig==true) {
		                        out << "ERROR:Number Not Conform To The Requirement." << endl;
		                    }
		                    else {
		                        m_cal.calculating(m_scan.ToStringQueue(input,2));
		                        if (m_cal.idbz==1) {
		                            out << "ERROR:Divided By Zero." << endl;
		                        }else if (m_cal.idbz==0){
		                            out << m_cal.calculating(m_scan.ToStringQueue(input,2)) << endl;
		                    }
		                  }       
                		}
					}			
				}
              	in.close();
                out.close();
            }  
        }
    }
    
    return 0;
}

