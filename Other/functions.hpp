#pragma once

#include "context.hpp"
#include "../Tool/Tool.hpp"
#include "../WidgetCreator/WidgetCreator.hpp"

namespace booba
{
    extern "C" Tool* init_module();

    extern "C" WidgetCreator* getWidgetCreator(Tool *tool);
}