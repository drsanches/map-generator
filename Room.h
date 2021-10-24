#include <iostream>
#include "Rectangle.h"

#ifndef ROOM_H
#define ROOM_H

class Room
{
    private:
        int x_, y_; //Coordinates of the lower left corner
        Rectangle* rectangle_ = NULL;

    public: 
        Room(int x, int y, int width, int height)
        {
            x_ = x;
            y_ = y;
            rectangle_ = new Rectangle(width, height);
            std::cout << "Room created" << std::endl;
        }

        int* operator[](const int index) { return rectangle_->Array()[index]; }

        int Width() { return rectangle_->Width(); }

        int Height() { return rectangle_->Height(); }

        int X() { return x_; }

        int Y() { return y_; }

        void clear()
        {
            rectangle_->clear();
            delete rectangle_;
            std::cout << "Room deleted" << std::endl;
        }
};

#endif