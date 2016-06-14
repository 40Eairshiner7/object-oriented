#include "Scan.h"

#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

queue<string> Scan::ToStringQueue(string input,int mol) {

    tooBig=false;
    input[input.length()]='+';
    int count=0,flag=0,bracket=0;
    string item = "";
    std::queue<string> outCharQueue,calculationCharQueue;

    for (int i=0; i<input.length()-1; i++) {

        if (input[i]=='(') {
            bracket++;
        }else if (input[i]==')') {
            bracket--;
        }

    }

    if (bracket<0) {
        for (int i=0; i>bracket; i--) {
            calculationCharQueue.push("(");
        }
    }

    for (int i=0; i<input.length(); i++) {

        if ((i==0 && input[i]=='-')||(input[i-1]=='(' && input[i]=='-')) {

            outCharQueue.push("-");
            calculationCharQueue.push("0");
            calculationCharQueue.push("-");
            calculationCharQueue.push("1");
            calculationCharQueue.push("*");

        }

        else if ((input[i]=='-')&&(input[i-1]=='+' || input[i-1]=='-' ||  input[i-1]=='*' ||
                              input[i-1]=='/' ||  input[i-1]=='^')) {

            outCharQueue.push("-");
            calculationCharQueue.push("(");
            calculationCharQueue.push("0");
            calculationCharQueue.push("-");
            calculationCharQueue.push("1");
            calculationCharQueue.push("*");
            flag=1;

        }

        else if (input[i]=='+' || input[i]=='-'|| input[i]=='*' || input[i]=='/' || input[i]=='^'
            ||input[i]=='(' || input[i]==')' ) {

            if(!item.empty()){
                outCharQueue.push(item);
                calculationCharQueue.push(item);
            }
            item.clear();
            count = 0;

            if (flag==1) {
                calculationCharQueue.push(")");
                flag=0;
            }

            if (input[i]=='(' && input[i-1]>='0' && input[i-1]>='9') {
                calculationCharQueue.push("*");
            }

            item = input[i];
            outCharQueue.push(item);
            calculationCharQueue.push(item);
            item.clear();
        }

        else if ((input[i] >= 48 && input[i] <=57) || input[i] == '.' ) {

            item += input[i];
            if (input[i] != '.') {
                count++;
            }
            if (count >= 10) {
                tooBig = true;
            }

        }
    }

    if (!item.empty()) {
        outCharQueue.push(item);
        calculationCharQueue.push(item);

        if (flag==1) {
            calculationCharQueue.push(")");
            flag=0;
        }

    }

    if (bracket>0) {
        for (int i=0; i<bracket; i++) {
            calculationCharQueue.push(")");
        }
    }

    calculationCharQueue.push("|");

    if (mol==2) return calculationCharQueue;
    return outCharQueue;
}
