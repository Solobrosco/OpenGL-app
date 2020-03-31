#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape.h>
#include <cmath>

class Circle : public Shape{
protected:
    // Position
    float x;
    float y;
    // Circle
    float radius;
    // Color
    float r;
    float g;
    float b;
public:
    Circle();
    Circle(float, float, float, float, float, float);

    void draw() const;

    // future implementations
    // getX, setX, getY, setY, setColor(r,g,b), getColor(), 

    ~Circle();
};

#endif