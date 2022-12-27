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
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/sprite.h"
#include "src/graphics/static_sprite.h"

// #define BATCH_RENDERER 1
#include<time.h>

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

    std::vector<Renderable2D*> sprites;
    srand(time(NULL));
    for(float y = 0; y < 9.0f; y+=0.1)
    {
        for(float x = 0; x < 16.0f; x+=0.1)
        {
            sprites.push_back(new Sprite(x,y,0.08f,0.08f,maths::vec4(rand()%1000/1000.0f,0,1,1)));
        }
    }
// #if BATCH_RENDERER
    Sprite sprite(5,5,4,4,maths::vec4(1,0,1,1));
    Sprite sprite1(7,1,2,3,maths::vec4(0.2,0,1,1));
    BatchRenderer2D renderer;

// #else 
//     StaticSprite sprite(5,5,4,4,maths::vec4(1,0,1,1),shader);
//     StaticSprite sprite1(7,1,2,3,maths::vec4(0.2,0,1,1),shader);
//     Simple2DRenderer renderer;
// #endif


    shader.setUniform2f("light_pos",{4,1.5});
    shader.setUniform4f("colour", {0.2,0.3,0.8,1.0});

    while(!window.closed())
    {
        window.clear();
        double x,y;
        window.getMousePosition(x,y);
        shader.setUniform2f("light_pos",{float(x*16.0f/960.0f),float(9.0f-y*9.0f/540.0f)});
        renderer.begin();
        for(const Renderable2D* sprite : sprites)
            renderer.submit(sprite);
        renderer.end();
        renderer.flush();

        window.update();
    }
    return 0;
}