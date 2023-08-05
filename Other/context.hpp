#pragma once

namespace booba
{
    struct ApplicationContext
    {
        /**
         * @brief fgColor - foreground drawing color.
         * @brief bgColor - background drawing color.
         */
        Color fgColor, bgColor;
    };

    extern ApplicationContext* APPCONTEXT;
}