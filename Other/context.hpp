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

    struct GUID
    {
        char str[37];
    };

    extern ApplicationContext* APPCONTEXT;
}