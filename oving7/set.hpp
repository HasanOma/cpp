#include <vector>
#include <string>
#pragma once


class Set{
private:
    std::vector<int> set;
public:
    Set();

    Set(std::vector<int> set);
    bool exists(int nr);
    void operator=(Set &different) ;
    Set operator+(Set &different) ;
    void operator+(int i);
    int& operator[](int);
    int& operator[](size_t);
    size_t size() ;
    std::string print() ;
};