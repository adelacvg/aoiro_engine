#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>


namespace aoiro
{
    namespace graphics
    {
        #define MAX_KEYS 1024
        #define MAX_BUTTONS 32
        class Window
        {
            private:
                int m_width,m_height;
                const char* m_title;
                GLFWwindow* m_window;
                bool m_closed;

                bool m_Keys[MAX_KEYS];
                bool m_MouseButtons[MAX_BUTTONS];
                double m_x;
                double m_y;
            public:
                Window(const char* title,int width,int height);
                ~Window();
                void update();
                bool closed() const;
                void clear() const;

                int getWidth()const{return m_width;}
                int getHeight()const{return m_height;}

                bool isKeyPressed(unsigned int keycode) const;
                bool isMouseButtonPressed(unsigned int button) const;
                void getMousePosition(double& x,double& y) const;
            private:
                bool init();
                friend void window_resize(GLFWwindow* window, int width,int height);
                friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
                friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
                friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        };
    }
}