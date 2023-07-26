#pragma once

#include <string>

#include "../Options/Color.hpp"
#include "../Options/Picture.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class Label
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

        virtual void setColor(Color color)                  = 0;

        virtual void setPicture(Picture picture)            = 0;

        virtual void setText(std::string string)            = 0;

        virtual void setCommand(const Command<> *command)   = 0;
        virtual const Command<> *getCommand()               = 0;
    };
}