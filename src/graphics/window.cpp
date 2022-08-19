#include"window.h"
#include<iostream>

namespace aoiro
{
    namespace graphics
    {
        void windowResize(GLFWwindow* window, int width,int height);
        Window::Window(const char* title, int width,int height):
        m_title(title),m_width(width),m_height(height)
        {
            init();
            if(!init())
                glfwTerminate();
        }
        Window::~Window()
        {
            glfwTerminate();
        }
        bool Window::init()
        {
            if(!glfwInit())
            {
                std::cout<<"Failed to initialize GLFW"<<std::endl;
                return false;
            }
            m_window = glfwCreateWindow(m_width,m_height,m_title,nullptr,nullptr);
            if(!m_window)
            {
                glfwTerminate();
                std::cout<<"Failed ot create GLFW window!"<<std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_window);
            glfwSetWindowSizeCallback(m_window,windowResize);
            return true;
        }
        bool Window::closed() const
        {
            return glfwWindowShouldClose(m_window)==1;
        }
        void Window::update()
        {
            glfwPollEvents();
            glfwGetFramebufferSize(m_window, &m_width,&m_height);
            glfwSwapBuffers(m_window);
        }
        void Window::clear()const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        void windowResize(GLFWwindow* window, int width,int height)
        {
            glViewport(0,0,width,height);
        }

    }
}