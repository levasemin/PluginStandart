#pragma once
#include "../Options/Color.hpp"

namespace booba
{
    class Widget
    {
        virtual int getX()                                  = 0;
        virtual void setX(int x)                            = 0;
        
        virtual int getY()                                  = 0;
        virtual void setY(int y)                            = 0;

        virtual int getW()                                  = 0;
        virtual void setW(int w)                            = 0;
        
        virtual int getH()                                  = 0;
        virtual void setH(int h)                            = 0;
        
        virtual void setColor(Color color)                  = 0;
    };
}