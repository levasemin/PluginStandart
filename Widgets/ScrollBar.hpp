#pragma once

#include "../Options/Color.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class ScrollBar
    {
    public:
        virtual int getX()                                  = 0;
        virtual void setX(int x)                            = 0;
        
        virtual int getY()                                  = 0;
        virtual void setY(int y)                            = 0;

        virtual int getW()                                  = 0;
        virtual void setW(int w)                            = 0;
        
        virtual int getH()                                  = 0;
        virtual void setH(int h)                            = 0;

        virtual double getValue()                           = 0;
        virtual void setValue(double value)                 = 0;

        virtual double getMinValue()                        = 0;
        virtual void setMinValue(double value)              = 0;

        virtual double getMaxValue()                        = 0;
        virtual void setMaxValue(double value)              = 0;

        virtual void setColor(Color color)                  = 0;

        virtual void setCommand(const Command<float> *command)   = 0;
        virtual const Command<float> *getCommand()               = 0;
    };
}