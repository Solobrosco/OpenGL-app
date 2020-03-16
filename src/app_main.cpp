#include <App.h>

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 500, 500, "OpenGL Demo");

    app->run();
}
