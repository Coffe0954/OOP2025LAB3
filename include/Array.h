#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <vector>
#include <memory>

class Array {
private:
    std::vector<Figure*> figures;
    
public:
    Array() = default;
    ~Array();
    
    void add(Figure* figure);
    void remove(size_t index);
    double totalArea() const;
    
    void printAll() const;
    void printCentersAndAreas() const;
    
    size_t size() const;
    Figure* operator[](size_t index);
    const Figure* operator[](size_t index) const;
    
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
};

#endif