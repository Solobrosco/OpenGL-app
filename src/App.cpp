#include <iostream>
#include <cmath>
#include <App.h>

static App* singleton;


void doSomething(){
    singleton->animating = !singleton->animating;
}
void circlePath(){   
    singleton->circle = !singleton->circle;
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    fullscreen = false;

    pic = new TexRect("textures/mushroom.png", -0.125, 0.125, 0.25, 0.25);

    text = new TextBox("Nikko's Lab", -0.9, 0.9, GLUT_BITMAP_HELVETICA_18, 1,1,1, 800);

    btn0 = new Button(-0.3, -1+0.25, 0.2, 0.2);
    btn1 = new Button(0.1, -1+0.25, 0.2, 0.2);

    btn0->func = doSomething;
    btn1->func = circlePath;


    animating = false;
    circle = false;
    up = true;

    singleton = this;

    theta = 0;
    inc = 2*M_PI/60;

    r = 0.5;
    cx = 0;
    cy = 0;
}

void App::draw() const {

    text->draw();

    btn0->draw();
    btn1->draw();

    pic->draw(0);
}

void App::leftMouseDown(float x, float y){
    //std::cout << "Mouse down at " << x << ", " << y << std::endl;
    // if (x >= 0.0 && x <= 0.3 && y <= 0 && y >= -0.1){
    //     std::cout << "Clicked button1" << std::endl;
    //     //animating = !animating;
    // }
    btn0->handle(x, y);
    btn1->handle(x, y);
}

void App::idle(){
    if (animating){
        if (pic->getX() >= 1 - 0.25){
            up = false;
        }
        if (pic->getX() <= -1){
            up = true;
        }

        if (up){
            pic->setX(pic->getX() + 0.05);

        }
        else if(!up){
            pic->setX(pic->getX() - 0.05);
        }
    }
    if(circle){
        pic->setX((r*cos(theta) + cx)-0.125);
        pic->setY((r*sin(theta) + cy)+0.125);
        theta += inc;
    }
    redraw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    if (key == ' '){
        animating = !animating;
    }
    else if (key == 'f'){
        toggleFullScreen();
    }
    else if (key == 'z'){
        circle = !circle;
    }
    redraw();
}

App::~App(){    
    delete pic;
    delete text;
    delete btn0;
    delete btn1;
    std::cout << "Exiting..." << std::endl;
}
