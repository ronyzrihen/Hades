#include "Item.h"
#include <iostream>
#include <string.h>



Item::Item():
m_name(NULL),
m_rarity(common)
{

}



Item::Item(Item& source):
m_name(_strdup(source.m_name)),
m_rarity(source.m_rarity)
{
}




Item& Item:: operator = (Item& source) {

	if (this == &source)
		return *this;

	delete m_name;

	m_name = _strdup(source.m_name);
	m_rarity = source.m_rarity;

	return *this;
}



Item Item:: operator + (Item& source) {

	Item new_item = *this;
	return new_item += source;

}

Item& Item:: operator += (Item& source) {

	if (strcmp(m_name, source.m_name) == 0) {

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

