#include "MapBuilder.h"
#include "Rectangle.h"
#include "Utils.h"


int main() 
{
	MapBuilder mapBuilder;

	mapBuilder.AddRoom(2, 1, 10, 5);
	mapBuilder.AddRoom(5, 5, 10, 5);

	Rectangle map = mapBuilder.build();

	Print(map);

	map.clear();

	return 0;
}