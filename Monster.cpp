
/*
Ofek Eliyahu 207753120
Rony Zrihen 318917549
*/

#include "Monster.h"

Monster::Monster()
	:
	m_name(" "),
	m_level(0)
{
}


Monster::Monster(Monster& source)
	:
	m_name(source.m_name),
	m_level(source.m_level)
{
}



Monster& Monster:: operator=(Monster& source) {
	if (this == &source)
		return *this;

	m_name = source.m_name;
	m_level = source.m_level;
	return *this;
}


Monster& Monster:: operator+=(Monster& source) {

	if (m_name == source.m_name) {
		if (m_level + source.m_level > 5)
			m_level = 5;
		else
			m_level += source.m_level;
	}
	return *this;
}


Monster Monster:: operator +(Monster& monster) {

	Monster new_monster = *this;
	new_monster += monster;

	return new_monster;
}


Monster& Monster:: operator++() {

	if (m_level == 5)
		return *this;

	m_level++;

	return *this;
}