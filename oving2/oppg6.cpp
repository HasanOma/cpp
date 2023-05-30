//
// Created by hassa on 25.08.2022.
//
#include <iostream>

int find_sum(const int *table, int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += table[i];
        std::cout << sum << " + " << table[i] << std::endl;
    }
    return sum;
}

int main(){

    int length = 20;
    int table[length];

    for(int i = 0; i<length; i++){
        table[i] = (i + 1) * 3;
    }

    int sum = find_sum(table, length-10);
    std::cout << "\n" << sum << "\n" << std::endl;

    sum = find_sum(&table[length-10], length-15);
    std::cout << "\n" << sum << "\n" << std::endl;

    sum = find_sum(&table[length-5], length-15);
    std::cout << "\n" << sum << "\n" << std::endl;

    return 0;
}