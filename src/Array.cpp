#include "Array.h"
#include <iostream>

Array::~Array() {
    for (auto figure : figures) {
        delete figure;
    }
}

void Array::add(Figure* figure) {
    figures.push_back(figure);
}

void Array::remove(size_t index) {
    if (index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}

double Array::totalArea() const {
    double total = 0;
    for (const auto figure : figures) {
        total += figure->area();
    }
    return total;
}

void Array::printAll() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
    }
}

void Array::printCentersAndAreas() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        auto center = figures[i]->center();
        double area = figures[i]->area();
        std::cout << "Figure " << i << ": Center(" << center.first << ", " 
                  << center.second << "), Area: " << area << std::endl;
    }
}

size_t Array::size() const {
    return figures.size();
}

Figure* Array::operator[](size_t index) {
    return figures[index];
}

const Figure* Array::operator[](size_t index) const {
    return figures[index];
}

Array::Array(const Array& other) {
    for (const auto figure : other.figures) {
        figures.push_back(figure->clone());
    }
}

Array::Array(Array&& other) noexcept : figures(std::move(other.figures)) {
    other.figures.clear();
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        for (auto figure : figures) {
            delete figure;
        }
        figures.clear();
        
        for (const auto figure : other.figures) {
            figures.push_back(figure->clone());
        }
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        for (auto figure : figures) {
            delete figure;
        }
        figures = std::move(other.figures);
        other.figures.clear();
    }
    return *this;
}