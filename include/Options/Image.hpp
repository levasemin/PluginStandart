#pragma once

#include "Color.hpp"
#include "Vector2d.hpp"

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
        virtual Vector2d getSize() const = 0;

        /**
         * @brief Get the Pixel object
         *
         * @param x - x coord. Must be less than width
         * @param y - y coord. Must be less than height
         * @return Color - color of pixel
         */
        virtual Color getPixel(Vector2d position) const = 0;

        /**
         * @brief Sets pixel on image.
         *
         * @param x - x coord. Must be less than width
         * @param y - y coord. Must be less than height
         * @param color - color of new pixel.
         */
        virtual void setPixel(Vector2d position, Color color) = 0;

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
        virtual Picture getPicture(Vector2d position, Vector2d shape) const = 0;

        /**
         * @brief Set picture - a rectangular pixel array.
         *
         * @note the rectangular must be in the images boundaries.
         *
         * @param pic - the picture to set, move-only
         */
        virtual void setPicture(Picture &pic, Vector2d image_pos, Vector2d pic_start, Vector2d pic_end, bool applyAlpha) = 0;
        
        /**
         * @brief 
         * 
         * @param pic 
         */
        virtual void replaceWithPicture(Picture &pic) = 0;
        
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