#pragma once
#include "line.h"
#include <iostream>
using namespace std;
class file {
private:
    line* head = nullptr;
    line* current = nullptr;
    friend class editor;

public:
    void goto_(int i)
    {
        current = head;
        for (int a = 1; a < i; a++) {
            current = (*current).next;
        }
    }
    void gotonextline()
    {
        if (current->next) {
            current = current->next;
        }
    }
    void read(istream& fin)
    {
        string temp;
        if (getline(fin, temp)) {
            head = new line(temp);
            current = head;

            while (getline(fin, temp)) {
                current->next = new line(temp);
                current = current->next;
            }
        }
    }
    void write() {

    }
    ~file()
    {
        line* ptr1 = head;
        while ( ptr1!= nullptr) {
            line* ptr2 = ptr1->next;
            delete ptr1;
            ptr1 = ptr2;
        }
    }
};
