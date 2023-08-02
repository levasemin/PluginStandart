#pragma once

#include "../Options/Image.hpp"
#include "../Options/Picture.hpp"
#include "../EventSystem/Event.hpp"

namespace booba 
{
    class Tool
    {
    public:
        /**
         * @brief This function will be called on every event happens.
         *
         * @param image - Image to apply tool / filter. Can be nullptr. You shouldn't expect it to be valid after return
         * @param event - Event to proceed. Not nullptr.
         */
        virtual void apply(Image* image, const Event* event) = 0;

        /**
         * @brief Destroy the Tool object
         *
         */
        virtual ~Tool() {}

        /**
         * @brief Get the texture to draw.
         *
         * @return const char* - rel path to texture.
         */
        virtual const char* getTexture() = 0;
    };
}