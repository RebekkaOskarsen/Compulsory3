#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

string get_file_contents(const char* filename); //Function to read the shader files

//Shader class
class Shader
{
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();
};

#endif
