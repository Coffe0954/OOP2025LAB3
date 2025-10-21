#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <vector>

class Rectangle : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Rectangle();
    Rectangle(const std::vector<std::pair<double, double>>& points);
    
    double area() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Figure* clone() const override;
    
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    ~Rectangle() override = default;
};

#endif