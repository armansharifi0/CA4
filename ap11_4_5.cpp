#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class IllegalArgumentException {};
class UndefinedOperation {};

class Shape {
public:
    Shape(int init_x, int init_y) : x(init_x), y(init_y) {}
    int get_x() const { return x; }
    int get_y() const { return y; }
    void move(int dx, int dy);

    virtual void scale(int s) = 0;
    virtual void print() = 0;
    virtual void area() = 0;
protected:
    int x;
    int y;
};

void Shape::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

class Rect : public Shape {
public:
    Rect(int init_x, int init_y, int w, int h);
    virtual void scale(int s);
    virtual void print();
private:
    int width;
    int height;
};

Rect::Rect(int init_x, int init_y, int w, int h)
    : Shape(init_x, init_y)
{
    if (w <= 0 || h <= 0)
	    throw IllegalArgumentException();
    width = w;
    height = h;
}

void Rect::scale(int s)
{
    width *= s;
    height *= s;
}

void Rect::print()
{
    cout << "Rect: " << x << ',' << y << ',' << width << ',' << height << endl;
}

class Circle : public Shape {
public:
    Circle(int init_x, int init_y, int r);
    virtual void scale(int s);
    virtual void print();
private:
    int radius;
};

Circle::Circle(int init_x, int init_y, int r)
    : Shape(init_x, init_y)
{
    if (r <= 0)
	    throw IllegalArgumentException();
    radius = r;
}

void Circle::scale(int s)
{
    radius *= s;
}

void Circle::print()
{
    cout << "Circle: " << x << ',' << y << ',' << radius << endl;
}


class Equilateral : public Shape {
public:
    Equilateral(int init_x, int init_y, int a);
    virtual void scale(int s);
    virtual void print();
private:
    int side;
};

Equilateral::Equilateral(int init_x, int init_y, int a)
    : Shape(init_x, init_y)
{
    side = a;
}

void Equilateral::scale(int s)
{
    side *= s;
}

void Equilateral::print()
{
    cout << "Equilateral: " << x << ',' << y << ',' << side << endl;
}

class Segment: public Shape
{
public:
    Segment(int init_x, int init_y, int l);
    virtual void scale(int s);
    virtual void print();
    virtual void area();
private:
    int length;
};

Segment::Segment(int init_x, int init_y, int l)
    : Shape(init_x, init_y)
{
    length = l;
}

void Segment::scale(int s)
{
    length *= s;
}

void Segment::print()
{
    cout << "Segment: " << x << ',' << y << ',' << length << endl;
}

void Segment::area()
{
    cout << "Not Defined" << endl;
}

int main()
{
    
}	
					