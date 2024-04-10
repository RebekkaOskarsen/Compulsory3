#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"Object.h"

using namespace std;

const unsigned int width = 800;
const unsigned int height = 800;

// vertices of the surface
float vertices[] =
{
    // Positions                // Colors
    -0.5f, -0.5f, 0.0f,         1.0f, 0.0f, 0.0f,  // Bottom Left
     0.5f, -0.5f, 0.0f,         0.0f, 1.0f, 0.0f,  // Bottom Right
     0.5f,  0.5f, 0.0f,         0.0f, 0.0f, 1.0f,  // Top Right
    -0.5f,  0.5f, 0.0f,         1.0f, 1.0f, 0.0f   // Top Left
};

// indices for the surface
unsigned int indices[] =
{
    0, 1, 2,  // First triangle
    0, 2, 3   // Second triangle
};


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, width, height);

    Shader shaderProgram("default.vert", "default.frag");


    // Set up vertex data and buffers
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Set up vertex attribute pointers for the surface
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); // color attribute
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    Object Object;

    // Set object color
    glm::vec3 objectColor = glm::vec3(1.0f, 0.0f, 0.0f);

    // Rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // Input handling

        // Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();

        glBindVertexArray(VAO);
        // surface
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    
        // Draw the object
        Object.DrawObject(shaderProgram);

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Deallocate resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}