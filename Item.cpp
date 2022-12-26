/*
Ofek Eliyahu 207753120
Rony Zrihen 318917549
*/


#include "Item.h"
#include <iostream>
#include <string.h>



Item::Item():
m_name(" "),
m_rarity(common)
{

}


Item::Item(Item& source):
m_name(source.m_name),
m_rarity(source.m_rarity)
{
}




Item& Item:: operator = (Item& source) {

	if (this == &source)
		return *this;

	m_name = source.m_name;
	m_rarity = source.m_rarity;

	return *this;
}



Item Item:: operator + (Item& source) {

	Item new_item = *this;
    new_item += source;
	return new_item;

}

Item& Item:: operator += (Item& source) {

	if (m_name == source.m_name) {

		if (m_rarity + source.m_rarity > legendary)
			m_rarity = legendary;
		else
			m_rarity += source.m_rarity;
	}
		return *this;
}

Item& Item:: operator ++ () {

	if (m_rarity == legendary)
		return *this;
	
	m_rarity++;
	return *this;
}



Item Item:: operator ++ (int) {

	Item new_item = *this;
	++(*this);

	return new_item;
}

