#pragma once

#include "../utils/fileutils.h"
#include "../maths/maths.h"
#include <GL/glew.h>
#include <vector>
#include <iostream>

namespace aoiro
{
    namespace graphics
    {
        class Shader
        {
            private:
                GLuint m_ShaderID;
                const char* m_VerPath;
                const char* m_FragPath;
            public:
                Shader(const char* vertPath, const char* fragPath);
                ~Shader();


                void setUniform1f(const GLchar* name, float value);
                void setUniform1i(const GLchar* name, int value);
                void setUniform2f(const GLchar* name, const maths::vec2& vector);
                void setUniform3f(const GLchar* name, const maths::vec3& vector);
                void setUniform4f(const GLchar* name, const maths::vec4& vector);
                void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

                void enable() const;
                void diable() const;
            private:
                GLint getUniformLocation(const GLchar* name);
                GLuint load();
        };
    }
}