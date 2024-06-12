#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


// c++ includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

namespace ShaderHandle {
    static bool generatedShaderProgram = false;
    static unsigned int shaderProgramInstance;

    unsigned int getShaderProgram();

    unsigned int initShaderProgram();

    // returns the shader for deleting by the caller
    void compileShader( unsigned int shaderBuffer, const char *shaderSourceCode );

    void prepareShaders( const char *vertexShaderPath, const char *fragmentShaderPath );

    char *read_file_to_char_pointer(const char *filePath);
}