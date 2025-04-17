//
// Created by ivan on 3/14/25.
//

#ifndef LAB_2_3_FIGURE_H
#define LAB_2_3_FIGURE_H

class Figure {
public:
    virtual ~Figure() = default;

    virtual double calc_area() = 0;

    virtual void show() = 0;
};

#endif //LAB_2_3_FIGURE_H
