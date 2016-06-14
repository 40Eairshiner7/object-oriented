#ifndef SCAN_H
#define SCAN_H

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

#endif // SCAN_H
