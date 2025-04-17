//
// Created by ivan on 3/14/25.
//
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double height, double width) {
    this-> height = new double (height);
    this-> width = new double (width);
}

Rectangle::~Rectangle(){
  delete height;
  delete width;
}

double Rectangle::calc_area() {
    return *height * *width;
}

void Rectangle::show(){
    std::cout << "Rectangle\n\theight: " << *height
    << "\n\twidth: " << *width << "\n\tarea: " << calc_area() << "\n";
};