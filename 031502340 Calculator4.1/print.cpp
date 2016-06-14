#include "Print.h"

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
