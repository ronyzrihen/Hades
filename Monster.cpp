#include "Monster.h"

Monster::Monster()
	:
	m_name(NULL),
	m_level(0)
{
}


Monster::Monster(Monster& source)
	:
	m_name(_strdup(source.m_name)),
	m_level(source.m_level)
{
}



Monster& Monster:: operator=(Monster& source) {
	if (this == &source)
		return *this;

	delete[] m_name;
	m_name = _strdup(source.m_name);
	m_level = source.m_level;
	return *this;
}


Monster& Monster:: operator+=(Monster& source) {

	if (strcmp(m_name, source.m_name) == 0) {
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