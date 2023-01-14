#pragma once

#include <string>

using namespace std;

class Figure
{
private:
    /* data */
public:
    string virtual Name() const = 0;
    float virtual Perimeter() const = 0;
    float virtual Area() const = 0;
};

class Rect : public Figure
{
public:
    Rect(const float &width, const float &height) : width_(width), height_(height){};
    string Name() const override;
    float Perimeter() const override;
    float Area() const override;

private:
    float width_;
    float height_;
    string name_ = "Rectangle";
};

class Triangle : public Figure
{
public:
    Triangle(const float &a, const float &b, const float &c) : a_(a), b_(b), c_(c){};
    string Name() const override;
    float Perimeter() const override;
    float Area() const override;

private:
    float a_;
    float b_;
    float c_;
    string name_ = "Triangle";
};

class Circle : public Figure
{
public:
    Circle(const float &r) : r_(r){};
    string Name() const override;
    float Perimeter() const override;
    float Area() const override;

private:
    float r_;
    string name_ = "Circle";
    float PI = 3.14;
};