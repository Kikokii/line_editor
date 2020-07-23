#include<iostream>
#include<string>
#include"line.h"
#include"file.h"
#include <fstream>
using namespace std;



int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Error" << endl;
        return 2;
    }
    fstream fin(argv[1]);
    file tobeopened;
    tobeopened.read(fin);



}
