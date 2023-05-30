//
// Created by hassa on 26.08.2022.
//
#ifndef OVING3_COMMODITY_HPP
#define OVING3_COMMODITY_HPP
#endif //OVING3_COMMODITY_HPP

#include<string>
using namespace std;

class Commodity{

public:
    Commodity(string name, int id, double price);
    string get_name();
    int get_id();
    double get_price(double);
    double get_price();
    double set_price(double);
    double get_price_with_sales_tax(double);

private:
    string name;
    int id;
    double price;

};