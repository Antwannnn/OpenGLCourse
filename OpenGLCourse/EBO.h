#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO
{

private:
	GLuint ID;

public :

	EBO(GLuint* indices, GLsizeiptr size);
	
	void Bind();
	void Unbind();
	void Delete();
};

#endif

