#include "set_of_figures.h"
#include <iostream>
#include <math.h>

string Rect::Name() const
{
    return this->name_;
}

float Rect::Perimeter() const
{
    return (this->width_ + this->height_) * 2.0f;
}

float Rect::Area() const
{
    return this->width_ * this->height_;
}

string Triangle::Name() const
{
    return this->name_;
}

float Triangle::Perimeter() const
{
    return (this->a_ + this->b_ + this->c_);
}
float Triangle::Area() const
{
    float s = (this->a_ + this->b_ + this->c_) / 2.0f;

    return sqrt(s * ((s - this->a_) * (s - this->b_) * (s - this->c_)));
}

string Circle::Name() const
{
    return this->name_;
}

float Circle::Perimeter() const
{
    return (2 * this->PI * this->r_);
}

float Circle::Area() const
{
    return (this->PI * this->r_ * this->r_);
}