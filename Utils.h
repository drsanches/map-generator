#include <iostream>
#include "Rectangle.h"

#ifndef UTILS_H
#define UTILS_H

void Print(Rectangle rectangle)
{
    for (int j = rectangle.Height() - 1; j >= 0; j--)
    {
        for (int i = 0; i < rectangle.Width(); i++)
            std::cout << rectangle[i][j] << " ";
        std::cout << std::endl;
    }
}

#endif