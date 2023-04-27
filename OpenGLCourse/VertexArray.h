#ifndef VERTEX_ARRAY_CLASS
#define VERTEX_ARRAY_CLASS

#include<glad/glad.h>
#include"VertexBuffer.h"

class VertexArray
{
private:

	GLuint ID;

public:

	VertexArray();

	void LinkVertexBuffer(VertexBuffer vbo, GLuint layout);
	void Bind();
	void Unbind();
	void Delete();

};

#endif

