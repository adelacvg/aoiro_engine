#include<iostream>


#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
    using namespace aoiro;
    using namespace graphics;
    using namespace maths;
    Window window("Aoiro", 960, 700);
    glClearColor(0.2f,0.3f,0.8f,1.0f);

    // std::cout<<glGetString(GL_VERSION)<<std::endl;
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    vec4 a(1.0f,2.0f,3,4),b(1,2,3,4);
    vec4 c=a+b;
    mat4 positon = mat4::translation({2,3,4});
    positon*=mat4::identity();


    while(!window.closed())
    {
        window.clear();
        std::cout<<a<<c<<std::endl;
        // if(window.isKeyPressed(GLFW_KEY_A))
        //     std::cout<<true<<std::endl;
        // if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
        //     std::cout<<"pressed!"<<std::endl;
        // double x,y;
        // window.getMousePosition(x,y);
        // std::cout<<x<<' '<<y<<std::endl;
        // glBegin(GL_QUADS);
        // glVertex2f(-0.5f,-0.5f);
        // glVertex2f(-0.5f,0.5f);
        // glVertex2f(0.5f,0.5f);
        // glVertex2f(0.5f,-0.5f);
        // glEnd();
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
        window.update();
    }
    return 0;
}