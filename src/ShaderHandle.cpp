#include "ShaderHandle.hpp"

namespace ShaderHandle {

    unsigned int getShaderProgram(){
        return shaderProgramInstance;
    }

    unsigned int initShaderProgram(){
        if(!generatedShaderProgram){
            std::cout << "initialising shader program" << std::endl;
            shaderProgramInstance = glCreateProgram();
            generatedShaderProgram = true;
        }
        return shaderProgramInstance;
    }

    void compileShader( unsigned int shaderBuffer, const char *shaderSourceCode ){

        // void glShaderSource( GLuint shader, GLsizei count, const GLchar **string, const GLint *length)
        glShaderSource( shaderBuffer, 1, &shaderSourceCode, NULL );

        // void glCompileShader( GLuint shader );
        glCompileShader( shaderBuffer );

        // check for shader compile errors
        int success;
        char infoLog[512];

        // void glGetShaderiv( GLuint shader, GLenum pname, GLint *params );
        glGetShaderiv( shaderBuffer, GL_COMPILE_STATUS, &success );

        if (!success)
        {
            glGetShaderInfoLog( shaderBuffer, 512, NULL, infoLog );
            std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
    }
    void prepareShaders( const char *vertexShaderPath, const char *fragmentShaderPath ){
        std::cout << "preparing shaders: \n--> ["<< vertexShaderPath <<"]\n--> ["<< fragmentShaderPath <<"]" << std::endl;

        // prepare sources
        char *vertexSource = read_file_to_char_pointer(vertexShaderPath);
        char *fragmentSource = read_file_to_char_pointer(fragmentShaderPath);
        // check they're loaded
        if(vertexSource == NULL || fragmentSource == NULL){
            // error for which one was null
            if(vertexSource == NULL) perror("vertex shader failed to prepare");
            if(fragmentSource == NULL) perror("fragment shader failed to prepare");
        }
        else {
            // otherwise happiness
            // ------------------

            // for checking shader compile errors
            int linkSuccess;
            char linkInfoLog[512];
            
            // the reference
            unsigned int shaderProgramReference = shaderProgramInstance;

            // GLuint glCreateShader( GLenum shaderType );
            unsigned int vertexShaderBuffer = glCreateShader( GL_VERTEX_SHADER );
            compileShader( vertexShaderBuffer, vertexSource );

            // GLuint glCreateShader( GLenum shaderType );
            unsigned int fragmentShaderBuffer = glCreateShader( GL_FRAGMENT_SHADER );
            compileShader( fragmentShaderBuffer, fragmentSource );
            
            // ------------------

            // link the shader program
            glAttachShader( shaderProgramReference, vertexShaderBuffer );
            glAttachShader( shaderProgramReference, fragmentShaderBuffer );
            glLinkProgram( shaderProgramReference );

            // check for linking errors
            glGetProgramiv(shaderProgramReference, GL_LINK_STATUS, &linkSuccess);
            if (!linkSuccess) {
                glGetProgramInfoLog(shaderProgramReference, 512, NULL, linkInfoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << linkInfoLog << std::endl;
            }
            // ------------------
            // clean up the shaders
            

            glDetachShader( shaderProgramReference, vertexShaderBuffer );
            glDetachShader( shaderProgramReference, fragmentShaderBuffer );
            
            glDeleteShader( vertexShaderBuffer );
            glDeleteShader( fragmentShaderBuffer );
            
            // ------------------

            // free the source code
            free(vertexSource);
            free(fragmentSource);
        }
    }


    char *read_file_to_char_pointer(const char *filePath){
        FILE *filePointer = NULL;;
        char *returnableContent = NULL;

        // try grab the file
        filePointer = fopen(filePath, "r");
        if(filePointer == NULL) perror("spooky file grab");
        else{
            int characterCount = 0;
            // read a character and throw it in the air
            for(characterCount = 0; !feof(filePointer); fgetc(filePointer), characterCount++ );

            // should be at the end now, rewind the stream
            rewind( filePointer );
            // allocate the memory
            returnableContent = (char *)malloc( characterCount + 1 );
            // read the file stuffs into the return buffer
            //  one character at a time for the number of characters there were
            fread( returnableContent, 1, characterCount, filePointer );
            // finish with the file
            fclose( filePointer );
            // also set the last char to null (incase it isnt already)
            returnableContent[characterCount] = '\0';
        }
        // return the content
        return returnableContent;
    }
}