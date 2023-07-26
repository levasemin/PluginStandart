#pragma once

#include <string>

#include "../Options/Color.hpp"
#include "../Options/Picture.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class Editor
    {
    public:
        virtual int getX();
        virtual void setX(int x);
        
        virtual int getY();
        virtual void setY(int y);

        virtual int getW();
        virtual void setW(int w);
        
        virtual int getH();
        virtual void setH(int h);

        virtual void setColor(Color color);

        virtual const char *getText();
        virtual void setText(std::string string);

        virtual void setCommand(const Command<std::string> *command) = 0;
        virtual const Command<std::string> *getCommand()             = 0;
    };
}