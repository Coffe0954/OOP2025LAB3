#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <vector>

class Triangle : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Triangle();
    Triangle(const std::vector<std::pair<double, double>>& points);
    
    double area() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Figure* clone() const override;
    
    /*првило пяти*/
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    ~Triangle() override = default;
};

#endif