#include<iostream>


#include "src/graphics/window.h"

int main()
{
    using namespace aoiro;
    using namespace graphics;
    Window window("Aoiro", 960, 700);
    glClearColor(0.2f,0.3f,0.8f,1.0f);

    // std::cout<<glGetString(GL_VERSION)<<std::endl;
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while(!window.closed())
    {
        window.clear();
        // if(window.isKeyPressed(GLFW_KEY_A))
        //     std::cout<<true<<std::endl;
        // if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
        //     std::cout<<"pressed!"<<std::endl;
        double x,y;
        window.getMousePosition(x,y);
        std::cout<<x<<' '<<y<<std::endl;
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