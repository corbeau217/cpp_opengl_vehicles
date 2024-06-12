#version 410 core

uniform mat4 u_mvpMatrix; // model to camera matrix

layout (location = 0) in vec3 aPos;

void main()
{
   gl_Position = u_mvpMatrix * vec4(aPos.xyz, 1.0);
}