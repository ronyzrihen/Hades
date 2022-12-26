/*
Ofek Eliyahu 207753120
Rony Zrihen 318917549
*/


#include "Game.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
    //creating game
    Game game;


    //creating items
    cout << "Creating Items.\n"
        << "```````````````\n";
    Item sword("Sword",uncommon);
    Item broad_sword("Broad Sword",uncommon);
    Item steel_sword("Steel Sword",epic);
    Item cross_bow("Cross Bow",uncommon);
    Item nunchuck("Nunchuck",legendary);
    Item axe("Axe",uncommon);
    Item trident("Trident",common);
    Item Wooden_sword("Wooden Sword",common); 


    //creating monsters
    cout << "Creating Monsters.\n"
        << "```````````````````\n";
    Monster davil("Devil", 4);
    Monster demon("Demon", 1);
    Monster soul_catcher("Soul Catcher", 2);
    Monster crawler("Crawler", 3);
    Monster Longspear("Longspear", 2);


    //creating rooms
    cout << "Creating Rooms.\n"
        << "````````````````\n";
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


  //adding item to a room
    cout << "Adding items to rooms.\n"
        << "```````````````````````\n";
  room1.add_item(nunchuck);
  room1.add_item(sword);
  room1.add_item(axe);
  room1.add_item(sword);
  room1.add_item(nunchuck);

  //adding a monster to a room
  cout << "Adding monsters to rooms.\n"
      << "``````````````````````\n";
  room1.add_monster(davil);
  room1.add_monster(demon);
  room1.add_monster(davil);



    //adding rooms to game data
    cout << "Adding rooms to data:\n"
        << "``````````````````````\n";
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

    //print rooms_data from data
    cout << "Printing rooms from data:\n"
        << "``````````````````````````\n";
    game.print_rooms_data();
  
    cout << "=======================================================\n\n";

    //connecting rooms
    cout << "Connecting rooms.\n"
        << "``````````````````\n";
   room1.set_West(&room2);
   room2.set_East(&room1);
   room2.set_North(&room3);
   room3.set_South(&room2);

   room6.set_North(&room7);
   room7.set_South(&room6);
   room8.set_East(&room6);
   room6.set_West(&room8);

   //print connected rooms
   cout << "Printing connected rooms:\n"
       << "``````````````````````````\n";
  Room *test = new Room(room1);
  test->print_rooms();
  cout << "=======================================================\n\n";

  //printing room's content
  cout << "Printing room's content:\n"
      << "`````````````````````````\n";
  cout << room1 << endl;
  cout << "=======================================================\n\n";
  
  //creating maps
	Map map1("ofek"), map2("dardale"), map3("keter"), map4("rony");
	
    //adding rooms to a map
    cout << "Adding rooms to map.\n"
        << "``````````````````````\n";
    map1.add_room(room1,north);
    map2.add_room(room5, west);
    map3.add_room(room6, east);

    //adding a map to data
    cout << "Adding maps to data.\n"
        << "``````````````````````\n";
    game.add_map(map1+map3);
    game.add_map(map2);
    game.add_map(map3);
    game.add_map(map4);

    //print maps_data from data
    cout << "Printing maps from data:\n"
        << "`````````````````````````\n";
    game.print_map_data();

    cout << "=======================================================\n\n";

    //uploading a map from data
    cout << "Uploading a map from data.\n"
        << "```````````````````````````\n";
    game.upload_map("ofek");
    cout<<"=======================================================\n\n";
    

    cout << "Printing current room:\n"
        << "```````````````````````\n";
    cout << game.get_curr_room();
    cout << "=======================================================\n\n";
    //adding a room to the current map
    cout << "Adding a room to the current map. \n"
        << "````````````````````````````````````\n";
    game.add_to_current(game.get_room("Hell"));
    game.add_to_current(game.get_room("Server room"));
    game.add_to_current(game.get_room("Restaurant"));
    game.add_to_current(game.get_room("Upside down"));
    cout << endl <<game.get_curr_room()<<endl;

    game.get_current().print_rooms();
    cout << "=======================================================\n\n";
   

    //map operators
    cout << "Map operators:\n"
        << "```````````````\n\n";
    
    cout << "\n||printing map2 + map3!!!||\n";
    cout << "=======================================================\n\n";
    (map2+map3).print_rooms();
    cout << "\n||printing map3!!!||\n";
    cout << "=======================================================\n\n";
    map3.print_rooms();
    map3 += map1;
    cout << "\n||printing new map3!!!||\n";
    cout << "=======================================================\n\n";
    map3.print_rooms();
    map3 = map2;
    cout << "\n||printing newest map3!!!||\n";
    cout << "=======================================================\n\n";
    map3.print_rooms();

    



return 0;
}