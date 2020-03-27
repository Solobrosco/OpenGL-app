#include <Circle.h>
#include <GlutApp.h>

Circle::Circle(){
	x = 0;
	y = 0;
    radius = 1;
	r = 0;
	g = 1;
	b = 0;
}

Circle::Circle(float x, float y, float radius, float r, float g, float b){
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::draw(){
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
	// trace circle
	glEnd();
}

Circle::~Circle(){
    // std::cout << "Circle removed" << std::endl;
}