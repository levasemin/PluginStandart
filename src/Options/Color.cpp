#include "../../include/Options/Color.hpp"

namespace booba
{
    Color::Color (uint8_t r, uint8_t g, uint8_t b, uint8_t a):
        r(r), g(g), b(b), a(a)
    {}

    Color::Color(uint32_t integer):
        r(uint8_t(integer >> 24)),
        g(uint8_t(integer >> 16)),
        b(uint8_t(integer >> 8)),
        a(uint8_t(integer))
    {}

    uint32_t Color::toInteger()
    {
        return (uint32_t(a) << 24) + (uint32_t(b) << 16) + (uint32_t(g) << 8) + uint32_t(r);
    }

    bool Color::operator ==(const Color &that) const
    {
        return r == that.r && g == that.g && b == that.b && a == that.a;
    }

    bool Color::operator !=(const Color &that) const
    {
        return !(*this == that);
    }
}