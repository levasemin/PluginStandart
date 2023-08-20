#pragma once

#include "Widget.hpp"
#include "../Options/Color.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class ScrollBar : public Widget
    {
    public:
        virtual double getValue()                           = 0;
        virtual void setValue(double value)                 = 0;

        virtual double getMinValue()                        = 0;
        virtual void setMinValue(double value)              = 0;

        virtual double getMaxValue()                        = 0;
        virtual void setMaxValue(double value)              = 0;

        virtual void setCommand(Command<float> *command)   = 0;
        virtual Command<float> *getCommand()               = 0;
    };
}