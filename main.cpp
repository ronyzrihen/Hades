#include "Game.h"
#include<iostream>
#include<string>
using namespace std;

int main() {

	Room room("ofek");
	cout << room;

	Map map;
	map.add_room(room,north);
	map.get_room(room.get_name());

}