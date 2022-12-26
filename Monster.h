#pragma once
#include <iostream>
#include <string>
using namespace std;



class Monster
{
public:
	Monster();
	Monster(const string& name, int level):m_name(name),m_level(level){};
	Monster(Monster& source);
	~Monster() {  };
public:
	//Operators
	Monster& operator=(Monster& source);
	Monster& operator+=(Monster& monster);
	Monster operator + (Monster& monster);
	Monster& operator ++();

	//Getters
	string& get_name() { return m_name; };
	int get_level() { return m_level; };

	//A setter
	void set_level(int level) { m_level = level; };

private:
	string m_name;
	int m_level;
};

