#pragma once
#include "../Options/Color.hpp"
#include "../Options/Vector2d.hpp"

namespace booba
{
    class Widget
    {
        virtual Vector2d getPosition() const                = 0;
        virtual void setPosition(Vector2d position)         = 0;
        
        virtual Vector2d getShape() const                   = 0;
        virtual void setShape(Vector2d position)            = 0;

        virtual void setColor(Color color)                  = 0;
    
    protected:
        virtual ~Widget()                                   = 0;
    };
}