#pragma once

#include "Color.hpp"

namespace booba
{
    class Picture;
    
    class Image
    {
    public:
        /**
         * @brief Get height of image
         *
         * @return size_t - height of image.
         */
        virtual size_t getH()     = 0;

        /**
         * @brief Get width of image
         *
         * @return size_t - width of image
         */
        virtual size_t getW()     = 0;

        /**
         * @brief Get the Pixel object
         *
         * @param x - x coord. Must be less than width
         * @param y - y coord. Must be less than height
         * @return Color - color of pixel
         */
        virtual Color getPixel(size_t x, size_t y) = 0;

        /**
         * @brief Sets pixel on image.
         *
         * @param x - x coord. Must be less than width
         * @param y - y coord. Must be less than height
         * @param color - color of new pixel.
         */
        virtual void setPixel(size_t x, size_t y, Color color) = 0;

        /**
         * @brief Get picture - a rectangular pixel array.
         *
         * @note the rectangular must be in the images boundaries.
         *
         * @param x - x coord of left down corner
         * @param y - y coord of left down corner
         * @param w - width of the rectangular
         * @param h - height of the rectangular
         */
        virtual Picture getPicture(size_t x, size_t y, size_t w, size_t h) = 0;

        /**
         * @brief Set picture - a rectangular pixel array.
         *
         * @note the rectangular must be in the images boundaries.
         *
         * @param pic - the picture to set, move-only
         */
        virtual void setPicture(Picture &pic, size_t image_x, size_t image_y, size_t pic_start_x, size_t pic_start_y, size_t pic_end_x, size_t pic_end_y, bool applyAlpha) = 0;

        /**
         * @brief clean image by color
         *
         * @param color color for clean
         */
        virtual void clean(const Color &color = Color::WHITE) = 0;

    protected:
        ~Image() {}
    };
}