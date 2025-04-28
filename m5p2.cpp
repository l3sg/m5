#include <iostream>
#include <string>

using namespace std;

class BasicShape {
private:
    double area;
    string name;
public:
    double getArea() const { return area; }
    void setArea(double a) { area = a; }
    string getName() const { return name; }
    void setName(string n) { name = n; }
    virtual void calcArea() = 0;
    virtual ~BasicShape() {}
};

class Circle : public BasicShape {
private:
    double xCenter, yCenter, radius;
public:
    Circle(double x, double y, double r, string n = "Circle")
        : xCenter(x), yCenter(y), radius(r) {
        setName(n);
        calcArea();
    }
    void calcArea() override {
        const double PI = 3.1415926535;
        setArea(PI * radius * radius);
    }
    double getXCenter() const { return xCenter; }
    double getYCenter() const { return yCenter; }
    double getRadius() const { return radius; }
};

class Rectangle : public BasicShape {
private:
    double length, width;
public:
    Rectangle(double l, double w, string n = "Rectangle")
        : length(l), width(w) {
        setName(n);
        calcArea();
    }
    void calcArea() override {
        setArea(length * width);
    }
    double getLength() const { return length; }
    double getWidth() const { return width; }
};

class Square : public Rectangle {
private:
    double side;
public:
    Square(double s, string n = "Square")
        : Rectangle(s, s, n), side(s) {
        setName(n); // Explicitly called as per instructions, though already set by Rectangle
    }
    double getSide() const { return side; }
};

int main() {
    BasicShape* shapes[5];
    shapes[0] = new Rectangle(1.0, 2.0, "Rect1");
    shapes[1] = new Rectangle(3.0, 4.0, "Rect2");
    shapes[2] = new Circle(0.0, 0.0, 1.0, "Circle1");
    shapes[3] = new Circle(1.0, 1.0, 2.0, "Circle2");
    shapes[4] = new Square(2.5, "Square1");

    for(int i = 0; i < 5; i++) {
        cout << "Shape: " << shapes[i]->getName() << ", Area: " << shapes[i]->getArea() << endl;
    }

    for(int i = 0; i < 5; i++) {
        delete shapes[i];
    }

    return 0;
}