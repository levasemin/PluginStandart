#pragma once

#include "Color.hpp"
#include "Image.hpp"
#include <assert.h>
#include <algorithm>

namespace booba
{    
    class Picture {
    public:
        
        Picture() = default;
        Picture(const Picture &other);
        Picture &operator=(const Picture &other);
        Picture(Picture &&other);
        Picture &operator=(Picture &&other);

        ~Picture();

        void create(Vector2d shape, Vector2d position, const Color *image, Vector2d image_shape);
        void create(Vector2d shape, Color color);

        void create(Vector2d shape, Vector2d position, const Image *image);

        void setPixel(Vector2d position, booba::Color color);

        const Color* getData() const;

        Color* takeData();
        
        Vector2d getSize() const;

        void setColor(booba::Color color);
    
    private:
        Vector2d shape_;
        Color *data_ = nullptr;
    };
}