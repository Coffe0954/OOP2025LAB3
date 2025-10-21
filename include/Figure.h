#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual double area() const = 0;
    virtual std::pair<double, double> center() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    virtual Figure* clone() const = 0;
    
    operator double() const {
        return area();
    }
};

inline std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.read(is);
    return is;
}

#endif