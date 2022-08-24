#include "vec4.h"

namespace aoiro
{
    namespace maths
    {
        vec4::vec4()
        {
            x=0.0f;
            y=0.0f;
        }
        vec4::vec4(const float& x,const float& y,const float& z,const float& w)
        {
            this->x=x;
            this->y=y;
            this->z=z;
            this->w=w;
        }
        vec4& vec4::add(const vec4& other)
        {
            x+=other.x;
            y+=other.y;
            z+=other.z;
            w+=other.w;
            return *this;
        }
        vec4& vec4::subtract(const vec4& other)
        {
            x-=other.x;
            y-=other.y;
            z-=other.z;
            w-=other.w;
            return *this;
        }
        vec4& vec4::multiply(const vec4& other)
        {
            x*=other.x;
            y*=other.y;
            z*=other.z;
            w*=other.w;
            return *this;
        }
        vec4& vec4::divide(const vec4& other)
        {
            x/=other.x;
            y/=other.y;
            z/=other.z;
            w/=other.w;
            return *this;
        }
        vec4 operator+(const vec4& left, const vec4& right)
        {
            return {left.x+right.x,left.y+right.y,left.z+right.z,left.w+right.w};
        }
        vec4 operator-(const vec4& left, const vec4& right)
        {
            return {left.x-right.x,left.y-right.y,left.z-right.z,left.w-right.w};
        }
        vec4 operator*(const vec4& left, const vec4& right)
        {
            return {left.x*right.x,left.y*right.y,left.z*right.z,left.w*right.w};
        }
        vec4 operator/(const vec4& left, const vec4& right)
        {
            return {left.x/right.x,left.y/right.y,left.z/right.z,left.w/right.w};
        }
        vec4& vec4::operator+=(vec4& other)
        {
            return add(other);
        }
        vec4& vec4::operator-=(vec4& other)
        {
            return subtract(other);
        }
        vec4& vec4::operator*=(vec4& other)
        {
            return multiply(other);
        }
        vec4& vec4::operator/=(vec4& other)
        {
            return divide(other);
        }
        bool vec4::operator==(const vec4& other)
        {
            return (x==other.x)&&(y==other.y)&&(z==other.z)&&(w==other.w);
        }
        bool vec4::operator!=(const vec4& other)
        {
            return !(*this==other);
        }
        std::ostream& operator<<(std::ostream& stream, const vec4 vector)
        {
            stream << "vec4: ("<<vector.x<<", "
                   <<vector.y<<", "
                   <<vector.z<<", "
                   <<vector.w
                   <<")"<<std::endl;
            return stream;
        }
    }
}