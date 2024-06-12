#include "Scene.hpp"
#include "ShaderHandle.hpp"

namespace Scene {
    // ....
    // ===================================
    /**
     * constructor
     */
    Scene::Scene(){
        std::cout << "constructing Scene instance" << std::endl;
        // camera.setModelMatrix( glm::translate(camera.modelToParent, glm::vec3(0.5f, 0.4f, 0.3f) ) );
    }
    /**
     * destructor
     */
    Scene::~Scene(){
        std::cout << "destructing Scene instance" << std::endl;
    }

    void Scene::init(){
        std::cout << "initialising scene" << std::endl;
        // camera.modelToParent = glm::mat4( glm::translate((camera.modelToParent), glm::vec3(0.3f, 0.3f, 0.0f) ) );
        // camera.modelToParent = glm::mat4( glm::translate((camera.modelToParent), glm::vec3(0, 0, -2) ) );
        // camera.modelToParent = glm::translate((camera.modelToParent), glm::vec3(0, 0, 2) );
        // camera.setModelMatrix( glm::translate(camera.modelToParent, glm::vec3(0, 0, 2) ) );

        // build and compile our shader program
        // ------------------------------------

        ShaderHandle::initShaderProgram();

        triangle.init();
        triangle.setParent(this);
    }

    glm::mat4 Scene::getWorldToCameraMatrix(){
        // tempMvpMatrix = glm::inverse( camera.getModelToWorldMatrix() );
        // return tempMvpMatrix;
        // yoinked from Camera.hpp:

        // vClp = P * V * M * vMdl
        // vClp = P * V * vWrld
        // vClp = P * vCam

        // leave out the modelt matrix because scene will do that during draw call with vpMatrix
        tempMvpMatrix = camera.getProjectionMatrix() * camera.getViewMatrix();

        // then give it to the things
        return tempMvpMatrix;
    }
    void Scene::draw(){
        // fetch the world to camera matrix
        this->tempMvpMatrix = getWorldToCameraMatrix();
        // draw the graph
        draw( tempMvpMatrix );
    }
    void Scene::updateSelf(float deltaTime){
        // std::cout << "delta time is: " << deltaTime << std::endl;
        // ....
        // camera.modelToParent = glm::mat4( glm::rotate(camera.modelToParent, deltaTime, glm::vec3(0, 1, 0) ) );
        // camera.setModelMatrix( glm::translate(camera.modelToParent, glm::vec3(0, 0, deltaTime) ) );
    }
}