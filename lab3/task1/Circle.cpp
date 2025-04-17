//
// Created by ivan on 3/14/25.
//
#include "Circle.h"
#include <iostream>

const double M_PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    this->radius = new double(radius);
}

double Circle::calc_area() {
    double area = M_PI * *radius * *radius;
    return area;
}

void Circle::show() {
    std::cout << "Circle " << "\n" << "Radius :" << *radius << "\n"
              << "Area :" << Circle::calc_area() << "\n";
}

Circle::~Circle() {
    delete radius;
}