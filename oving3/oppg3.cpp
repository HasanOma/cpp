//
// Created by hassa on 26.08.2022.
//
#include <iostream>
#include<string>
#include "Commodity.hpp"
using namespace std;

const float tax = 1.25;

Commodity::Commodity(string name, int id, double price) {
    this->name = name;
    this->id = id;
    this->price = price;
}

string Commodity::get_name() {
    return this->name;
}

int Commodity::get_id() {
    return this->id;
}

double Commodity::get_price(double quantity) {
    return this->price*quantity;
}

double Commodity::get_price() {
    return this->price;
}

double Commodity::set_price(double price) {
    this->price = price;
    return 0;
}

double Commodity::get_price_with_sales_tax(double quantity) {
    return this->price*quantity*tax;
}

int main() {
    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id() << " Pris pr enhet: " << commodity.get_price() << endl;

    cout << "Kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    commodity.set_price(79.60);
    cout << "Ny kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;
}