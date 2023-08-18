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
            shape_(other.shape_)
        {
            data_ = new Color[shape_.x_ * shape_.y_];
            for (int pos = 0; pos < shape_.x_ * shape_.y_; pos++)
            {
                data_[pos] = other.data_[pos];
            }
        }

        Picture &operator=(const Picture &other)
        {
            shape_ = other.shape_;

            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[shape_.x_ * shape_.y_];
            for (int pos = 0; pos < shape_.x_ * shape_.y_; pos++)
            {
                data_[pos] = other.data_[pos];
            }
        }
        
        void create(Vector2d shape, Vector2d position, Color *image, Vector2d image_shape)
        {
            shape_ = shape;
            
            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[shape_.x_ * shape_.y_];
            for (size_t i = 0; i < shape_.y_; ++i)
                std::copy(image + (i + position.y_) * image_shape.x_ + position.x_,
                            image + (i + shape_.y_) * image_shape.x_ + position.x_ + shape_.x_,
                            data_ + i * shape_.x_);
        }

        void create(Vector2d shape, Color color)
        {
            shape_ = shape;

            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[shape_.x_ * shape_.y_];
            
            for (size_t pos = 0; pos < shape_.x_ * shape_.y_; pos++)
            {
                data_[pos] = color;
            }
        }

        void create(Vector2d shape, Vector2d position, Image *image)
        {
            shape_ = shape;

            assert(position.x_ + shape.x_ <= image->getSize().x_ and position.y_ + shape_.y_ <= image->getSize().y_);

            if (data_)
            {
                delete[] data_;
            }

            data_ = new Color[shape_.x_ * shape_.y_];
            for (size_t i = 0; i < shape.y_; ++i)
                for (size_t j = 0; j < shape_.x_; ++j)
                    data_[j * shape_.x_ + i] = image->getPixel(Vector2d(i + position.x_, j + position.y_));
        }

        Picture &operator=(Picture &&other)
        {
            if (data_)
            {
                delete[] data_;
            }

            data_  = other.data_;
            shape_ = other.shape_;

            other.shape_ = Vector2d(-1, -1);
            other.data_ = nullptr;

            return *this;
        }

        ~Picture()
        {
            if (data_)
            {
                delete[] data_;
            }
            
            data_ = nullptr;
        }
        
        void setPixel(Vector2d position, booba::Color color)
        {
            if (data_)
            {
                data_[position.y_ * shape_.x_ + position.x_] = color;
            }
        }

        
        const Color* getData() const
        {
            return data_;
        }

        Color* takeData()
        {
            auto ret = data_;

            shape_ = Vector2d(-1, -1);
            data_ = nullptr;

            return ret;
        }
        
        Vector2d getSize() const 
        {
            return shape_;
        }

        void setColor(booba::Color color)
        {
            for (size_t y = 0; y < shape_.y_; y++)
            {
                for (size_t x = 0; x < shape_.x_; x++)
                {
                    data_[y * shape_.x_ + x] = color;
                }
            }
        }

    private:
        Vector2d shape_;
        Color *data_ = nullptr;
        bool owning_ = true;
    };
}