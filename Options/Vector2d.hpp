#pragma once

#include <iostream>

namespace booba
{
    class Vector2d
    {
    public:
        int x_, y_;

        Vector2d(float x = 0, float y = 0): 
            x_(x),
            y_(y)
            {};

        Vector2d(int x, int y): 
            x_(static_cast<int>(x)),
            y_(static_cast<int>(y))
            {};
        
        Vector2d(uint32_t x, uint32_t y): 
            x_(static_cast<int>(x)),
            y_(static_cast<int>(y))
            {};

        Vector2d(size_t x, size_t y): 
            x_(static_cast<int>(x)),
            y_(static_cast<int>(y))
            {};
            
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

    Vector2d operator + (const Vector2d &first, const Vector2d &second)
    {
        Vector2d new_vector = first;
        new_vector += second;
        return new_vector;
    }

    Vector2d operator + (const Vector2d &first, float num)
    {
        Vector2d new_vector = first;
        new_vector.x_ += num;
        new_vector.y_ += num;
        return new_vector;
    }

    Vector2d operator + (float num, const Vector2d &first)
    {
        Vector2d new_vector = first;
        new_vector.x_ += num;
        new_vector.y_ += num;
        return new_vector;
    }

    Vector2d operator - (const Vector2d &first, const Vector2d &second)
    {
        Vector2d new_vector = first;
        new_vector -= second;
        return new_vector;
    }

    Vector2d operator - (const Vector2d &first, float num)
    {
        Vector2d new_vector = first;
        new_vector.x_ -= num;
        new_vector.y_ -= num;
        return new_vector;
    }

    Vector2d operator * (const Vector2d &that, float num)
    {
        Vector2d new_vector = that;
        new_vector *= num;
        return new_vector;
    }

    Vector2d operator * (float num, const Vector2d &that)
    {
        Vector2d new_vector = that;
        new_vector *= num;
        return new_vector;
    }

    Vector2d operator / (const Vector2d &that, float num)
    {
        Vector2d new_vector = that;
        new_vector /= num;
        return new_vector;
    }

    Vector2d &Vector2d::operator -= (const Vector2d &that)
    {
        x_ -= that.x_;
        y_ -= that.y_;

        return *this;
    }

    Vector2d &Vector2d::operator+= (const Vector2d &that)
    {
        x_ += that.x_;
        y_ += that.y_;

        return *this;
    }

    Vector2d &Vector2d::operator *= (float num)
    {
        x_ *= num;
        y_ *= num;

        return *this;
    }

    Vector2d &Vector2d::operator /= (float num)
    {
        x_ /= num;
        y_ /= num;

        return *this;
    }
}