#pragma once

#include<GLFW/glfw3.h>


namespace aoiro
{
    namespace graphics
    {
        class Window
        {
            private:
                int m_width,m_height;
                const char* m_title;
                GLFWwindow* m_window;
                bool m_closed;
            public:
                Window(const char* title,int width,int height);
                ~Window();
                void update();
                bool closed() const;
                void clear() const;

                int getWidth()const{return m_width;}
                int getHeight()const{return m_height;}
            private:
                bool init();
        };
    }
}