//
// Created by hassa on 25.08.2022.
//

#include <iostream>

int main(){
    double number = 2;
    double *p = &number;
    double &r = number;

    std::cout << number << std::endl;
    *p =  999.99;
    std::cout << number << std::endl;
    r = 5555.55;
    std::cout << number << std::endl;

    return 0;
}