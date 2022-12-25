#include "Game.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
    Game game;

    Item sword("Sword",uncommon);
    Item broad_sword("Broad Sword",uncommon);
    Item steel_sword("Steel Sword",epic);
    Item cross_bow("Cross Bow",uncommon);
    Item nunchuck("Nunchuck",legendary);
    Item axe("Axe",uncommon);
    Item trident("Trident",common);
    Item Wooden_sword("Wooden Sword",common);   



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



    game.add_room_to_data(room1);
    game.add_room_to_data(room2);
    game.add_room_to_data(room3);
    game.add_room_to_data(room4);
    game.add_room_to_data(room5);
    game.add_room_to_data(room6);
    game.add_room_to_data(room7);
    game.add_room_to_data(room8);
    game.add_room_to_data(room9);
    game.add_room_to_data(room10);


   room1.set_West(&room2);
   room2.set_East(&room1);
   room2.set_North(&room3);
   room3.set_South(&room2);

   room6.set_North(&room7);
   room7.set_South(&room6);
   room8.set_East(&room6);
   room6.set_West(&room8);

  Room *test = new Room(room1);
  test->print_rooms();
  cout << "\n=================================\n";
  room1.print_rooms();



	

	Map map1("ofek"), map2("dardale"), map3("keter"), map4("rony");
	
    map1.add_room(room1,north);
    map2.add_room(room5, west);
    map3.add_room(room6, east);

    game.add_map(map1+map3);
    game.add_map(map2);
    game.add_map(map3);
    game.add_map(map4);


	map1.get_room("null");
    game.upload_map("ofek");
    cout<<"+++++++++++++++++++++++++++++++++++++++++=\n";
    cout << game.get_curr_room();
    game.add_to_current(game.get_room("Hell"));
    game.add_to_current(game.get_room("Server room"));
    game.add_to_current(game.get_room("Restaurant"));
    game.add_to_current(game.get_room("Upside down"));
    cout << game.get_curr_room();
    game.get_current().print_rooms();
    cout<<"+++++++++++++++++++++++++++++++++++++++++=\n";
   

    



    cout << "||printing!!!||\n";
    map3.print_rooms();
    cout << "||printing!!!||\n";
    (map2+map3).print_rooms();
    cout << "||printing!!!||\n";
map4.print_rooms();



//    game.print_map_data();



return 0;
}