#pragma once
#include "file.h"
#include "line.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
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
        const std::regex base_regex("([1-9][0-9]*)|([adpyqw])([1-9][0-9]*)?");
        std::smatch base_match;
        std::string command;
        line* savedlines = nullptr;
        for (;;) {
            cout << ":";
            getline(cin, command);
            if (std::regex_match(command, base_match, base_regex)) {
                if (base_match[1].matched) {
                    print_exact_line(stoi(base_match[1].str()));
                    cout << endl;
                }
                if (base_match[2].matched) {
                    switch (base_match[2].str()[0]) {
                    case 'a':
                        tobeopened.current->append();
                        break;
                    case 'd':
                        tobeopened.current->delete_();
                        break;
                    case 'p':
                        tobeopened.current->paste();
                        break;
                    case 'y':
                        if (base_match[3].matched)
                           savedlines= tobeopened.current->yank(stoi(base_match[3].str()));
                        else {
                           savedlines= tobeopened.current->yank();
                        }
                        break;
                    case 'q':
                        return;
                    case 'w':
                        tobeopened.write();
                        break;
                    }


                }
            } else if (command.empty()) {
                tobeopened.gotonextline();
                cout << tobeopened.current->content << endl;
            } else {
                cout << "Error" << endl;
            }
        }
    }
};
