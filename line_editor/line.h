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

   
    void paste(line *savedlines)
    {
        if (savedlines==nullptr)
            return;
        auto copy = new line();
        line* firstone = copy;
        copy->content = savedlines->content;
        for (; savedlines->next;) {
            copy->next = new line();
            copy->next->content = savedlines->next->content;
            copy=copy->next;
            savedlines = savedlines->next;
        }
        line* lastone = firstone;
        for (;lastone->next;) {
            lastone = lastone->next;
        }
        lastone->next = this->next;
        this->next = firstone;

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
