#pragma once

#include <iostream>

namespace booba
{
    class Vector2d
    {
    public:
        int x_, y_;

        Vector2d(int x = 0, int y = 0);

        Vector2d(float x, float y);
        
        Vector2d(uint32_t x, uint32_t y);

        Vector2d(size_t x, size_t y);

        Vector2d(const Vector2d &source) = default;
        Vector2d &operator= (const Vector2d &source) = default;
        ~Vector2d() = default;
        
        friend Vector2d operator + (const Vector2d &first, const Vector2d &second);
        friend Vector2d operator + (float num, const Vector2d &first);
        friend Vector2d operator + (const Vector2d &first, float num);
        friend Vector2d operator - (const Vector2d &first, const Vector2d &second);
        friend Vector2d operator - (const Vector2d &first, float num);
        friend Vector2d operator * (const Vector2d &first, float num);
        friend Vector2d operator * (float num, const Vector2d &first);
        friend Vector2d operator / (const Vector2d &first, float num);
        
        Vector2d &operator -= (const Vector2d &that);
        Vector2d &operator += (const Vector2d &that);
        Vector2d &operator *= (float num);
        Vector2d &operator /= (float num);
    };

    Vector2d operator + (const Vector2d &first, const Vector2d &second);
    Vector2d operator + (const Vector2d &first, float num);
    Vector2d operator + (float num, const Vector2d &first);
    Vector2d operator - (const Vector2d &first, const Vector2d &second);
    Vector2d operator - (const Vector2d &first, float num);
    Vector2d operator * (const Vector2d &that, float num);
    Vector2d operator * (float num, const Vector2d &that);
    Vector2d operator / (const Vector2d &that, float num);
}