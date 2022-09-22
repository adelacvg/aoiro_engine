#include<iostream>


#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"

#include"src/graphics/buffers/buffer.h"
#include"src/graphics/buffers/indexbuffer.h"
#include"src/graphics/buffers/vertexarray.h"

#include"src/graphics/renderer2d.h"
#include"src/graphics/renderable2d.h"
#include"src/graphics/simple2drenderer.h"

int main()
{
    using namespace aoiro;
    using namespace graphics;
    using namespace maths;

    Window window("Aoiro", 960, 540);
    // glClearColor(0,1,1,1);


    mat4 ortho = mat4::orthographic(0,16,0,9,-1,1);
    

    Shader shader("src/shaders/basic.vert",
                  "src/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix",ortho);
    shader.setUniformMat4("ml_matrix", mat4::translation({4,3,0}));
    Renderable2D sprite(maths::vec3(5,5,0),maths::vec2(4,4),maths::vec4(1,0,1,1),shader);
    Renderable2D sprite1(maths::vec3(7,1,0),maths::vec2(2,3),maths::vec4(0.2,0,1,1),shader);
    Simple2DRenderer renderer;

    shader.setUniform2f("light_pos",{4,1.5});
    shader.setUniform4f("colour", {0.2,0.3,0.8,1.0});

    while(!window.closed())
    {
        window.clear();
        double x,y;
        window.getMousePosition(x,y);
        shader.setUniform2f("light_pos",{float(x*16.0f/960.0f),float(9.0f-y*9.0f/540.0f)});
        renderer.submit(&sprite);
        renderer.submit(&sprite1);
        renderer.flush();

        window.update();
    }
    return 0;
}