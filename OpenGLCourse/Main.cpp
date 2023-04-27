#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"shaderClass.h"
#include"VertexArray.h"
#include"VertexBuffer.h"
#include"EBO.h"

#define WIDTH 800
#define HEIGHT 500
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080;

int main()
{
	glfwInit();

	// Precising the major version of OpenGL used in the project
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// Precising the minor version of OpenGL used in the project;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Precising the OpenGL profile used for this project. We're using core profile for modern opengl features
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat vertices[]
	{

		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // inner left  
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down

	};

	GLuint indices[] =
	{
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	// Creating a new GLFWWindow object with predefined width and height and giving it a name
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLCourse", NULL, NULL);

	// Checking if the window is null / could have not been created
	if (window == NULL)
	{
		std::cout << "Failed to create main window";
		glfwTerminate();
		return 1;
	}

	// Telling GLFW that we're using the window we created before as current context
	glfwMakeContextCurrent(window);

	// Loading glad to configure OpenGL settings
	gladLoadGL();

	// Specifying OpenGL viewport, here going from 0;0 to WIDTH;HEIGHT
	glViewport(0, 0, WIDTH, HEIGHT);
	
	Shader shaderProgram("default.vert", "default.frag");

	VertexArray vao;
	vao.Bind();
	
	VertexBuffer vbo(vertices, sizeof(vertices));
	EBO ebo(indices, sizeof(indices));
	
	vao.LinkVertexBuffer(vbo, 0);
	vao.Unbind();
	ebo.Unbind();


	// Setting up a custom background color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clearing the back buffer
	glClear(GL_COLOR_BUFFER_BIT);
	// Swapping the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Loop looping until a poll event is listened
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		vao.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vbo.Delete();
	vao.Delete();
	ebo.Delete();
	shaderProgram.Delete();

	// Destroying the main window
	glfwDestroyWindow(window);
	// Terminating glfw process
	glfwTerminate();
	return 0;
}