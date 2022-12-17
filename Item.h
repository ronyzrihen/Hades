#pragma once


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
	~Item() { delete[] m_name; };

public:
	Item& operator = (Item& source);
	Item& operator += (Item& source);
	Item operator + (Item& source);
	Item& operator ++ ();
	Item operator ++ (int);


private:
	char* m_name;
	int m_rarity;
};


