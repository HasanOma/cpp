#include <iostream>
using namespace std;

template <typename T> bool equal(T a, T b){
    cout << "Integer:" << endl;
    return a == b;
}

bool equal(double a, double b){
    cout << "Double:" << endl;
    return  a-b < 0.00001;
}

int main(int, char**) {
    cout << equal(10, 10) << endl;
    cout << equal(10.0000009, 10.0000010) << endl;
}