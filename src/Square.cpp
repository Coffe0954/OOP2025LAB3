#include "Square.h"
#include <cmath>
#include <sstream>

Square::Square() : vertices(4) {}

Square::Square(const std::vector<std::pair<double, double>>& points) {
    if (points.size() == 4) {
        vertices = points;
    } else {
        vertices.resize(4);
    }
}

double Square::area() const {
    double side = std::sqrt(std::pow(vertices[1].first - vertices[0].first, 2) + 
                           std::pow(vertices[1].second - vertices[0].second, 2));
    return side * side;
}

std::pair<double, double> Square::center() const {
    double center_x = 0, center_y = 0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    return {center_x / 4.0, center_y / 4.0};
}

void Square::print(std::ostream& os) const {
    os << "Square verticess: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Square::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 4; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Invalid input");
        }
        vertices.emplace_back(x, y);
    }
}

Figure* Square::clone() const {
    return new Square(*this);
}

Square::Square(const Square& other) : vertices(other.vertices) {}

Square::Square(Square&& other) noexcept : vertices(std::move(other.vertices)) {}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}