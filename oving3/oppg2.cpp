//
// Created by hassa on 26.08.2022.
//
#include <iostream>

using namespace std;

const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    int get_area();
    double get_circumference();

private: double radius;

    double radius_;

};

Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() {
    return pi * radius * radius;
}

double Circle::get_circumference()  {
    double circumference = 2.0 * pi * radius;
    return circumference;
}

int main() {
    Circle circle(5);

    int area = circle.get_area();
    cout << "Arealet er lik " << area <<  endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}