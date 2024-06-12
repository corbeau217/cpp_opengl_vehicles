#include "Triangle.hpp"



namespace Triangle {

    Triangle::Triangle(){
        // ...
        std::cout << "constructing Triangle instance" << std::endl;
    }
    Triangle::~Triangle(){
        std::cout << "destructing Triangle instance" << std::endl;
        // ...

        // free the vertex data array
        free(vertices);

        // optional: de-allocate all resources once they've outlived their purpose:
        // ------------------------------------------------------------------------
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
    }
    // ===================================

    void Triangle::init(){
        std::cout << "initialising triangle" << std::endl;

        this->shaderProgram = ShaderHandle::getShaderProgram();

        // hand off for prepare shaders
        ShaderHandle::prepareShaders( VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH );

        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------

        // hand off generate vertices
        generateVertices();

        // unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //  need to manually calculate the size of the data overall since we're using heap allocation
        glBufferData(GL_ARRAY_BUFFER, vertexDataCount * sizeof(float), vertices, GL_STATIC_DRAW);

        // glVertexAttribPointer ( GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer )
        //  size -> number of components per vertex
        //  type -> data type of components
        //  normalized -> do they get normalized or nah
        //  stride -> byte offset between consecutive vertex attributes
        //  pointer -> offset of the first component of the first vertex attribute in the data store currently bound
        glVertexAttribPointer(0, COMPONENTS_PER_VERTEX, GL_FLOAT, GL_FALSE, COMPONENTS_PER_VERTEX * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0); 

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0); 
    }

    void Triangle::generateVertices(){
        std::cout<<"generating vertices"<<std::endl;
        
        // static generation
        float vertexArray[] = {
            -0.5f, -0.5f, 0.0f, // left  
            0.5f, -0.5f, 0.0f, // right 
            0.0f,  0.5f, 0.0f  // top   
        };
        
        // allocate in heap
        this->vertices = (float *)malloc(sizeof(vertexArray));

        // get the number of things
        vertexDataCount = sizeof(vertexArray)/sizeof(float);
        vertexCount = vertexDataCount / COMPONENTS_PER_VERTEX;

        // copy the data to each
        for(int i = 0; i < vertexDataCount; i++){
            vertices[i] = vertexArray[i];
            // std::cout<<"["<<i<<"] - "<< (vertices[i]) << std::endl;
        }
        // std::cout<<"we have "<<( sizeof(vertexArray)/sizeof(float) )<<" elements"<<std::endl;
    }


    void Triangle::drawSelf(glm::mat4 mvpMatrix){
        // std::cout << glm::to_string(mvpMatrix) << std::endl;


        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

        unsigned int mvpMatrixLocation = glGetUniformLocation( shaderProgram, "u_mvpMatrix" );
        
        glUniformMatrix4fv( mvpMatrixLocation, 1, GL_FALSE, glm::value_ptr(mvpMatrix) );

        // glDrawArrays( GLenum mode, GLint first, GLsizei count )
        //  mode -> kind of primitives to render
        //  first -> starting index
        //  count -> number of indices
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
        glBindVertexArray(0); // no need to unbind it every time 
    }
}