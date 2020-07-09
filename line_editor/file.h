#pragma once
#include "line.h"
#include <iostream>
using namespace std;
class file {
private:
    line* head;
    line* current;

public:
    file(line* firstline): head ( firstline)
    {} 
    void goto_(int i)
    {
        current = head;
        for (int a = 1; a < i; a++) {
            current = (*current).next;
        }
    }
};
