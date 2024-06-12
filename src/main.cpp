#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "App.hpp"



// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

using namespace std;

int main(int argc, char** argv){
    App::App appable = App::App( SCR_WIDTH, SCR_HEIGHT );

    appable.run();

    return 0;
}

