#include <gtest/gtest.h>
#include <cmath> // ? ƒŒ¡¿¬»“‹ ›“” —“–Œ ”
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

TEST(TriangleTest, AreaCalculation) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    EXPECT_NEAR(triangle.area(), 6.0, 1e-6);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle triangle({{0, 0}, {4, 0}, {0, 3}});
    auto center = triangle.center();
    EXPECT_NEAR(center.first, 4.0/3.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

TEST(SquareTest, AreaCalculation) {
    Square square({{0, 0}, {2, 0}, {2, 2}, {0, 2}});
    EXPECT_NEAR(square.area(), 4.0, 1e-6);
}

TEST(SquareTest, CenterCalculation) {
    Square square({{0, 0}, {2, 0}, {2, 2}, {0, 2}});
    auto center = square.center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle({{0, 0}, {4, 0}, {4, 2}, {0, 2}});
    EXPECT_NEAR(rectangle.area(), 8.0, 1e-6);
}

TEST(ArrayTest, AddAndRemove) {
    Array array;
    array.add(new Triangle({{0, 0}, {1, 0}, {0, 1}}));
    EXPECT_EQ(array.size(), 1);
    
    array.remove(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array array;
    array.add(new Square({{0, 0}, {1, 0}, {1, 1}, {0, 1}}));
    array.add(new Triangle({{0, 0}, {2, 0}, {0, 2}}));
    
    double total = array.totalArea();
    EXPECT_NEAR(total, 1.0 + 2.0, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}