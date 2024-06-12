#pragma once

// opengl includes
#include <glm/ext.hpp>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

// c++ includes
#include <iostream>

// project includes
#include "SceneObject.hpp"


/**
 * vertexScreenPosition = Perspective * View * Model * VertexPosition
------------------------------------------------------

    T = translation
    R = rotation
    S = scale

------------------------------------------------------

    M = T * R * S
    ModelMatrix = ModelTranslation * ModelRotation * ModelScale

    vWrld = M * vMdl
    vertexWorld = ModelMatrix * vertexModel

    vCam = V * M * vMdl
    vCam = V * vWrld
    vertexCamera = ViewMatrix * ModelMatrix * vertexModel

    vClp = P * V * M * vMdl
    vClp = P * V * vWrld
    vClp = P * vCam
    vertexClip = PerspectiveMatrix * ViewMatrix * ModelMatrix * vertexModel

------------------------------------------------------

    cameraT = cameraTranslation
    cameraR = cameraRotation
    cameraS = cameraScale

    matrixCameraToWorld = cameraT * cameraR * cameraS

    matrixWorldToCamera = matrixCameraToWorld^-1
    matrixWorldToCamera = cameraS^-1 * cameraR^-1 * cameraT^-1

    matrixWorldToCamera = P * V

    P = cameraS^-1
    V = cameraR^-1 * cameraT^-1

------------------------------------------------------
*/
namespace Camera {
    static const float TAU = 6.28318530718f;

    class Camera : public SceneObject::SceneObject{
        public:
            // glm::mat4 cameraToWorldMatrix;
            glm::mat4 viewMatrix;
            glm::mat4 projectionMatrix;
            glm::mat4 worldToCameraMatrix;

            float fovY = TAU/5.0f;
            float nearPlane = 1.0f;
            float farPlane = 4.0f;
            float aspect = 1.0f;

            /*
                glm::ortho(
                    left,
                    right,
                    bottom,
                    top,
                    zNear,
                    zFar
                )
                glm::ortho(
                    left,
                    right,
                    bottom,
                    top
                )
            */
            /*
                glm::perspective(
                    fovy,
                    aspect,
                    near,
                    far
                )
                glm::perspective(
                    fovy,
                    width,
                    height,
                    near,
                    far
                )
            */

            Camera();
            ~Camera();

            // get the view matrix
            //     V = cameraRotation^-1 * cameraTranslation^-1
            glm::mat4 getViewMatrix();

            // get the projection matrix
            //     P = cameraScale^-1
            glm::mat4 getProjectionMatrix();
    };
}