#ifndef App_h
#define App_h
#include <vector>

#include <GlutApp.h>
#include <Rect.h>
#include <TexRect.h>
#include <TextBox.h>
#include <Button.h>
#include <Circle.h>


class App: public GlutApp {
    
    bool fullscreen;

    Button* btn0;
    Button* btn1;
    Circle* cicl; 

    TexRect* pic;

    TextBox* text;

    bool up;
    
    float theta;
    float inc;
    float r;
    float cx;
    float cy;

public:

    bool animating;
    bool circle;
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void idle();

    void leftMouseDown(float x, float y);
    
    ~App();
};

#endif
