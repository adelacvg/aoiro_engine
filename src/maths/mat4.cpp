#include"mat4.h"

namespace aoiro
{
    namespace maths
    {
        float toRadians(float degrees)
        {
            return degrees/180.f*M_PI;
        }
        mat4::mat4()
        {
            std::memset(elements,0,sizeof elements);
        }
        mat4::mat4(float diagnal):mat4::mat4()
        {
            elements[0+0*4]=diagnal;
            elements[1+1*4]=diagnal;
            elements[2+2*4]=diagnal;
            elements[3+3*4]=diagnal;
        }
        mat4 mat4::identity()
        {
            return mat4(1.0f);
        }
        mat4& mat4::multiply(const mat4& other)
        {
            mat4 result;
            for(int x=0;x<4;x++)
            {
                for(int y=0;y<4;y++)
                {
                    float sum=0.f;
                    for(int e=0;e<4;e++)
                    {
                        sum+=elements[x+e*4]*other.elements[y*4+e];
                    }
                    result.elements[x+y*4]=sum;
                }
            }
            std::memcpy(elements,result.elements,sizeof elements);
            return *this;
        }
        mat4 operator*(const mat4& left,const mat4& right)
        {
            mat4 result;
            for(int x=0;x<4;x++)
            {
                for(int y=0;y<4;y++)
                {
                    float sum=0.f;
                    for(int e=0;e<4;e++)
                    {
                        sum+=left.elements[x+e*4]*right.elements[y*4+e];
                    }
                    result.elements[x+y*4]=sum;
                }
            }
            return result;
        }
        mat4& mat4::operator*=(const mat4& other)
        {
            return multiply(other);
        }
        mat4 mat4::orthographic(float left, float right,float bottom,float top,float near,float far)
        {
            mat4 result;
            auto& mat=result.elements;
            mat[0+0*4]=2.0f/(right-left);
            mat[1+1*4]=2.0f/(top-bottom);
            mat[2+2*4]=-2.0f/(far-near);
            mat[0+3*4]=-(right+left)/(right-left);
            mat[1+3*4]=-(top+bottom)/(top-bottom);
            mat[2+3*4]=-(far+near)/(far-near);
            mat[3+3*4]=1;
            return result;
        }
        mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
        {
            float top=std::tan(toRadians(fov/2.0f))*near;
            float bottom=-top;
            float right = top*aspectRatio;
            float left= -right;
            mat4 result;
            auto& mat=result.elements;
            mat[0+0*4]=2.0f*near/(right-left);
            mat[0+2*4]=(right+left)/(right-left);
            mat[1+1*4]=2.0f*near/(top-bottom);
            mat[1+2*4]=(top+bottom)/(top-bottom);
            mat[2+2*4]=-(far+near)/(far-near);
            mat[2+3*4]=-2*far*near/(far-near);
            mat[3+2*4]=-1;
            return result;
        }
        mat4 mat4::translation(const vec3& translation)
        {
            mat4 result(1.0f);
            result.elements[0+3*4]=translation.x;
            result.elements[1+3*4]=translation.y;
            result.elements[2+3*4]=translation.z;
            return result;
        }
        mat4 mat4::rotation(float angle, const vec3& axis)
        {
            mat4 result;

            float r=toRadians(-angle);
            float c=cos(r);
            float s=sin(r);
            float omc=1.0f-c;

            float x=axis.x;
            float y=axis.y;
            float z=axis.z;
            float rot_mat[16]={
                x*x*omc+c,x*y*omc-z*s,x*z*omc+y*s,0,
                y*x*omc+z*s,y*y*omc+c,y*z*omc-x*s,0,
                z*x*omc-y*s,z*y*omc+x*s,z*z*omc+c,0,
                0,0,0,1
            };
            memcpy(result.elements,rot_mat,sizeof result.elements);
            return result;
        }
        mat4 mat4::scale(const vec3& scale)
        {
            mat4 result(1.0f);
            result.elements[0+0*4]=scale.x;
            result.elements[1+1*4]=scale.y;
            result.elements[2+2*4]=scale.z;
            return result;
        }
    }
}