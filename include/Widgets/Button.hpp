#pragma once

#include <string>
#include "Widget.hpp"
#include "../Options/Color.hpp"
#include "../Options/Picture.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class Button : public Widget
    {
    public:
        virtual void setText(std::string string)              = 0;

        virtual Command<> *getLeftClick()               = 0;
        virtual void setLeftClick(Command<> *command)   = 0;
        
        virtual Command<> *getReleaseLeftClick()               = 0;
        virtual void setReleaseLeftClick(Command<> *command)   = 0;

        virtual Command<> *getRightClick()               = 0;
        virtual void setRightClick(Command<> *command)   = 0;

        virtual Command<> *getReleaseRightClick()               = 0;
        virtual void setReleaseRightClick(Command<> *command)   = 0;
    };
}