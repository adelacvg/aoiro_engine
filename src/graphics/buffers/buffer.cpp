#include"buffer.h"

namespace aoiro
{
    namespace graphics
    {
        GLuint Buffer::getComponentCount() const
        {
            return m_componentCount;
        }
        Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
        :m_componentCount(componentCount)
        {
            glGenBuffers(1,&m_BufferID);
            glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
            glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER,0);
        }

        void Buffer::bind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
        }
        void Buffer::unbind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER,0);
        }
    }
}