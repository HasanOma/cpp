#include "fraction.hpp"
#include "set.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const string &text, const Fraction &fraction) {
    cout << text << fraction.numerator << " / " << fraction.denominator << endl;
}

void fractions(){
    Fraction a(10, 20);
    Fraction b(3, 4);
    a = a - 5;
    b = 5 - b;

    cout << b.numerator << " / " << b.denominator << endl;
    cout << a.numerator << " / " << a.denominator << endl;
}

void sets(){
    vector<int> vec1 {1, 4, 3};
    vector<int> vec2 {4, 7};

    Set set(vec1);
    Set set2(vec2);

    Set set3 = set + set2;
    cout << set3.print() << endl;

    set + 2;
    cout << set.print() << endl;

    set3 = set;
    cout << set3.print() << endl;
}

int main() {
    cout << "\nTask 1\n" << endl;
    fractions();
    cout << "\nTask 2\n" << endl;
    sets();
}