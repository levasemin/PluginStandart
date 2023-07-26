#pragma once

#include "Color.hpp"
#include "Image.hpp"
#include <assert.h>
#include <algorithm>

namespace booba
{    
    class Picture {
    public:
        Picture(size_t x, size_t y, size_t w, size_t h, Color *image, size_t image_w, size_t image_h)
            : x(x), y(y), w(w), h(h)
        {
            assert(x + w <= image_w and y + h <= image_h);

            size_t size = w * h;
            data = new Color[size];
            for (size_t i = 0; i < h; ++i)
                std::copy(image + (i + y) * image_w + x,
                          image + (i + y) * image_w + x + w,
                          data + i * w);

        }

        Picture(Color *data, size_t x, size_t y, size_t w, size_t h, bool owning = true)
            : x(x), y(y), w(w), h(h), data(data), owning(owning) {}

        Picture(size_t x, size_t y, size_t w, size_t h, Image *image)
            : x(x), y(y), w(w), h(h)
        {
            size_t image_w = image->getW();
            size_t image_h = image->getH();
            assert(x + w <= image_w and y + h <= image_h);

            size_t size = w * h;
            data = new Color[size];
            for (size_t i = 0; i < w; ++i)
                for (size_t j = 0; j < h; ++j)
                    data[j * w + i] = image->getPixel(i + x, j + y);
        }

        Picture(const Picture &other) = delete;

        Picture(Picture &&other)
            : x(other.x), y(other.y), w(other.w), h(other.h), data(other.data)
        {
            other.x = other.y = -1;
            other.w = other.h = -1;
            other.data = nullptr;
        }

        void operator=(const Picture &other) = delete;

        void operator=(Picture &&other)
        {
            if (data != nullptr and owning)
                delete[] data;

            data = other.data;
            x = other.x;
            y = other.y;
            w = other.w;
            h = other.h;

            other.x = other.y = -1;
            other.w = other.h = -1;
            other.data = nullptr;
        }

        ~Picture()
        {
            if (data != nullptr and owning)
                delete[] data;

            x = y = -1;
            w = h = -1;
            data = nullptr;
        }

        Color& operator()(size_t x, size_t y)
        {
            assert(x < w and y < h);
            return data[y * w + x];
        }

        const Color& operator()(size_t x, size_t y) const
        {
            assert(x < w and y < h);
            return data[y * w + x];
        }

        void reshape(size_t new_x, size_t new_y, size_t new_w, size_t new_h)
        {
            if (new_x == -1)
                new_x = x;
            if (new_y == -1)
                new_y = y;
            if (new_w == -1)
                new_w = w;
            if (new_h == -1)
                new_h = h;

            assert(new_w * new_h == w * h);
            x = new_x;
            y = new_y;
            w = new_w;
            h = new_h;
        }

        Color* getData() const
        {
            return data;
        }

        Color* takeData()
        {
            auto ret = data;

            x = y = -1;
            w = h = -1;
            data = nullptr;

            return ret;
        }

        size_t getH() const
        {
            return h;
        }

        size_t getW() const
        {
            return w;
        }

        size_t getX() const
        {
            return x;
        }

        size_t getY() const
        {
            return y;
        }

    private:
        size_t x, y;
        size_t w, h;
        Color *data = nullptr;
        bool owning = true;
    };
}