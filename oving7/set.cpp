#include "set.hpp"
#include <vector>
#include <algorithm>
#include <string>


Set::Set(){
    this->set = std::vector<int>();
}

Set::Set(std::vector<int> set){
    for (size_t i = 0; i< set.size(); i++){
        this->operator+(set[i]);
    }
}

bool Set::exists(int nr){
    bool exist = false;
    for (int i = 0; i<this->size(); i++){
        if(this->set.at(i) == nr){
            exist = true;
            break;
        }
    }
    return exist;
}

size_t Set::size() {
    return this->set.size();
}

int& Set::operator[](int i)  {
    return this->set[i];
}

int& Set::operator[](size_t i)  {
    return this->set[i];
}

void Set::operator+(int i) {
    if (!this->exists(i)) {
        this->set.emplace_back(i);
    }
}

void Set::operator=(Set &different)  {
    this->set.clear();
    for (size_t i = 0; i < different.size(); i++){
        this->operator+(different[i]);
    }
}

Set Set::operator+(Set &different) {
    Set temp{};
    for (size_t i = 0; i< this->size() || i < different.size(); i++){
        if (i< this->size() &&!temp.exists(this->set[i])) {
            temp + ( this->operator[](i));
        }
        if (i < different.size() && !temp.exists(different.set[i])){
            temp + (different[i]);
        }
    }
    return temp;
}

std::string Set::print()  {
    std::string str = "{";
    for (size_t i = 0; i< this->size(); i++){
        int nr = this->operator[](i);
        str.append(std::to_string(nr) + ", ");
    }
    str.append("}");
    return str;
}