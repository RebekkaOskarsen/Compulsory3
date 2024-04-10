#ifndef OBJECT_CLASS_H
#define OBJECT_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

class Object
{
public:
    Object();
    ~Object();
    void DrawObject(Shader& shader);

    void SetModelMatrix(glm::mat4 model) { this->model = model; }

private:
    
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    glm::mat4 model;

};

#endif
