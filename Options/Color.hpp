#pragma once

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

        Color (uint8_t r = 0u, uint8_t g = 0u, uint8_t b = 0u, uint8_t a = 255u):
            r(r), g(g), b(b), a(a)
        {}

        Color(uint32_t integer):
            r(uint8_t(integer >> 24)),
            g(uint8_t(integer >> 16)),
            b(uint8_t(integer >> 8)),
            a(uint8_t(integer))
        {}

        uint32_t toInteger()
        {
            return (uint32_t(a) << 24) + (uint32_t(b) << 16) + (uint32_t(g) << 8) + uint32_t(r);
        }

        bool operator ==(const Color &that) const
        {
            return r == that.r && g == that.g && b == that.b && a == that.a;
        }

        bool operator !=(const Color &that) const
        {
            return !(*this == that);
        }
    };
}