#include <iostream>
#include <memory>
#include <limits> // ? днаюбхрэ щрс ярпнйс
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

void printMenu() {
    std::cout << "\n=== Figuress ===" << std::endl;
    std::cout << "1. Add Triangle" << std::endl;
    std::cout << "2. Add Square" << std::endl;
    std::cout << "3. Add Rectangle" << std::endl;
    std::cout << "4. Remove Figure" << std::endl;
    std::cout << "5. All Figures" << std::endl;
    std::cout << "6. Centers and Areas" << std::endl;
    std::cout << "7. Total Area" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Choose: ";
}

int main() {
    Array figures;
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter 3 vertices (x y) for triangle:" << std::endl;
                    auto triangle = std::make_unique<Triangle>();
                    std::cin >> *triangle;
                    figures.add(triangle.release());
                    std::cout << "Triangle added!" << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Enter 4 vertices (x y) for square:" << std::endl;
                    auto square = std::make_unique<Square>();
                    std::cin >> *square;
                    figures.add(square.release());
                    std::cout << "Square added!" << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Enter 4 vertices (x y) for rectangle:" << std::endl;
                    auto rectangle = std::make_unique<Rectangle>();
                    std::cin >> *rectangle;
                    figures.add(rectangle.release());
                    std::cout << "Rectangle added!" << std::endl;
                    break;
                }
                case 4: {
                    std::cout << "Enter index to remove: ";
                    size_t index;
                    std::cin >> index;
                    if (index < figures.size()) {
                        figures.remove(index);
                        std::cout << "Figure removed!" << std::endl;
                    } else {
                        std::cout << "Invalid index!" << std::endl;
                    }
                    break;
                }
                case 5: {
                    std::cout << "\nAll Figures:" << std::endl;
                    figures.printAll();
                    break;
                }
                case 6: {
                    std::cout << "\nCenters and Areas:" << std::endl;
                    figures.printCentersAndAreas();
                    break;
                }
                case 7: {
                    double total = figures.totalArea();
                    std::cout << "Total area: " << total << std::endl;
                    break;
                }
                case 8: {
                    std::cout << "POKA!" << std::endl;
                    return 0;
                }
                default: {
                    std::cout << "Invalid option!" << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Oshibka: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return 0;
}