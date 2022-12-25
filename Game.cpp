#include "Game.h"

using namespace std;

void Game:: add_to_current(Room* room){
if(room == NULL){
    cout << "Room dont exist\n";
    return;
}
    currantmap->add_to_curr(room);

}

void Game::upload_map(string name) {


	Map* temp = NULL;

		temp = data.getmap(name);
		if (temp == NULL) {
			cout << "no map" << endl;
			return ;
		}
	if (currantmap == NULL) {
		currantmap = new Map(*temp);
	}
	currantmap = temp;

}

