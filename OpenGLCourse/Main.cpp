#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 500
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080;

// Declaring the vertex shader source code 
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

// Declaring the fragment shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

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
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
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

	// Creating an opengl unsigned int to create a new vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Applying the vertex shader source code to the vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// Compiling the vertex shader
	glCompileShader(vertexShader);

	// Doing the same for the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Wrapping them to a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Wrapping up the shader program
	glLinkProgram(shaderProgram);

	// Now the shaders are in the shader program we can delete the shaders themselves
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLuint VBO, VAO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


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
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	// Destroying the main window
	glfwDestroyWindow(window);
	// Terminating glfw process
	glfwTerminate();
	return 0;
}