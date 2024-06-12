#pragma once

#include <glm/glm.hpp>              // mat4
// glm matrix includes
// #include <glm/ext/matrix_float4x4.hpp>              // mat4
// #include <glm/ext/matrix_transform.hpp>             // translate, rotate
// #include <glm/ext/matrix_clip_space.hpp>            // perspective

// standard library
#include <iostream> 
#include <vector> 


// https://cplusplus.com/reference/vector/vector/
namespace SceneObject {
    // ...
    class SceneObject {
        public:
            SceneObject *parent;
            std::vector<SceneObject*> children;
            glm::mat4 modelToParent;

            // calculations buffer
            glm::mat4 tempMvpMatrix;

            // ===================================

            SceneObject();
            ~SceneObject();

            // ===================================

            void setParent(SceneObject *parentObject);

            void addChild(SceneObject *childObject);

            void update(float deltaTime);

            virtual void updateSelf(float deltaTime);

            void draw(glm::mat4 mvpMatrix);

            virtual void drawSelf(glm::mat4 mvpMatrix);

            // ===================================
            
            // should get current in parent in parent all the way up to root node
            glm::mat4 getModelToWorldMatrix();

            // get the object's relation to parent
            glm::mat4 getModelMatrix();

            // set the object's relation to parent
            void setModelMatrix(glm::mat4 updatedMatrix);

            // ===================================
    };
}