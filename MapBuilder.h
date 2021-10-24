#include <vector>
#include <algorithm>
#include <limits.h>
#include "Rectangle.h"
#include "Room.h"
#include "CellType.h"

#ifndef MAP_BUILDER_H
#define MAP_BUILDER_H

class MapBuilder {

    private:
        std::vector<Room*> rooms_;

    public: 
        void AddRoom(int x, int y, int width, int height) 
        {
            Room* room = new Room(x, y, width, height);
            for (int i = 0; i < width; i++)
                for (int j = 0; j < height; j++)
                    if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
                        (*room)[i][j] = CellType::WALL;
                    else
                        (*room)[i][j] = CellType::FLOOR;
            rooms_.push_back(room);
        }

        Rectangle build()
        {
            int minX = INT_MAX;
            int minY = INT_MAX;
            int width = 0;
            int height = 0;
            for (auto room: rooms_)
            {
                minX = std::min(minX, room->X());
                minY = std::min(minY, room->Y());
                width = std::max(width, room->X() + room->Width());
                height = std::max(height, room->Y() + room->Height());
            }

            width -= minX;
            height -= minY;

            Rectangle map(width, height);
            for (int i = 0; i < map.Width(); i++)
                for (int j = 0; j < map.Height(); j++)
                    map[i][j] = 0;

            for (auto room: rooms_) 
                for (int i = 0; i < room->Width(); i++)
                    for (int j = 0; j < room->Height(); j++)
                        map[room->X() - minX + i][room->Y() - minY + j] = (*room)[i][j];
            return map;
        }

        ~MapBuilder()
        {
            for (auto room: rooms_)
                room->clear();
        }
};

#endif