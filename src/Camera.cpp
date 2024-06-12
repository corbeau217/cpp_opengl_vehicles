#include "Camera.hpp"

namespace Camera {
    // glm::mat4 viewMatrix;
    // glm::mat4 projectionMatrix;
    // glm::mat4 worldToCameraMatrix;

    // float fovY = TAU/5.0f;
    // float nearPlane = 1.0f;
    // float farPlane = 4.0f;
    // float aspect = 1.0f;
   
    Camera::Camera(){
        // ...
    }
    Camera::~Camera(){
        // ...
    }

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

    // get the view matrix
    //     V = cameraRotation^-1 * cameraTranslation^-1
    //   what if we just undo the scale part by multiplying the projection
    glm::mat4 Camera::getViewMatrix(){
        // mWTC = (TRS)^-1
        // mWTC = S^-1 * R^1 * T^-1
        worldToCameraMatrix = glm::inverse( getModelToWorldMatrix() );
        // S = (S^-1)^-1
        // S = (P)^-1
        // V = R^-1 * T^-1
        // V = (S^-1)^-1 * ( S^-1 * R^-1 * T^-1 )
        // V = (P)^-1 * ( S^-1 * R^-1 * T^-1 )
        viewMatrix = glm::inverse( getProjectionMatrix() ) * worldToCameraMatrix;
        // done
        return viewMatrix;
    }

    // get the projection matrix
    //     P = cameraScale^-1
    glm::mat4 Camera::getProjectionMatrix(){
        // projectionMatrix = glm::ortho( left, right, bottom, top, nearPlane, farPlane );
        projectionMatrix = glm::perspective( fovY, aspect, nearPlane, farPlane );
        // done
        return projectionMatrix;
    }
}