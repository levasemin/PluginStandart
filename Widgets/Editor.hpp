#pragma once

#include <string>

#include "Widget.hpp"
#include "../Options/Color.hpp"
#include "../Options/Picture.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class Editor : public Widget
    {
    public:
        virtual const char *getText();
        virtual void setText(std::string string);

        virtual void setCommand(Command<std::string> *command) = 0;
        virtual Command<std::string> *getCommand()             = 0;
    };
}