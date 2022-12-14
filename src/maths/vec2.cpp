#include "vec2.h"

namespace aoiro
{
    namespace maths
    {
        vec2& vec2::add(const vec2& other)
        {
            x+=other.x;
            y+=other.y;
            return *this;
        }
        vec2& vec2::subtract(const vec2& other)
        {
            x-=other.x;
            y-=other.y;
            return *this;
        }
        vec2& vec2::multiply(const vec2& other)
        {
            x*=other.x;
            y*=other.y;
            return *this;
        }
        vec2& vec2::divide(const vec2& other)
        {
            x/=other.x;
            y/=other.y;
            return *this;
        }
        vec2 operator+(const vec2& left, const vec2& right)
        {
            return {left.x+right.x, left.y+right.y};
        }
        vec2 operator-(const vec2& left, const vec2& right)
        {
            return {left.x-right.x,left.y-right.y};
        }
        vec2 operator*(const vec2& left, const vec2& right)
        {
            return {left.x*right.x,left.y*right.y};
        }
        vec2 operator/(const vec2& left, const vec2& right)
        {
            return {left.x/right.x,left.y/right.y};
        }
        vec2& vec2::operator+=(vec2& other)
        {
            return add(other);
        }
        vec2& vec2::operator-=(vec2& other)
        {
            return subtract(other);
        }
        vec2& vec2::operator*=(vec2& other)
        {
            return multiply(other);
        }
        vec2& vec2::operator/=(vec2& other)
        {
            return divide(other);
        }
        bool vec2::operator==(const vec2& other)
        {
            return (x==other.x)&&(y==other.y);
        }
        bool vec2::operator!=(const vec2& other)
        {
            return !(*this==other);
        }
        std::ostream& operator<<(std::ostream& stream, const vec2 vector)
        {
            stream << "vec2: ("<<vector.x<<", "<<vector.y<<")"<<std::endl;
            return stream;
        }
    }
}