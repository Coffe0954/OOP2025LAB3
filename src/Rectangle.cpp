#include "Rectangle.h"
#include <cmath>
#include <sstream>

Rectangle::Rectangle() : vertices(4) {}

Rectangle::Rectangle(const std::vector<std::pair<double, double>>& points) {
    if (points.size() == 4) {
        vertices = points;
    } else {
        vertices.resize(4);
    }
}

double Rectangle::area() const {
    double width = std::sqrt(std::pow(vertices[1].first - vertices[0].first, 2) + 
                            std::pow(vertices[1].second - vertices[0].second, 2));
    double height = std::sqrt(std::pow(vertices[2].first - vertices[1].first, 2) + 
                             std::pow(vertices[2].second - vertices[1].second, 2));
    return width * height;
}

std::pair<double, double> Rectangle::center() const {
    double center_x = 0, center_y = 0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    return {center_x / 4.0, center_y / 4.0};
}

void Rectangle::print(std::ostream& os) const {
    os << "rectangle vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Rectangle::read(std::istream& is) {
    vertices.clear();
    for (int i = 0; i < 4; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Invalid input");
        }
        vertices.emplace_back(x, y);
    }
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

Rectangle::Rectangle(const Rectangle& other) : vertices(other.vertices) {}

Rectangle::Rectangle(Rectangle&& other) noexcept : vertices(std::move(other.vertices)) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}