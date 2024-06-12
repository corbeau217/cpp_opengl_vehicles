#include "SceneObject.hpp"

// https://cplusplus.com/reference/vector/vector/
namespace SceneObject {
    // ...

    // ===================================

    SceneObject::SceneObject(){
        // ...
        modelToParent = glm::mat4(1);
        tempMvpMatrix = glm::mat4(1);
    }
    SceneObject::~SceneObject(){
        // ...
    }

    // ===================================
    
    /**
     * @pre: 'this' is dangling node or within a graph
     * @pre: 'parent' is dangling node or within a graph
     * @post: 'parent' is the element 'this.parent'
     * @post: 'this' is an element of 'parent.children'
     * @invariant: 'parent.parent' stays the same
     * @invariant: 'this.children' stays the same
     */
    void SceneObject::setParent(SceneObject *parentObject){
        if(parentObject != NULL){
            parentObject->addChild( this );
        }
        // outside the check, in the case of setting it to null
        this->parent = parentObject;
    }

    /**
     * @pre: 'this' is dangling node or within a graph
     * @pre: 'child' is dangling node or within a graph
     * @post: 'this' is the element 'child.parent'
     * @post: 'child' is an element of 'this.children'
     * @invariant: 'this.parent' stays the same
     * @invariant: 'child.children' stays the same
    */
    void SceneObject::addChild(SceneObject *childObject){
        if(childObject != NULL){
            children.push_back(childObject);
            childObject->parent = this;
        }
    }

    // ===================================

    /**
     * also updates all children attached to this
    */
    void SceneObject::update(float deltaTime){
        // for self
        updateSelf(deltaTime);

        //and the children
        for (std::vector<SceneObject*>::iterator childIterator = children.begin(); childIterator != children.end(); childIterator++){
            // blindly assume we werent given null
            (*childIterator)->update(deltaTime);
        }
        
    }
    void SceneObject::updateSelf(float deltaTime){
        // ...
    }

    // ===================================

    /**
     * also draws all children attached to this
    */
    void SceneObject::draw(glm::mat4 mvpMatrix){
        // W = Outter * Inner
        //  W = Mvp * Mtp
        tempMvpMatrix = mvpMatrix * modelToParent;

        // for self
        drawSelf(mvpMatrix);
        
        //and the children
        for (std::vector<SceneObject*>::iterator childIterator = children.begin(); childIterator != children.end(); childIterator++){
            // blindly assume we werent given null
            (*childIterator)->draw(tempMvpMatrix);
        }
        
    }
    void SceneObject::drawSelf(glm::mat4 mvpMatrix){
        // ...
    }

    // ===================================
    
    // should get current in parent in parent all the way up to root node
    glm::mat4 SceneObject::getModelToWorldMatrix(){
        // base case
        if(parent==NULL)
            return modelToParent;
        // recursive case
        // (not tail recursive optimised)
        return parent->getModelToWorldMatrix() * modelToParent;
    }

    // get the object's relation to parent
    glm::mat4 SceneObject::getModelMatrix(){
        return modelToParent;
    }

    // set the object's relation to parent
    void SceneObject::setModelMatrix(glm::mat4 updatedMatrix){
        modelToParent = updatedMatrix;
    }

    // ===================================
}