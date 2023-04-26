#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

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

	// Setting up a custom background color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clearing the back buffer
	glClear(GL_COLOR_BUFFER_BIT);
	// Swapping the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Loop looping until a poll event is listened
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	// Destroying the main window
	glfwDestroyWindow(window);
	// Terminating glfw process
	glfwTerminate();
	return 0;
}