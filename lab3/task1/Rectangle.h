//
// Created by ivan on 3/14/25.
//

#ifndef LAB_2_3_RECTANGLE_H
#define LAB_2_3_RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
    double* height;
    double* width;
public:
    Rectangle(double height, double width);
    ~Rectangle() override;
    double calc_area() override;
    void show() override;
};

#endif //LAB_2_3_RECTANGLE_H
