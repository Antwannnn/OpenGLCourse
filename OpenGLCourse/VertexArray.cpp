#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

void VertexArray::LinkVertexBuffer(VertexBuffer vbo, GLuint layout)
{

	vbo.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(layout);
	vbo.Unbind();

}

void VertexArray::Bind()
{

	glBindVertexArray(ID);

}

void VertexArray::Unbind()
{
	glBindVertexArray(0);

}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &ID);

}
