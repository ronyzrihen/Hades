#pragma once
#include <iostream>
#include <string>




class Monster
{
public:
	Monster();
	Monster(Monster& source);
	~Monster() { delete[] m_name; };
public:
	Monster& operator=(Monster& source);
	Monster& operator+=(Monster& monster);
	Monster operator + (Monster& monster);
	Monster& operator ++();
private:
	char* m_name;
	int m_level;
};

