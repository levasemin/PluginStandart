#pragma once

#include "context.hpp"
#include "../Tool/Tool.hpp"

namespace booba
{
    extern "C" GUID getGUID();

    extern "C" void init_module();

    extern "C" bool setToolBarSize(size_t w, size_t h);   

    extern "C" void addTool(Tool* tool);

    extern "C" void addFilter(Tool* tool);

    extern "C" void* getLibSymbol(GUID guid, const char* name);

    extern "C" void* getWidgetCreator();
}