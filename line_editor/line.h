#pragma once
#include <iostream>
using namespace std;
class line {
private:
    string content;
    line* next;
    friend class file;
    friend class editor;

public:
    line()
        : next(nullptr)
    {
    }
    explicit line(const string& str)
        : content(str)
    {
    }

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

    void delete_()
    {
    }
    void paste()
    {
    }
    line* yank()
    {
        auto yankobj = new line();
        yankobj->content = content;
        return yankobj;
    }
    line* yank(int num)
    {
        auto yankobj = new line();
        yankobj->content = content;
        line* temp1 = this;
        line* temp2 = yankobj;
        for (int i = 1; i < num; i++) {
            yankobj->next = new line();
            yankobj->next->content = temp1->next->content;
            yankobj = yankobj->next;
            temp1 = temp1->next;
        }
        return temp2;
    }
};
