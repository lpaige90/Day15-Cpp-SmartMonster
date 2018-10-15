#include "monster.h"
#include <stdlib.h>
#include <time.h>

//Constructor for creating custom monster
Monster::Monster(std::string name, int element, int health) {
	monsterName = name;
	monsterElement = element;
	monsterHealth = health;
}

//Default constructor
Monster::Monster() {
	monsterElement = rand() % 4;//Assigns a monster element type from 0-3, corresponding to fire, frost, arcane, or poison, respectively.
	
	monsterName = monster_name(monsterElement);//Sets monster name

	monsterHealth = 100 + 100 * (rand() % 3);//Assigns a health value from 100-300, in increments of 100
}

//Function to set monster name and description based on element type
std::string Monster::monster_name(int element) {
	std::string elementName;
	std::string monsterDescription;

	//Monster Elemental Type Names
	std::string fireMonster [4] = { "Demon", "Dragon", "Hellhound", "Skeleton" };
	std::string frostMonster [4] = { "Vampire", "Wendigo", "Ice Worm", "Ghoul" };
	std::string arcaneMonster [4] = { "Banshee", "Shapeshifter", "Fairy", "Unicorn" };
	std::string poisonMonster [4] = { "Basilisk", "Arachnid", "Imp", "Orc" };

	//Monster Descriptive Names
	std::string description [10] = { "Malicious", "Vicious", "Vile", "Savage", "Murderous", "Bloodthirsty", "Ferocious", "Fierce", "Horrific", "Gruesome" };

	int randDescription = rand() % 10;//There are 10 possible words that can describe the monsters
	monsterDescription = description[randDescription];

	int randElementName = rand() % 4;//There are 4 possible monsters within each element type

	if ( element == 0 ) {
		elementName = fireMonster[randElementName];
	} else if ( element == 1 ) {
		elementName = frostMonster[randElementName];
	} else if ( element == 2 ) {
		elementName = arcaneMonster[randElementName];
	} else {
		elementName = poisonMonster[randElementName];
	}

	return monsterDescription + " " + elementName;
}

//Returns monster name
std::string Monster::get_name() {
	return monsterName;
}

//Returns monster element
int Monster::get_element() {
	return monsterElement;
}

//Returns monster health
int Monster::get_health() {
	return monsterHealth;
}

//Sets monster health
void Monster::set_health(int health) {
	monsterHealth = health;
}