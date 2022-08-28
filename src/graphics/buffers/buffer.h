#pragma once

#include<GL/glew.h>

namespace aoiro
{
    namespace graphics
    {
        class Buffer
        {
            private:
                GLuint m_BufferID;
                GLuint m_componentCount;
            public:
                Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

                void bind() const;
                void unbind() const;
                GLuint getComponentCount() const;
        };
    }
}