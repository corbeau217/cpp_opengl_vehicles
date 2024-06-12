#pragma once

// opengl includes
#include <glm/ext.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// c++ includes
#include <iostream>

// project includes
#include "SceneObject.hpp"
#include "Camera.hpp"
#include "Triangle.hpp"

namespace Scene {
    /**
     * instance of the scene
     */
    class Scene : public SceneObject::SceneObject {
        public:
            // ===================================

            Camera::Camera camera;
            Triangle::Triangle triangle;

            // ===================================
            /**
             * constructor
             */
            Scene();
            /**
             * destructor
             */
            ~Scene();
            // ===================================

            void init();


            glm::mat4 getWorldToCameraMatrix();
            void draw();

            // using SceneObject::SceneObject::setParent;
            // using SceneObject::SceneObject::addChild;
            // using SceneObject::SceneObject::update;
            // using SceneObject::SceneObject::updateSelf;
            using SceneObject::SceneObject::draw;
            // using SceneObject::SceneObject::drawSelf;

            void updateSelf( float deltaTime ) override;

    };
}