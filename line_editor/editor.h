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
};



