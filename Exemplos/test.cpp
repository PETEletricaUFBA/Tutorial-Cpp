// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;

   public:
    Circle() { radius = 100; };
    Circle(double r) : radius(r) {}
    double area() { return radius * radius * 3.14159265; }
};

class Cylinder {
    Circle base;
    double height;

   public:
    Cylinder() {
        std::cout << "Defaulted Constructed!" << std::endl;
    }
    Cylinder(double r, double h) : base(r), height(h) {}
    Cylinder(double r) : base(r), height(r) {}
    double volume() { return base.area() * height; }
};

int main() {
    Cylinder foo(10, 20);
    std::cout << "Foos" << std::endl;
    Cylinder bar = 20;
    std::cout << "Bar" << std::endl;
    Cylinder roh = Cylinder(30, 30);
    std::cout << "Roh" << std::endl;
    Cylinder kek{20, 20};
    std::cout << "Kek" << std::endl;
    Cylinder kek2 {10, 200};
    std::cout << "KeeK" << std::endl;

    foo.~Cylinder();

    cout << "foo's volume: " << foo.volume() << '\n';
    cout << "bar's volume: " << kek2.volume() << '\n';
    return 0;
}