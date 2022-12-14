#include "vec3.h"

namespace aoiro
{
    namespace maths
    {
        vec3& vec3::add(const vec3& other)
        {
            x+=other.x;
            y+=other.y;
            z+=other.z;
            return *this;
        }
        vec3& vec3::subtract(const vec3& other)
        {
            x-=other.x;
            y-=other.y;
            z-=other.z;
            return *this;
        }
        vec3& vec3::multiply(const vec3& other)
        {
            x*=other.x;
            y*=other.y;
            z*=other.z;
            return *this;
        }
        vec3& vec3::divide(const vec3& other)
        {
            x/=other.x;
            y/=other.y;
            z/=other.z;
            return *this;
        }
        vec3 operator+(const vec3& left, const vec3& right)
        {
            return {left.x+right.x,left.y+right.y,left.z+right.z};
        }
        vec3 operator-(const vec3& left, const vec3& right)
        {
            return {left.x-right.x,left.y-right.y,left.z-right.z};
        }
        vec3 operator*(const vec3& left, const vec3& right)
        {
            return {left.x*right.x,left.y*right.y,left.z*right.z};
        }
        vec3 operator/(const vec3& left, const vec3& right)
        {
            return {left.x/right.x,left.y/right.y,left.z/right.z};
        }
        vec3& vec3::operator+=(vec3& other)
        {
            return add(other);
        }
        vec3& vec3::operator-=(vec3& other)
        {
            return subtract(other);
        }
        vec3& vec3::operator*=(vec3& other)
        {
            return multiply(other);
        }
        vec3& vec3::operator/=(vec3& other)
        {
            return divide(other);
        }
        bool vec3::operator==(const vec3& other)
        {
            return (x==other.x)&&(y==other.y)&&(z==other.z);
        }
        bool vec3::operator!=(const vec3& other)
        {
            return !(*this==other);
        }
        std::ostream& operator<<(std::ostream& stream, const vec3 vector)
        {
            stream << "vec3: ("<<vector.x<<", "<<vector.y<<", "<<vector.z<<")"<<std::endl;
            return stream;
        }
    }
}