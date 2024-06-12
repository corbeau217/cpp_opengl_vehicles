#include "App.hpp"

namespace App {
    long long timeInMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    // ===================================
    /**
     * constructor
     */
    App::App( int width, int height){
        std::cout << "constructing App instance" << std::endl;
        // change to be using the new shader format
        screenWidth = width;
        screenHeight = height;
        // prepare the time holder
        oldTime = timeInMillis();
    }
    /**
     * destructor
     */
    App::~App(){
        std::cout << "destructing App instance" << std::endl;

        // glfw: terminate, clearing all previously allocated GLFW resources.
        // ------------------------------------------------------------------
        glfwTerminate();
    }
    // ===================================
    /**
     * direct replacement for int main right now
    */
    int App::run(){
        int initReturn = this->init();

        // when not successful
        if(initReturn != 0){
            return initReturn;
        }


        // uncomment this call to draw in wireframe polygons.
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // render loop
        // -----------
        while (!glfwWindowShouldClose(window))
        {
            this->prepareFrame();
            // ---------------------

            processInput(window);

            this->update();

            this->draw();
    
            // ---------------------
            this->pushChanges();
        }

        return 0;
    }

    int App::init(){
        
        // glfw: initialize and configure
        // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

        // glfw window creation
        // --------------------
        window = glfwCreateWindow(screenWidth, screenHeight, this->windowTitle, NULL, NULL);
        // check failures
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        // App: try for initialise scene
        // ---------------------------------------

        scene.init();

        // ---------------------------------------

        // ok success
        return 0;
    }

    void App::prepareFrame(){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void App::update(){
        // time stuffs 
        // ------
        long long newTime = timeInMillis();
        float deltaTime = (float)( (newTime - oldTime) ) / 1000.0f;
        oldTime = newTime;

        // try for scene update
        // ------
        scene.update( deltaTime );
    }

    void App::draw(){
        // try for draw scene
        // ------
        scene.draw();
    }

    void App::pushChanges(){
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
    // ---------------------------------------------------------------------------------------------------------
    void App::processInput(GLFWwindow *window){
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
    
    // glfw: whenever the window size changed (by OS or user resize) this callback function executes
    // ---------------------------------------------------------------------------------------------------------
    void App::framebuffer_size_callback(GLFWwindow* window, int width, int height){
        screenWidth = width;
        screenHeight = height;
        // make sure the viewport matches the new window dimensions; note that width and 
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }
    // ===================================
}