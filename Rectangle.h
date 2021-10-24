#include <iostream>

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle 
{
    private:
        int width_; 
        int height_;
        int** array_ = NULL;

    public:
        Rectangle(int width, int height) 
        {
            width_ = width;
            height_ = height;
            array_ = new int*[width_];
            for (int i = 0; i < width_; i++) 
                array_[i] = new int[height_];
            std::cout << "Rectangle created" << std::endl;
        }

        int Width() { return width_; }

        int Height() { return height_; }

        int** Array() { return array_; }

        int* operator[](const int index) { return array_[index]; }

        void clear() 
        {
            for (int i = 0; i < width_; i++)
                delete[] array_[i];
            delete[] array_;
            std::cout << "Rectangle deleted" << std::endl;
        }
};

#endif