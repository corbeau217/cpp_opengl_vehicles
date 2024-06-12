#pragma once

// opengl includes
#include <glm/ext.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

// c++ includes
#include <iostream>

// project includes
#include "SceneObject.hpp"
#include "ShaderHandle.hpp"


namespace Triangle {
    // ...
    class Triangle : public SceneObject::SceneObject {
        public:

            // doesn't do much right now but i like it separate
            const char *VERTEX_SHADER_PATH = "../shaders/vertex.glsl";
            const char *FRAGMENT_SHADER_PATH = "../shaders/fragment.glsl";

            const unsigned int COMPONENTS_PER_VERTEX = 3;

            unsigned int shaderProgram;

            float *vertices;
            unsigned int vertexCount;
            unsigned int vertexDataCount;
            
            unsigned int VBO, VAO;
            
            // ===================================

            Triangle();
            ~Triangle();

            // ===================================

            void generateVertices();

            void init();
            
            // ===================================

            // using SceneObject::SceneObject::setParent;
            // using SceneObject::SceneObject::addChild;
            // using SceneObject::SceneObject::update;
            // using SceneObject::SceneObject::updateSelf;
            // using SceneObject::SceneObject::draw;
            // using SceneObject::drawSelf;
            
            // ===================================

            // ...
            // virtual void updateSelf(float deltaTime) override;
            virtual void drawSelf(glm::mat4 mvpMatrix) override;
    };
}