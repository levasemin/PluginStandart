#pragma once
#include <cstdint>

namespace booba
{
    class Color
    {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        enum
        {
            RED    = 0xFF0000FF, 
            ORANGE = 0xFF6600FF,
            YELLOW = 0xFFFF00FF,
            GREEN  = 0x00FF00FF, 
            BLUE   = 0x0000FFFF, 
            INDIGO = 0x480082FF,
            VIOLET = 0x8800FFFF,
            BLACK  = 0x000000FF,
            WHITE  = 0xFFFFFFFF,
            TRANSPARENT = 0x0
        };

        Color (uint8_t r = 0u, uint8_t g = 0u, uint8_t b = 0u, uint8_t a = 255u);

        Color(uint32_t integer);

        uint32_t toInteger();

        bool operator ==(const Color &that) const;

        bool operator !=(const Color &that) const;
    };
}