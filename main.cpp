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
    //cout << game.get_data_size() << endl;
 //   game.print_rooms_data();

  //  stupid.print_rooms_data();

   room1.set_West(&room2);
   room2.set_East(&room1);
   room2.set_North(&room3);
   room3.set_South(&room2);

   room6.set_North(&room7);
   room7.set_South(&room6);
   room8.set_East(&room6);
   room6.set_West(&room8);

  



	

	Map map1("ofek"), map2("dardale"), map3("zibi");
	
    map1.add_room(room1,north);
    map2.add_room(room5, west);
    map3.add_room(room6, east);
    map1.print_rooms();
    game.add_map(map1);
    game.add_map(map2);
    game.add_map(map3);
	map1.get_room("null");
    game.upload_map("ofek");
   
    cout << game.print_current();
    
    game.get_current() += ( * (game.get_map("zibi")) + *(game.get_map("dardale")));//lo tofes.
    cout << game.get_num_of_rooms()<< endl;

//    game.print_map_data();



return 0;
}