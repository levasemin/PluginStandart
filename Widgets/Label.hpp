#pragma once

#include <string>

#include "Widget.hpp"
#include "../Options/Color.hpp"
#include "../Options/Picture.hpp"
#include "../EventSystem/Command.hpp"

namespace booba
{
    class Label : public Widget
    {
    public:
        virtual void setText(std::string string)            = 0;
    };
}