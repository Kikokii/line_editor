#pragma once
#include "line.h"
#include "file.h"
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
class editor {
private:
    file tobeopened;

public:
    void loaddata(string filename)    
    {
        fstream fin(filename);
        tobeopened.read(fin);
    }
    void print_exact_line(int num)
    {
        tobeopened.goto_(num);
        cout << tobeopened.current->content;
        
    }
    void main_loop()
    {
        for (;;) {
            int num;
            cout << ":";
            cin >> num;
            print_exact_line(num);
            cout << endl;
        }

    }
};



