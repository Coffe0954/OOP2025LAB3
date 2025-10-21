#include "Triangle.h"
#include <cmath>
#include <sstream>

Triangle::Triangle() : vertices(3) {}

Triangle::Triangle(const std::vector<std::pair<double, double>>& points) {
    if (points.size() == 3) {
        vertices = points;
    } else {
        vertices.resize(3);
    }
}

double Triangle::area() const {
    double x1 = vertices[0].first, y1 = vertices[0].second;
    double x2 = vertices[1].first, y2 = vertices[1].second;
    double x3 = vertices[2].first, y3 = vertices[2].second;
    
    return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

std::pair<double, double> Triangle::center() const {
    double center_x = 0, center_y = 0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    return {center_x / 3.0, center_y / 3.0};
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Triangle::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 3; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Invalid input for triangle");
        }
        vertices.emplace_back(x, y);
    }
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}

Triangle::Triangle(const Triangle& other) : vertices(other.vertices) {}

Triangle::Triangle(Triangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}