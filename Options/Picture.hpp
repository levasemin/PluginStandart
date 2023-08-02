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
        Picture(const Picture &other):
            w_(other.w_),
            h_(other.h_)
        {
            data_ = new Color[w_ * h_];
            for (int pos = 0; pos < w_ * h_; pos++)
            {
                data_[pos] = other.data_[pos];
            }
        }

        Picture &operator=(const Picture &other)
        {
            w_ = other.w_;
            h_ = other.h_;

            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[w_ * h_];
            for (int pos = 0; pos < w_ * h_; pos++)
            {
                data_[pos] = other.data_[pos];
            }
        }
        
        void create(size_t w, size_t h, size_t x, size_t y, Color *image, size_t image_w, size_t image_h)
        {
            w_ = w;
            h_ = h;
            
            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[w * h];
            for (size_t i = 0; i < h; ++i)
                std::copy(image + (i + y) * image_w + x,
                            image + (i + y) * image_w + x + w,
                            data_ + i * w);
        }

        void create(size_t w, size_t h, Color color)
        {
            w_ = w;
            h_ = h;

            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[h * w];
            
            for (size_t pos = 0; pos < w * h; pos++)
            {
                data_[pos] = color;
            }
        }

        void create(size_t w, size_t h, size_t x, size_t y, Image *image)
        {
            w_ = w;
            h_ = h;

            size_t image_w = image->getW();
            size_t image_h = image->getH();
            assert(x + w <= image_w and y + h <= image_h);

            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[w * h];
            for (size_t i = 0; i < w; ++i)
                for (size_t j = 0; j < h; ++j)
                    data_[j * w + i] = image->getPixel(i + x, j + y);
        }

        Picture &operator=(Picture &&other)
        {
            if (data_)
            {
                delete[] data_;
            }

            data_ = other.data_;
            w_ = other.w_;
            h_ = other.h_;

            other.w_ = other.h_ = -1;
            other.data_ = nullptr;

            return *this;
        }

        ~Picture()
        {
            if (data_)
            {
                delete[] data_;
            }
            
            w_ = h_ = -1;
            data_ = nullptr;
        }
        
        void setPixel(size_t x, size_t y, booba::Color color)
        {
            if (data_)
            {
                data_[y * w_ + x] = color;
            }
        }

        
        const Color* getData() const
        {
            return data_;
        }

        Color* takeData()
        {
            auto ret = data_;

            w_ = h_ = -1;
            data_ = nullptr;

            return ret;
        }
        
        size_t getH() const
        {
            return h_;
        }

        size_t getW() const
        {
            return w_;
        }

        void setColor(booba::Color color)
        {
            for (size_t x = 0; x < w_; x++)
            {
                for (size_t y = 0; y < h_; y++)
                {
                    data_[y * w_ + x] = color;
                }
            }
        }

    private:
        size_t w_, h_;
        Color *data_ = nullptr;
        bool owning_ = true;
    };
}