#pragma once

#include "context.hpp"
#include "../Tool/Tool.hpp"

namespace booba
{
    extern "C" void* init_module();

    extern "C" void* getWidgetCreator(Tool *tool);
}