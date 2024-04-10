#version 330 core
out vec4 FragColor;

in vec3 vertexColor; // Input variable for receiving color from the vertex shader

void main()
{
    FragColor = vec4(vertexColor, 1.0); // Set fragment color to vertex color
}
