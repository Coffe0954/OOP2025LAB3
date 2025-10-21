#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include <vector>

class Square : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    
public:
    Square();
    Square(const std::vector<std::pair<double, double>>& points);
    
    double area() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Figure* clone() const override;
    
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    ~Square() override = default;
};

#endif