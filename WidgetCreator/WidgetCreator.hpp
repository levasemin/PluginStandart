#pragma once

#include "../Widgets/Widget.hpp"

namespace booba
{
    class WidgetCreator
    {
    public:
        enum class Type
        {
            LABEL,
            BUTTON,
            EDITOR,
            SCROLLBAR
        };

        virtual Widget *createWidget(Type type, int w, int h, int x, int y) = 0;
    };
}