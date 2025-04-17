//
// Created by ivan on 3/14/25.
//

#ifndef LAB_2_3_CIRCLE_H
#define LAB_2_3_CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
    double* radius;
public:
    Circle(double radius);
    ~Circle() override;
    double calc_area() override;
    void show() override;
};



#endif //LAB_2_3_CIRCLE_H
