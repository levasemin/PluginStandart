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

        virtual Widget *createWidget(Type type, Vector2d shape, Vector2d position) = 0;
    };
}