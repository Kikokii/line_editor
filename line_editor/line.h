#pragma once
#include <iostream>
using namespace std;
class line {
private:
    string content;
    line* next;
    friend class file;

public:
    line()
        : next(nullptr)
    {
    }

    line(string, line*);
    void append()
    {
        line* saved = next;
        auto temp = this;
        for (;;) {
            auto ptrappendline = new line();
            getline(cin, (*ptrappendline).content);
            if ((*ptrappendline).content != ".") {
                (*temp).next = ptrappendline;
                temp = ptrappendline;
            } else {
                delete ptrappendline;
                break;
            }
        }
        (*temp).next = saved;
    }
    void delete_();
    void paste();
};