#pragma once
#include <iostream>
#include <string>
using namespace  std;

typedef enum {
	common,
	uncommon,
	epic,
	legendary
}Rarity;

class Item
{
public:
	Item();
	Item(Item& source);
	~Item() { };

public:
    string& get_name(){return m_name;};
    int get_rarity() {return m_rarity;};
    void set_rarity(Rarity rarity) {m_rarity = rarity;};
	Item& operator = (Item& source);
	Item& operator += (Item& source);
	Item operator + (Item& source);
	Item& operator ++ ();
	Item operator ++ (int);


private:
	string m_name;
	int m_rarity;
};


