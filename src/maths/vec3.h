#pragma once

#include<iostream>

namespace aoiro
{
    namespace maths
    {
        struct vec3
        {
            float x,y,z;
            vec3& add(const vec3& other);
            vec3& subtract(const vec3& other);
            vec3& multiply(const vec3& other);
            vec3& divide(const vec3& other);
            bool operator==(const vec3& other);
            bool operator!=(const vec3& other);

            friend vec3 operator+(const vec3& left, const vec3& right);
            friend vec3 operator-(const vec3& left, const vec3& right);
            friend vec3 operator*(const vec3& left, const vec3& right);
            friend vec3 operator/(const vec3& left, const vec3& right);

            vec3& operator+=(vec3& other);
            vec3& operator-=(vec3& other);
            vec3& operator*=(vec3& other);
            vec3& operator/=(vec3& other);

            friend std::ostream& operator<<(std::ostream& stream, const vec3 vector);

        };
    }
}