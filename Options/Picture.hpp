#pragma once

#include "Color.hpp"
#include "Image.hpp"
#include <assert.h>
#include <algorithm>

namespace booba
{    
    class Picture {
    public:

        Picture(const Picture &other) = delete;
        Picture &operator=(const Picture &other) = delete;
        Picture &operator=(Picture &&other);
        Picture(Picture &&other);
        ~Picture();
        
        void create(size_t w, size_t h, size_t x, size_t y, Color *image, size_t image_w, size_t image_h);
        void create(size_t w, size_t h, Color color);
        void create(size_t w, size_t h, Color *data_, bool owning = true);
        void create(size_t w, size_t h, size_t x, size_t y, Image *image);
        
        void setPixel(size_t x, size_t y, booba::Color color);
        
        const Color* getData() const;

        Color* takeData();
        
        size_t getH() const;

        size_t getW() const;

        void setColor(booba::Color color);
        
    private:
        size_t w_, h_;
        Color *data_ = nullptr;
        bool owning_ = true;
    };

    void Picture::create(size_t w, size_t h, size_t x, size_t y, Color *image, size_t image_w, size_t image_h)
    {
        w_ = w;
        h_ = h;

        size_t size = w * h;
        data_ = new Color[size];
        for (size_t i = 0; i < h; ++i)
            std::copy(image + (i + y) * image_w + x,
                        image + (i + y) * image_w + x + w,
                        data_ + i * w);
    }

    void Picture::create(size_t w, size_t h, Color color)
    {
        w_ = w;
        h_ = h;
        data_ = new Color[h * w];
        
        for (size_t pos = 0; pos < w * h; pos++)
        {
            data_[pos] = color;
        }
    }

    void Picture::create(size_t w, size_t h, size_t x, size_t y, Image *image)
    {
        w_ = w;
        h_ = h;

        size_t image_w = image->getW();
        size_t image_h = image->getH();
        assert(x + w <= image_w and y + h <= image_h);

        data_ = new Color[w * h];
        for (size_t i = 0; i < w; ++i)
            for (size_t j = 0; j < h; ++j)
                data_[j * w + i] = image->getPixel(i + x, j + y);
    }

    Picture &Picture::operator=(Picture &&other)
    {
        if (data_ != nullptr and owning_)
            delete[] data_;

        data_ = other.data_;
        w_ = other.w_;
        h_ = other.h_;

        other.w_ = other.h_ = -1;
        other.data_ = nullptr;

        return *this;
    }

    Picture::~Picture()
    {
        if (data_ != nullptr && owning_)
            delete[] data_;

        w_ = h_ = -1;
        data_ = nullptr;
    }
    
    void Picture::setPixel(size_t x, size_t y, booba::Color color)
    {
        data_[y * w_ + x] = color;
    }

    
    const Color* Picture::getData() const
    {
        return data_;
    }

    Color* Picture::takeData()
    {
        auto ret = data_;

        w_ = h_ = -1;
        data_ = nullptr;

        return ret;
    }
    
    size_t Picture::getH() const
    {
        return h_;
    }

    size_t Picture::getW() const
    {
        return w_;
    }


    void Picture::setColor(booba::Color color)
    {
        for (size_t x = 0; x < w_; x++)
        {
            for (size_t y = 0; y < h_; y++)
            {
                data_[y * w_ + x] = color;
            }
        }
    }
}