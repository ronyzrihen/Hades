#include "Game.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
    Game game;
	Room room1("Hall");
    Room room2("Hell");
    Room room3("Kanye");
    Room room4("Nether");
    Room room5("Upside down");
    Room room6("School");
    Room room7("Shenkar");
    Room room8("Bathroom");
    Room room9("Server room");
    Room room10("Restaurant");

    game.add_room(room1);
   game.add_room(room2);
  game.add_room(room3);
  game.add_room(room4);
  game.add_room(room5);
  game.add_room(room6);
  game.add_room(room7);
  game.add_room(room8);
  game.add_room(room9);
    game.add_room(room10);
    cout << game.get_data_size() << endl;
    game.print_rooms_data();

  //  stupid.print_rooms_data();

//    room1.set_West(&room2);
//    room2.set_East(&room1);
//    room2.set_North(&room3);
//    room3.set_South(&room2);


	cout << room1;

	Map map;
	map.add_room(room1,north);

	map.get_room("room1.get_name()");
return 0;
}