#include"sprite.h"

namespace aoiro
{
    namespace graphics
    {
        Sprite::Sprite(float x, float y, float width, float height, const maths::vec4& color)
            : Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color)
        {
        }

        // Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
        //     : Renderable2D(math::Vector3f(x, y, 0), math::Vector2f(width, height), math::Vector4f(1, 1, 1, 1))
        // {
        //     m_Texture = texture;
        // }
    }
}