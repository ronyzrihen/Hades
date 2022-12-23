#include <iostream>
using namespace std;
class Room
{
public:
  Room(int id) : id_(id), north_(nullptr), south_(nullptr), east_(nullptr), west_(nullptr), visited_(false) {}
  int getId() const { return id_; }
  bool getVisited() const { return visited_; }
  void setVisited(bool visited) { visited_ = visited; }
  void setNorth(Room *north) { north_ = north; }
  Room *getNorth() const { return north_; }
  void setSouth(Room *south) { south_ = south; }
  Room *getSouth() const { return south_; }
  void setEast(Room *east) { east_ = east; }
  Room *getEast() const { return east_; }
  void setWest(Room *west) { west_ = west; }
  Room *getWest() const { return west_; }

private:
  int id_;
  bool visited_;
  Room *north_;
  Room *south_;
  Room *east_;
  Room *west_;
};

class Map
{
public:
  Map() : head_(nullptr) {}
  void setHead(Room *head) { head_ = head; }
  Room *getHead() const { return head_; }

private:
  Room *head_;
};

void copyRooms(Map &dest, Room *src)
{
  if (src == nullptr || src->getVisited())
  {
    return; // the source map is empty or the room has already been visited
  }

  src->setVisited(true);

  Room *destRoom = new Room(src->getId());
  if (dest.getHead() == nullptr)
  {
    // this is the first room being copied
    dest.setHead(destRoom);
  }

  // copy the rooms in the north direction
  if (src->getNorth() != nullptr)
  {
    Map northDest;
    copyRooms(northDest, src->getNorth());
    destRoom->setNorth(northDest.getHead());
  }

  // copy the rooms in the south direction
  if (src->getSouth() != nullptr)
  {
    Map southDest;
    copyRooms(southDest, src->getSouth());
    destRoom->setSouth(southDest.getHead());
  }

  // copy the rooms in the east direction
  if (src->getEast() != nullptr)
  {
    Map eastDest;
    copyRooms(eastDest, src->getEast());
    destRoom->setEast(eastDest.getHead());
  }

  // copy the rooms in the west direction
  if (src->getWest() != nullptr)
  {
    Map westDest;
    copyRooms(westDest, src->getWest());
    destRoom->setWest(westDest.getHead());
  }
}

int main()
{
  Map srcMap;

  Room *room1 = new Room(1);
  Room *room2 = new Room(2);
  Room *room3 = new Room(3);

  room1->setNorth(room2);
  room2->setSouth(room1);

  room2->setEast(room3);
  room3->setWest(room2);

  srcMap.setHead(room1);

  Map destMap;
  copyRooms(destMap, srcMap.getHead());

  Room *currentRoom = destMap.getHead();

  cout << "Room ID: " << currentRoom->getId() << endl;
  currentRoom = currentRoom->getNorth();
  cout << "Room ID: " << currentRoom->getId() << endl;
  currentRoom = currentRoom->getEast();
  cout << "Room ID: " << currentRoom->getId() << endl;
}