#include <iostream>

int main() {

    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    std::cout << " i - verdi | adresse: " <<  i << " | " << &i <<std::endl;
    std::cout << " j - verdi | adresse: " <<  j << " | " << &j <<std::endl;
    std::cout << "*p - verdi | adresse: " <<  *p << " | " << &*p <<std::endl;
    std::cout << "*q - verdi | adresse: " <<  *q << " | " << &*q <<std::endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    std::cout << "\n*p | *q - verdi | verdi: " << *p << " | " << *q << std::endl;

    return 0;
}
