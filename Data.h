#pragma once
#include "Map.h"
#include "Room.h"




class Data
{
public:
	Data();
	~Data();

private:
	Map* mapsdata;
	Room* roomsData;
};

Data::Data()
{
}

Data::~Data()
{
}
